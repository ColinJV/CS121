#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_DISKS 4
#define NUMBER_POSTS 3
#define MAX_DISKS 20

void runTaskOne(void);
void printReverseStringRecursively(char* targetString);
void actuallyReverseTheString(char* targetString, int first, int last);

void runTaskTwo(void);
int computeDigitSumRecursively(int input);

void runTaskThree(void);
void generateMazeRandomly(char maze[][8]);
void displayMaze(char maze[][8]);
int hasBeenVisited(int visited[][8], int row, int column);
int solveMaze(char maze[][8], int visited[][8], int startingRow, int startingColumn);
int isValidMove(char maze[][8], int visited[][8], int row, int column);
int moveIsInBounds(int row, int column);

void initializePosts(int posts[][NUMBER_POSTS]);
void displayRules(void);
void displayPosts(int posts[][NUMBER_POSTS]);
void moveDisk(int posts[][NUMBER_POSTS], int source, int destination);
void solveHanoi(int posts[][NUMBER_POSTS], int numberOfDisks, int source, int destination, int helper);
void runTaskFour(void);