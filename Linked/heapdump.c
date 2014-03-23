/*
 * Function heapdump() reports the state of the heap to the console. Call it
 * when you want to know the state of the heap.
 * Notice that the address given by malloc() is 32 (0x20) bytes later than
 * the original begining of the block. There are also 4 bytes after the
 * memory block (maybe for checking buffer overflows)
 *
 * If you want to know whether there are memory leaks on your code, call
 * function heapleak() at the end of your application to check leaks
 * (it report to the Visual Studio Output window). You need to include
 * heapdump.h file before your malloc.h include statement to enable leak
 * detector's source code report.
 */

#include <stdio.h>
#include <malloc.h>
#include "heapdump.h"


void heapdump(void) {
    _HEAPINFO hinfo;
    int heapstatus;
    int numLoops;

    hinfo._pentry = NULL;
    numLoops = 0;
    while((heapstatus = _heapwalk(&hinfo)) == _HEAPOK && numLoops < 200) {
        printf("%6s block at %Fp of size %4.4X\n",
                (hinfo._useflag == _USEDENTRY ? "USED" : "FREE"),
                hinfo._pentry, hinfo._size);
        numLoops++;
    }
  
    switch(heapstatus) {
    case _HEAPEMPTY:
        printf("OK - empty heap\n");
        break;
    case _HEAPEND:
        printf("OK - end of heap\n");
        break;
    case _HEAPBADPTR:
        printf("ERROR - bad pointer to heap\n");
        break;
    case _HEAPBADBEGIN:
        printf("ERROR - bad start of heap\n");
        break;
    case _HEAPBADNODE:
        printf("ERROR - bad node in heap\n");
        break;
    }
}

void heapleak(void) {
	_CrtDumpMemoryLeaks();
}
