/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA4
* Date: October 2, 2023
* Description: This program implements a craps game according to
* the rules of craps. It will give the user the option to play,
* view rules, or quit. It will take a wager from the user's bank
* balance, roll dice, and determine whether the player wins, loses,
* or can continue to roll the dice. The game will print various
* chatter messages to engage the player.
* General Notes: I have largely followed the boilerplate function
* prototypes given in PA4.pdf, with some notable deviations where
* it was necessary either to improve the experience or to better
* integrate my design decisions. I split the chatter_messages()
* function into several functions that are called at different times
* throughout the game, and generate pseudorandom numbers to
* determine which message to print out of multiple options for each
* condition. The boilerplate function adjust_bank_balance() was split
* into adjust_bank_balance_win() and adjust_bank_balance_wager(); the
* former is called only if the player wins, the latter is called after
* every call to get_wager_amount. Some functions given in .pdf have
* been renamed. Despite changes, all intended functionality of
* instructor provided functions from PA4.pdf still exists.
******************************************************************/




#define _CRT_SECURE_NO_WARNINGS			// Silences warnings for printf() and scanf()
#include <stdio.h>						// printf() and scanf()
#include <stdlib.h>						// rand() and srand()
#include <time.h>						// time()


/*************************************************************
* Function: print_game_rules()		                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Prints the rules of craps to the screen		*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: User requested rules to be displayed       *
* Postconditions: NA                                        *
*************************************************************/

void print_game_rules(void);




/*************************************************************
* Function: get_bank_balance()		                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Prompts the player for an initial bank		*
* balance from which wagers will be subtracted and winnings *
* will be added.											*
* Input parameters: void				                    *
* Returns: double (bank balance in dollars)                 *
* Preconditions: User requested to play the game		    *
* Postconditions: Balance returns to the main function to   *
* be compared to the upcoming wagers.						*
*************************************************************/

double get_bank_balance(void);





/*************************************************************
* Function: get_wager_amount()		                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Prompts the player for a wager before a		*
* dice roll and returns the value. The verbiage of the		*
* message varies dependent on if it is an inital wager or	*
* an update.												*
* Input parameters: int roll_count		                    *
* Returns: double (wager value in dollars)	                *
* Preconditions: User requested to play the game.			*
* Postconditions: Wager value is returned to the main 		*
* function.													*
*************************************************************/

double get_wager_amount(int roll_count);





/*************************************************************
* Function: check_wager_amount()	                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Compares the player's wager to the player's	*
* bank balance. Returns 0 if the wager exceeds the player's	*
* balance, otherwise returns 1.								*
* Input parameters: double wager, double balance			*
* Returns: int (0 or 1)						                *
* Preconditions: User has made a wager and input a bank		*
* balance.													*
* Postconditions: If function returns 1, the player may		*
* roll the dice. If the function returns 0, the player may	*
* not roll the dice and is returned to the main menu.		*
*************************************************************/

int check_wager_amount(double wager, double balance);





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
* Function: calculate_sum_dice()	                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Sums two integer inputs between 1 and 6 and	*
* returns the result.										*
* Input parameters: int die1, int die2						*
* Returns: int (2-12)						                *
* Preconditions: User has rolled two dice.					*
* Postconditions: Function returns the sum of the dice roll	*
* to main().												*
*************************************************************/

int calculate_sum_dice(int die1, int die2);




/*************************************************************
* Function: first_dice_roll()		                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Determines the result of the first dice roll.*
* If the sum of the dice is 7 or 11, the player wins and	*
* the function returns 1. If the sum is 2, 3, or 12, the	*
* player loses and 0 is returned. If the sum is 4, 5, 6, 8, *
* 9, or 10, the function returns -1.						*
* Input parameters: int sum_dice							*
* Returns: int (-1, 0, 1)					                *
* Preconditions: User has rolled two dice one time.			*
* Postconditions: The player wins, loses, or continues to	*
* roll the dice.											*
*************************************************************/

int first_dice_roll(int sum_dice);




/*************************************************************
* Function: determine_win_state		                        *
* Date Created: 10/02/2023                                  *
* Date Last Modified: 10/02/2023                            *
* Description: Determines the result of any successive dice *
* roll after the first. If the sum of the roll is the		*
* point_value, returns 1. If the sum of the roll is a 7,	*
* returns 0. Otherwise, returns -1.							*
* Input parameters: int sum_dice, int point_value			*
* Returns: int (1, 0, -1)					                *
* Preconditions: User has rolled dice more than once.		*
* Postconditions: User will either continue rolling dice,	*
* they make their point and win, or they crap out and lose.	*
*************************************************************/

int determine_win_state(int sum_dice, int point_value);




/*************************************************************
* Function: adjust_bank_balance_win()	                    *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Takes double inputs for bank balance and		*
* wager amount, and adds 2x the wager amount to the bank	*
* balance.													*
* Input parameters: double bank_balance, double				*
* wager_amount												*
* Returns: double							                *
* Preconditions: User has won the game.						*
* Postconditions: Bank balance is adjusted according to the	*
* function's algorithm and the user may replay or quit.		*
*************************************************************/

