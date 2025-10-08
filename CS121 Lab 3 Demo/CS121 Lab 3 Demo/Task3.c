#include "Header.h"

double getExamScore(int examNumber) {
	double userInput = 0;
	printf("Please enter the score for Exam %d.\n", examNumber);
	scanf("%lf", &userInput);
	return(userInput);
}

double getLabScore(int labNumber) {
	double userInput = 0;
	printf("Please enter the score for Lab %d.\n", labNumber);
	scanf("%lf", &userInput);
	return(userInput);
}

double getProjectScore(int projectNumber) {
	double userInput = 0;
	printf("Please enter the score for Project %d.\n", projectNumber);
	scanf("%lf", &userInput);
	return(userInput);
}

double computeAssignmentAverage(double score1, double score2) {
	return((score1 + score2) / 2);
}

double computeWeightedAverage(double examAverage, double labAverage, double projectAverage) {
	return((examAverage * .6) + (labAverage * .1) + (projectAverage * .3));
}

void displayWeightedAverage(double weightedAverage) {
	printf("The weighted average of all assignments is %lf.", weightedAverage);
}

void runTaskThree(void) {
	double exam1 = getExamScore(1), exam2 = getExamScore(2);
	double lab1 = getLabScore(1), lab2 = getLabScore(2);
	double project1 = getProjectScore(1), project2 = getProjectScore(2);

	double examAverage = computeAssignmentAverage(exam1, exam2);
	double labAverage = computeAssignmentAverage(lab1, lab2);
	double projectAverage = computeAssignmentAverage(project1, project2);

	double GPA = computeWeightedAverage(examAverage, labAverage, projectAverage);
	displayWeightedAverage(GPA);
}