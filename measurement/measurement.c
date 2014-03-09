#include "measurement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tmeasurement readMeasurements(char *filename) {
	FILE *fp;
	Tmeasurement measures;
	int i;

	fp = fopen(filename, "r");
	fscanf(fp, "%d", &measures.count);

	measures.numbers = (double *)malloc(measures.count*sizeof(double));

	for(i = 0; i < measures.count; i++) {
		fscanf(fp, "%lf", &measures.numbers[i]);
	}

	fclose(fp);

	return measures;
}

void printMeasurements(Tmeasurement m) {
	int i;
	for(i = 0; i < m.count; i++) {
		printf("%f\n", m.numbers[i]);
	}
}

double meanMeasurements(Tmeasurement m) {
	double sum = 0;
	int i;
	for(i = 0; i < m.count; i++) {
		sum += m.numbers[i];
	}

	return sum/m.count;
}

void incMeasurements(Tmeasurement m, double increment) {
	int i;
	for(i = 0; i < m.count; i++) {
		m.numbers[i] += increment;
	}
}

Tmeasurement copyMeasurements(Tmeasurement m) {
	Tmeasurement nm;
	nm = m;
	nm.numbers = (double *)malloc(nm.count * sizeof(double));
	memcpy(nm.numbers, m.numbers, m.count*sizeof(double));

	return nm;
}