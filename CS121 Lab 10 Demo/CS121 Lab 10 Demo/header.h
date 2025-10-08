#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5
#define MAX_SIZE 200
#define NUM_ROWS 3

typedef struct coordinate {
	int row;
	int column;
} Coordinate;

typedef struct cell {
	int occupied;
	char symbol;
	Coordinate location;
} Cell;

typedef struct game_info {
	int wins;
	int losses;
	int totalGamesPlayed;
} Game_info;

void runTaskOne(void);
void generate20RandomSentences(char* article[], char* noun[], char* verb[], char* preposition[], char sentence[][MAX_SIZE]);
void generateRandomSentence(char* article[], char* noun[], char* verb[], char* preposition[], char* sentence, int sentenceNumber);
void putWordInSentence(char* word[], char* sentence);
void capitalizeFirstLetter(char* sentence);
void addBlankSpace(char* sentence);
void addPunctuation(char* sentence, int sentenceNumber);
void displaySentences(char sentence[][MAX_SIZE]);

void runTaskTwo(void);
void play2PlayerGame(Game_info* newGame);
void initGameBoard(Cell gameBoard[][NUM_ROWS]);
void playerTurn(int player, Cell gameBoard[][NUM_ROWS]);
static void promptForCoordinateInput(void);
Coordinate getCoordinateInput(void);
int targetIsValid(Coordinate target, Cell board[][NUM_ROWS]);
void markCell(int player, Cell board[][NUM_ROWS], Coordinate target);
void displayPlayersTurn(int player);
void checkForVictory(Cell board[][NUM_ROWS], int* victory, int* winner);
void checkRowForThree(Cell board[][NUM_ROWS], int* victory, int* winner, int row);
void checkColumnForThree(Cell board[][NUM_ROWS], int* victory, int* winner, int col);
void checkDiagonals(Cell board[][NUM_ROWS], int* victory, int* winner);
void displayBoard(Cell board[][NUM_ROWS]);
void modifyGameStats(Game_info* newGame, int winner);