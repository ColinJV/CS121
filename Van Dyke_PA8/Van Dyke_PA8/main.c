/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA8
* Date: December 5, 2023
* Description: This program implements the required six functions
* listed in the PA8.pdf document. Main() contains declarations of
* variables and puts() or printf() calls that are helpful for testing
* the functions and displaying results.
******************************************************************/

#include "Header.h"

int main(void) {
	srand((unsigned int)time(NULL));

	// This section tests my_str_n_cat() using testSource and testDestination.
	// Ensure testDestination has sufficient memory allocated for concatenation from testSource.
	
	char* testSource = "Riposte.";
	char testDestination[50] = "Engarde. Pirouette. Parry.";

	puts(testSource);
	puts(testDestination);

	my_str_n_cat(testDestination, testSource, 5);

	puts(testDestination);

	// This section tests binary_search() with an array of 30 elements and target value 17

	int sortedList[30] = { 0 };

	initializeList(sortedList, 30);
	sortList(sortedList, 30);
	printf("Target Index: %d\n\n", binary_search(sortedList, 17, 30));

	// This section tests bubble_sort() with an array of pointers to strings below
	// puts() calls before and after sort to verify functionality

	char* strings[] = { "This is a string.", "I prefer alternate notation.", 
		"Zis string goes at ze bottom.", "CptS 121 has been fun.", 
		"My PA5 still isn't graded.", "San Diego is nice this time of year.", 
		"Silly Putty.", "Elden Ring Randomizer is fun.", 
		"World of Warcraft destroyed my high school GPA." };
	int index = 0;
	
	while (index < 9) {
		puts(strings[index]);
		++index;
	}
	
	bubble_sort(&strings, 9);

	for (index = 0; index < 9; ++index) {
		puts(strings[index]);
	}

	// This section tests is_palindrome() using the strings declared

	char* first = "race car",
		* second = "sir i demand i am a maid named iris",
		* third = "tattarrattat";
	int firstIsPalindrome = 0,
		secondIsPalindrome = 0,
		thirdIsPalindrome = 0;

	puts(first);
	firstIsPalindrome = is_palindrome(first, 8);
	printf("Is Palindrome? %d\n", firstIsPalindrome);
	puts(second);
	secondIsPalindrome = is_palindrome(second, 35);
	printf("Is Palindrome? %d\n", secondIsPalindrome);
	puts(third);
	thirdIsPalindrome = is_palindrome(third, 12);
	printf("Is Palindrome? %d\n", thirdIsPalindrome);

	// This section tests sum_primes() using three unsigned integers

	unsigned int firstPrimeTester = 72,
		secondPrimeTester = 169,
		thirdPrimeTester = 18;

	printf("First Number: %u   Sum of Primes: %u\n", firstPrimeTester, sum_primes(firstPrimeTester));
	printf("Second Number: %u   Sum of Primes: %u\n", secondPrimeTester, sum_primes(secondPrimeTester));
	printf("Third Number: %u   Sum of Primes: %u\n", thirdPrimeTester, sum_primes(thirdPrimeTester));

	// This section tests maximum_occurrences()
	// In the absence of more specific instructions on how
	// to associate array elements of arrayOccurrences[] with a specific
	// character value, I declared an array of length 128, which encompasses
	// all alphanumeric and whitespace characters. The element of arrayOccurrences[]
	// at index n represents information for the character with ASCII value n, functionally
	// turning the array of Occurrences into a frequency table.

	char* maxOccurrencesString = "The quick brown fox jumps over the lazy dog and this string contains no punctuation and only 1 capital letter",
		mostFrequentCharacter = '\0';
	int maxOccurrences = 0;
	Occurrences arrayOccurrences[128] = { 0, 0.0 };

	maximum_occurrences(maxOccurrencesString, arrayOccurrences, &maxOccurrences, &mostFrequentCharacter);
	printf("The most frequent character is '%c'.\n", mostFrequentCharacter);
	printf("The character occurs %d	times.\n", maxOccurrences);

	return(0);
}