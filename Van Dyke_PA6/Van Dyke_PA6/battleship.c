/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA6
* Date: October 30, 2023
* Description: This program implements the popular game Battleship
* according to the traditional rules. Player 1 is always the user,
* Player 2 is always the Computer Played User. When a game is
* initiated, Player 1 may manually place ships or have them randomly
* placed. The game randomly chooses who will go first. Each player
* selects a coordinate on a 2-dimensional board to fire upon. If
* the other player has placed a ship on this grid space, the shot
* hits. After firing on a grid space, it may not be fired on again.
* The game continues until one player has sunk all the enemy ships
* by hitting each ship a certain number of times that correspond to
* its size. The game outputs data for each turn and overall game
* statistics at the conclusion of the game to a log file. Game may
* be played again after each game concludes. Log is not overwritten
* by starting subsequent game rounds.
******************************************************************/

#include "battleship.h"


/*************************************************************
* Function: display_main_menu()								*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Displays a menu of options to display rules,	*
* play the game, or quit.									*
* Input parameters: none									*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_main_menu(void) {
	printf("1. Display Game Rules\n");
	printf("2. Play Game\n");
	printf("3. Quit\n\n");
}



/*************************************************************
* Function: display_splash_screen()							*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/31/2023                            *
* Description: Displays "BATTLESHIP" in ASCII art generated *
* by textkool.com/en/ascii-art-generator					*
* Input parameters: void									*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_splash_screen(void) {
	printf("       ______   ___   _____  _____  _      _____  _____  _   _  _____ ______  \n");
	printf("       | ___ \\ / _ \\ |_   _||_   _|| |    |  ___|/  ___|| | | ||_   _|| ___ \\ \n");
	printf("       | |_/ // /_\\ \\  | |    | |  | |    | |__  \\ `--. | |_| |  | |  | |_/ / \n");
	printf("       | ___ \\|  _  |  | |    | |  | |    |  __|  `--. \\|  _  |  | |  |  __/  \n");
	printf("       | |_/ /| | | |  | |    | |  | |____| |___ /\\__/ /| | | | _| |_ | |     \n");
	printf("       \\____/ \\_| |_/  \\_/    \\_/  \\_____/\\____/ \\____/ \\_| |_/ \\___/ \\_|     \n");
}



/*************************************************************
* Function: display_game_rules()	                        *
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/31/2023                            *
* Description: Prints the rules of Battleship to the screen	*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: User requested rules to be displayed       *
* Postconditions: NA                                        *
*************************************************************/

void display_game_rules(void) {
	printf("Rules of Battleship:\n");
	printf("For this implementation of Battleship, you are Player 1 and the computer is always Player 2.\n");
	printf("Each player has five ships. Each ship may be differentiated by its size, or the number of cells it\n");
	printf("takes up on the game board. The Carrier has 5 cells, the Battleship has 4 cells, the Cruiser has 3\n");
	printf("cells, the Submarine has 3 cells, and the Destroyer has 2 cells. Each player places their ships on\n");
	printf("the game board either vertically or horizontally, and the game begins. Each player targets one cell\n");
	printf("on the game board and fires a shot. If the other player has a ship that occupies that space, then\n");
	printf("the shot hits, and the enemy ship loses 1 point of health. If the other player does not have a ship\n");
	printf("occupying that space, the shot misses. After a player shoots, it becomes the other player's turn,\n");
	printf("and the process repeats over again. When a ship's health reaches 0 (i.e., when every cell the ship\n");
	printf("occupies has been hit), the ship is sunk. The game ends when a player has sunk all five of their\n");
	printf("opponent's ships.\n");
}



