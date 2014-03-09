#include "measurement.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
	Tmeasurement m1, m2;
	m1 = readMeasurements("z:\\AlgLabs\\Debug\\mea.dat");
	printMeasurements(m1);
	m2 = copyMeasurements(m1);
	incMeasurements(m2, 0.1);
	printf("Mean m1 is %.4lf\n", meanMeasurements(m1));
	printf("Mean m2 is %.4lf\n", meanMeasurements(m2));
	fflush(stdin); getchar();
	return 0;
}