#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	// Computes the perpendicular bisector at the midpoint of a line segment between two points
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0,
		xMid = 0, yMid = 0, slope = 0, bisectorSlope = 0,
		yInt = 0;
	printf("This will compute the perpindicular bisector at the midpoint of a line segment between two points.\n");
	printf("Please enter the x and y coordinates of the first point: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Please enter the x and y coordinates of the second point: ");
	scanf("%lf%lf", &x2, &y2);
	xMid = (x1 + x2) / 2;
	yMid = (y1 + y2) / 2;
	slope = (y2 - y1) / (x2 - x1);
	bisectorSlope = -1 / slope;
	yInt = yMid - bisectorSlope * xMid;
	printf("The formula for the perpendicular bisector at the midpoint of the input line segment is:\n");
	printf("y = %lfx + %lf", bisectorSlope, yInt);


	// Calculates BMI based on user inputs
	double BMI = 0, weight = 0, height = 0;
	printf("This will compute a BMI based on height and weight inputs.\n");
	printf("Please enter a weight in pounds: ");
	scanf("%lf", &weight);
	printf("Please enter a height in feet: ");
	scanf("%lf", &height);
	height = height * 12;
	BMI = (weight / pow(height, 2)) * 703;
	printf("The resultant BMI is %lf.\n", BMI);
	printf("A BMI of less than 18 indicates you are underweight.\n");
	printf("A BMI between 18 and 25 means you are at a healthy weight.\n");
	printf("A BMI between 25 and 30 means you are overweight.\n");
	printf("A BMI greater than 30 means you are obese.\n");
}