/*************************************************************
* Function: get_integer_input()								*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Scans for an integer input from the user and	*
* returns its value.										*
* Input parameters: void									*
* Returns: int												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int get_integer_input(void) {
	int input = 0;
	scanf("%d", &input);
	return(input);
}



/*************************************************************
* Function: clear_screen()									*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Clears the terminal.							*
* Input parameters: void									*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void clear_screen(void) {
	system("cls");
}



/*************************************************************
* Function: press_any_key()									*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Prompts the user to press any key to			*
* continue.													*
* Input parameters: void									*
* Returns: int 1											*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int press_any_key(void) {
	system("pause");
	return(1);
}



/*************************************************************
* Function: coin_flip()				                        *
* Date Created: 10/31/2023                                  *
* Date Last Modified: 10/31/2023                            *
* Description: Randomly generates a number either 0 or 1	*
* and returns the value										*
* Input parameters: void									*
* Returns: int (0 or 1)						                *
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int coin_flip(void) {
	int dice = 0;
	dice = rand() % 2;
	return(dice);
}



/*************************************************************
* Function: initialize_character_array()					*
* Date Created: 10/31/2023                                  *
* Date Last Modified: 10/31/2023                            *
* Description: Fills a character array with '~' characters	*
* Input parameters: int number_of_rows, int					*
* number_of_columns											*
* Output parameters: char array[][10]						*
* Returns: void												*
* Preconditions: A 10x10 2D character array exists			*
* Postconditions: None										*
*************************************************************/

void initialize_character_array(char array[][10], int number_of_rows, int number_of_columns) {
	int row_index = 0, column_index = 0;
	for (; row_index < number_of_rows; row_index++) {
		for (column_index = 0; column_index < number_of_columns; column_index++) {
			array[row_index][column_index] = '~';
		}
	}
}



/*************************************************************
* Function: prompt_ship_placement()							*
* Date Created: 11/01/2023                                  *
* Date Last Modified: 11/01/2023                            *
* Description: Prompts the player for an input to determine	*
* whether they want to manually place their ships or allow	*
* random placement. Returns 0 for random, 1 for manual.		*
* Input parameters: None									*
* Output parameters: None									*
* Returns: int (0 or 1)										*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int prompt_ship_placement(void) {
	char input = '\0';
	int manual = -1, valid = 0;
	do {
		printf("Would you to place your ships manually? If no, ships will be placed randomly. Y/N\n");
		scanf(" %c", &input);
		if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
			valid = 1;
		}
	} while (valid == 0);

	if (input == 'Y' || input == 'y') {
		manual = 1;
	}
	else if (input == 'N' || input == 'n') {
		manual = 0;
	}
	return(manual);
}



/*************************************************************
* Function: place_ships_manually()							*
* Date Created: 11/01/2023                                  *
* Date Last Modified: 11/01/2023                            *
* Description: Prompts the player to place each of their 5	*
* ships and checks for the validity of the locations. If	*
* placement is invalid, requests the player to choose		*
* another placement. If valid, places the ship.				*
* Input parameters:	Ship *player_ships						*
* Output parameters: char game_board[][]					*
* Returns: None												*
* Preconditions: Player has chosen to manually place ships	*
* Postconditions: None										*
*************************************************************/

