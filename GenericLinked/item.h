#pragma once

/*
* Interface of the general purpose, object like item ADT
*/
typedef struct {
	void (*print)(void *p); // printing function
	int (*cmp)(void *p1, void *p2); // compare function
	void (*copy)(void *to, void *from);// copy function
	void (*del)(void *p); // delete function
} Titemtype;
typedef struct {
	void *data; // pointer to the data itself
	Titemtype *type; // pointer to the type definition block
} Titem;
Titemtype *CreateType(void (*print)(void *p),
					  int (*cmp)(void *p1, void *p2),
					  void (*copy)(void *to, void *from),
					  void (*del)(void *p));
void DestroyType(Titemtype *p);
Titem CreateItem(void *data, Titemtype *type);
void DestroyItem(Titem item);
void PrintItem(Titem item);
int CmpItem(Titem item1, Titem item2);