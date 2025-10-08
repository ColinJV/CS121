#include "Header.h"

void runTaskOne(void) {
	FILE* ifstream = openSalaryFile();

	double income = readIncomeFromFile(ifstream);
	closeFile(ifstream);

	char taxBracket = getTaxBracket(income);
	displayTaxBracket(taxBracket);
}

FILE* openSalaryFile(void) {
	FILE* ifstream = NULL;
	ifstream = fopen("salaries.txt", "r");
	return(ifstream);
}

double readIncomeFromFile(FILE* ifstream) {
	double income = 0;
	for (int i = 0; i < 4; ++i) {
		double quarterlyIncome = 0;
		fscanf(ifstream, "%lf", &quarterlyIncome);
		income += quarterlyIncome;
	}
	return income;
}

void closeFile(FILE* filestream) {
	fclose(filestream);
}

char getTaxBracket(double income) {
	char taxBracket = 0;

	if (income > 200000) {
		taxBracket = 'h';
	}
	else if (income > 15000) {
		taxBracket = 'm';
	}
	else taxBracket = 'l';
	return(taxBracket);
}

void displayTaxBracket(char taxBracket) {
	printf("The tax bracket for the scanned income is %c.\n\n", taxBracket);
}