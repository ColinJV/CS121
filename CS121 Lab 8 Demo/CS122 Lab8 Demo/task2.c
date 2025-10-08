#include "header.h"

void runTaskTwo(void) {
	int size = 30;
	char sentence[30] = { 'C', 'p', 't', 's', '1', '2', '1', ' ', 'i', 's',' ', 'f', 'u', 'n' };
	displayCharacterArray(sentence, size);
	removeWhitespace(sentence, size);
	displayCharacterArray(sentence, size);
}

void displayCharacterArray(char* characterArray, int size) {
	int index = 0;
	// it's quite important that the conditions for this while() loop appear in the order that they do
	// can you figure out why?
	while (index < size && characterArray[index] != 0) { 
		printf("%c", characterArray[index++]);
	}
	printf("\n");
}

void removeWhitespace(char* characterArray, int size) {
	int index = 0;
	// it's quite important that the conditions for this while() loop appear in the order that they do
	// can you figure out why?
	while (index < size && characterArray[index] != 0) {
		if (characterArray[index] == ' ') {
			int iterator = index;
			while (characterArray[iterator] != 0) {
				char temp = characterArray[iterator];
				characterArray[iterator] = characterArray[iterator + 1];
				++iterator;
			}
		}
		++index;
	}
}