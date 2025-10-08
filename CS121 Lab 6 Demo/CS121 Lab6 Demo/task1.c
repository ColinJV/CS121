#include "header.h"

void runTaskOne(void) {
	FILE* ifstream = fopen("primenumbers.txt", "r");
	int sum = getSumFromFile(ifstream);
	fclose(ifstream);

	int primeFlag = isPrime(sum);
	displayPrimeResult(primeFlag, sum);

	int digitSum = getSumOfDigits(sum);
	primeFlag = isPrime(digitSum);
	displayPrimeDigitResult(primeFlag, digitSum);
}

int getSumFromFile(FILE* ifstream) {
	int sum = 0, temp = 0;
	while (fscanf(ifstream, "%d", &temp) != EOF) {
		sum += temp;
	}
	return(sum);
}

int isPrime(int sum) {
	int divisor = 2, primeFlag = 1;
	if (sum <= 1) {
		primeFlag = 0;
	}
	else {
		while (divisor <= sqrt(sum) && primeFlag == 1) {
			// "?" on line 36 is called the ternary operator
			// "?" has three operands, hence its name
			// Operand 1) the conditional expression on the left side of the ?, evaluated as true or false
			// Operand 2) the expression on the left side of the :, executes if the condition is true
			// Operand 3) the expression on the right side of the :, executes if the condition is false
			sum % divisor == 0 ? primeFlag = 0 : divisor++;

			// alternately, the below logic is equivalent to line 36
			//if (sum % divisor == 0) {
			//	primeFlag = 0;
			//}
			//else {
			//	divisor++;
			//}
		}
	}
	return(primeFlag);
}

void displayPrimeResult(int isPrime, int sum) {
	switch (isPrime) {
	case 0:
		printf("The sum of the numbers, %d, is not prime.\n", sum);
		break;
	case 1:
		printf("The sum of the numbers, %d, is prime.\n", sum);
		break;
	default:
		break;
	}
}

int getSumOfDigits(int num) {
	int sumOfDigits = 0;
	while (num > 0) {
		sumOfDigits += num % 10;
		num = num / 10;
	}
	return(sumOfDigits);
}

void displayPrimeDigitResult(int isPrime, int sumOfDigits) {
	switch (isPrime) {
	case 0:
		printf("The sum of the digits, %d, is not prime.\n", sumOfDigits);
		break;
	case 1:
		printf("The sum of the digits, %d, is prime.\n", sumOfDigits);
		break;
	default:
		break;
	}
}