void place_ships_manually(char player_board[MAX_ROWS][MAX_COLUMNS], Ship* player_ships) {
	int ships_placed = 0;
	while (ships_placed < 5) {
		int orientation = -1, starting_row = -1, starting_column = -1,
			enough_rows = 1, enough_columns = 1, valid_placement = 0,
			steps = 0;
		print_board(player_board, MAX_ROWS, MAX_COLUMNS);
		do {
			printf("For the %s, should it be placed vertically or horizontally? 1 for vertical, 0 for horizontal.\n", player_ships[ships_placed].name);
			orientation = get_integer_input();
		} while (orientation < 0 || orientation > 1);
		do {
			printf("Please select a starting row for the %s. The %s will extend down from this row if it is vertical.\n", player_ships[ships_placed].name, player_ships[ships_placed].name);
			starting_row = get_integer_input();
			if (orientation == 1) {
				enough_rows = (starting_row + player_ships[ships_placed].size <= MAX_ROWS);
			}
			printf("Please select a starting column for the %s. The %s will extend right from this row if it is horizontal.\n", player_ships[ships_placed].name, player_ships[ships_placed].name);
			starting_column = get_integer_input();
			if (orientation == 0) {
				enough_columns = (starting_column + player_ships[ships_placed].size <= MAX_COLUMNS);
			}
			valid_placement = (enough_rows && enough_columns);
			if (valid_placement) {
				// steps through array and checks for validity by scanning for anything other than '~'
				while (steps < player_ships[ships_placed].size && valid_placement) {
					if (orientation == 0) {
						if (player_board[starting_row][starting_column + steps] != '~') {
							valid_placement = 0;
						}
					}
					else if (orientation == 1) {
						if (player_board[starting_row + steps][starting_column] != '~') {
							valid_placement = 0;
						}
					}
					++steps;
				}
				steps = 0;
				//steps through array and overwrites '~'
				while (steps < player_ships[ships_placed].size && valid_placement) {
					if (orientation == 0) {
						player_board[starting_row][starting_column + steps] = player_ships[ships_placed].abbreviation;
					}
					else if (orientation == 1) {
						player_board[starting_row + steps][starting_column] = player_ships[ships_placed].abbreviation;
					}
					++steps;
				}
			}
			if (!valid_placement) {
				printf("Your selection is invalid. The ship extends out of bounds or over an existing ship. Please try again.\n");
			}

		} while (valid_placement == 0);
		++ships_placed;
	}
}



/*************************************************************
* Function: print_board()									*
* Date Created: NA			                                *
* Date Last Modified: 11/02/2023                            *
* Description: Prints the game board in a user friendly		*
* display. This function was written by Andy in class and	*
* provided on Canvas in code from October 26 lecture		*
* Input parameters: int num_rows, int num_cols,				*
* char board[][10]											*
* Output parameters: NA										*
* Returns: None												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void print_board(char board[][MAX_COLUMNS], int num_rows, int num_cols) {
	int row_index = 0, col_index = 0;

	printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (; row_index < num_rows; ++row_index)
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("|%2c ", board[row_index][col_index]);
		}
		putchar('|');
		putchar('\n');
	}
}



/*************************************************************
* Function: place_ships_randomly()							*
* Date Created: 11/02/2023                                  *
* Date Last Modified: 11/02/2023                            *
* Description: Places ships on a game board randomly.		*
* Input parameters:	Ship *ships_array						*
* Output parameters: char game_board[][]					*
* Returns: None												*
* Preconditions: Player chooses to randomly place ships or	*
* placement of CPU ships is required.						*
* Postconditions: None										*
*************************************************************/

void place_ships_randomly(char game_board[MAX_ROWS][MAX_COLUMNS], Ship* ships_array) {
	int ships_placed = 0;
	while (ships_placed < 5) {
		int orientation = -1, starting_row = -1, starting_column = -1,
			enough_rows = 1, enough_columns = 1, valid_placement = 0,
			steps = 0;
		orientation = rand() % 2;
		do {
			starting_row = rand() % 10;
			if (orientation == 1) {
				enough_rows = (starting_row + ships_array[ships_placed].size <= MAX_ROWS);
			}
			starting_column = rand() % 10;
			if (orientation == 0) {
				enough_columns = (starting_column + ships_array[ships_placed].size <= MAX_COLUMNS);
			}
			valid_placement = (enough_rows && enough_columns);
			if (valid_placement) {
				// steps through array and checks for validity by scanning for anything other than '~'
				while (steps < ships_array[ships_placed].size && valid_placement) {
					if (orientation == 0) {
						if (game_board[starting_row][starting_column + steps] != '~') {
							valid_placement = 0;
						}
					}
					else if (orientation == 1) {
						if (game_board[starting_row + steps][starting_column] != '~') {
							valid_placement = 0;
						}
					}
					++steps;
				}
				steps = 0;
				//steps through array and overwrites '~'
				while (steps < ships_array[ships_placed].size && valid_placement) {
					if (orientation == 0) {
						game_board[starting_row][starting_column + steps] = ships_array[ships_placed].abbreviation;
					}
					else if (orientation == 1) {
						game_board[starting_row + steps][starting_column] = ships_array[ships_placed].abbreviation;
					}
					++steps;
				}
			}
		} while (valid_placement == 0);
		++ships_placed;
	}
}



