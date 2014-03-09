#ifndef _TIME
#define _TIME

typedef struct {
	int hh;
	int mm;
} Ttime;

int read_time(Ttime *, const char *);
void diff_time(Ttime, Ttime, Ttime *);
void print_time(Ttime);

#endif