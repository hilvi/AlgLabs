#pragma once

#define DO_LIST_HEADER(NAME, Titem, MAX) \
typedef struct  { \
	   int count; \
	   Titem array[MAX]; \
} TOrderedList_##NAME; \
void initialize_list_##NAME(TOrderedList_##NAME *list); \
int insert_item_##NAME(TOrderedList_##NAME *list, Titem item); \
int retrieve_ith_##NAME(const TOrderedList_##NAME *list, int i, Titem *item); \
int number_of_items_##NAME(const TOrderedList_##NAME *list); \
int list_empty_##NAME(const TOrderedList_##NAME *list); \
int read_##NAME(Titem *item, const Titem *prompt); \
void print_##NAME(Titem item); \
int compare_##NAME(Titem item1, Titem item2);



#define DO_LIST_IMP(NAME, Titem, MAX)  \
void initialize_list_##NAME(TOrderedList_##NAME *list) { \
     list->count = 0; \
} \
int insert_item_##NAME(TOrderedList_##NAME *list, Titem item) { \
    int find_position_##NAME(Titem *array, Titem item, int number_of_items); \
    int make_room_##NAME(Titem *array, int where, int size_of_array); \
    int i; \
    if (list->count < MAX ) { \
		i = find_position_##NAME(list->array, item,  list->count); \
		make_room_##NAME(list->array,i, list->count); \
		list->array[i] = item; \
		list->count++; \
		return 1; \
    } else \
		return 0; \
} \
int retrieve_ith_##NAME(const TOrderedList_##NAME *list, int i, Titem *item) { \
    if (!list_empty_##NAME(list) && i <list->count) { \
		*item = list->array[i]; \
		return 1; \
    } else \
		return 0; \
} \
int number_of_items_##NAME(const TOrderedList_##NAME *list){ \
    return list->count; \
} \
int list_empty_##NAME(const TOrderedList_##NAME *list) { \
    return !list->count; \
} \
int find_position_##NAME(Titem *array, Titem item, int number_of_items) { \
    int i=0; \
	while (compare_##NAME(array[i], item) == -1 && i < number_of_items) i++; \
    return i; \
} \
int make_room_##NAME(Titem *array, int where, int number_of_items) { \
    int i; \
	if (number_of_items < MAX) { \
	for (i = number_of_items - 1 ; i >= where ; i-- ) \
	    array[i+1] = array[i]; \
	    return 1; \
	} else \
	    return 0; \
}