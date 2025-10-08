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




// Silences warnings for fprintf() and fscanf(), and imports
// stdio.h and math.h libraries for use in main() and other functions
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double read_double(FILE* infile);
int read_integer(FILE* infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
void print_double(FILE* outfile, double number);