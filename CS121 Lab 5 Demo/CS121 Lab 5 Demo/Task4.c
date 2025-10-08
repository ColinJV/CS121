#include "Header.h"

void runTaskFour(void) {
	FILE* ifstream = openHighLowDataFile();
	int high = getHighFromFile(ifstream);
	closeFile(ifstream);

	ifstream = openHighLowDataFile();
	int low = getLowFromFile(ifstream);
	closeFile(ifstream);

	displayHighLow(high, low);
}

FILE* openHighLowDataFile(void) {
	FILE* ifstream = fopen("highlowdata.txt", "r");
	return(ifstream);
}

int getHighFromFile(FILE* ifstream) {
	int number = 0, high = INT_MIN;

	while (fscanf(ifstream, "%d", &number) != EOF) {
		if (number > high) {
			high = number;
		}
	}

	return(high);
}

int getLowFromFile(FILE* ifstream) {
	int number = 0, low = INT_MAX;

	while (fscanf(ifstream, "%d", &number) != EOF) {
		if (number < low) {
			low = number;
		}
	}

	return(low);
}

void displayHighLow(int high, int low) {
	printf("The high value is %d.\n", high);
	printf("The low value is %d.\n", low);
}