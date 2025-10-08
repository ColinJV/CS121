#include "header.h"

void runTaskOne(void) {
	char* article[ARRAY_SIZE] = { "the", "a", "one", "some", "any" };
	char* noun[ARRAY_SIZE] = { "boy", "girl", "dog", "town", "car" };
	char* verb[ARRAY_SIZE] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[ARRAY_SIZE] = { "to", "from", "over", "under", "on" };
	char sentence[20][MAX_SIZE] = { 0 };

	generate20RandomSentences(article, noun, verb, preposition, sentence);
	displaySentences(sentence);
}

void generate20RandomSentences(char* article[], char* noun[], char* verb[], char* preposition[], char sentence[][MAX_SIZE]) {
	int i = 0;
	while (i < 20) {
		generateRandomSentence(article, noun, verb, preposition, sentence[i], i);
		++i;
	}
}

void generateRandomSentence(char* article[], char* noun[], char* verb[], char* preposition[], char* sentence, int sentenceNumber) {
	putWordInSentence(article, sentence);
	capitalizeFirstLetter(sentence);
	addBlankSpace(sentence);
	putWordInSentence(noun, sentence);
	addBlankSpace(sentence);
	putWordInSentence(verb, sentence);
	addBlankSpace(sentence);
	putWordInSentence(preposition, sentence);
	addBlankSpace(sentence);
	putWordInSentence(article, sentence);
	addBlankSpace(sentence);
	putWordInSentence(noun, sentence);
	addPunctuation(sentence, sentenceNumber);
}

void putWordInSentence(char* word[], char* sentence) {
	int index = rand() % 5;
	strncat(sentence, word[index], MAX_SIZE - strnlen(sentence, MAX_SIZE));
}

void capitalizeFirstLetter(char* sentence) {
	sentence[0] = sentence[0] - 32;
}

void addBlankSpace(char* sentence) {
	strncat(sentence, " ", MAX_SIZE - strnlen(sentence, MAX_SIZE));
}

void addPunctuation(char* sentence, int sentenceNumber) {
	if (sentenceNumber == 19) {
		strncat(sentence, "!", MAX_SIZE - strnlen(sentence, MAX_SIZE));
	}
	else {
		strncat(sentence, ".", MAX_SIZE - strnlen(sentence, MAX_SIZE));
	}
}

void displaySentences(char sentence[][MAX_SIZE]) {
	int sentenceNumber = 0;
	while (sentenceNumber < 20) {
		puts(sentence[sentenceNumber]);
		++sentenceNumber;
	}
}