#include <stdio.h>
#include "char_list.h"
#include "time_list.h"

int main () {
     TOrderedList_char cList; char cItem;
	 TOrderedList_time tList; Ttime tItem;
     int i;

     initialize_list_char(&cList);
	 initialize_list_time(&tList);
     printf("\n Enter items in any order\n");

     for (i = 0 ; i < 3 ; i++) {
        read_char(&cItem, "Give character: ");
		read_time(&tItem, "Give time (hh mm): ");
        if (!insert_item_char(&cList, cItem))
            printf("\nChar list is full");
		if (!insert_item_time(&tList, tItem))
            printf("\nTime list is full");
     }

     printf("\nChar list ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items_char(&cList); i++) {
		retrieve_ith_char(&cList, i, &cItem);
		print_char(cItem);
     }

	 printf("\nTime list ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items_time(&tList); i++) {
		retrieve_ith_time(&tList, i, &tItem);
		print_time(tItem);
     }

	 fflush(stdin);
	 getchar();
     return 0;
}