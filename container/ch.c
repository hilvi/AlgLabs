#include "ch.h"
#include <stdio.h>

int read_char(char *item, const char *prompt) {
	printf(prompt);
    fflush(stdin);	// flush (emtpy) the input keyboard buffer
    *item = getchar();

    return 1;
}

void print_char(char item) {
    printf("%c\n", item);
}

int compare_char(char item1 , char item2) {
    if ((int)item1 < (int)item2)
		return -1;
    else if ((int)item1 == (int)item2)
		return 0;
    else
		return 1;
}