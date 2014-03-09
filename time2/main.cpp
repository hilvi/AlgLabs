#include "stdafx.h"
#include "time2.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Ttime time1;
	Ttime time2;
	Ttime result;
	
	char prompt[] = "Give time (hh mm): ";
	
	while(!read_time(&time1, prompt))
		printf ("Invalid time");
	while(!read_time(&time2, prompt))
		printf ("Invalid time");
		
	diff_time(time1, time2, &result);
	print_time(result);
	
	return 0;
}

