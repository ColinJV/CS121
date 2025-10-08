#include "header.h"

void runTaskTwo(void) {
	Game_info newGame = { 0,0,0 };
	int continuePlaying = 1;
	do {
		play2PlayerGame(&newGame);
		continuePlaying = promptToPlayAgain();
	} while (continuePlaying);
}

void play2PlayerGame(Game_info* newGame) {
	Cell board[3][3];
	initGameBoard(board);

	int player = 0, turns = 0, victory = 0, winner = 0;
	while (turns < 9 && !victory) {
		system("cls");
		displayPlayersTurn(player);
		playerTurn(player++, board);
		checkForVictory(board, &victory, &winner);
		displayBoard(board);
		++turns;
		system("pause");
	}
	modifyGameStats(newGame, winner);
}

void initGameBoard(Cell board[][NUM_ROWS]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j].location.row = i + 1;
			board[i][j].location.column = j + 1;
			board[i][j].occupied = 0;
			board[i][j].symbol = ' ';
		}
	}
}

void playerTurn(int player, Cell board[][NUM_ROWS]) {
	Coordinate target = { 0,0 };
	do {
		promptForCoordinateInput();
		target = getCoordinateInput();
		if (!targetIsValid(target, board)) {
			printf("The target coordinate is already occupied. Please enter another.\n");
		}
	} while (!targetIsValid(target, board));
	markCell(player, board, target);
}

static void promptForCoordinateInput(void) {
	printf("Please enter a row to target, followed by a column, between 1 and 3.\n");
}

Coordinate getCoordinateInput(void) {
	int rowInput = 0, columnInput = 0;
	do {
		scanf("%d", &rowInput);
		scanf("%d", &columnInput);
		if (rowInput < 1 || rowInput > 3 || columnInput < 1 || columnInput > 3) {
			printf("The selection is outside of valid range. Please enter another.\n");
		}
	} while (rowInput < 1 || rowInput > 3 || columnInput < 1 || columnInput > 3);
	Coordinate newCoordinate = { rowInput, columnInput };
	return(newCoordinate);
}

int targetIsValid(Coordinate target, Cell board[][NUM_ROWS]) {
	int valid = 0;
	if (board[target.row - 1][target.column - 1].occupied == 0) {
		valid = 1;
	}
	return(valid);
}

void markCell(int player, Cell board[][NUM_ROWS], Coordinate target) {
	board[target.row - 1][target.column - 1].occupied = 1;
	if (player % 2 == 0) {
		board[target.row - 1][target.column - 1].symbol = 'X';
	}
	else {
		board[target.row - 1][target.column - 1].symbol = 'O';
	}
}

void displayPlayersTurn(int player) {
	if (player % 2 == 0) {
		printf("It is Player 1's turn.\n");
	}
	else {
		printf("It is Player 2's turn.\n");
	}
}

void checkForVictory(Cell board[][NUM_ROWS], int* victory, int* winner) {
	int i = 0;
	while (i < 3 && !(*victory)) {
		checkRowForThree(board, victory, winner, i);
		checkColumnForThree(board, victory, winner, i);
		++i;
	}
	checkDiagonals(board, victory, winner);
}

void checkRowForThree(Cell board[][NUM_ROWS], int* victory, int* winner, int row) {
	if (board[row][0].symbol == board[row][1].symbol &&
		board[row][0].symbol == board[row][2].symbol &&
		board[row][0].symbol != ' ') {
		*victory = 1;
		if (board[row][0].symbol == 'X') {
			*winner = 1;
		}
		else if (board[row][0].symbol == 'O') {
			*winner = 2;
		}
	}
}

void checkColumnForThree(Cell board[][NUM_ROWS], int* victory, int* winner, int col) {
	if (board[0][col].symbol == board[1][col].symbol &&
		board[0][col].symbol == board[2][col].symbol &&
		board[0][col].symbol != ' ') {
		*victory = 1;
		if (board[0][col].symbol == 'X') {
			*winner = 1;
		}
		else if (board[0][col].symbol == 'O') {
			*winner = 2;
		}
	}
}

void checkDiagonals(Cell board[][NUM_ROWS], int* victory, int* winner) {
	if (board[0][0].symbol == board[1][1].symbol &&
		board[0][0].symbol == board[2][2].symbol &&
		board[0][0].symbol != ' ') {
		*winner = 1;
		if (board[0][0].symbol == 'X') {
			*winner = 1;
		}
		else if (board[0][0].symbol == 'O') {
			*winner = 2;
		}
	}
	else if (board[0][2].symbol == board[1][1].symbol &&
		board[0][2].symbol == board[2][0].symbol &&
		board[0][2].symbol != ' ') {
		*winner = 1;
		if (board[0][2].symbol == 'X') {
			*winner = 1;
		}
		else if (board[0][2].symbol == 'O') {
			*winner = 2;
		}
	}
}

void displayBoard(Cell board[][NUM_ROWS]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf(" ");
			printf("%c", board[i][j].symbol);
			if (j != 2) {
				printf(" |");
			}
		}
		if (i != 2) {
			printf("\n___________\n");
		}
	}
	printf("\n\n");
}

void modifyGameStats(Game_info* newGame, int winner) {
	newGame->totalGamesPlayed++;
	if (winner == 1) {
		newGame->wins++;
	}
	else {
		newGame->losses++;
	}
}

int promptToPlayAgain(void) {
	int input = 0;
	printf("Would you like to play again?\n");
	scanf("%d", &input);
	return(input);
}