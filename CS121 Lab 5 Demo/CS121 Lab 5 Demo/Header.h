#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

void runTaskOne(void);
FILE* openSalaryFile(void);
double readIncomeFromFile(FILE* ifstream);
void closeFile(FILE* filestream);
char getTaxBracket(double income);
void displayTaxBracket(char taxBracket);

void runTaskTwo(void);
FILE* openDataFile(void);
double computeAverageDataValue(FILE* ifstream);
FILE* openOutputFile(void);
void writeAverageToFile(FILE* ofstream, double average);

void runTaskThree(void);
FILE* openNumberFile(void);
int computeGreatestCommonDivisor(FILE* ifstream);
FILE* openOutputGCDFile(void);
void outputGCDToFile(FILE* ofstream, int GCD);

void runTaskFour(void);
FILE* openHighLowDataFile(void);
int getHighFromFile(FILE* ifstream);
int getLowFromFile(FILE* ifstream);
void displayHighLow(int high, int low);

#endif