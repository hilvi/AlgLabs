#ifndef _RUNNER
#define _RUNNER

#include "time2.h"

typedef struct {
	char name[30];
	Ttime time;
} Trunner;

void readName(Trunner *, const char *);
void readTime(Trunner *, const char *);
void displayRunner(const Trunner *);
int betterRunner(const Trunner *, const Trunner *);
void printTimeDifference(const Trunner *, const Trunner *);

#endif