double adjust_bank_balance_win(double bank_balance, double wager_amount);




/*************************************************************
* Function: adjust_bank_balance_wager()	                    *
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Subtracts a player's wager from their bank	*
* balance and returns the new bank balance.					*
* Input parameters: double bank_balance, double	wager_amount*
* Returns: double							                *
* Preconditions: User has placed a wager.					*
* Postconditions: Bank balance is adjusted according to the	*
* function's algorithm and the game continues.				*
*************************************************************/

double adjust_bank_balance_wager(double bank_balance, double wager_amount);




/*************************************************************
* Function: update_wager_amount()		                    *
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Adds a wager_update input to current_wager	*
* and returns the result									*
* Input parameters: double wager_update, double				*
* current_wager												*
* Returns: double							                *
* Preconditions: User has placed a wager					*
* Postconditions: Wager is updated and the game continues	*
*************************************************************/

double update_wager_amount(double current_wager, double wager_update);




/*************************************************************
* Function: print_big_spender_chatter()		                *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/05/2023                            *
* Description: Prints a message if the player makes a large	*
* bet relative to their balance								*
* Input parameters: double current_bank_balance, double 	*
* wager_amount												*
* Returns: void												*
* Preconditions: Player has made a large wager				*
* Postconditions: Game continues							*
*************************************************************/

void print_big_spender_chatter(double current_bank_balance, double wager_amount);




/*************************************************************
* Function: print_bet_more_chatter()		                *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/05/2023                            *
* Description: Prints a message if the player makes a very	*
* small bet relative to their bank balance.					*
* Input parameters: double current_bank_balance, double 	*
* wager_amount												*
* Returns: void												*
* Preconditions: Player has made a very small wager			*
* Postconditions: Game continues							*
*************************************************************/

void print_bet_more_chatter(double current_bank_balance, double wager_amount);



/*************************************************************
* Function: print_cash_in_chatter()				            *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/05/2023                            *
* Description: Prints a message if the player's current		*
* bank balance is much greater than their starting balance.	*
* Input parameters: double current_bank_balance, double 	*
* initial_bank_balance										*
* Returns: void												*
* Preconditions: Player's balance has been adjusted			*
* Postconditions: Game continues or player quits			*
*************************************************************/

void print_cash_in_chatter(double current_bank_balance, double initial_bank_balance);





/*************************************************************
* Function: print_high_rolls_chatter()				        *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/05/2023                            *
* Description: Prints a message if the player's roll count	*
* exceeds 4 without a win or loss.							*
* Input parameters: int number_rolls						*
* Returns: void												*
* Preconditions: Player has rolled the dice					*
* Postconditions: Game continues or player quits			*
*************************************************************/

void print_high_rolls_chatter(int number_rolls);




/*************************************************************
* Function: print_broke_chatter()					        *
* Date Created: 10/05/2023                                  *
* Date Last Modified: 10/05/2023                            *
* Description: Prints a message if the player's bank		*
* balance falls below a threshold of 10% of the initial		*
* balance.													*
* Input parameters: double initial_bank_balance, double		*
* current_bank_balance										*
* Returns: void												*
* Preconditions: Player has lost a bet						*
* Postconditions: Game continues or player quits			*
*************************************************************/

void print_broke_chatter(double initial_bank_balance, double current_bank_balance);




/*************************************************************
* Function: display_dice_totals()					        *
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Prints the result of each individual die and	*
* the sum of the dice.										*
* Input parameters: int die1, int die2, int die_sum			*
* Returns: void												*
* Preconditions: Player has rolled the dice					*
* Postconditions: Game continues or player quits			*
*************************************************************/

void display_dice_totals(int die1, int die2, int dice_sum);




/*************************************************************
* Function: display_win_loss_condition()			        *
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Prints a message informing the player they	*
* have either won or lost the game, depending on the win	*
* condition input. Prints a subsequent message that the		*
* player's wager has been deposited or withdrawn from their *
* bank balance, depending on win/loss, and showing the new	*
* balance.													*
* Input parameters: int win_condition, double wager_amt, 	*
* double current_bank_balance								*
* Returns: void												*
* Preconditions: Player has won or lost and bank balance	*
* has been adjusted.										*
* Postconditions: NA										*
*************************************************************/

void display_win_loss_condition(int win_condition, double wager_amt, double current_bank_balance);




/*************************************************************
* Function: display_return_menu()							*
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Prints a secondary menu after a game round	*
* finishes that lets the player either play again or return	*
* to the main menu.											*
* Input parameters: void									*
* Returns: int (1 or 0)										*
* Preconditions: Player has won or lost and bank balance	*
* has been adjusted.										*
* Postconditions: Player quits or plays again				*
*************************************************************/

int display_return_menu(void);




/*************************************************************
* Function: display_splash_screen()							*
* Date Created: 10/06/2023                                  *
* Date Last Modified: 10/06/2023                            *
* Description: Displays "CRAPS" in ASCII art				*
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