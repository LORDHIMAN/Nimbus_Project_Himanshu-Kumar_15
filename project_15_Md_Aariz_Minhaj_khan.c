#include "fleet.h"

// Add a trip
void addTrip(struct Trip t[], int *tripCount,
             struct Vehicle v[], int vehicleCount) {
    int id, index;

    if (*tripCount >= MAX_TRIPS) {
        printf("Trip list is full.\n");
        return;
    }

    if (vehicleCount == 0) {
        printf("No vehicles. Add a vehicle first.\n");
        return;
    }

    printf("Enter Vehicle ID for this trip: ");
    scanf("%d", &id);

    index = findVehicle(v, vehicleCount, id);
    if (index == -1) {
        printf("Vehicle not found.\n");
        return;
    }

    printf("Enter Distance (km): ");
    scanf("%f", &t[*tripCount].dist);
    printf("Enter Fuel Used (liters): ");
    scanf("%f", &t[*tripCount].fuel);
    printf("Enter Start Point: ");
    scanf("%s", t[*tripCount].start);
    printf("Enter End Point: ");
    scanf("%s", t[*tripCount].end);

    t[*tripCount].vehicleId = id;

    // Update vehicle totals 
    v[index].totalDist += t[*tripCount].dist;
    v[index].totalFuel += t[*tripCount].fuel;

    (*tripCount)++;      
    printf("Trip added.\n");
}

// Show all trips
void showTrips(struct Trip t[], int tripCount) {
    int i;
    if (tripCount == 0) {
        printf("No trips recorded.\n");
        return;
    }

    printf("\n--- ALL TRIPS ---\n");
    for (i = 0; i < tripCount; i++) {
        float eff = 0;
        if (t[i].fuel > 0)
            eff = t[i].dist / t[i].fuel;

        printf("%d) VehID=%d, Dist=%.2f km, Fuel=%.2f L, Eff=%.2f km/L, %s -> %s\n",
               i + 1,
               t[i].vehicleId,
               t[i].dist,
               t[i].fuel,
               eff,
               t[i].start,
               t[i].end);
    }
}