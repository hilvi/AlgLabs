#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "time2.h"

Titemtype *tChar;
Titemtype *tComplex;
Titemtype *tTime;
/* character */

void DestroyChar(void *p) {
	free(p);
}
void PrintChar(void *p) {
	printf("%c ", *(char *)p);
}
int cmpchar(void *p1, void *p2) {
	if (*(char *)p1 > *(char *)p2)
		return 1;
	else if (*(char *)p1 < *(char *)p2)
		return -1;
	else
		return 0;
}
void copychar(void *to, void *from) {
	*(char *)to = *(char *)from;
}
Titem CreateCharItem(char c) {
	void *p;
	p = malloc(sizeof(char));
	*(char *)p = c;
	return (CreateItem(p, tChar));
}
Titem ReadCharItem(void) {
	char to_be_searched;
	fflush(stdin); scanf("%c", &to_be_searched);
	return (CreateCharItem(to_be_searched));
}

typedef struct {
	int r;
	int i;
} tComplexNumber;

void DestroyComplex(void *p) {
	free(p);
}
void PrintComplex(void *p) {
	tComplexNumber *com = (tComplexNumber *)p;
	printf("%d+%di ", com->r, com->i);
}
int CmpComplex(void *p1, void *p2) {
	int lhs, rhs;
	lhs = ((tComplexNumber *)p1)->r;
	rhs = ((tComplexNumber *)p2)->r;
	
	if (lhs > rhs)
		return 1;
	else if (lhs < rhs)
		return -1;
	else {
		lhs = ((tComplexNumber *)p1)->i;
		rhs = ((tComplexNumber *)p2)->i;

		if (lhs > rhs)
			return 1;
		else if (lhs < rhs)
			return -1;
		else
			return 0;
	}
}
void CopyComplex(void *to, void *from) {
	*(tComplexNumber *)to = *(tComplexNumber *)from;
}
Titem CreateComplexItem(tComplexNumber c) {
	void *p;
	p = malloc(sizeof(tComplexNumber));
	*(tComplexNumber *)p = c;
	return (CreateItem(p, tComplex));
}
Titem CreateComplexItem(int r, int i) {
	tComplexNumber *complex = (tComplexNumber *)malloc(sizeof(tComplexNumber));
	complex->r = r;
	complex->i = i;
	return (CreateItem(complex, tComplex));
}
Titem ReadComplexItem(void) {
	tComplexNumber to_be_searched;
	fflush(stdin); scanf("%d %d", &to_be_searched.r, &to_be_searched.i);
	return (CreateComplexItem(to_be_searched));
}

void DestroyTime(void *p) {
	free(p);
}
void PrintTime(void *p) {
	print_time(*(Ttime *)p);
	printf(" ");
}
int CmpTime(void *p1, void *p2) {
	return compare_times(*(Ttime *)p1, *(Ttime *)p2);
}
void CopyTime(void *to, void *from) {
	*(Ttime *)to = *(Ttime *)from;
}
Titem CreateTimeItem(int hh, int mm) {
	Ttime *item = (Ttime *)malloc(sizeof(Ttime));
	*item = hh*60+mm;
	return (CreateItem(item, tTime));
}
Titem CreateTimeItem(Ttime *time) {
	return (CreateItem(time, tTime));
}
Titem ReadTimeItem(void) {
	Ttime *to_be_searched = (Ttime *)malloc(sizeof(Ttime));
	fflush(stdin); read_time(to_be_searched, "");
	print_time(*to_be_searched);
	return (CreateTimeItem(to_be_searched));
}

int main () {
	Tlist list;
	Titem to_be_searched;
	int order_no;
	initialize_list(&list);
	tChar = CreateType(PrintChar, cmpchar, copychar, DestroyChar);
	tComplex = CreateType(PrintComplex, CmpComplex, CopyComplex, DestroyComplex);
	tTime = CreateType(PrintTime, CmpTime, CopyTime, DestroyTime);
	insert_to_list_end(&list, CreateCharItem('x'));
	insert_to_list_end(&list, CreateCharItem('a'));
	insert_to_list_end(&list, CreateCharItem('b'));
	insert_to_list_end(&list, CreateCharItem('c'));
	insert_to_list_end(&list, CreateComplexItem(1, 2));
	insert_to_list_end(&list, CreateCharItem('d'));
	insert_to_list_end(&list, CreateTimeItem(23, 30));
	insert_to_list_end(&list, CreateCharItem('y'));
	print_list(list);
	printf("Enter first character to be searced\n");
	to_be_searched = ReadCharItem();
	if (find_pos_in_list(&list,to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	printf("Enter first complex number to be searced\n");
	to_be_searched = ReadComplexItem();
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	printf("Enter first time to be searced\n");
	to_be_searched = ReadTimeItem();
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	delete_first(&list);
	print_list(list);
	delete_last(&list);
	print_list(list);
	cleanup_list(&list);
	DestroyType(tChar); DestroyType(tComplex); DestroyType(tTime);
	fflush(stdin); getchar();
}