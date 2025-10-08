#include "Header.h"

double getAngleOfElevation(void) {
	double userInput = 0;
	printf("Please enter the angle of elevation in radians.\n");
	scanf("%lf", &userInput);
	return(userInput);
}

double getDistanceToTarget(void) {
	double userInput = 0;
	printf("Please enter the distance to target in feet.\n");
	scanf("%lf", &userInput);
	return(userInput);
}

double getProjectileVelocity(void) {
	double userInput = 0;
	printf("Please enter the velocity of the projectile in feet per second.\n");
	scanf("%lf", &userInput);
	return(userInput);
}

double computeTimeInFlight(double angle, double distance, double velocity) {
	double time = distance / (velocity * cos(angle));
	return(time);
}

double computeHeightOfImpact(double angle, double time, double velocity) {
	double height = velocity * sin(angle) * time - ((GRAVITY_EARTH_SURFACE * pow(time, 2)) / 2);
	return(height);
}

void displayTimeAndHeight(double time, double height) {
	printf("The time the projectile is in flight is %lf seconds. ", time);
	printf("The height of the projectile at time of impact is %lf feet.\n", height);
}

void runTaskTwo(void) {
	double angle = getAngleOfElevation();
	double distance = getDistanceToTarget();
	double velocity = getProjectileVelocity();
	double time = computeTimeInFlight(angle, distance, velocity);
	double height = computeHeightOfImpact(angle, time, velocity);
	displayTimeAndHeight(time, height);
}