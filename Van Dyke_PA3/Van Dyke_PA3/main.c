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

int main(void) {
	// This section declares variables for input and output files, and variables
	// for the 20 values that will be read from the input file.
	FILE* infile = "\0", * outfile = "\0";
	int student1_id = 0, student2_id = 0, student3_id = 0, student4_id = 0, student5_id = 0;
	int student1_standing = 0, student2_standing = 0, student3_standing = 0, student4_standing = 0, student5_standing = 0;
	double student1_gpa = 0, student2_gpa = 0, student3_gpa = 0, student4_gpa = 0, student5_gpa = 0;
	double student1_age = 0, student2_age = 0, student3_age = 0, student4_age = 0, student5_age = 0;


	// Opens input.dat for reading and output.dat for writing
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");


	// Reads values from input.dat in the sequence they exist in the file and assigns them to proper variables
	student1_id = read_integer(infile);
	student1_gpa = read_double(infile);
	student1_standing = read_integer(infile);
	student1_age = read_double(infile);
	
	student2_id = read_integer(infile);
	student2_gpa = read_double(infile);
	student2_standing = read_integer(infile);
	student2_age = read_double(infile);

	student3_id = read_integer(infile);
	student3_gpa = read_double(infile);
	student3_standing = read_integer(infile);
	student3_age = read_double(infile);

	student4_id = read_integer(infile);
	student4_gpa = read_double(infile);
	student4_standing = read_integer(infile);
	student4_age = read_double(infile);

	student5_id = read_integer(infile);
	student5_gpa = read_double(infile);
	student5_standing = read_integer(infile);
	student5_age = read_double(infile);




	// Declares variables for sums of GPAs, standings, and ages
	double gpa_sum = 0, standing_sum = 0, age_sum = 0;

	// Calculates sums of GPAs, standings, and ages
	gpa_sum = calculate_sum(student1_gpa, student2_gpa, student3_gpa, student4_gpa, student5_gpa);
	standing_sum = calculate_sum(student1_standing, student2_standing, student3_standing, student4_standing, student5_standing);
	age_sum = calculate_sum(student1_age, student2_age, student3_age, student4_age, student5_age);




	// Declares variables for means of GPAs, standings, and ages
	double gpa_mean = 0, standing_mean = 0, age_mean = 0;

	// Calculates means of GPAs, standings, and ages, calls print_double to print
	// each result to output.dat. Calls fflush() to ensure fprintf() occurs.
	gpa_mean = calculate_mean(gpa_sum, 5);
	print_double(outfile, gpa_mean);
	standing_mean = calculate_mean(standing_sum, 5);
	print_double(outfile, standing_mean);
	age_mean = calculate_mean(age_sum, 5);
	print_double(outfile, age_mean);




	// Declares variables for the deviation of each GPA from the mean
	double student1_gpa_deviation = 0, student2_gpa_deviation = 0, student3_gpa_deviation = 0, student4_gpa_deviation = 0, student5_gpa_deviation = 0;

	// Calls calculate_deviation for each student's GPA to determine deviation
	// from the mean
	student1_gpa_deviation = calculate_deviation(student1_gpa, gpa_mean);
	student2_gpa_deviation = calculate_deviation(student2_gpa, gpa_mean);
	student3_gpa_deviation = calculate_deviation(student3_gpa, gpa_mean);
	student4_gpa_deviation = calculate_deviation(student4_gpa, gpa_mean);
	student5_gpa_deviation = calculate_deviation(student5_gpa, gpa_mean);




	// Declares variable for GPA variance
	double gpa_variance = 0;

	// Calculates GPA variance by calling calculate_variance() and inputting each student's deviation
	gpa_variance = calculate_variance(student1_gpa_deviation, student2_gpa_deviation, student3_gpa_deviation, student4_gpa_deviation, student5_gpa_deviation, 5);




	// Declares variable for GPA Standard Deviation
	double gpa_standard_deviation = 0;

	// Calculates the Standard Deviation and prints the result to output.dat
	gpa_standard_deviation = calculate_standard_deviation(gpa_variance);
	print_double(outfile, gpa_standard_deviation);



	// Declares variable for minimum GPA
	double minimum_gpa = 0;

	// Calls find_min() to find the minimum GPA and assigns the value to minimum_gpa, then
	// prints the value to output.dat
	minimum_gpa = find_min(student1_gpa, student2_gpa, student3_gpa, student4_gpa, student5_gpa);
	print_double(outfile, minimum_gpa);



	// Declares variable for maximum GPA
	double maximum_gpa = 0;

	// Calls find_max() to find the maximum GPA and assigns the value to maximum_gpa, then
	// prints the value to output.dat
	maximum_gpa = find_max(student1_gpa, student2_gpa, student3_gpa, student4_gpa, student5_gpa);
	print_double(outfile, maximum_gpa);

	// Closes input.dat and output.dat
	fclose(infile);
	fclose(outfile);

	return(0);
}