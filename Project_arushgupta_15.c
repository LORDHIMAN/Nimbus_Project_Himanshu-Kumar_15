#include "fleet.h"

int main() {
    struct Vehicle vehicles[MAX_VEHICLES];
    struct Trip trips[MAX_TRIPS];
    int vehicleCount = 0;
    int tripCount = 0;
    int choice, i;

    // Initialize vehicles 
    for (i = 0; i < MAX_VEHICLES; i++) {
        vehicles[i].id = 0;
        vehicles[i].totalDist = 0;
        vehicles[i].totalFuel = 0;
    }

    while (1) {
        printf("\n=== FLEET FUEL ANALYZER ===\n");
        printf("1. Add Vehicle\n");
        printf("2. Add Trip\n");
        printf("3. Show All Trips\n");
        printf("4. Show Vehicle Stats\n");
        printf("5. Suggest Best Vehicle\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        if (choice == 1)
            addVehicle(vehicles, &vehicleCount);
        else if (choice == 2)
            addTrip(trips, &tripCount, vehicles, vehicleCount);
        else if (choice == 3)
            showTrips(trips, tripCount);
        else if (choice == 4)
            showStats(vehicles, vehicleCount);
        else if (choice == 5)
            bestVehicle(vehicles, vehicleCount);
        else
            printf("Invalid choice.\n");
    }

    printf("Exiting program.\n");
    return 0;
}