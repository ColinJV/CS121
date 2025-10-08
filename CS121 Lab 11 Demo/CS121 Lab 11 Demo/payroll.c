#include "header.h"

void computePayroll(void) {
	// this lab is conducted before instruction on heap space and there is no
	// expectation to dynamically allocate memory.

	FILE* ofstream = NULL;
	Employee payrollEmployees[MAX_SIZE];
	initPayrollEmployees(payrollEmployees);

	double totalPayroll = 0, averagePayment = 0,
		maxPayment = 0, minPayment = 0;

	loadEmployeeDataFromFile(payrollEmployees);

	computeIndividualPayments(payrollEmployees);
	totalPayroll = computeTotalPayments(payrollEmployees);
	averagePayment = computeAveragePayment(totalPayroll, payrollEmployees);
	maxPayment = findMaxPayment(payrollEmployees);
	minPayment = findMinPayment(payrollEmployees);

	ofstream = openPayrollOutputFile(ofstream);
	writePayrollData(ofstream, totalPayroll, averagePayment, maxPayment, minPayment);
	closePayrollOutputFile(ofstream);
}

void loadEmployeeDataFromFile(Employee* payrollEmployees) {
	FILE* ifstream = NULL;
	ifstream = openPayrollInputFile();
	readPayrollFile(payrollEmployees, ifstream);
	closePayrollInputFile(ifstream);
}

FILE* openPayrollInputFile(void) {
	return fopen("payroll.txt", "r");
}

void closePayrollInputFile(FILE* ifstream) {
	fclose(ifstream);
}

void initPayrollEmployees(Employee* payrollEmployees) {
	for (int i = 0; i < MAX_SIZE; ++i) {
		payrollEmployees[i].hours_worked = 0;
		payrollEmployees[i].payRate = 0;
		payrollEmployees[i].payment = 0;
		payrollEmployees[i].title = 0;
		strcpy(payrollEmployees->name, "");
	}
}

void readPayrollFile(Employee* payrollEmployees, FILE* payrollFile) {
	char scannedValue[NAME_LENGTH] = "";
	int i = 0;

	while (fgets(scannedValue, NAME_LENGTH, payrollFile) && i < MAX_SIZE) {
		strcpy(payrollEmployees[i].name, strtok(scannedValue, "\n"));
		//strtok() is a string.h library function you will learn more about in Cpts122.
		//		Basically it will return the contents of a string, scannedValue, that occur
		//		before a target character called the delimiter. Multiple characters can be
		//		delimiters, so it is passed to strtok() as a literal string, hence double quotes.
		//		E.g. if I wanted the contents of a string until a comma, newline, or period were
		//		encountered, the delimiter parameter would be ",.\n".
		//		It is completely unnecessary here and I am only using it to get rid of the
		//		newline character at the end of the name.
		fgets(scannedValue, NAME_LENGTH, payrollFile);
		payrollEmployees[i].title = getTitleFromString(scannedValue);
		fgets(scannedValue, NAME_LENGTH, payrollFile);
		payrollEmployees[i].hours_worked = convertStringToDouble(scannedValue);
		fgets(scannedValue, NAME_LENGTH, payrollFile);
		payrollEmployees[i].payRate = convertStringToDouble(scannedValue);
		++i;
	}
}

char getTitleFromString(char* string) {
	return string[0];
}

double convertStringToDouble(char* string) {
	return(strtod(string, NULL));
}

void computeIndividualPayments(Employee* payrollEmployees) {
	for (int i = 0; payrollEmployees[i].title != 0 && i < MAX_SIZE; ++i) {
		double overtimePayment = 0;
		if (payrollEmployees[i].hours_worked > 80) {
			overtimePayment = computeOvertimePayment(&(payrollEmployees[i]));
		}
		double basePayment = computeBasePayment(&(payrollEmployees[i]));
		payrollEmployees[i].payment = roundToNearestCent(overtimePayment + basePayment);
	}
}

double computeOvertimePayment(Employee* payrollEmployee) {
	double overtimePayment = 0;
	double overtimeHours = payrollEmployee->hours_worked - 80;

	if (payrollEmployee->title == 'B') {
		overtimePayment = overtimeHours * payrollEmployee->payRate * 1.5;
	}
	else if (payrollEmployee->title == 'M') {
		overtimePayment = overtimeHours * payrollEmployee->payRate * 1.8;
	}

	return(overtimePayment);
}

double computeBasePayment(Employee* payrollEmployee) {
	double hours = 80;
	if (payrollEmployee->hours_worked < 80) {
		hours = payrollEmployee->hours_worked;
	}

	double basePay = hours * payrollEmployee->payRate;

	return(basePay);
}

double roundToNearestCent(double dollarAmount) {
	int temp = dollarAmount * 100 + 0.5;
	double rounded = temp / ((double)(100));
	return(rounded);
}

double computeTotalPayments(Employee* payrollEmployees) {
	double totalPayment = 0;

	for (int i = 0; payrollEmployees[i].title != 0 && i < MAX_SIZE; i++) {
		totalPayment += payrollEmployees[i].payment;
	}

	return(totalPayment);
}

double computeAveragePayment(double totalPayment, Employee* payrollEmployees) {
	int i = 0;
	for (; i < MAX_SIZE && payrollEmployees[i].title != 0; ++i);
	double averagePayment = roundToNearestCent(totalPayment / i);
	return(averagePayment);
}

double findMaxPayment(Employee* payrollEmployees) {
	double max = payrollEmployees[0].payment;
	for (int i = 1; i < MAX_SIZE && payrollEmployees[i].title != 0; ++i) {
		if (payrollEmployees[i].payment > max) {
			max = payrollEmployees[i].payment;
		}
	}
	return(max);
}

double findMinPayment(Employee* payrollEmployees) {
	double min = payrollEmployees[0].payment;

	for (int i = 1; i < MAX_SIZE && payrollEmployees[i].title != 0; ++i) {
		if (payrollEmployees[i].payment < min) {
			min = payrollEmployees[i].payment;
		}
	}

	return(min);
}

FILE* openPayrollOutputFile(void) {
	return fopen("paid.txt", "w");
}

void closePayrollOutputFile(FILE* ofstream) {
	fflush(ofstream);
	fclose(ofstream);
}

void writePayrollData(FILE* ofstream, double totalPayroll, double averagePayment, double maxPayment, double minPayment) {
	fprintf(ofstream, "Total: $%.2lf\n", totalPayroll);
	fprintf(ofstream, "Average: $%.2lf\n", averagePayment);
	fprintf(ofstream, "Max: $%.2lf\n", maxPayment);
	fprintf(ofstream, "Min: $%.2lf\n", minPayment);
}