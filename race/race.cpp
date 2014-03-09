// race.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "runner.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int size = 10;
	Trunner runners[size];
	char namePrompt[] = "Give name for runner: ";
	char timePrompt[] = "Give time (hh mm): ";
	
	int names;
	printf("How many runners (max 10): ");
	scanf_s("%d", &names);
	
	int i;
	for(i = 0; i < names; i++) {
		readName(&runners[i], namePrompt);
		readTime(&runners[i], timePrompt);
	}
	
	Trunner *fastest = runners;
	for(i = 1; i < names; i++) {
		if(betterRunner(fastest, &runners[i]) == 1)
			fastest = &runners[i];
	}
	
	printf("Winner: ");
	displayRunner(fastest);
	printf("\n\n");
	
	for(i = 0; i < names; i++) {
		printf("%d: ", i+1);
		displayRunner(&runners[i]);
		printf(" ");
		printTimeDifference(fastest, &runners[i]);
		printf("\n");
	}

	return 0;
}

