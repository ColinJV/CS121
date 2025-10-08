#include "Header.h"

void runTaskThree(void) {
	FILE* ifstream = openNumberFile();
	int GCD = computeGreatestCommonDivisor(ifstream);
	closeFile(ifstream);

	FILE* ofstream = openOutputGCDFile();
	outputGCDToFile(ofstream, GCD);
	closeFile(ofstream);
}

FILE* openNumberFile(void) {
	FILE* ifstream = fopen("numbers.txt", "r");
	return(ifstream);
}

int computeGreatestCommonDivisor(FILE* ifstream) {
	int numerator = 0, divisor = 0, remainder = -1;
	fscanf(ifstream, "%d", &numerator);
	fscanf(ifstream, "%d", &divisor);

	while (remainder != 0) {
		remainder = numerator % divisor;
		numerator = divisor;
		divisor = remainder;
	}

	return(numerator);
}

FILE* openOutputGCDFile(void) {
	FILE* ofstream = fopen("GCDoutput.txt", "w");
	return(ofstream);
}

void outputGCDToFile(FILE* ofstream, int GCD) {
	fprintf(ofstream, "The GCD is %d.", GCD);
}