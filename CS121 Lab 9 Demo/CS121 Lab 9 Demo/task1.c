#include "header.h"

void runTaskOne(void) {
	char reverseThisString[50] = "Can't stop reversing till I get enough.";
	printString(reverseThisString);
	stringReverse(reverseThisString);
	//stringReversePointer(reverseThisString);
	printString(reverseThisString);
}

char* stringReverse(char* targetString) {
	int stringSize = 0, iterator = 0;
	while (targetString[stringSize] != 0) {
		++stringSize;
	}
	--stringSize;
	while (iterator < stringSize) {
		char temp = 0;
		temp = targetString[stringSize];
		targetString[stringSize--] = targetString[iterator];
		targetString[iterator++] = temp;
	}

	return(targetString);
}

char* stringReversePointer(char* targetString) {
	int stringSize = 0, iterator = 0;
	while (*(targetString + stringSize) != 0) {
		++stringSize;
	}
	--stringSize;
	while (iterator < stringSize) {
		char temp = 0;
		temp = *(targetString + stringSize);
		*(targetString + stringSize--) = *(targetString + iterator);
		*(targetString + iterator++) = temp;
	}
	return(targetString);
}

void printString(char* targetString) {
	int iterator = 0;
	while (targetString[iterator] != 0) {
		printf("%c", targetString[iterator]);
		++iterator;
	}
	printf("\n");
}