/************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA2
* Date: September 10, 2023
* Description: This program will evaluate equations describing
* Newton's Second Law of Motion, the volume of a cylinder, a
* character encoding equation, gravity, resistance, distance
* between two points, and a general mathematical equation
* based on user inputs. All calculations will be done using
* functions in equations.h and results displayed in main.c
************************************************************/

#define _CRT_SECURE_NO_WARNINGS								//silences compiler warnings due to printf and scanf functions

#include <stdio.h>											//imports library that includes printf and scanf functions

#include <math.h>											//imports library with various mathematical functions


#define PI 3.141592											//defines PI as a constant value for use in volume calculation

#define GRAVITATIONAL_CONSTANT 6.67e-11						//defines GRAVITATIONAL_CONSTANT as the gravitational constant
																// used to calculate force due to gravity

double calculate_newtons_2nd_law(double mass1, double acceleration);						// function prototype for calculate_newtons_2nd_law()

double calculate_volume_cylinder(double radius, double height);								// function prototype for calculate_volume_cylinder

char perform_character_encoding(char plaintext_character);									// function prototype for perform_character_encoding

double calculate_force_gravity(double mass2, double mass3, double distance1);				// function prototype for calculate_force_gravity

double calculate_resistance(double resistance1, double resistance2, double voltage_in);		// function prototype for calculate_resistance

double calculate_distance(double x1, double x2, double y1, double y2);						// function prototype for calculate_distance

double calculate_general_equation(double x3, double z1, int a1);							// function prototype for calculate_general_equation