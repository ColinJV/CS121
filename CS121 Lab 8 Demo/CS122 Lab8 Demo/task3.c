#include "header.h"

void runTaskThree(void) {
	int randomNumber[20] = { 0 }, frequencyTable[101] = { 0 };
	populateArray(randomNumber, 20);
	displayArray(randomNumber, 20);
	populateFrequencyTable(randomNumber, 20, frequencyTable);
	displayArray(frequencyTable, 101);
}

void populateArray(int* targetArray, int size) {
	int index = 0;
	while (index < size) {
		targetArray[index] = rand() % 100 + 1;
		++index;
	}
}

void populateFrequencyTable(int* baseArray, int baseArraySize, int* frequencyTable) {
	int index = 0;

	while (index < baseArraySize) {
		frequencyTable[baseArray[index++]]++;
	}
}