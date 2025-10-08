#include "Header.h"

void runTaskTwo(void) {
	FILE* ifstream = openDataFile();
	double average = computeAverageDataValue(ifstream);
	closeFile(ifstream);

	FILE* ofstream = openOutputFile();
	writeAverageToFile(ofstream, average);
	closeFile(ofstream);
}

FILE* openDataFile(void) {
	FILE* ifstream = fopen("data.txt", "r");
	return(ifstream);
}

double computeAverageDataValue(FILE* ifstream) {
	double sum = 0, temp = 0, average = -1;
	int count = 0;

	while (fscanf(ifstream, "%lf", &temp) != -1) {
		sum += temp;
		++count;
	}

	if (count != 0) {
		average = sum / count;
	}

	return(average);
}

FILE* openOutputFile(void) {
	FILE* ofstream = fopen("output.txt", "w");
	return(ofstream);
}

void writeAverageToFile(FILE* ofstream, double average) {
	fprintf(ofstream, "%lf", average);
}