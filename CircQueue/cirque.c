/* arrque0.c -- An array implementation of Queue
 *
 * This is simple solution where array elements are moved
 * forward in the array in dequeue operation
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <memory.h>
#include "cirque.h"

/* Application */
/*int main() {
    Tqueue queue;
    Tboolean succeed;
    char chr;

    initialize_queue(&queue);
    printf("\nEnter a letter to be queued ");
    printf("\nor digit 1 to dequeue a letter");
    printf("\nor Return to quit a program\n");

    chr = _getche();
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
			succeed=enqueue(&queue, chr);
			print_queue(&queue);
			if (!succeed)
				printf("\n Enqueue operation failed\n");
		}
		if (chr == '1') {
			succeed = dequeue(&queue, &chr);
			if  (succeed) {
				printf("\na letter dequeued %c ", chr);
				print_queue(&queue);
			} else
				printf("\nDequeue operation failed\n ");
		}

		chr = _getche();
     }
}*/

/* The implementations of operation functions of the queue */
void initialize_queue ( Tqueue *Pqueue)  {
	Pqueue->array = (Titem *)malloc(sizeof(Titem) * INCREMENT);
	Pqueue->size = INCREMENT;
	Pqueue->first = 0;
	Pqueue->last = -1;
	Pqueue->number_of_items = 0;
}

Tboolean enqueue( Tqueue *Pqueue, Titem item) {
	if (Pqueue->number_of_items >= Pqueue->size) {
		if(!incrementSize(Pqueue))
			return NOT_OK;
	}
    
	if(++Pqueue->last >= Pqueue->size)
		Pqueue->last = 0;

	Pqueue->array[Pqueue->last] = item;
	Pqueue->number_of_items++;
	return (OK);
}

Tboolean incrementSize(Tqueue *Pqueue) {
		int newSize = Pqueue->size + INCREMENT;
		Titem *newArray = (Titem *)malloc(sizeof(Titem)*newSize);

		if(newArray == NULL)
			return NOT_OK;

		memcpy(newArray, &Pqueue->array[Pqueue->first], sizeof(Titem) * (Pqueue->size - Pqueue->first));
		memcpy(&newArray[Pqueue->size - Pqueue->first], Pqueue->array, sizeof(Titem) * Pqueue->first);
		
		free(Pqueue->array);
		Pqueue->array = newArray;
		Pqueue->first = 0;
		Pqueue->last = Pqueue->number_of_items-1;
		Pqueue->size = newSize;
		//printf("Size incremented to %d\n", newSize);

		return OK;
}

Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
    if (Pqueue->number_of_items == 0)
		return(NOT_OK);
    else {
		Pqueue->number_of_items--;
        *Pitem = Pqueue->array[Pqueue->first];

		if(++Pqueue->first >= Pqueue->size)
			Pqueue->first = 0;

		return (OK);
    }
}

void print_queue (const Tqueue *Pqueue) {
    int i, index;

    printf("\nQueue now: \n\n");
    for (i = 0, index = Pqueue->first; i <  Pqueue->number_of_items ; i++, index++) {
		if(index >= Pqueue->size)
			index = 0;

		printf(" %d ", Pqueue->array[index]);
    }
	printf("\nFirst: %d Last: %d Items: %d Size: %d", Pqueue->first, Pqueue->last, Pqueue->number_of_items, Pqueue->size);
    printf("\n\n");
}