/*************************************************************
* Function: get_valid_player_target()						*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Gets a target coordinate from the player.	*
* Ensures the selected coordinate is in-bounds and has not	*
* previously been fired upon. Returns a valid coordinate.	*
* Input parameters:	char cpu_mirror[][10]					*
* Output parameters: None									*
* Returns: Target coordinate								*
* Preconditions: Target coordinate is declared in main()	*
* and cpu_board has ships placed on it.						*
* Postconditions: None										*
*************************************************************/

Target get_valid_player_target(char cpu_mirror[MAX_ROWS][MAX_COLUMNS]) {
	int row = -1, column = -1, valid = 0;
	do {
		do {
			printf("Please select an enemy row to target.\n");
			row = get_integer_input();
			if (row < 0 || row >= MAX_ROWS) {
				printf("Your selection is out of bounds. Please try again.\n");
			}
		} while (row < 0 || row >= MAX_ROWS);

		do {
			printf("Please select an enemy column to target.\n");
			column = get_integer_input();
			if (column < 0 || column >= MAX_COLUMNS) {
				printf("Your selection is out of bounds. Please try again.\n");
			}
		} while (column < 0 || column >= MAX_COLUMNS);

		valid = (cpu_mirror[row][column] == '~');

		if (valid == 0) {
			printf("Your selected coordinate has already been fired upon. Please try again.\n");
		}

	} while (valid == 0);

	Target coordinate = { row, column };
	return(coordinate);
}



/*************************************************************
* Function: display_target()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays a coordinate targeted by a player.	*
* Prompts the player to press any key before continuing.	*
* Input parameters:	int player, Target coordinate			*
* Output parameters: None									*
* Returns: None												*
* Preconditions: Target coordinate has been determined		*
* Postconditions: None										*
*************************************************************/

void display_target(int player, Target coordinate) {
	printf("Player %d targets enemy grid! Row %d, Column %d.\n", player, coordinate.row, coordinate.column);
	press_any_key();
	clear_screen();
}



/*************************************************************
* Function: check_shot()									*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Checks if a shot taken was a hit or miss.	*
* Input parameters:	char board[10][10], Target coordinate	*
* Output parameters: None									*
* Returns: int hit (0 or 1)									*
* Preconditions: A coordinate has been targetted, and it	*
* has not been targetted previously.						*
* Postconditions: None										*
*************************************************************/

int check_shot(char board[MAX_ROWS][MAX_COLUMNS], Target coordinate) {
	Target target_cell = coordinate;
	int hit = -1;
	hit = (board[target_cell.row][target_cell.column] != '~');
	return(hit);
}



/*************************************************************
* Function: find_which_ship()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/05/2023                            *
* Description: Determines which ship in which array has		*
* been hit.	Once found, decrements that ship's health, 		*
* increments player shots and hits, and logs which ship was *
* damaged. Returns the index of the damaged ship.			*
* Input parameters:	char enemy_board[10][10],				*
* Target coordinate, Ship *enemy_ships						* 
* Output parameters: Stats player_stats						*
* Returns: int victory (0 or 1)								*
* Preconditions: A shot taken by Player 1 or CPU has hit	*
* an enemy ship.											*
* Postconditions: None										*
*************************************************************/

int find_which_ship(char enemy_board[MAX_ROWS][MAX_COLUMNS], Target coordinate, Stats* friendly_stats,
	Ship* enemy_ships, int player, FILE* output) {
	int index = 0, found = 0;
	while ((index < NUMBER_OF_SHIPS) && !found) {
		if (enemy_ships[index].abbreviation == enemy_board[coordinate.row][coordinate.column]) {
			found = 1;
		}
		else {
			++index;
		}
	}
	++(*friendly_stats).number_of_shots;
	++(*friendly_stats).number_of_hits;
	--enemy_ships[index].health;
	log_hit_damage(player, coordinate, enemy_ships[index].name, output);
	return(index);
}



