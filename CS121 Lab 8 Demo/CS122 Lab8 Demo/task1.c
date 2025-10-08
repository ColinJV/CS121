#include "header.h"

void runTaskOne(void) {
	int fileReadValues[100] = { 0 }, arraySize = 0;
	arraySize = populateArrayFromFile(fileReadValues);
	displayArray(fileReadValues, arraySize);
	reverseArray(fileReadValues, arraySize);
	displayArray(fileReadValues, arraySize);
}

int populateArrayFromFile(int* fileReadValues) {
	FILE* ifstream = fopen("integerValues.txt", "r");
	int scannedValue = 0, arraySize = 0;

	// note: lines 17 and 18 do the exact same thing. Why?
	while (fscanf(ifstream, "%d", &scannedValue) == 1) {
		fileReadValues[arraySize] = scannedValue;
		*(fileReadValues + arraySize) = scannedValue;
		++arraySize;
		scannedValue = 0;
	}

	fclose(ifstream);
	return(arraySize);
}

void reverseArray(int* targetArray, int arraySize) {
	int index = 0;
	printf("Reversing array...\n");
	while (index < arraySize) {
		int temp = 0;
		temp = targetArray[index];
		targetArray[index++] = targetArray[--arraySize];
		targetArray[arraySize] = temp;
	}
}

void displayArray(int* targetArray, int arraySize) {
	int index = 0;

	while (index < arraySize) {
		printf("Position %d: %d\n", index, targetArray[index]);
		++index;
	}
}