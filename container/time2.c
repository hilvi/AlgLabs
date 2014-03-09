#include <stdio.h>
#include "time2/time2.h"

int read_time(Ttime *time, const char *prompt) {
	int hh, mm;
	
	printf(prompt);
	scanf_s("%d %d", &hh, &mm);
	if(hh >= 0 && hh <= 12 && mm >= 0 && mm < 60) {
		*time = hh*60 + mm;
		return 1;
	}
	else
		return 0;
}

void diff_time(Ttime time1, Ttime time2, Ttime *result) {
	*result = time1 - time2;

	if(*result < 0)
		*result = -*result;
}

void print_time(Ttime time) {
	int hh = time/60;
	int mm = time%60;
	printf("%02d:%02d\n", hh, mm);
}

int compare_time(Ttime time1, Ttime time2) {
	if(time1 < time2)
		return -1;
	else if(time2 < time1)
		return 1;
	else
		return 0;
}