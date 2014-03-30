/* dynlist4a.c -- Dynamic linked linear list
*
* The abstraction is ok, because first and last are are
* incapsulated inside datatype Tlist and all paramaters of
* operation functions are of this type.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Interface of list
typedef struct node *Tpointer;
typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;

/*typedef struct {
Tpointer first;
Tpointer last;
} Tlist;*/

typedef Tpointer Tlist;
void initialize_list (Tlist *list);
void insert_to_list_end(Tlist *list, Titem data);
void print_list (Tlist list);
void cleanup_list(Tlist *list);

void delete_first(Tlist *list);
void delete_last(Tlist *list);
int find_pos_in_list(const Tlist *list, Titem item, int *pos);