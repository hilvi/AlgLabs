#include "main.h"
#include "intstack.h"
#include <stdio.h>


int main() {
	char input;
	int item1, item2;
	Tintstack stack;
	initialize_int_stack(&stack);

	do {
		input = getchar();
		if(input >= '0' || input <= '9') {
				input = input - '0';
				push_int(&stack, input);
		}

		if(!is_empty_int_stack(&stack)) {
			pop_int(&stack, &item1);
		} else {
			printf("Stack empty!\n");
			continue;
		}

		if(input == '=') {
			printf("%d", item1);
			push_int(&stack, item1);
			continue;
		}

		if(!is_empty_int_stack(&stack)) {
			pop_int(&stack, &item2);
		} else {
			printf("Not enough items in stack!\n");
			push_int(&stack, item1);
			continue;
		}

		switch(input) {
		case '+':
			item1 += item2;
			push_int(&stack, item1);
			break;
		case '-':
			item1 -= item2;
			push_int(&stack, item1);
			break;
		} 
	} while(input != 'Q' || input != 'q');

	print_int_stack(&stack);
}

