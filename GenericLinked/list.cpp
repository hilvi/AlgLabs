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
// Implementation of list (only obj is need in appl)
void initialize_list (Tlist *list) {
	*list = NULL;
}

void cleanup_list(Tlist *list) {
	Tpointer aux1, aux2;

	aux1 = *list;
	while (aux1 != NULL) {
		aux2 = aux1->next;
		aux1->item.type->del(aux1->item.data);
		free(aux1);
		printf("\nDeleted"); //for testing purposes
		aux1 = aux2;
	}
	initialize_list(list);
}

void insert_to_list_end(Tlist *list, Titem data) {
	Tpointer newnode;

	newnode = (Tpointer) malloc(sizeof(Tnode));
	newnode -> item = data;
	newnode -> next = NULL;
	if (*list == NULL) {
		*list = newnode;       //first node
	} else {
		Tpointer node = *list;
		while(node->next != NULL) {
			node = node->next;
		}
		node->next = newnode;
	}
}

void print_list (Tlist list) {
	Tpointer what;

	printf("\nList 4 :");
	what = list;
	while (what != NULL) {
		what->item.type->print(what->item.data);
		what = what->next;
	}
}

void delete_first(Tlist *list) {
	Tlist org = *list;
	*list = (*list)->next;
	free(org);
}
void delete_last(Tlist *list) {
	Tlist node = *list;
	if(node == NULL) {
		return;
	} else if(node->next == NULL) {
		(*list)->item.type->del((*list)->item.data);
		free(*list);
		*list = NULL;
	} else {
		while(node->next->next != NULL) {
			node = node->next;
		}
		node->next->item.type->del(node->next->item.data);
		free(node->next);
		node->next = NULL;
	}
}
int find_pos_in_list(const Tlist *list, Titem item, int *pos) {
	int i = 1;
	Tpointer node = *list;
	while(node != NULL) {
		if(node->item.type == item.type) {
			if(node->item.type->cmp(node->item.data, item.data) == 0) {
				*pos = i;
				return i;
			}
		}
		++i;
		node = node->next;
	}
	*pos = 0;
	return 0;
}