/*************************************************************
* Function: check_for_sunk()								*
* Date Created: 11/05/2023                                  *
* Date Last Modified: 11/05/2023                            *
* Description: Checks the health of a damaged ship. If		*
* health is zero, displays a message indicating the ship	*
* has been sunk, logs the event, and increments player		*
* statistic for ships sunk. The function returns a flag for	*
* whether the ship was sunk.								*
* Input parameters:	Ship *enemy_ships, int index, int player*
* Output parameters: Stats *friendly_stats, FILE *output	*
* Returns: int sunk (0 or 1)								*
* Preconditions: A shot taken by Player 1 or CPU has hit	*
* an enemy ship.											*
* Postconditions: None										*
*************************************************************/

int check_for_sunk(Ship* enemy_ships, int index, Stats* friendly_stats, int player, FILE* output){
	int sunk = 0;
	if (enemy_ships[index].health == 0) {
		sunk = 1;
		if (player == 1) {
			printf("The enemy %s has been sunk!\n", enemy_ships[index].name);
		}
		if (player == 2) {
			printf("Your %s has been sunk!\n", enemy_ships[index].name);
		}
		log_ship_sunk(player, enemy_ships[index].name, output);
		++(*friendly_stats).ships_sunk;
	}
	return(sunk);
}



/*************************************************************
* Function: check_for_victory()								*
* Date Created: 11/05/2023                                  *
* Date Last Modified: 11/05/2023                            *
* Description: Scans the health values of an array of ships.*
* If all health values are zero, a player has won, function	*
* returns 1.												*
* Input parameters:	Ship array_of_ships						*
* Output parameters: None									*
* Returns: int victory (0 or 1)								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_victory(Ship *array_of_ships) {
	int index = 0, victory = 1;
	while (index < NUMBER_OF_SHIPS) {
		if (array_of_ships[index].health != 0) {
			victory = 0;
		}
		index++;
	}
	return(victory);
}



/*************************************************************
* Function: display_hit_miss()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays a message communicating that a shot	*
* either hit or missed.										*
* Input parameters:	int hit									*
* Output parameters: None									*
* Returns: None												*
* Preconditions: Shot has been taken						*
* Postconditions: None										*
*************************************************************/

void display_hit_miss(int hit) {
	if (hit == 1) {
		printf("Hit!\n");
	}
	else {
		printf("Miss!\n");
	}
}



/*************************************************************
* Function: update_displayed_boards()						*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Updates the char arrays that act as game		*
* boards after a player action that changes what should be	*
* displayed (shot taken & hit or missed)					*
* Input parameters:	Target coordinates, int hit,			*
* int player												*
* Output parameters: char player_mirror[][10],				*
* char enemy_mirror[][10]									*
* Returns: None												*
* Preconditions: A player has shot at a grid space			*
* Postconditions: None										*
*************************************************************/

void update_displayed_boards(char player_mirror[MAX_ROWS][MAX_COLUMNS], char enemy_mirror[MAX_ROWS][MAX_COLUMNS],
	Target coordinates, int hit, int player) {
	if (player == 1) {
		if (hit == 1) {
			enemy_mirror[coordinates.row][coordinates.column] = '*';
		}
		if (hit == 0) {
			enemy_mirror[coordinates.row][coordinates.column] = 'm';
		}
	}
	else {
		if (hit == 1) {
			player_mirror[coordinates.row][coordinates.column] = '*';
		}
		if (hit == 0) {
			player_mirror[coordinates.row][coordinates.column] = 'm';
		}
	}
}



/*************************************************************
* Function: shot_miss_actions()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description:												*
* Input parameters:	Stats *friendly_stats, int player		*
* Output parameters: FILE *output							*
* Returns: void												*
* Preconditions: A shot taken by Player 1 or Player 2 hit	*
* an enemy ship.											*
* Postconditions: None										*
*************************************************************/

