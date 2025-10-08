#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 200
#define NAME_LENGTH 100

typedef struct employee {
	char name[100];
	char title;
	double hours_worked;
	double payRate;
	double payment;
} Employee;

void computePayroll(void);
void loadEmployeeDataFromFile(Employee* payrollEmployees);
FILE* openPayrollInputFile(void);
void closePayrollInputFile(FILE* ifstream);
void initPayrollEmployees(Employee* payrollEmployees);
void readPayrollFile(Employee* payrollEmployees, FILE* payrollFile);
char getTitleFromString(char* string);
double convertStringToDouble(char* string);
void computeIndividualPayments(Employee* payrollEmployees);
double computeOvertimePayment(Employee* payrollEmployee);
double computeBasePayment(Employee* payrollEmployee);
double roundToNearestCent(double dollarAmount);
double computeTotalPayments(Employee* payrollEmployees);
double computeAveragePayment(double totalPayment, Employee* payrollEmployees);
double findMaxPayment(Employee* payrollEmployees);
double findMinPayment(Employee* payrollEmployees);
FILE* openPayrollOutputFile(void);
void closePayrollOutputFile(FILE* ofstream);
void writePayrollData(FILE* ofstream, double totalPayroll, double averagePayment, double maxPayment, double minPayment);