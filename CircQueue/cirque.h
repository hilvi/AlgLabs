#pragma once

typedef int Titem;

/* The interface of queue */
#define INCREMENT 3
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
    Titem *array;
    int number_of_items;
	int size;
	int first;
	int last;
} *Tqueue;
Tqueue CreateQueue ();
void DestroyQueue(Tqueue p);
Tboolean enqueue(Tqueue p, Titem item);
Tboolean dequeue(Tqueue p, Titem *Pitem);
void print_queue(const Tqueue Pqueue);