void shot_miss_actions(Stats *friendly_stats, int player, FILE *output) {
	++(*friendly_stats).number_of_shots;
	++(*friendly_stats).number_of_misses;
	log_miss(player, output);
}



/*************************************************************
* Function: display_interface()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays an obscured CPU board above a copy 	*
* of the player's board, creating a 2D representation of a	*
* Battleship game board.									*
* Input parameters:	char cpu_mirror, char player_mirror		*
* Output parameters: None									*
* Returns: None												*
* Preconditions: Both input char arrays have been init.		*
* Postconditions: None										*
*************************************************************/

void display_interface(char cpu_mirror[MAX_ROWS][MAX_COLUMNS], char player_mirror[MAX_ROWS][MAX_COLUMNS]) {
	print_board(cpu_mirror, MAX_ROWS, MAX_COLUMNS);
	printf("\n");
	print_board(player_mirror, MAX_ROWS, MAX_COLUMNS);
	printf("\n");
}



/*************************************************************
* Function: get_valid_cpu_target()							*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Selects a target for the CPU player to fire	*
* upon by generating random numbers betwen 0 and 9 for row	*
* and column. Returns a coordinate ordered pair.			*
* Input parameters:	char player_mirror						*
* Output parameters: None									*
* Returns: Target coordinate								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

Target get_valid_cpu_target(char player_mirror[MAX_ROWS][MAX_COLUMNS]) {
	int row = -1, column = -1, valid = 0;
	do {
		row = rand() % 10;
		column = rand() % 10;
		valid = ((player_mirror[row][column] != '*') && (player_mirror[row][column] != 'm'));
	} while (valid == 0);

	Target coordinate = { row, column };
	return(coordinate);
}



/*************************************************************
* Function: display_winner()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays a message announcing a game winner	*
* Input parameters:	int player								*
* Output parameters: None									*
* Returns: None												*
* Preconditions: victory = 1								*
* Postconditions: None										*
*************************************************************/

void display_winner(int player) {
	printf("The winner is Player %d!\n", player);
	press_any_key();
}



/*************************************************************
* Function: display_who_goes_first()						*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays a message announcing which player 	*
* goes first.												*
* Input parameters:	int player								*
* Output parameters: None									*
* Returns: None												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_who_goes_first(int player) {
	printf("Player %d will go first!\n", player);
	press_any_key();
	clear_screen();
}



/*************************************************************
* Function: display_whose_turn()							*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Displays a message announcing whose turn it	*
* is.														*
* Input parameters:	int player								*
* Output parameters: None									*
* Returns: None												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_whose_turn(int player) {
	printf("It's Player %d's turn!\n", player);
	press_any_key();
	clear_screen();
}



/*************************************************************
* Function: log_turn()										*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message relating to the turn		*
* number to the log file.									*
* Input parameters:	int turn								*
* Output parameters: FILE *output							*
* Returns: None												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void log_turn(int turn, FILE *output) {
	fprintf(output, "\nTurn #%d\n", turn);
	fprintf(output, "------------------\n");
	fflush(output);
}



/*************************************************************
* Function: log_target()									*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message containing the targeted	*
* coordinates to the log file.								*
* Input parameters:	int player, Target coordinates			*
* Output parameters: FILE *output							*
* Returns: None												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void log_target(int player, Target coordinates, FILE* output) {
	fprintf(output, "Player %d targets Row %d Column %d.\n", player, coordinates.row, coordinates.column);
	fflush(output);
}



/*************************************************************
* Function: log_hit_damage()								*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message to the log file indicating	*
* that a shot hit a ship, which ship was hit, and that it	*
* has taken damage.											*
* Input parameters:	int player, Target coordinates, char	*
* *ship_name												*
* Output parameters: FILE *output							*
* Returns: None												*
* Preconditions: A shot has hit								*
* Postconditions: None										*
*************************************************************/

