#pragma once

#define MAX 

typedef struct {
	int count;
	double *numbers;
} Tmeasurement;

Tmeasurement readMeasurements(char *filename);
void printMeasurements(Tmeasurement m);
double meanMeasurements(Tmeasurement m);
void incMeasurements(Tmeasurement m, double increment);
Tmeasurement copyMeasurements(Tmeasurement m);