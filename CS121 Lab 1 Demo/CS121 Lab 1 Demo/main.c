#define _CRT_SECURE_NO_WARNINGS  // This needs to be at the top of your file above everything else

#define PI 3.1415926

#include <stdio.h>
#include <math.h>

int main(void) {
	// Prints "Hello World" to the terminal
	printf("Hello World!\n\n");

	// Declares and initializes two integers and two floating point variables in memory
	int number1_int = 0, number2_int = 0;
	double number1_float = 0, number2_float = 0;

	// Prompts the user for inputs for the two integer variables
	printf("Enter two integer values: \n");
	scanf("%d%d", &number1_int, &number2_int);

	// Prompts the user for inputs for the two floating point variables
	printf("Enter two floating point values: \n");
	scanf("%lf%lf", &number1_float, &number2_float);

	// Sums the integer variables and displays the result
	int sum_int = number1_int + number2_int;
	printf("The sum of integer 1 and integer 2 is %d.\n", sum_int);

	// Takes the difference of the floating point variables and displays the result
	double difference_float = number2_float - number1_float;
	printf("The result of subtracting number1_float from number2_float is %lf.\n", difference_float);

	// Computes the product of number1_int and number1_float and displays the result as an integer
	int product_mixed = number1_int * number1_float;
	printf("The product of number1_int and number1_float as an integer is %d.\n", product_mixed);

	// Computes the quotient of number1_int and number2_int and prints the result as an integer and a floating-point value
	int quotient_integer = number1_int / number2_int;
	double quotient_float = number1_int / number2_int;  // should notice a subtle Intellisense notification here telling you that you'll lose precision
	printf("The integer result of number1_int divided by number2_int is %d.\n", quotient_integer);
	printf("The floating point result of number1_int divided by number2_int is %lf.\n", quotient_float);

	// Computes the quotient of number1_int and number2_float and prints the result as an integer and a floating point value
	quotient_integer = number1_int / number2_float;
	quotient_float = number1_int / number2_float;	// notice there is no warning here and the result is accurate, i.e. no loss of precision
	printf("The integer result of number1_int divided by number2_float is %d.\n", quotient_integer);
	printf("The floating point result of number1_int divided by number2_float is %lf.\n", quotient_float);

	// Cast number1_int as a floating point value and divide by number2_int, print result as floating point
	quotient_float = ((double)number1_int) / number2_int;
	printf("The floating point result of number1_int cast to a floating point type and divided by number2_int is %lf.\n", quotient_float);

	// Try to mod number1_float by number2_float
	// int modulus = number1_float % number2_float;		<-- this will not compile because the modulus operator requires two integral type operands
	int modulus = (int)number1_float % (int)number2_float;
	printf("The result of number1_float modulo number2_float is %d once both floating point numbers have been explicitly cast to integers.\n", modulus);

	// Determine if number1_int and number2_int are even or odd. Print 0 if even and 1 if odd. Do not use conditional logic.
	int number1_odd = number1_int % 2;
	int number2_odd = number2_int % 2;
	printf("Is number1_int even or odd? 0 if even, 1 if odd: %d\n", number1_odd);
	printf("Is number2_int even or odd? 0 if even, 1 if odd: %d\n", number2_odd);

	// Gets integer inputs for resistance and current to calculate voltage.
	int current = 0, resistance = 0, voltage = 0;
	printf("Please provide integer values for current and resistance for Ohm's Law calculation: ");
	scanf("%d%d", &current, &resistance);
	voltage = current * resistance;
	printf("The voltage in accordance with Ohm's Law, V = IR = %d.\n", voltage);


	// Gets integer inputs for resistance and voltage to calculate power.
	int power = 0;
	resistance = 0;
	voltage = 0;
	printf("Please provide integer values for voltage and resistance for Joule's Law calculation: ");
	scanf("%d%d", &voltage, &resistance);
	power = voltage * voltage / resistance;
	printf("The Power according to Joule's Law, P = V^2 / R, is %d.\n", power);


	// Gets inputs for various values to compute the given polynomial equation.
	// Note that not all the inputs are collected at once: when many inputs are needed,
	// prompting the user for them all at once becomes confusing and vague very quickly.
	// Use math.h library function pow() to avoid needing to multiply a value by itself repeatedly for exponents.
	int aVal = 0, bVal = 0, cVal = 0, dVal = 0, xVal = 0, yVal = 0;
	printf("The polynomial equation y = 3ax^3 + (1/4)bx^2 + 10 * cx + (-5) * d is to be evaluated.\n");
	printf("Please provide an integer input for a: ");
	scanf("%d", &aVal);
	printf("Please provide an integer input for b: ");
	scanf("%d", &bVal);
	printf("Please provide an integer input for c: ");
	scanf("%d", &cVal);
	printf("Please provide an integer input for d: ");
	scanf("%d", &dVal);
	printf("Please provide an integer input for x: ");
	scanf("%d", &xVal);
	yVal = (3 * aVal * pow(xVal, 3)) + (((double)1) / 4) * bVal* pow(xVal, 2) + 10 + cVal * xVal + (-5) * dVal;
	printf("The result of the polynomial equation evaluation as an integer is y = %d.\n\n\n", yVal);


	// Gets a floating point input for radius to compute the circumference of a circle.
	// PI is defined as a constant at the top of the file to improve readability and minimize errors.
	double circumference = 0, radius = 0;
	printf("For calculating the circumference of a circle, please provide a floating point input for the radius: ");
	scanf("%lf", &radius);
	circumference = 2 * PI * radius;
	printf("The circumference of the circle is %lf.\n\n\n", circumference);
}