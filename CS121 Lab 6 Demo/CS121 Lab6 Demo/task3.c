#include "header.h"

void runTaskThree(void) {
	int fibonacciTerm = getNonNegativeIntegerInput();
	int fibonacciNumber = calculateFibonacciNumber(fibonacciTerm);
	displayFibonacciNumber(fibonacciNumber, fibonacciTerm);
}

int calculateFibonacciNumber(int term) {
	int i = 2, num1 = 0, num2 = 1, nthTerm = 0;

	if (term == 1) {
		nthTerm = 0;
	}
	else if (term == 2) {
		nthTerm = 1;
	}
	else {
		while (i < term) {
			nthTerm = num1 + num2;
			num1 = num2;
			num2 = nthTerm;
			++i;
		}
	}
	return(nthTerm);
}

void displayFibonacciNumber(int nthTerm, int term) {
	printf("The number at position %d in the Fibonacci sequence is %d.\n", term, nthTerm);
}