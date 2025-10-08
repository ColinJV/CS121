#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define GRAVITY_EARTH_SURFACE 32.17

double getHeightInFeet(void);
double getWeightInPounds(void);
double convertHeightToInches(double heightInFeet);
double computeBMI(double heightInInches, double weightInPounds);
void displayBMI(double BMI);
void runTaskOne(void);

double getAngleOfElevation(void);
double getDistanceToTarget(void);
double getProjectileVelocity(void);
double computeTimeInFlight(double angle, double distance, double velocity);
double computeHeightOfImpact(double angle, double time, double velocity);
void displayTimeAndHeight(double time, double height);
void runTaskTwo(void);

double getExamScore(int examNumber);
double getLabScore(int labNumber);
double getProjectScore(int projectNumber);
double computeAssignmentAverage(double score1, double score2);
double computeWeightedAverage(double examAverage, double labAverage, double projectAverage);
void displayWeightedAverage(double weightedAverage);
void runTaskThree(void);