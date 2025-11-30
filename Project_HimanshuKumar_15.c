#include "fleet.h"

// Find vehicle index by ID
int findVehicle(struct Vehicle v[], int vehicleCount, int id) {
    int i;
    for (i = 0; i < vehicleCount; i++) {
        if (v[i].id == id)
            return i;
    }
    return -1;
}

// Add a vehicle
void addVehicle(struct Vehicle v[], int *vehicleCount) {
    int id;

    if (*vehicleCount >= MAX_VEHICLES) {
        printf("Vehicle list is full.\n");
        return;
    }

    printf("Enter Vehicle ID: ");
    scanf("%d", &id);

    if (findVehicle(v, *vehicleCount, id) != -1) {
        printf("Vehicle ID already exists.\n");
        return;
    }

    v[*vehicleCount].id = id;
    v[*vehicleCount].totalDist = 0;
    v[*vehicleCount].totalFuel = 0;

    (*vehicleCount)++;   
    printf("Vehicle added.\n");
}

// Show stats for each vehicle and fleet 
void showStats(struct Vehicle v[], int vehicleCount) {
    int i;
    float totalDist = 0;
    float totalFuel = 0;

    if (vehicleCount == 0) {
        printf("No vehicles.\n");
        return;
    }

    printf("\n--- VEHICLE STATS ---\n");
    for (i = 0; i < vehicleCount; i++) {
        float eff = 0;
        if (v[i].totalFuel > 0)
            eff = v[i].totalDist / v[i].totalFuel;

        printf("Vehicle ID=%d\n", v[i].id);
        printf("  Total Distance: %.2f km\n", v[i].totalDist);
        printf("  Total Fuel    : %.2f L\n", v[i].totalFuel);
        printf("  Avg Efficiency: %.2f km/L\n\n", eff);

        totalDist += v[i].totalDist;
        totalFuel += v[i].totalFuel;
    }

    if (totalFuel > 0) {
        printf("Fleet Total Distance: %.2f km\n", totalDist);
        printf("Fleet Total Fuel    : %.2f L\n", totalFuel);
        printf("Fleet Avg Efficiency: %.2f km/L\n",
               totalDist / totalFuel);
    }
}

// Suggest best vehicle (highest average km/L) and estimate cost 
void bestVehicle(struct Vehicle v[], int vehicleCount) {
    int i, bestIndex = -1;
    float bestEff = -1;
    float routeDist, fuelPrice;

    if (vehicleCount == 0) {
        printf("No vehicles.\n");
        return;
    }

    for (i = 0; i < vehicleCount; i++) {
        if (v[i].totalFuel > 0) {
            float eff = v[i].totalDist / v[i].totalFuel;
            if (eff > bestEff) {
                bestEff = eff;
                bestIndex = i;
            }
        }
    }

    if (bestIndex == -1) {
        printf("No fuel data available.\n");
        return;
    }

    printf("Best Vehicle: ID=%d with AvgEff=%.2f km/L\n",
           v[bestIndex].id, bestEff);

    printf("Enter route distance (km): ");
    scanf("%f", &routeDist);
    printf("Enter fuel price per liter: ");
    scanf("%f", &fuelPrice);

    if (bestEff > 0) {
        float fuelNeeded = routeDist / bestEff;
        float cost = fuelNeeded * fuelPrice;
        printf("Estimated fuel needed: %.2f L\n", fuelNeeded);
        printf("Estimated fuel cost  : %.2f\n", cost);
    }
}
