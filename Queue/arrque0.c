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
typedef char Titem;

/* The interface of queue */
#define INCREMENT 3
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
    Titem *array;
    int   number_of_items;
	int   size;
} Tqueue;
void initialize_queue (Tqueue *Pqueue);
Tboolean enqueue(Tqueue *p, Titem item);
Tboolean dequeue(Tqueue *p, Titem *Pitem);
void print_queue(const Tqueue *Pqueue);


/* Application */
int main() {
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
}

/* The implementations of operation functions of the queue */
void initialize_queue ( Tqueue *Pqueue)  {
    Pqueue->number_of_items = 0;
	Pqueue->array = (Titem *)malloc(sizeof(Titem) * INCREMENT);
	Pqueue->size = INCREMENT;
}

Tboolean enqueue( Tqueue *Pqueue, Titem item) {
	if (Pqueue->number_of_items >= Pqueue->size) {
		int newSize = Pqueue->size + INCREMENT;
		Titem *newArray = (Titem *)malloc(sizeof(Titem)*newSize);

		if(newArray == NULL)
			return NOT_OK;

		memcpy(newArray, Pqueue->array, Pqueue->size);
		free(Pqueue->array);

		Pqueue->array = newArray;
		Pqueue->size = newSize;
		printf("Size incremented to %d\n", newSize);
	}
    else {
		Pqueue->array[Pqueue->number_of_items++] = item;
		return (OK);
    }
}

Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
    int i;

    if (Pqueue->number_of_items == 0)
		return(NOT_OK);
    else {
        *Pitem = Pqueue->array[0];
        for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
            Pqueue->array[i] = Pqueue->array[i+1];
        Pqueue->number_of_items--;

		return (OK);
    }
}

void print_queue (const Tqueue *Pqueue) {
    int i;

    printf("\nQueue now: \n\n");
    for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
		printf(" %c ", Pqueue->array[i]);
    }
    printf("\n\n");
}
