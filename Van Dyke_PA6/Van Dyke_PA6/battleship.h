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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define CARRIER_SIZE 5
#define BATTLESHIP_SIZE 4
#define CRUISER_SIZE 3
#define SUBMARINE_SIZE 3
#define DESTROYER_SIZE 2
#define NUMBER_OF_SHIPS	5

typedef struct stats {
	int number_of_hits;
	int number_of_misses;
	int number_of_shots;
	double percentage_hits;
	int ships_sunk;
	int won_or_lost;
} Stats;

typedef struct ship {
	char name[15];
	char abbreviation;
	int health;
	int size;
} Ship;

typedef struct target {
	int row;
	int column;
} Target;



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

void display_main_menu(void);



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

void display_splash_screen(void);



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

void display_game_rules(void);



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

int get_integer_input(void);



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

void clear_screen(void);



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

int press_any_key(void);



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

int coin_flip(void);



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

void initialize_character_array(char array[][10], int number_of_rows, int number_of_columns);



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

int prompt_ship_placement(void);



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

void place_ships_manually(char player_board[MAX_ROWS][MAX_COLUMNS], Ship* player_ships);



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

void print_board(char board[][MAX_COLUMNS], int num_rows, int num_cols);



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

void place_ships_randomly(char game_board[MAX_ROWS][MAX_COLUMNS], Ship* ships_array);



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

Target get_valid_player_target(char cpu_mirror[MAX_ROWS][MAX_COLUMNS]);



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

void display_target(int player, Target coordinate);



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

int check_shot(char board[MAX_ROWS][MAX_COLUMNS], Target coordinate);



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
	Ship* enemy_ships, int player, FILE* output);



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

int check_for_sunk(Ship* enemy_ships, int index, Stats* friendly_stats, int player, FILE* output);



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

int check_for_victory(Ship *array_of_ships);



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

void display_hit_miss(int hit);



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
	Target coordinates, int hit, int player);



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

void shot_miss_actions(Stats* friendly_stats, int player, FILE* output);



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

void display_interface(char cpu_mirror[MAX_ROWS][MAX_COLUMNS], char player_mirror[MAX_ROWS][MAX_COLUMNS]);



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

Target get_valid_cpu_target(char player_mirror[MAX_ROWS][MAX_COLUMNS]);



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

void display_winner(int player);



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

void display_who_goes_first(int player);



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

void display_whose_turn(int player);



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

void log_turn(int turn, FILE* output);



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

void log_target(int player, Target coordinates, FILE* output);



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

void log_hit_damage(int player, Target coordinates, char* ship_name, FILE* output);



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

void log_ship_sunk(int player, char* ship_hit, FILE* output);



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

void log_victory(int player, FILE* output);



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

void calculate_hit_percentage(Stats* user_stats);



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

void log_end_data(Stats player_stats, Stats cpu_stats, int game, int turn, FILE* output);



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

void log_miss(int player, FILE* output);



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

Target get_valid_somewhat_smart_cpu_target(char player_board[][MAX_COLUMNS]);



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

void copy_character_array(char destination[][MAX_COLUMNS], char source[][MAX_COLUMNS]);