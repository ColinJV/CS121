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

#include "equations.h"																			// imports equations.h header file containing other imported libraries,
																									// constant definitions, and function prototypes




double calculate_newtons_2nd_law(double mass1, double acceleration) {							// function to calculate force from mass and acceleration according to Newton's 2nd Law

	double force = 0.0;																			// declares a local double variable force for upcoming computation using user inputs

	force = mass1 * acceleration;																// computes mass1 * acceleration from user input function arguments and assigns the
																									// computed value to the double force

	return(force);																				// returns the value of force to the main function
}



double calculate_volume_cylinder(double radius, double height) {								// function to calculate a cylinder's volume from radius and height

	double volume_cylinder = 0.0;																// declares a local double variable volume_cylinder for upcoming computation using user inputs

	volume_cylinder = PI * pow(radius, 2) * height;												// computes PI * radius^2 * height from user input function arguments and assigns the
																									// computed value to the double volume_cylinder

	return(volume_cylinder);																	// returns the value of volume_cylinder to the main function
}





char perform_character_encoding(char plaintext_character) {										// function to perform encoding on a user input character

	char encoded_character = '0';																// declares a local char variable encoded_character for upcoming computation

	encoded_character = (plaintext_character - 'a') + 'A';										// performs an ASCII computation on the user input function argument
																									// if user input is a lower-case letter, encoded_character will be
																									// capitalized version of that letter.
																									// if user input is a capitalized letter, encoded_character will be
																									// a different ASCII character, possibly out of range

	return(encoded_character);																	// returns the value of encoded_character to the main function
}




double calculate_force_gravity(double mass1, double mass2, double distance) {					// function to calculate force due to gravity between two objects

	double force = 0.0;																			// declares a local double variable force for upcoming computation using user inputs

	force = GRAVITATIONAL_CONSTANT * (mass1 * mass2) / pow(distance, 2);						// computes G * (mass1 * mass2) / (distance^2) using user input function arguments
																									// and assigns the value to the double force

	return(force);																				// returns the value of force to the main function
}





double calculate_resistance(double resistance1, double resistance2, double voltage_in) {		// function to calculate the voltage output from two resistors

	double voltage_out = 0.0;																	// declares a local double variable voltage_out for upcoming computation using user inputs

	voltage_out = resistance2 / (resistance1 + resistance2) * voltage_in;						// computes resistance2 / (resistance1 + resistance2) * voltage_in and assigns the
																									// computed value to the double voltage_out

	return(voltage_out);																		// returns the value of voltage_out to the main function
}





double calculate_distance(double x1, double x2, double y1, double y2) {							// function to calculate the distance between two points on a 2-dimensional plane

	double distance = 0.0;																		// declares a local double variable distance for upcoming computation using user inputs

	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));											// computes sqrt((x1-x2)^2 + (y1-y2)^2) and assigns the value of the computation to distance

	return(distance);																			// returns the value of distance to the main function
}




double calculate_general_equation(double x1, double z1, int a1) {								// function to compute a general equation

	double y1 = 0.0;																			// declares a local double variable y1 for upcoming computation using user inputs
	
	y1 = ((double)73 / (double)12) - x1 * z1 + a1 / (a1 % 2);									// typecasts 73 and 12 to doubles, then computes 73/12 - x1 * z1 + a1 / (a1 % 2) and
																									// assigns the value of the computation to y1
																									// Note: if a1 is even, the function is dividing by zero and will encounter an error
																											// if a1 is odd, the function will complete and return a valid value

	return(y1);																					// returns the value of y1 to the main function
}