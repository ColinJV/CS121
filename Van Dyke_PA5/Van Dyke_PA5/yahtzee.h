/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA5
* Date: October 16, 2023
* Description: This program allows two players to play Yahtzee
* in accordance with the listed rules of Yahtzee. Displays a main
* menu that can start the game, display rules, or quit. On a player's
* turn they roll five dice, and may reroll up to five dice up to
* two times. When finished rolling, the players dice accumulate a
* score that depends on the dice face value and frequency, with
* 13 scoring options available at the beginning. When a score
* option is chosen it cannot be chosen again. After 13 rounds,
* the player with the higher score is the winner and the game
* returns to the main menu.
******************************************************************/




#define _CRT_SECURE_NO_WARNINGS			// silences warnings for printf() and scanf()
#define MAX_DICE 5						// defines constant MAX_DICE as 5
#define BONUS_POINTS 35					// defines constant BONUS_POINTS as 35
#define SCORING_FIELDS 13				// defines constant SCORING_FIELDS as 13

#include <stdio.h>						// printf() and scanf()
#include <stdlib.h>						// rand() and srand()
#include <time.h>						// time()



/*************************************************************
* Function: display_game_rules()							*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Prints the rules of yahtzee to the screen	*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: none										*
* Postconditions: none										*
*************************************************************/

void display_game_rules(void);




/*************************************************************
* Function: roll_die()				                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Randomly generates a value between 1 and 6	*
* inclusively. Returns the value of the dice roll.			*
* Input parameters: void									*
* Returns: int (1-6)						                *
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int roll_die(void);





/*************************************************************
* Function: display_splash_screen()							*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Displays "YAHTZEE" in ASCII art generated 	*
* by textkool.com/en/ascii-art-generator					*
* Input parameters: void									*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_splash_screen(void);




/*************************************************************
* Function: display_dice_art()								*
* Date Created: 10/08/2023                                  *
* Date Last Modified: 10/08/2023                            *
* Description: Displays ASCII art of dice corresponding to 	*
* the player's rolls.										*
* Input parameters: int dice_value							*
* Returns: void												*
* Preconditions: Player has rolled dice						*
* Postconditions: None										*
*************************************************************/

void display_dice_art(int dice_value);




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
* Function: display_whose_turn()							*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Displays a message to the player indicating	*
* whose turn it is.											*
* Input parameters: int turn								*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_whose_turn(int turn);





/*************************************************************
* Function: press_any_key()									*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Prompts for an input of any key from the 	*
* user and returns 1 when input has been made				*
* Input parameters: void									*
* Returns: int												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int press_any_key(void);





/*************************************************************
* Function: roll_dice()										*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Rolls a certain number of dice based on		*
* input and returns their value by output parameter			*
* Input parameters: int number_of_dice						*
* Output parameters: int *dice_array						*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void roll_dice(int* dice_array, int number_of_dice);




/*************************************************************
* Function: prompt_for_reroll								*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Asks the user if they would like to reroll	*
* any dice. Returns 1 or 0 to main (1 for yes, 0 for no.)	*
* Input parameters: void									*
* Output parameters: none									*
* Returns: int (0 or 1)		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int prompt_for_reroll(void);





/*************************************************************
* Function: display_dice_values()							*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Displays each die and its corresponding		*
* value														*
* Input parameters: int dice_value							*
* Returns: void												*
* Preconditions: Player has rolled dice						*
* Postconditions: None										*
*************************************************************/

void display_dice_values(const int* dice);





