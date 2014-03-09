#ifndef _TIME2
#define _TIME2

typedef int Ttime;

int read_time(Ttime *, const char *);
void diff_time(Ttime, Ttime, Ttime *);
void print_time(Ttime);
int compare_times(Ttime, Ttime);
#endif