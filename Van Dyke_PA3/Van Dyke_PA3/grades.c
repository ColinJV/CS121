/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA3
* Date: September 16, 2023
* Description: This program will read integer and floating
* point values from an input stream from a text file, input.dat,
* using functions defined in grades.c and called in main.c. These
* values represent Student ID numbers, GPAs, class standings, and
* ages for five students. After reading values, the program will perform
* a variety of mathematical computations on these values using
* functions defined in grades.c, and outputs GPA mean, Standings mean,
* Age mean, GPA Standard Deviation, Minimum GPA, and Maximum GPA
* to an output text file, output.dat, as floating-point values.
******************************************************************/



#include "grades.h"



// Reads a floating-point value from an input file
double read_double(FILE* infile) {
	double number = 0;
	fscanf(infile, "%lf", &number);
	return(number);
}



// Reads an integer value from an input file
int read_integer(FILE* infile) {
	int number = 0;
	fscanf(infile, "%d", &number);
	return(number);
}



// Calculates the sum of five numbers
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	double sum = 0;
	sum = number1 + number2 + number3 + number4 + number5;
	return(sum);
}



// Calculates mean by dividing a sum of numbers by the number of values
double calculate_mean(double sum, int number) {
	double mean = 0;
	if (number != 0) {
		mean = sum / number;
		return(mean);
	}
	else {
		return(-1.0);
	}
}



// Calculates the deviation of a number from a mean by subtracting the mean from the number
double calculate_deviation(double number, double mean) {
	double deviation = 0;
	deviation = number - mean;
	return(deviation);
}



// Calculates variance by squaring each input for deviation and then calling calculate_mean() to average the values
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double deviation_sum = 0, variance = 0;
	deviation1 = pow(deviation1, 2);
	deviation2 = pow(deviation2, 2);
	deviation3 = pow(deviation3, 2);
	deviation4 = pow(deviation4, 2);
	deviation5 = pow(deviation5, 2);
	deviation_sum = deviation1 + deviation2 + deviation3 + deviation4 + deviation5;
	variance = calculate_mean(deviation_sum, 5);
	return(variance);
}



// Calculates standard deviation by taking the square root of an input
double calculate_standard_deviation(double variance) {
	double standard_deviation = 0;
	standard_deviation = sqrt(variance);
	return(standard_deviation);
}


// Prints a floating-point number to two decimal places to output.dat and goes to a new line
void print_double(FILE* outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
	return;
}


// Finds the minimum input value through an algorithm methodically checking
// inputs against each other in a simple inequality, input1 < input2.
// Starting with number1, it checks against 2, 3, etc. in order up to 5
// If number1 is not less than a value it is compared against, the algorithm then begins
// to check the new value against values that have not yet been compared against.
// This algorithm terminates after 4 comparisons.
double find_min(double number1, double number2, double number3, double number4, double number5) {
	double min = 0;
	if (number1 < number2) {
		if (number1 < number3) {
			if (number1 < number4) {
				if (number1 < number5) {
					min = number1;
					return(min);
				}
				else {
					min = number5;
					return(min);
				}
			}
			else if (number4 < number5) {
				min = number4;
				return(min);
			}
			else {
				min = number5;
				return(min);
			}	
		}
		else if (number3 < number4){
			if (number3 < number5) {
				min = number3;
				return(min);
			}
			else {
				min = number5;
				return(min);
			}
		}
		else if (number4 < number5) {
			min = number4;
			return(min);
		}
		else {
			min = number5;
			return(min);
		}
		}
	else if (number2 < number3) {
		if (number2 < number4) {
			if (number2 < number5) {
				min = number2;
				return(min);
			}
			else {
				min = number5;
				return(min);
			}
		}
		else if (number4 < number5) {
			min = number4;
			return(min);
		}
		else {
			min = number5;
			return(min);
		}
	}
	else if (number3 < number4) {
		if (number3 < number5) {
			min = number3;
			return(min);
		}
		else {
			min = number5;
			return(min);
		}
	}
	else if (number4 < number5) {
		min = number4;
		return(min);
	}
	else {
		min = number5;
		return(min);
	}
}


// Finds the maximum input value through an algorithm methodically checking
// inputs against each other in a simple inequality, input1 > input2.
// Starting with number1, it checks against 2, 3, etc. in order up to 5
// If number1 is not greater than a value it is compared against, the algorithm then begins
// to check the new value against values that have not yet been compared against.
// This algorithm terminates after 4 comparisons.
double find_max(double number1, double number2, double number3, double number4, double number5) {
	double max = 0;
	if (number1 > number2) {
		if (number1 > number3) {
			if (number1 > number4) {
				if (number1 > number5) {
					max = number1;
					return(max);
				}
				else {
					max = number5;
					return(max);
				}
			}
			else if (number4 > number5) {
				max = number4;
				return(max);
			}
			else {
				max = number5;
				return(max);
			}
		}
		else if (number3 > number4) {
			if (number3 > number5) {
				max = number3;
				return(max);
			}
			else {
				max = number5;
				return(max);
			}
		}
		else if (number4 > number5) {
			max = number4;
			return(max);
		}
		else {
			max = number5;
			return(max);
		}
	}
	else if (number2 > number3) {
		if (number2 > number4) {
			if (number2 > number5) {
				max = number2;
				return(max);
			}
			else {
				max = number5;
				return(max);
			}
		}
		else if (number4 > number5) {
			max = number4;
			return(max);
		}
		else {
			max = number5;
			return(max);
		}
	}
	else if (number3 > number4) {
		if (number3 > number5) {
			max = number3;
			return(max);
		}
		else {
			max = number5;
			return(max);
		}
	}
	else if (number4 > number5) {
		max = number4;
		return(max);
	}
	else {
		max = number5;
		return(max);
	}
}