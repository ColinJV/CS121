#include "header.h"

void runTaskFour(void) {
	char hangmanWord[20] = { 'p','r','o','s','t','r','a','t','i','o','n' };
	char maskingArray[20] = { 0 };
	initializeMaskingArray(maskingArray, hangmanWord);

	int won = 0, tooManyGuesses = 0, wrongGuesses = 0;

	while (!won && !tooManyGuesses) {
		char guess = getUserGuess(maskingArray);
		int guessExists = guessIsInWord(guess, hangmanWord);
		if (guessExists) {
			revealGuess(guess, maskingArray, hangmanWord);
			if (!gameShouldContinue(maskingArray)) {
				won = 1;
			}
		}
		else {
			++wrongGuesses;
			if (wrongGuesses > 7 && !won) {
				tooManyGuesses = 1;
			}
		}
	}
	displayGameResult(hangmanWord, won);
}

void initializeMaskingArray(char* maskingArray, char* hangmanWord) {
	int index = 0;
	while (hangmanWord[index] != 0) {
		maskingArray[index] = '*';
		++index;
	}
}

char getUserGuess(char* maskingArray) {
	char guess = 0;
	int index = 0;
	while (maskingArray[index] != 0) {
		printf("%c", maskingArray[index]);
		++index;
	}
	printf("\nPlease enter a letter to guess.\n");
	scanf(" %c", &guess);
	return(guess);
}

int guessIsInWord(char guess, char* hangmanWord) {
	int guessExists = 0, index = 0;

	while (hangmanWord[index] != 0 && !guessExists) {
		if (guess == hangmanWord[index]) {
			guessExists = 1;
		}
		++index;
	}

	return(guessExists);
}

void revealGuess(char guess, char* maskingArray, char* hangmanWord) {
	int index = 0;
	while (hangmanWord[index] != 0) {
		if (hangmanWord[index] == guess) {
			maskingArray[index] = guess;
		}
		++index;
	}
}

int gameShouldContinue(char* maskingArray) {
	int index = 0, asteriskFound = 0;
	while (maskingArray[index] != 0) {
		if (maskingArray[index] == '*') {
			asteriskFound = 1;
		}
		++index;
	}
	return(asteriskFound);
}

void displayGameResult(char* hangmanWord, int gameWon) {
	int index = 0;
	if (gameWon == 1) {
		printf("You've won! You guessed the word ");
		while (hangmanWord[index] != 0) {
			printf("%c", hangmanWord[index]);
			++index;
		}
		printf(".\n");
	}
	else {
		printf("You lose! The word was ");
		while (hangmanWord[index] != 0) {
			printf("%c", hangmanWord[index]);
			++index;
		}
		printf(".\n");
	}
}