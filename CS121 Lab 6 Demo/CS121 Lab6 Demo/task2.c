#include "header.h"

void runTaskTwo(void) {
	int number = getNonNegativeIntegerInput();
	int factorial = calculateFactorial(number);
	displayFactorialResult(factorial, number);
}

int getNonNegativeIntegerInput(void) {
	int input = -1;
	while (input < 0) {
		printf("Please enter a non-negative integer.\n");
		scanf("%d", &input);
		if (input < 0) {
			printf("The provided input was invalid, please try again.\n");
		}
	}
	return(input);
}

int calculateFactorial(int number) {
	int factorial = 1;
	switch (number) {
	case 0:
		break;
	case 1:
		break;
	default:
		while (number > 1) {
			factorial *= number--;
		}
		break;
	}
	return(factorial);
}

void displayFactorialResult(int factorial, int number) {
	printf("The result of %d! is %d.\n", number, factorial);
}