#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

// Push
void
push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full, can't push %g sp = %d\n", f, sp);
}

// Pop
double
pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: Stack is empty\n");
		return 0.0;
	}
}

void
show(void) {
	if (sp > 0)
		printf("top element of the stack - %g\n", val[sp - 1]);
	else
		printf("I am sorry, the stack is empty\n");
}

int
duplicate(double val2[]) {
	int i = 0;
	while (i < sp) {
		val2[i] = val[i];
		i++; 
	}
	return i;
}

void
clear(void) {
	while (sp >= 0)
		val[--sp] = 0.0;
}

void
top_swap(void) {
	double temp;
	if (sp >= 2) {
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
}

void
display(void) {
	for (int i = 0; i < sp && sp > 0; i++)
		printf("%g\t", val[i]);
	printf("\n");
}


// For testing purposes and Ex 4.4
// int
// main() {
// 	int i;
// 	for (i = 0; i < 100; i += 5)
// 		push(i);
// 	printf("displaying\n");
// 	display();
// 	double val2[MAXVAL];
// 	int size = duplicate(val2);
// 	printf("displaying duplicate array\n");
// 	for(i = 0; i < size; i++)
// 		printf("%g\t", val2[i]);
// 	printf("\n");
// 	top_swap();
// 	printf("display after top swap\n");
// 	display();
// 	clear();
// 	printf("display after clear\n");
// 	display();
// 	return 0;
// }