/*************************************************************
* Function: count_dice_frequency()							*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Counts the number of times a certain die		*
* face appears on a dice roll and stores that result as		*
* an output parameter.										*
* Input parameters: int *dice, int *dice_frequency			*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void count_dice_frequency(const int* dice, int* dice_frequency);



/*************************************************************
* Function: sequential_search()								*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Searches an integer array for a value.		*
* Returns 1 if the value is found, 0 if it is not found.	*
* Input parameters: int *array								*
* Returns: int (0 or 1)		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int sequential_search(const int* array);





/*************************************************************
* Function: sequential_search()								*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Searches an integer array for a value.		*
* Returns 1 if found, 0 if not found.						*
* Input parameters: int *array, int array_size, int target	*
* Returns: int found (0 or 1)                               *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int sequential_search(const int* array, int array_size, int target);





/*************************************************************
* Function: calculate_bonus									*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Sums the contents of the face value scores	*
* and, if the sum is >= 63, returns
* Input parameters: int *array, int size_of_array			*
* Output parameters: none									*
* Returns: int score		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int calculate_bonus(int* array, int size_of_array);







/*************************************************************
* Function: display_scoreboard_both()						*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Calculates and displays the score total for	*
* both players after each round								*
* Input parameters: int *player1_score, int *player2_score,	*
* int array_size, int round									*
* Output parameters: int *player1_total, int *player2_total	*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void display_scoreboard_both(int* player1_score, int* player2_score, int array_size, int* player1_total, int* player2_total, int round);






/*************************************************************
* Function: calculate_sum_score								*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Sums the contents of a player's score array	*
* and returns the value.									*
* Input parameters: int *array, int size					*
* Output parameters: none									*
* Returns: int score		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int calculate_sum_score(int* array, int size);





/*************************************************************
* Function: display_winner()								*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Sums the contents of a player's score array	*
* and returns the value.									*
* Input parameters: int *player1_score, int *player2_score	*
* Output parameters: none									*
* Returns: int score		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void display_winner(int* player1_score, int* player2_score);






/*************************************************************
* Function: calculate_temporary_score()						*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Computes a list of possible scores based on	*
* the player's dice rolls.									*
* Input parameters: int *dice, int *dice_frequency,			*
* Output parameters: int *temporary_score					*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void calculate_temporary_score(int* dice, int* dice_frequency, int* temporary_score);







/*************************************************************
* Function: display_temporary_score()						*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Displays a temporary scoreboard with which	*
* the player can decide which score box to retain.			*
* Input parameters: int *temporary_score, int *score_mirror	*
* Output parameters: none									*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void display_temporary_score(int* temporary_score, int* score_mirror);







/*************************************************************
* Function: reset_some_dice()								*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Iterates through dice and asks the user if	*
* they wish to reroll. If the user answers yes, resets the	*
* value in dice[] to 0										*
* Input parameters: none									*
* Output parameters: int *dice								*
* Returns: void				                                *
* Preconditions: reroll = 1									*
* Postconditions: NA                                        *
*************************************************************/

void reset_some_dice(int* dice);





/*************************************************************
* Function: bubble_sort()									*
* Date Created: 10/20/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Sorts an array using the buble sort			*
* Input parameters:	int array_size							*
* Output parameters: int *dice								*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void bubble_sort(int* array, int array_size);







/*************************************************************
* Function: how_many_saved_dice()							*
* Date Created: 10/20/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Sorts dice[], then counts the non-zero		*
* Input parameters:	none									*
* Output parameters: int *dice								*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int how_many_saved_dice(int* dice);





/*************************************************************
* Function: reset_array()									*
* Date Created: 10/20/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Iterates through an array, setting all values*
* to 0.														*
* Input parameters:	none									*
* Output parameters: int *temporary_score					*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

reset_array(int* array, int array_size);







/*************************************************************
* Function: select_score()									*
* Date Created: 10/20/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Prompts the user for an input corresponding	*
* to the score they would like to save. Checks input against*
* allowed values by reading data from player_score_mirror[],*
* looping if the value is not allowed and assigning the		*
* selected score value if it is allowed.					*
* Input parameters:	int *temporary_score, int *score_mirror	*
* Output parameters: int *player_score						*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

select_score(int* temporary_score, int* player_score, int* score_mirror);