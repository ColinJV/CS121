#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double getWeightFromFile(FILE* ifstream);
double getHeightFromFile(FILE* ifstream);
int getAgeFromFile(FILE* ifstream);
char getGenderFromFile(FILE* ifstream);
int getActivityLevel(void);
double computeBMR(char gender, double weight, double height, int age);
double computeDailyCaloricIntake(double basalMetabolicRate, int activityLevel);
void runTaskOne(void);
FILE* openDataFileForReading(void);
void closeFile(FILE* ifstream);
void displayDailyCaloricIntake(double dailyCalories);

void runTaskTwo(void);
int computeBaseballBonus(void);
int getAllStarAppearance(void);
int getRegularSeasonMVP(void);
int getWorldSeriesMVP(void);
int getGoldGloveRecipient(void);
int getSilverSluggerRecipient(void);
int getHomeRunChampRecipient(void);
int getBattingAverageChampRecipient(void);
char getCharInput(void);

void runTaskThree(void);
void displayTaskThreeMenu(void);
double averageValues(double num1, double num2, double num3, double num4, double num5);
double findHighestValue(double num1, double num2, double num3, double num4, double num5);
double findLowestValue(double num1, double num2, double num3, double num4, double num5);
double readNumberFromFile(FILE* ifstream);
int getIntegerInput(void);
void runUserInput(double num1, double num2, double num3, double num4, double num5, int userInput);

#endif