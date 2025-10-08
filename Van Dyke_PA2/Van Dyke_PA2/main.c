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

#include "equations.h"

int main(void) {

	double mass1 = 0.0, acceleration = 0.0, force = 0.0;																		// declares double variables for use in calculate_newtons_2nd_law()

	printf("For Newton's Second Law of Gravity, described by F = mass * acceleration, provide floating-point value \n");
	printf("inputs for mass and acceleration: \n");																				// prompts user for inputs for mass and acceleration to use in calculate_newtons_2nd_law()

	scanf("%lf%lf", &mass1, &acceleration);																						// takes user inputs from the keyboard for mass and acceleration

	force = calculate_newtons_2nd_law(mass1, acceleration);																		// performs the function calculate_newtons_2nd_law in equations.c with given inputs and assigns
																																	// its return value to the double force

	printf("The resultant force: Force = %lf * %lf = %.2lf\n", mass1, acceleration, force);										// prints the result of calculate_newtons_2nd_law() to the terminal




	

	double radius = 0.0, height = 0.0, volume_cylinder = 0.0;																	// declares double variables for use in calculate_volume_cylinder()

	printf("\nFor the volume of a cylinder, described by V = pi * (radius^2) * height, provide \n");
	printf("floating-point value inputs for radius and height: \n");															// prompts user for inputs for radius and height to use in calculate_volume_cylinder()

	scanf("%lf%lf", &radius, &height);																							// takes user inputs from the keyboard for radius and height

	volume_cylinder = calculate_volume_cylinder(radius, height);																// performs the function calculate_volume_cylinder in equations.c with given inputs
																																	// and assigns the return value to volume_cylinder

	printf("The volume of the given cylinder is Volume = pi * (%lf)^2 * %lf = %.2lf\n", radius, height, volume_cylinder);		// prints the value of volume_cylinder to the terminal








	char plaintext_character = '0', encoded_character = '0';																	// declares char variables for plaintext_character and encoded_character to be used for
																																	// calculate_character_encoding()

	printf("\nFor character encoding described by Encoded Character = Plaintext Character - 'a' + 'A',\n");
	printf("input a plaintext character : \n");																					// prompts user for an input for plaintext_character to be used in perform_character_encoding()

	scanf(" %c", &plaintext_character);																							// takes input from the keyboard and assigns plaintext_character to that input

	encoded_character = perform_character_encoding(plaintext_character);														// calls the perform_character_encoding function and assigns encoded_character the value of the
																																	// function return

	printf("The resultant encoded character is Encoded Character = %c - 'a' + 'A' = %c\n", plaintext_character, encoded_character);			// prints the encoded character resulting from the ASCII computation






	double mass2 = 0.0, mass3 = 0.0, distance1 = 0.0;																			// declares floating point variables for upcoming user inputs to be used in calculate_force_gravity()

	printf("\nFor the force due to gravity between two objects described by F = G * (m1 * m2) / (distance^2), provide\n");
	printf("floating point value inputs for the mass of object 1, the mass of object 2, and the distance between them.\n");		// prompts the user for inputs for mass2, mass3, and distance for use in calculate_force_gravity()

	scanf("%lf%lf%lf", &mass2, &mass3, &distance1);																				// takes inputs from the keybaord for mass2, mass3, and distance for use in calculate_force_gravity()

	force = calculate_force_gravity(mass2, mass3, distance1);																	// calls the function calculate_force_gravity() and assigns its output to the double force

	printf("The force due to gravity is Force = G * (%lf * %lf) / (%lf)^2 = %.2lf\n", mass2, mass3, distance1, force);			// prints the value of force to the terminal






	double resistance1 = 0.0, resistance2 = 0.0, voltage_in = 0.0, voltage_out = 0.0;											// declares double variables for upcoming user inputs to be used in calculate_resistance()

	printf("\nFor the voltage output of a resistive divider described by V_out = r2 / (r1 + r2) * V_in, provide\n");
	printf("floating point value inputs for the first resistance, the second resistance, and voltage input: \n");				// prompts the user for inputs for voltage_in, resistance1, and resistance2 for use in calculate_resistance()

	scanf("%lf%lf%lf", &resistance1, &resistance2, &voltage_in);																// takes input from the keyboard for resistance1, resistance2, and voltage_in

	voltage_out = calculate_resistance(resistance1, resistance2, voltage_in);													// calls the calculate_resistance function and assigns the double variable voltage_out the value of the function return

	printf("The voltage output is V_out = %lf / (%lf + %lf) * %lf = %.2lf\n", resistance2, resistance1, resistance2, voltage_in, voltage_out);	// prints the value of voltage_out





	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance2 = 0.0;																// defines double variables for the upcoming X and Y coordinates of two user input points

	printf("\nFor the distance between two points described by Distance = sqrt((x1 - x2)^2 + (y1 - y2)^2), provide\n");
	printf("floating point value inputs for the X and Y coordinates of the first point: \n");									// prompts the user for x1 and y1, the X and Y coordinates of some point

	scanf("%lf%lf", &x1, &y1);																									// takes input from the keyboard for x1 and y1

	printf("Provide floating point value inputs for the X and Y coordinates of the second point: \n");							// prompts the user for x2 and y2, the X and Y coordinates of some other point

	scanf("%lf%lf", &x2, &y2);																									// takes input from the keyboard for x2 and y2

	distance2 = calculate_distance(x1, x2, y1, y2);																				// calls the function calculate_distance() and the double variable distance to its return

	printf("The distance is Distance = sqrt((%lf - %lf)^2 + (%lf - %lf)^2) = %.2lf\n", x1, x2, y1, y2, distance2);				// prints the value of distance





	double x3 = 0.0, z1 = 0.0, y3 = 0.0;																						// defines double variable z1 for an upcoming user input and use in calculate_general_equation()

	int a1 = 0;																													// defines int variable a1 for an upcoming user input

	printf("\nFor the general equation y = (73 / 12) - x * z + a / (a %% 2), provide floating point value inputs\n");
	printf("for x and z: \n");																									// prompts the user for inputs for doubles x1 and z1

	scanf("%lf%lf", &x3, &z1);																									// takes input from the keyboard for x1 and z1

	printf("For the previous equation, provide an integer input for a: \n");													// prompts the user for input for integer a1

	scanf("%d", &a1);																											// takes input from the keyboard for a1

	y3 = calculate_general_equation(x3, z1, a1);																				// calls the calculate_general_equation() function and assigns y1 its return value

	printf("For y = (73 / 12) - %lf * %lf + %d / (%d %% 2), y = %.2lf\n", x3, z1, a1, a1, y3);									// prints the value of y1

	return(0);
}

