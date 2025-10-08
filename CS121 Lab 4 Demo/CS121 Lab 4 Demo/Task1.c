#include "Header.h"

double getWeightFromFile(FILE* ifstream) {
	double weight = 0;
	fscanf(ifstream, "%lf", &weight);
	return(weight);
}

double getHeightFromFile(FILE* ifstream) {
	double height = 0;
	fscanf(ifstream, "%lf", &height);
	return(height);
}

int getAgeFromFile(FILE* ifstream) {
	int age = 0;
	fscanf(ifstream, "%d", &age);
	return(age);
}

char getGenderFromFile(FILE* ifstream) {
	char gender = 0;
	fscanf(ifstream, " %c", &gender);
	return(gender);
}

int getActivityLevel(void) {
	int activityLevel = 0;
	printf("Please enter the activity level.\n");
	printf("1. Sedentary (little to no exercise).\n");
	printf("2. Low activity.\n");
	printf("3. Moderate activity.\n");
	printf("4. High activity.\n");
	printf("5. Extra activity.\n");
	scanf("%d", &activityLevel);
	return(activityLevel);
}

double computeBMR(char gender, double weight, double height, int age) {
	double basalMetabolicRate = 0;
	if (gender == 'm' || gender == 'M') {
		basalMetabolicRate = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}
	else if (gender == 'f' || gender == 'F') {
		basalMetabolicRate = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	}
	return(basalMetabolicRate);
}

double computeDailyCaloricIntake(double basalMetabolicRate, int activityLevel) {
	double dailyCalories = 0;
	switch (activityLevel) {
	case 1:
		dailyCalories = basalMetabolicRate * 1.2;
		break;
	case 2:
		dailyCalories = basalMetabolicRate * 1.375;
		break;
	case 3:
		dailyCalories = basalMetabolicRate * 1.55;
		break;
	case 4:
		dailyCalories = basalMetabolicRate * 1.725;
		break;
	case 5:
		dailyCalories = basalMetabolicRate * 1.9;
		break;
	default:
		break;
	}
	return(dailyCalories);
}

void runTaskOne(void) {
	FILE* ifstream = openDataFileForReading();

	char gender = 0;
	gender = getGenderFromFile(ifstream);

	double height = 0, weight = 0;
	height = getHeightFromFile(ifstream);
	weight = getWeightFromFile(ifstream);

	int age = 0;
	age = getAgeFromFile(ifstream);

	double basalMetabolicRate = 0, dailyCalories = 0;
	basalMetabolicRate = computeBMR(gender, weight, height, age);
	dailyCalories = computeDailyCaloricIntake(basalMetabolicRate, getActivityLevel());

	displayDailyCaloricIntake(dailyCalories);
	closeFile(ifstream);
}

FILE* openDataFileForReading(void) {
	FILE* ifstream = fopen("data.txt", "r");
	return(ifstream);
}

void closeFile(FILE* ifstream) {
	fclose(ifstream);
}

void displayDailyCaloricIntake(double dailyCalories) {
	printf("The required daily caloric intake for maintenance is %lf.\n\n", dailyCalories);
}