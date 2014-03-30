#pragma once

typedef int Ttime;

int read_time(Ttime *, const char *);
void diff_time(Ttime, Ttime, Ttime *);
void print_time(Ttime);
int compare_times(Ttime, Ttime);
