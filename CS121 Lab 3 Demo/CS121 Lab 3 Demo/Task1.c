#include "Header.h"

double getHeightInFeet(void) {
	double userInput = 0;
	printf("Please enter the height in feet.\n");
	scanf("%lf", &userInput);
	return(userInput);
}

double getWeightInPounds(void) {
	double userInput = 0;
	printf("Please enter the weight in pounds.\n");
	scanf("%lf", &userInput);
	return(userInput);
}

double convertHeightToInches(double heightInFeet) {
	return(heightInFeet * 12);
}

double computeBMI(double heightInInches, double weightInPounds) {
	return((weightInPounds / pow(heightInInches, 2)) * 703);
}

void displayBMI(double BMI) {
	printf("The BMI is %lf. ", BMI);
	if (BMI < 18) {
		printf("This BMI is underweight.\n");
	}
	else if (BMI < 25) {
		printf("This BMI is healthy.\n");
	}
	else if (BMI < 30) {
		printf("This BMI is overweight.\n");
	}
	else {
		printf("This BMI is obese.\n");
	}
}

void runTaskOne(void) {
	double height = getHeightInFeet();
	double weight = getWeightInPounds();
	height = convertHeightToInches(height);
	double BMI = computeBMI(height, weight);
	displayBMI(BMI);
}