void log_hit_damage(int player, Target coordinates, char *ship_name, FILE* output) {
	fprintf(output, "Player %d's shot on Row %d Column %d hits enemy %s.\n", player,
		coordinates.row, coordinates.column, ship_name);
	fprintf(output, "Enemy %s takes damage.\n", ship_name);
	fflush(output);
}



/*************************************************************
* Function: log_ship_sunk()									*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message to the log file indicating	*
* which ship has been sunk.									*
* Input parameters:	int player, char *ship_hit				*
* Output parameters: FILE *output							*
* Returns: None												*
* Preconditions: A ship has been sunk						*
* Postconditions: None										*
*************************************************************/

void log_ship_sunk(int player, char* ship_hit, FILE* output) {
	fprintf(output, "Player %d has sunk the enemy %s!\n", player, ship_hit);
	fflush(output);
}



/*************************************************************
* Function: log_victory()									*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message to the log file indicating	*
* which player has won.										*
* Input parameters:	int player								*
* Output parameters: FILE *output							*
* Returns: None												*
* Preconditions: A player has won the game					*
* Postconditions: None										*
*************************************************************/

void log_victory(int player, FILE* output) {
	fprintf(output, "Player %d has sunk all enemy ships.\n", player);
	fprintf(output, "Player %d has won the game!\n\n", player);
	fflush(output);
}



/*************************************************************
* Function: calculate_hit_percentage()						*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Casts as doubles the values for number of	*
* hits and number of shots, divides number of hits by		*
* number of shots, multiplies by 100, & assigns the result	*
* to the indirect value of the pointer to					*
* user_stats.percentage_hits.								*
* Input parameters:	Stats user_stats						*
* Output parameters: Stats user_stats						*
* Returns: void												*
* Preconditions: Game has ended								*
* Postconditions: None										*
*************************************************************/

void calculate_hit_percentage(Stats *user_stats) {
	double hits = 0.0, shots = 0.0;
	hits = (*user_stats).number_of_hits;
	shots = (*user_stats).number_of_shots;
	(*user_stats).percentage_hits = (hits / shots) * 100;
}



/*************************************************************
* Function: log_end_data()									*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs to log file user statistics for both	*
* players at the end of the game							*
* Input parameters:	Stats player_stats, Stats cpu_stats, 	*
* int game, int turn										*
* Output parameters: FILE *output							*
* Returns: void												*
* Preconditions: Game has ended								*
* Postconditions: None										*
*************************************************************/

void log_end_data(Stats player_stats, Stats cpu_stats, int game, int turn, FILE *output) {
	fprintf(output, "***End of Game %d Statistics***\n", game);
	fprintf(output, "Game %d lasted %d turns.\n", game, turn);
	fprintf(output, "Total shots fired: %d\n", player_stats.number_of_shots + cpu_stats.number_of_shots);
	fprintf(output, "Total shots hit: %d\n", player_stats.number_of_hits + cpu_stats.number_of_hits);
	fprintf(output, "Total shots missed: %d\n", player_stats.number_of_misses + cpu_stats.number_of_misses);
	fprintf(output, "Total ships sunk: %d\n\n", player_stats.ships_sunk + cpu_stats.ships_sunk);
	fprintf(output, "Player 1 Statistics:\n");
	fprintf(output, "   Number of hits: %d\n", player_stats.number_of_hits);
	fprintf(output, "   Number of misses: %d\n", player_stats.number_of_misses);
	fprintf(output, "   Number of shots: %d\n", player_stats.number_of_shots);
	fprintf(output, "   Hit percentage: %.2lf%%\n", player_stats.percentage_hits);
	fprintf(output, "   Ships sunk: %d\n", player_stats.ships_sunk);
	fprintf(output, "   Was winner: %d\n\n", player_stats.won_or_lost);
	fprintf(output, "Player 2 Statistics:\n");
	fprintf(output, "   Number of hits: %d\n", cpu_stats.number_of_hits);
	fprintf(output, "   Number of misses: %d\n", cpu_stats.number_of_misses);
	fprintf(output, "   Number of shots: %d\n", cpu_stats.number_of_shots);
	fprintf(output, "   Hit percentage: %.2lf%%\n", cpu_stats.percentage_hits);
	fprintf(output, "   Ships sunk: %d\n", cpu_stats.ships_sunk);
	fprintf(output, "   Was winner: %d\n\n", cpu_stats.won_or_lost);
	fflush(output);
}



