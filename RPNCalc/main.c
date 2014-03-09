#include "intstack.h"
#include <stdio.h>


int main() {
	char input;
	int item1, item2;
	Tintstack stack;
	initialize_int_stack(&stack);

	do {
		fflush(stdin);
		input = getchar();
		if(input >= '0' && input <= '9') {
				input = input - '0';
				push_int(&stack, input);
				continue;
		}

		if(!pop_int(&stack, &item1)) {
			printf("Stack empty!\n");
			continue;
		}

		if(input == '=') {
			printf("top value is %d\n", item1);
			push_int(&stack, item1);
			continue;
		}

		if(!pop_int(&stack, &item2)) {
			printf("Not enough items in stack!\n");
			push_int(&stack, item1);
			continue;
		}

		switch(input) {
		case '+':
			item2 += item1;
			push_int(&stack, item2);
			break;
		case '-':
			item2 -= item1;
			push_int(&stack, item2);
			break;
		default:
			push_int(&stack, item2);
			push_int(&stack, item1);
		} 
	} while(input != 'Q' && input != 'q');

	printf("Stack contained:\n");
	while(!is_empty_int_stack(&stack)) {
		pop_int(&stack, &item1);
		printf("%d\n", item1);
	}

	fflush(stdin);
	getchar();
}

