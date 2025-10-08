#include "header.h"

void runTaskTwo(void) {
	testMyStrCpy();
	testMyStrCat();
	testMyStrCmp();
	testMyStrLen();
}

char* my_strcpy(char* destination, const char* source) {
	int i = 0;
	while (source[i] != 0) {
		destination[i] = source[i];
		++i;
	}
	destination[i] = source[i];
	return(destination);
}

void testMyStrCpy(void) {
	char testString[100] = "I came here to chew bubble gum and write software, and I'm all out of gum.";

	printf("Testing my_strcpy()...\nSource string: ");
	printString(testString);

	char destination[100] = "";

	printf("Running my_strcpy()...\n");
	my_strcpy(destination, testString);

	printf("Printing formerly empty string...\nDestination string: ");
	printString(destination);
}

char* my_strcat(char* destination, const char* source) {
	int i = 0, j = 0;
	
	while (destination[i] != 0) {
		++i;
	}

	while (source[j] != 0) {
		destination[i++] = source[j++];
	}

	destination[i] = source[j];
	return(destination);
}

void testMyStrCat(void) {
	char testString[100] = "I came here to chew bubble gum and write software";
	char appendThisString[100] = ", and I'm all out of gum.";

	printf("Testing my_strcat()...\nDestination string: ");
	printString(testString);
	printf("String to be appended to above: ");
	printString(appendThisString);

	printf("Running my_strcat()...\n");
	char* concatenatedString = my_strcat(testString, appendThisString);

	printf("Printing original test string: ");
	printString(testString);

	printf("Printing new string from my_strcat() return: ");
	printString(concatenatedString);
}

int my_strcmp(const char* string1, const char* string2) {
	int i = 0, stringsAreNotIdentical = 0;

	while ((string1[i] != 0 || string2[i] != 0) && !stringsAreNotIdentical) {
		if (string1[i] < string2[i]) {
			stringsAreNotIdentical = -1;
		}
		else if (string1[i] > string2[i]) {
			stringsAreNotIdentical = 1;
		}
		++i;
	}

	return(stringsAreNotIdentical);
}

void testMyStrCmp(void) {
	char testString1[100] = "I came here to chew bubble gum and write software, and I'm all out of gum.";
	char testString2[50] = "I came here to";
	char testString3[50] = "I love Elden Ring.";

	printf("String 1: ");
	printString(testString1);
	printf("String 2: ");
	printString(testString2);
	printf("String 3: ");
	printString(testString3);

	printf("Testing my_strcmp() comparing String 1 with String 1...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString1, testString1));

	printf("Testing my_strcmp() comparing String 1 with String 2...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString1, testString2));

	printf("Testing my_strcmp() comparing String 1 with String 3...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString1, testString3));

	printf("Testing my_strcmp() comparing String 2 with String 1...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString2, testString1));

	printf("Testing my_strcmp() comparing String 2 with String 2...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString2, testString2));

	printf("Testing my_strcmp() comparing String 2 with String 3...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString2, testString3));

	printf("Testing my_strcmp() comparing String 3 with String 1...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString3, testString1));

	printf("Testing my_strcmp() comparing String 3 with String 2...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString3, testString2));

	printf("Testing my_strcmp() comparing String 3 with String 3...\n");
	printf("Return of my_strcmp(): %d\n", my_strcmp(testString3, testString3));
}

int my_strlen(const char* targetString) {
	int length = 0;
	
	while (targetString[length] != 0) {
		++length;
	}

	return(length);
}

void testMyStrLen(void) {
	char testString1[100] = "I came here to chew bubble gum and write software, and I'm all out of gum.";
	char testString2[50] = "I came here to";
	char testString3[50] = "I love Elden Ring.";
	char testString4[10] = "";

	printf("String 1: ");
	printString(testString1);
	printf("String 2: ");
	printString(testString2);
	printf("String 3: ");
	printString(testString3);
	printf("String 4 is the empty string.\n");

	printf("Testing my_strlen() on String 1: %d\n", my_strlen(testString1));
	printf("Testing my_strlen() on String 2: %d\n", my_strlen(testString2));
	printf("Testing my_strlen() on String 3: %d\n", my_strlen(testString3));
	printf("Testing my_strlen() on String 4: %d\n", my_strlen(testString4));
}