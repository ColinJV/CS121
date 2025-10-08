#include "header.h"

void runTaskOne(void) {
	char reverseThisString[100] = "Recursion is cool.";
	printReverseStringRecursively(reverseThisString);
	printf("\n");

	puts(reverseThisString);
	actuallyReverseTheString(reverseThisString, 0, strlen(reverseThisString) - 1);
	puts(reverseThisString);
}

void printReverseStringRecursively(char* targetString) {
	if (*targetString != 0) {
		printReverseStringRecursively(targetString + 1);
		printf("%c", *targetString);
	}
}

void actuallyReverseTheString(char* targetString, int first, int last) {
	if (first >= last) {
		return;
	}
	else {
		char temp = targetString[first];
		targetString[first] = targetString[last];
		targetString[last] = temp;
		actuallyReverseTheString(targetString, first + 1, last - 1);
	}
}