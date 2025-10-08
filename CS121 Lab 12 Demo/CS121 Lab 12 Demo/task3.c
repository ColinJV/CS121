#include "header.h"

void runTaskThree(void) {
	char maze[8][8] = { 0 };
	int visited[8][8] = { 0 };

	generateMazeRandomly(maze);
	displayMaze(maze);

	int solved = solveMaze(maze, visited, 0, 1);
	if (solved == 0) {
		printf("No path to the end exists.\n");
	}
}

void generateMazeRandomly(char maze[][8]) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int coinFlip = rand() % 4;
			if (!coinFlip) {
				maze[i][j] = 'X';
			}
			else maze[i][j] = ' ';
		}
	}
	maze[0][1] = ' ';
	maze[7][7] = ' ';
}

void displayMaze(char maze[][8]) {
	printf("   0  1  2  3  4  5  6  7 \n");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", i);
		for (int j = 0; j < 8; ++j) {
			printf(" %c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int hasBeenVisited(int visited[][8], int row, int column) {
	return(visited[row][column]);
}

int solveMaze(char maze[][8], int visited[][8], int startingRow, int startingColumn) {
	int solved = 0;
	visited[startingRow][startingColumn] = 1;

	if (startingRow == 7 && startingColumn == 7) {
		solved = 1;
	}
	if (isValidMove(maze, visited, startingRow, startingColumn + 1) && !solved) {
		solved = solveMaze(maze, visited, startingRow, startingColumn + 1);
		if (solved) {
			printf("Move from (%d, %d) to (%d, %d).\n", startingRow, startingColumn, startingRow, startingColumn + 1);
		}
	}
	if (isValidMove(maze, visited, startingRow + 1, startingColumn) && !solved) {
		solved = solveMaze(maze, visited, startingRow + 1, startingColumn);
		if (solved) {
			printf("Move from (%d, %d) to (%d, %d).\n", startingRow, startingColumn, startingRow + 1, startingColumn);
		}
	}
	if (isValidMove(maze, visited, startingRow, startingColumn - 1) && !solved) {
		solved = solveMaze(maze, visited, startingRow, startingColumn - 1);
		if (solved) {
			printf("Move from (%d, %d) to (%d, %d).\n", startingRow, startingColumn, startingRow, startingColumn - 1);
		}
	}
	if (isValidMove(maze, visited, startingRow - 1, startingColumn) && !solved) {
		solved = solveMaze(maze, visited, startingRow - 1, startingColumn);
		if (solved) {
			printf("Move from (%d, %d) to (%d, %d).\n", startingRow, startingColumn, startingRow - 1, startingColumn);
		}
	}
	if (!solved) {
		visited[startingRow][startingColumn] = 0;
	}

	return solved;
}

int isValidMove(char maze[][8], int visited[][8], int row, int column) {
	int valid = 0;
	if (maze[row][column] == ' ' && 
		!hasBeenVisited(visited, row, column) &&
		moveIsInBounds(row, column)) {
		valid = 1;
	}
	return(valid);
}

int moveIsInBounds(int row, int column) {
	return(row < 8 && column < 8 && row >= 0 && column >= 0);
}