/*************************************************************
* Function: log_miss()										*
* Date Created: 11/04/2023                                  *
* Date Last Modified: 11/04/2023                            *
* Description: Outputs a message to the log file indicating	*
* a shot missed.											*
* Input parameters:	int player								*
* Output parameters: FILE *output							*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void log_miss(int player, FILE* output) {
	fprintf(output, "Player %d's shot missed.\n", player);
	fflush(output);
}



/*************************************************************
* Function: get_valid_somewhat_smart_cpu_target()			*
* Date Created: 11/05/2023                                  *
* Date Last Modified: 11/05/2023                            *
* Description: Selects a target for the CPU player to fire	*
* upon by searching for hits that have unchecked grid spaces*
* next to them. If no grid space is found that has a hit	*
* target with no unchecked spaces next to it, selects a		*
* target by generating semirandom numbers betwen 0 and 9 	*
* for values of row and column.								*
* Input parameters:	char player_board[][10]					*
* Output parameters: FILE *output							*
* Returns: Target coordinate								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

Target get_valid_somewhat_smart_cpu_target(char player_board[][MAX_COLUMNS]) {
	int target_row = -1, target_column = -1, valid = 0, smart = 0, player_row = 0, player_column = 0, tries = 0;
	do {
		for (; player_row < MAX_ROWS && !smart; player_row++) {
			for (player_column = 0; player_column < MAX_COLUMNS && !smart; player_column++) {
				if (player_board[player_row][player_column] == '*'){
					if (!smart && player_board[player_row - 1][player_column] != '*' &&
						player_board[player_row - 1][player_column] != 'm' && player_row - 1 >= 0) {
						target_row = player_row - 1;
						target_column = player_column;
						smart = 1;
					}
					if (!smart && player_board[player_row][player_column - 1] != '*' &&
						player_board[player_row][player_column - 1] != 'm' && player_column - 1 >= 0) {
						target_row = player_row;
						target_column = player_column - 1;
						smart = 1;
					}
					if (!smart && player_board[player_row][player_column + 1] != '*' && 
						player_board[player_row][player_column + 1] != 'm' && player_column + 1 < MAX_COLUMNS) {
						target_row = player_row;
						target_column = player_column + 1;
						smart = 1;
					}
					if (!smart && player_board[player_row + 1][player_column] != '*' && 
						player_board[player_row + 1][player_column] != 'm' && player_row + 1 < MAX_ROWS) {
						target_row = player_row + 1;
						target_column = player_column;
						smart = 1;
					}
				}
			}
		}
	} while (player_row < MAX_ROWS && !smart);

	while (!smart && !valid) {
		target_row = rand() % 10;
		target_column = rand() % 10;
		valid = ((player_board[target_row][target_column] != '*') && (player_board[target_row][target_column] != 'm'));
	}

	Target coordinate = { target_row, target_column };
	return(coordinate);
}



/*************************************************************
* Function: copy_character_array()							*
* Date Created: 11/06/2023                                  *
* Date Last Modified: 11/06/2023                            *
* Description: Copies every value from one array to another	*
* array.													*
* Input parameters: char source[][10]						*
* Output parameters: char destination[][10]					*
* Returns: void												*
* Preconditions: Source array has been initialized.			*
* Postconditions: None										*
*************************************************************/

void copy_character_array(char destination[][MAX_COLUMNS], char source[][MAX_COLUMNS]) {
	int row = 0, column = 0;
	for (; row < MAX_ROWS; ++row) {
		for (column = 0; column < MAX_COLUMNS; ++column) {
			destination[row][column] = source[row][column];
		}
	}
}