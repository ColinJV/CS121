#include "header.h"

void runTaskFour(void) {
	int randomNumber = generateRandomNumberInRange(100);

	int userGuess = 0, guessCount = 0, found = 0;
	while (!found) {
		userGuess = getUserInputInRange();
		found = compareGuessToNumber(userGuess, randomNumber);
		guessCount++;
	}
	displayGuessCount(guessCount);
}

void displayGuessCount(int guessCount) {
	printf("You made %d total guesses.\n", guessCount);
}

int generateRandomNumberInRange(int range) {
	int randomNumber = rand() % (range + 1);

	if (coinFlip()) {
		randomNumber *= -1;
	}

	return(randomNumber);
}

int coinFlip(void) {
	return(rand() % 2);
}

int getUserInputInRange(void) {
	int userInput = -200;
	while (inputIsInvalid(userInput)) {
		printf("Please guess an integer between -100 and 100.\n");
		scanf("%d", &userInput);
		if (inputIsInvalid(userInput)) {
			printf("The input value is invalid. Please try again.\n");
		}
	}
	return(userInput);
}

static int inputIsInvalid(int input) {
	return (input < -100 || input > 100);
}

int compareGuessToNumber(int userGuess, int randomNumber) {
	int found = 0;
	if (userGuess == randomNumber) {
		printf("Your guess is correct.\n");
		found = 1;
	}
	else if (userGuess > randomNumber) {
		printf("Your guess is high.\n");
	}
	else {
		printf("Your guess is low.\n");
	}
	return(found);
}