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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef struct occurrences {
	int numOccurrences;
	double frequency;
} Occurrences;

/*************************************************************
* Function: my_str_n_cat()									*
* Date Created: 12/5/2023									*
* Date Last Modified: 12/5/2023								*
* Description: Copies at most num characters from the source*
* string to the end of the destination string. If the fctn	*
* encounters a null character before reaching num characters*
* it ends concatenation.									*
* Input parameters:	char *source, int num					*
* Output parameters: char *destination						*
* Returns: void												*
* Preconditions: strlen(destination) + num is less than the	*
* number of characters allocated in memory for *destination.*
* Postconditions: None										*
*************************************************************/
void my_str_n_cat(char* destination, char* source, int num);

/*************************************************************
* Function: binary_search()									*
* Date Created: 12/5/2023									*
* Date Last Modified: 12/5/2023								*
* Description: Conducts a binary search through a sorted	*
* integer array for a target value. Returns the index where	*
* the target value is found, or if not found returns -1.	*
* Input parameters:	int *sortedList, int targetValue, int	*
* sizeOfList												*
* Output parameters: none									*
* Returns: int targetIndex									*
* Preconditions: int *sortedList is actually sorted			*
* Postconditions: None										*
*************************************************************/
int binary_search(int* sortedList, int targetValue, int sizeOfList);

/*************************************************************
* Function: initializeList()								*
* Date Created: 12/5/2023									*
* Date Last Modified: 12/5/2023								*
* Description: I wrote this to fill a list with values		*
* so I could test binary_search()							*
* Input parameters:	int size								*
* Output parameters: int *list								*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
void initializeList(int* list, int size);

/*************************************************************
* Function: sortList()										*
* Date Created: 12/5/2023									*
* Date Last Modified: 12/5/2023								*
* Description: I wrote this to sort a list of int values	*
* so I could test binary_search()							*
* Input parameters:	int size								*
* Output parameters: int *list								*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
void sortList(int* list, int size);

/*************************************************************
* Function: bubble_sort()									*
* Date Created: 12/6/2023									*
* Date Last Modified: 12/6/2023								*
* Description: Traverses through an array of pointers to	*
* strings and checks the first character of the string. If	*
* the first character of a string pointed to is less than	*
* the item to its left, the function swaps the values of the*
* pointers to those strings. This process continues until	*
* array is sorted.											*
* Input parameters:	int numberOfStrings						*
* Output parameters: char *strings[]						*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
void bubble_sort(char* strings[], int numberOfStrings);

/*************************************************************
* Function: is_palindrome()									*
* Date Created: 12/6/2023									*
* Date Last Modified: 12/6/2023								*
* Description: Recursively determines whether a given string*
* is a palindrome. If it encounters a whitespace character	*
* it skips to the next character (or, if the whitespace is	*
* at the end, moves one character left for comparison).		*
* Returns 0 if the string is not a palindrome, 1 if it is.	*
* Input parameters:	int lengthOfString						*
* Output parameters: char *string							*
* Returns: int isPalindrome (0 or 1)						*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
int is_palindrome(char* string, int lengthOfString);

/*************************************************************
* Function: sum_primes()									*
* Date Created: 12/6/2023									*
* Date Last Modified: 12/6/2023								*
* Description: Recursively sums all prime numbers between 2	*
* and the input number num.									*
* Input parameters:	unsigned int num						*
* Output parameters: none									*
* Returns: int sum											*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
int sum_primes(unsigned int num);

/*************************************************************
* Function: maximum_occurrences()							*
* Date Created: 12/6/2023									*
* Date Last Modified: 12/6/2023								*
* Description: Accepts a pointer to a string and counts the	*
* number of times any given character appears in the string,*
* storing this information in an array of Occurrences.		*
* Returns as pointers the most common character and the		*
* number of times that character appears.					*
* Input parameters:	char *string							*
* Output parameters: Occurrences *arrayOccurrences,			*
* int *maxOccurrences, char *mostFrequentCharacter			*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/
void maximum_occurrences(char* string, Occurrences* arrayOccurrences, int* maxOccurrences, char* mostFrequentCharacter);