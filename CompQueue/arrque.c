/* arrque0.c -- An array implementation of Queue
*
* This is simple solution where array elements are moved
* forward in the array in dequeue operation
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "arrque.h"

Tboolean enqueue_cir( Tqueue Pqueue, Titem item);
Tboolean enqueue_arr( Tqueue Pqueue, Titem item);
Tboolean incrementSize_cir(Tqueue Pqueue);
Tboolean incrementSize_arr(Tqueue Pqueue);
Tboolean dequeue_cir( Tqueue Pqueue, Titem *Pitem);
Tboolean dequeue_arr( Tqueue Pqueue, Titem *Pitem);

/* The implementations of operation functions of the queue */
Tqueue CreateQueue(Tboolean circular)  {
	Tqueue Pqueue = (Tqueue)malloc(sizeof(*Pqueue));
	Pqueue->array = (Titem *)malloc(sizeof(Titem) * INCREMENT);
	Pqueue->size = INCREMENT;
	Pqueue->first = 0;
	Pqueue->last = -1;
	Pqueue->number_of_items = 0;
	Pqueue->circular = circular;

	if(circular) {
		Pqueue->enq = enqueue_cir;
		Pqueue->deq = dequeue_cir;
		Pqueue->inc = incrementSize_cir;
	} else {
		Pqueue->enq = enqueue_arr;
		Pqueue->deq = dequeue_arr;
		Pqueue->inc = incrementSize_arr;
	}

	return Pqueue;
}

void DestroyQueue(Tqueue p) {
	free(p->array);
	free(p);
}

Tboolean enqueue( Tqueue Pqueue, Titem item) {
	return Pqueue->enq(Pqueue, item);
}

Tboolean enqueue_cir( Tqueue Pqueue, Titem item) {
	if (Pqueue->number_of_items >= Pqueue->size) {
		if(!Pqueue->inc(Pqueue))
			return NOT_OK;
	}

	if(++Pqueue->last >= Pqueue->size)
		Pqueue->last = 0;

	Pqueue->array[Pqueue->last] = item;
	Pqueue->number_of_items++;
	return (OK);
}

Tboolean enqueue_arr( Tqueue Pqueue, Titem item) {
	if (Pqueue->number_of_items >= Pqueue->size) {
		if(!Pqueue->inc(Pqueue))
			return NOT_OK;
	}

	Pqueue->array[Pqueue->number_of_items++] = item;
	return (OK);
}

Tboolean incrementSize(Tqueue Pqueue) {
	return Pqueue->inc(Pqueue);
}

Tboolean incrementSize_cir(Tqueue Pqueue) {
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

Tboolean incrementSize_arr(Tqueue Pqueue) {
	int newSize = Pqueue->size + INCREMENT;
	Titem *newArray = (Titem *)malloc(sizeof(Titem)*newSize);

	if(newArray == NULL)
		return NOT_OK;

	memcpy(newArray, Pqueue->array, sizeof(Titem)*Pqueue->size);
	free(Pqueue->array);

	Pqueue->array = newArray;
	Pqueue->size = newSize;
	//printf("Size incremented to %d\n", newSize);

	return OK;
}

Tboolean dequeue( Tqueue Pqueue, Titem *item) {
	return Pqueue->deq(Pqueue, item);
}

Tboolean dequeue_cir( Tqueue Pqueue, Titem *Pitem) {
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

Tboolean dequeue_arr( Tqueue Pqueue, Titem *Pitem) {
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

void print_queue (const Tqueue Pqueue) {
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
