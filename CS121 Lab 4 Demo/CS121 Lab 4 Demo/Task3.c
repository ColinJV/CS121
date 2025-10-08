#include "Header.h"

void displayTaskThreeMenu(void) {
	printf("Select the computation to perform on the numbers read from file.\n");
	printf("1. Average value.\n");
	printf("2. High value.\n");
	printf("3. Low value.\n");
}

int getIntegerInput(void) {
	int input = 0;
	scanf("%d", &input);
	return(input);
}

double averageValues(double num1, double num2, double num3, double num4, double num5) {
	double average = 0;
	average = (num1 + num2 + num3 + num4 + num5) / 5;
	return(average);
}

double findHighestValue(double num1, double num2, double num3, double num4, double num5) {
	double highest = -200000;
	if (num1 > highest) {
		highest = num1;
	}
	if (num2 > highest) {
		highest = num2;
	}
	if (num3 > highest) {
		highest = num3;
	}
	if (num4 > highest) {
		highest = num4;
	}
	if (num5 > highest) {
		highest = num5;
	}
	return(highest);
}

double findLowestValue(double num1, double num2, double num3, double num4, double num5) {
	double lowest = 10000000;
	if (num1 < lowest) {
		lowest = num1;
	}
	if (num2 < lowest) {
		lowest = num2;
	}
	if (num3 < lowest) {
		lowest = num3;
	}
	if (num4 < lowest) {
		lowest = num4;
	}
	if (num5 < lowest) {
		lowest = num5;
	}
}

void runTaskThree(void) {
	FILE* ifstream = NULL;
	double num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
	int userInput = 0;

	ifstream = fopen("fiveNumbers.txt", "r");
	num1 = readNumberFromFile(ifstream);
	num2 = readNumberFromFile(ifstream);
	num3 = readNumberFromFile(ifstream);
	num4 = readNumberFromFile(ifstream);
	num5 = readNumberFromFile(ifstream);
	fclose(ifstream);

	displayTaskThreeMenu();
	userInput = getIntegerInput();
	runUserInput(num1, num2, num3, num4, num5, userInput);
}

double readNumberFromFile(FILE* ifstream) {
	double number = 0;
	fscanf(ifstream, "%lf", &number);
	return(number);
}

void runUserInput(double num1, double num2, double num3, double num4, double num5, int userInput) {
	double result = 0;
	switch (userInput) {
	case 1:
		result = averageValues(num1, num2, num3, num4, num5);
		printf("The average value is %lf.\n", result);
		break;
	case 2:
		result = findHighestValue(num1, num2, num3, num4, num5);
		printf("The highest value is %lf.\n", result);
		break;
	case 3:
		result = findLowestValue(num1, num2, num3, num4, num5);
		printf("The lowest value is %lf.\n", result);
		break;
	default:
		break;
	}
}