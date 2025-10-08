#include "header.h"

void runTaskTwo(void) {
	double hoursUsed = 0, totalCharge = 0, averageCostPerHour = 0;
	hoursUsed = getHoursUsed();
	computeCharges(hoursUsed, &totalCharge, &averageCostPerHour);
	totalCharge = roundMoney(totalCharge);
	outputCharge(totalCharge);
}

void computeCharges(double hoursUsed, double* totalCharge, double* averageCostPerHour) {

	if (hoursUsed <= 10) {
		*totalCharge = 7.99;
	}
	else {
		*totalCharge = 7.99 + 1.99 * (hoursUsed - 10);
	}
	*averageCostPerHour = *totalCharge / hoursUsed;
}

double roundMoney(double money) {
	money = (double)((int)(money * 100 + 0.5)) / 100;
	return(money);
}

double getHoursUsed(void) {
	int junk = 0;
	double hoursUsed = 0;
	FILE* ifstream = fopen("customerData.txt", "r");
	fscanf(ifstream, "%d", &junk);
	fscanf(ifstream, "%d", &junk);
	fscanf(ifstream, "%d", &junk);
	fscanf(ifstream, "%lf", &hoursUsed);
	fclose(ifstream);
	return(hoursUsed);
}

void outputCharge(double totalCharge) {
	FILE* ofstream = fopen("internetCharge.txt", "w");
	fprintf(ofstream, "The total Internet charge is $%.2lf.\n", totalCharge);
	fflush(ofstream);
	fclose(ofstream);
}