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
#include <stdlib.h> 
#include <time.h> 
#include "cirque.h" 

#define N 100000

int main() { 
	Tqueue queue; 
	Titem item; 
	clock_t tic, tac; 
	double duration; 
	int i; 

	initialize_queue(&queue); 

	// first we play a little with the queue to test that it really works 
	printf("Fill the queue with %d items\n", N); 
	item = 0;
	
	for (i = 0; i < N; i++) { 
		if (enqueue(&queue, item++) != OK) { 
			fprintf(stderr, "Enqueue failed\n"); 
			exit(1); 
		} 
	}

	printf("Remove half of them\n"); 
	for (i = 0; i < N/2; i++) { 
		if (dequeue(&queue, &item) != OK) {
			fprintf(stderr, "Dequeue failed\n"); 
			exit(1); 
		} 
	} 
	printf("Add then new %d items to the queue\n", N/2); 

	item++; 
	for (i = 0; i < N/2; i++) { 
		if (enqueue(&queue, item++) != OK) { 
			fprintf(stderr, "Enqueue failed\n"); 
			exit(1); 
		} 
	} 

	// then we deque elements and measure the execution time 
	printf("Then dequeue them\n"); 
	tic = clock(); 
	for (i = 0; i < N; i++) {
		dequeue(&queue, &item); 
	}
	tac = clock(); 
	printf("Last item value %d (should be %d)\n", item, N-1); 

	duration = (double)(tac - tic) / CLOCKS_PER_SEC; 
	printf("\ndequeue took %lf us to run\n", duration/N*1e6);
	fflush(stdin);
	getchar();
}