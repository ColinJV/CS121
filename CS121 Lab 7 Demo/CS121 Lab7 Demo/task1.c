#include "header.h"

void runTaskOne(void) {
	char firstChar = 0, secondChar = 0, thirdChar = 0;
	getInitials(&firstChar, &secondChar, &thirdChar);
	displayInitials(firstChar, secondChar, thirdChar);
}

void getInitials(char* firstInitial, char* secondInitial, char* thirdInitial) {
	puts("Enter the first initial.");
	scanf(" %c", firstInitial);
	puts("Enter the second initial.");
	scanf(" %c", secondInitial);
	puts("Enter the third initial.");
	scanf(" %c", thirdInitial);
}

void displayInitials(char firstInitial, char secondInitial, char thirdInitial) {
	printf("The initials are %c%c%c", firstInitial, secondInitial, thirdInitial);
}