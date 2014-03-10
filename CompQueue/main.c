/* 
* Performance measurement application for the queue. 
* 
* Not a very accurate measurement system if the dequeue() function is relative short (compared to the 
* time consumed in for-loop) 
* 
* In order to run this program in Visual Studio 2012 select 
* Debug-Start-without-Debugging (or pressing Ctrl-F5) 
*/ 

#include <stdio.h> 
#include <time.h> 
#include <math.h> 
#include "arrque.h" 

/*
DEBUG N=400000
Array-memcpy	799.21255us
circular		0.07 us -> 11417 kertaa nopeampi

OPTIMOITU N=400000
Array-memcpy	220.4us
circular		0.005us -> 44801 kertaa nopeampi
*/

#define N 100000 // number of test iterations, must be even 


/* test the operation of the dequeue/enqueue operations, 
* and measures the execution time of a single dequeue operation 
*/ 
double measureQueue(Tqueue queue, int n) { 
	clock_t tic, tac; 
	int i, item; 

	printf("Fill the queue with %d items\n", n); 
	item = 0; 
	for (i = 0; i < n; i++) 
		enqueue(queue, item++); 
	printf("Remove half of them\n"); 
	for (i = 0; i < n/2; i++) 
		dequeue(queue, &item); 
	printf("Add then new %d items to the queue\n", n/2); 
	item++; 
	for (i = 0; i < n/2; i++) 
		enqueue(queue, item++); 

	printf("Then dequeue all the items\n"); 
	tic = clock(); 
	for (i = 0; i < n; i++) 
		dequeue(queue, &item); 
	tac = clock(); 
	printf("Last item value %d (should be %d)\n", item, n-1); 

	if (dequeue(queue, &item)) 
		printf("There were some elements remaining on the queue\n"); 
	else 
		printf("The queue is now empty\n"); 

	return (double)(tac - tic) / CLOCKS_PER_SEC / (double)n; 
} 


/* test application */ 
int main() { 
	Tqueue queue; 
	double Ta, Tc; 

	queue = CreateQueue(NOT_OK); 
	printf("First the simple array implementation\n"); 
	printf("dequeue() took %lf us to run\n", Ta = measureQueue(queue, N)*1e6);
	DestroyQueue(queue); 

	queue = CreateQueue(OK); 
	printf("\nThen the circular array implementation\n"); 
	printf("dequeue() took %lf us to run\n", Tc = measureQueue(queue, N)*1e6);
	DestroyQueue(queue); 

	if (Tc != 0.0) 
		printf("\nCircular implementation was %d times faster than array implementation\n", (int)floor(Ta/Tc + .5)); 
	else 
		printf("\nNo circular implmentation measurement available\n");

	fflush(stdin);
	getchar();
} 
