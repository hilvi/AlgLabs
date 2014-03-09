#include "stdafx.h"
#include "time.h"

int read_time(Ttime *time, const char *prompt) {
	printf(prompt);
	scanf_s("%d %d", &time->hh, &time->mm);
	if(time->hh >= 0 && time->hh <= 12 && time->mm >= 0 && time->mm < 60)
		return 1;
	else
		return 0;
}

void diff_time(Ttime time1, Ttime time2, Ttime *result) {
	int mins1 = time1.hh*60 + time1.mm;
	int mins2 = time2.hh*60 + time2.mm;
	
	mins1 -= mins2;
	
	if(mins1 < 0)
		mins1 = -mins1;

	result->hh = mins1/60;
	result->mm = mins1%60;
}

void print_time(Ttime time) {
	printf("Time is: %02d:%02d\n", time.hh, time.mm);
}