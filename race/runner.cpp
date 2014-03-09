#include "stdafx.h"
#include "time2.h"
#include "runner.h"

void readName(Trunner *runner, const char *prompt) {
	printf(prompt);
	scanf("%s", runner->name);
}

void readTime(Trunner *runner, const char *prompt) {
	read_time(&runner->time, prompt);
}

void displayRunner(const Trunner *runner) {
	printf("%s\t", runner->name);
	print_time(runner->time);
}

int betterRunner(const Trunner *runner1, const Trunner *runner2) {
	return compare_times(runner1->time, runner2->time);
}

void printTimeDifference(const Trunner *runner1, const Trunner *runner2) {
	printf("+");
	Ttime result;
	diff_time(runner1->time, runner2->time, &result);
	print_time(result);
}