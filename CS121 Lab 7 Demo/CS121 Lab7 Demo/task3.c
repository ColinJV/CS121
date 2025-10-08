#include "header.h"

void runTaskThree(void) {
	int year = 0, targetRevenueInMillions = 1000000;
	predictYear(&year, targetRevenueInMillions);
	writeRevenueToFileByYear(year);
}

void calculateRevenue(int yearsSince1984, double* revenue) {
	*revenue = 203.265 * pow(1.071, yearsSince1984);
}

void predictYear(int* year, int targetRevenueInMillions) {
	double revenue = 0;
	int yearsSince1984 = 0;
	if (targetRevenueInMillions <= 203) {
		*year = 1984;
	}
	else {
		while (revenue < targetRevenueInMillions) {
			calculateRevenue(yearsSince1984, &revenue);
			if (revenue < targetRevenueInMillions) {
				++yearsSince1984;
			}
			else {
				*year = 1984 + yearsSince1984;
			}
		}
	}
}

void writeRevenueToFile(int year, double revenue, FILE* ofstream) {
	fprintf(ofstream, "%d,%lf\n", year, revenue);
}

void writeRevenueToFileByYear(int finalYear) {
	int year = 1984;
	double revenue = 0;
	FILE* ofstream = fopen("broadwayRevenue.txt", "w");
	fprintf(ofstream, "Year,Revenue\n");
	while (year < finalYear) {
		calculateRevenue(year - 1984, &revenue);
		writeRevenueToFile(year, revenue, ofstream);
		++year;
	}
	fclose(ofstream);
}