#include "header.h"

void runTaskTwo(void) {
	int testNumber = 15476;
	int sum = computeDigitSumRecursively(testNumber);
	printf("Sum of %d digits: %d.\n\n\n", testNumber, sum);
}

int computeDigitSumRecursively(int input) {
	int sum = 0;
	if (input / 10 != 0) {
		sum = computeDigitSumRecursively(input / 10);
	}
	return sum + (input % 10);
}