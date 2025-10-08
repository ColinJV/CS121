#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void runTaskOne(void);
void getInitials(char* firstInitial, char* secondInitial, char* thirdInitial);
void displayInitials(char firstInitial, char secondInitial, char thirdInitial);

void runTaskTwo(void);
void computeCharges(double hoursUsed, double* totalCharge, double* averageCostPerHour);
double roundMoney(double money);
double getHoursUsed(void);
void outputCharge(double totalCharge);

void runTaskThree(void);
void calculateRevenue(int yearsSince1984, double* revenue);
void predictYear(int* year, int targetRevenueInMillions);
void writeRevenueToFile(int year, double revenue, FILE* ofstream);
void writeRevenueToFileByYear(int finalYear);