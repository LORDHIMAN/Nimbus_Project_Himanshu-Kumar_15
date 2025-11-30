#ifndef FLEET_H
#define FLEET_H

#include <stdio.h>

#define MAX_VEHICLES 5
#define MAX_TRIPS 20

struct Vehicle {
    int id;
    float totalDist;
    float totalFuel;
};

struct Trip {
    int vehicleId;
    float dist;
    float fuel;
    char start[20];
    char end[20];
};

// Function declarations 
int  findVehicle(struct Vehicle v[], int vehicleCount, int id);
void addVehicle(struct Vehicle v[], int *vehicleCount);
void addTrip(struct Trip t[], int *tripCount, struct Vehicle v[], int vehicleCount);
void showTrips(struct Trip t[], int tripCount);
void showStats(struct Vehicle v[], int vehicleCount);
void bestVehicle(struct Vehicle v[], int vehicleCount);

#endif // FLEET_H 
