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




// includes the header file
#include "craps.h"


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

void print_game_rules(void) {
	printf("\nRules of Craps:\n");
	printf("A player rolls two (2) six sided dice. Each die side contains 1, 2,\n");
	printf("3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the\n");
	printf("spots on the upward faces is calculated. If the sum is 7 or 11 on the\n");
	printf("first throw, the player wins. If the sum is 2, 3, or 12 on the first\n");
	printf("throw, the player loses (i.e. the ""house"" wins). If the sum is 4, 5,\n");
	printf("6, 8, 9, or 10 on the first throw, then the sum becomes the player's ""point"".\n");
	printf("To win, you must continue rolling the dice until you ""make your point.""\n");
	printf("The player loses by rolling a 7 before making the point.\n\n");
}


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

double get_bank_balance(void) {
	double bank_balance = 0.0;
	do {
		printf("Please enter your bank balance: ");
		scanf("%lf", &bank_balance);
	} while (bank_balance <= 0);
	return(bank_balance);
}



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

double get_wager_amount(int roll_count) {
	double wager = 0.0;
	if (roll_count == 0) {
		printf("Enter a wager amount (between $0.00 and your bank balance): ");
		scanf("%lf", &wager);
	}
	else {
		printf("If you would like to make an additional wager, enter\n");
		printf("the additional amount: ");
		scanf("%lf", &wager);
	}
	return(wager);
}



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

int check_wager_amount(double wager, double balance) {
	if ((wager <= balance) && (wager >= 0)) {
		return(1);
	}
	else return(0);
}



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

int roll_die(void) {
	int dice = 0;
	dice = (rand() % 6) + 1;
	return(dice);
}



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

int calculate_sum_dice(int die1, int die2) {
	return(die1 + die2);
}


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

int first_dice_roll(int sum_dice) {
	if ((sum_dice == 7) || (sum_dice == 11)) {
		return(1);
	}
	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12)) {
		return(0);
	}
	else return(-1);
}


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

int determine_win_state(int sum_dice, int point_value) {
	if (sum_dice == point_value) {
		return(1);
	}
	else if (sum_dice == 7) {
		return(0);
	}
	else return(-1);
}



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

double adjust_bank_balance_win(double bank_balance, double wager_amount) {
	bank_balance += 2 * wager_amount;
	return(bank_balance);
}




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

double adjust_bank_balance_wager(double bank_balance, double wager_amount) {
	double new_balance = 0.0;
	new_balance = bank_balance - wager_amount;
	return(new_balance);
}





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

double update_wager_amount(double current_wager, double wager_update) {
	double new_wager = 0.0;
	new_wager = current_wager + wager_update;
	return(new_wager);
}



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

void print_big_spender_chatter(double current_bank_balance, double wager_amount) {
	int random_assignment = 0;
	if (current_bank_balance <= (4 * wager_amount)) {
		random_assignment = rand() % 4;
		if (random_assignment == 0) {
			printf("Good luck, big spender.\n");
		}
		else if (random_assignment == 1) {
			printf("Now that's a lot of sauce.\n");
		}
		else if (random_assignment == 2) {
			printf("I hope you're done grocery shopping for the month already.\n");
		}
		else {
			printf("If you think you may have a gambling problem, seek help at 1-800-662-4357.\n");
		}
	}
	else return;
}



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

void print_bet_more_chatter(double current_bank_balance, double wager_amount) {
	int random_assignment = 0;
	if (current_bank_balance > (25 * wager_amount)) {
		random_assignment = rand() % 4;
		if (random_assignment == 0) {
			printf("C'mon, you can go bigger than that!\n");
		}
		else if (random_assignment == 1) {
			printf("Did your mortgage payment just hit or something?\n");
		}
		else if (random_assignment == 2) {
			printf("Go big! You don't need to eat this week, do you?\n");
		}
		else {
			printf("Maybe the penny slots would be more to your liking?\n");
		}
	}
	else return;
}




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

void print_cash_in_chatter(double current_bank_balance, double initial_bank_balance) {
	int random_assignment = 0;
	if (current_bank_balance > (3 * initial_bank_balance)) {
		random_assignment = rand() % 4;
		if (random_assignment == 0) {
			printf("You got to know when to hold'em, know when to fold'em, know when to walk away, and know when to run.\n");
		}
		else if (random_assignment == 1) {
			printf("You're up big. Now might be a good time to cash in your chips.\n");
		}
		else if (random_assignment == 2) {
			printf("The point of gambling is to give the casino money, you're doing it wrong.\n");
		}
		else {
			printf("Please leave.\n");
		}
	}
	else return;
}




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

void print_high_rolls_chatter(int number_rolls) {
	int random_assignment = 0;
	if ((number_rolls >= 5) && (number_rolls < 10)) {
		random_assignment = rand() % 2;
		if (random_assignment == 0) {
			printf("You're on quite a roll, there... Get it?\n");
		}
		else {
			printf("Staying alive, staying alive...\n");
		}
	}
	else if (number_rolls >= 10) {
		random_assignment = rand() % 2;
		if (random_assignment == 0) {
			printf("Is your arm getting tired yet?\n");
		}
		else {
			printf("Well, this is getting awkward.\n");
		}
	}
	else return;
}



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

void print_broke_chatter(double initial_bank_balance, double current_bank_balance) {
	int random_assignment = 0;
	if ((current_bank_balance * 10) < initial_bank_balance) {
		random_assignment = rand() % 4;
		if (random_assignment == 0) {
			printf("You're looking a little light there, champ. Maybe you want to call it a day?\n");
		}
		else if (random_assignment == 1) {
			printf("If you walk away now, you'll never know what being completely wiped out feels like.\n");
		}
		else if (random_assignment == 2) {
			printf("C'mon buddy. It's clearly not your day. Let's go get a drink and talk about your choices.\n");
		}
		else {
			printf("If you think you may have a gambling problem, seek help at 1-800-662-4357.\n");
		}
	}
}





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

void display_dice_totals(int die1, int die2, int dice_sum) {
	display_dice_art(die1);
	display_dice_art(die2);
	printf("Your dice total is %d.\n", dice_sum);
}





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

void display_win_loss_condition(int win_condition, double wager_amt, double current_bank_balance) {
	if (win_condition == 1) {
		printf("You win!\n");
		printf("Your wager of $%.2lf has been added to your account.\n", wager_amt);
		printf("Your new account balance is $%.2lf.\n", current_bank_balance);
	}
	else if (win_condition == 0) {
		printf("You lose.\n");
		printf("Your wager of $%.2lf has been removed from your account.\n", wager_amt);
		printf("Your new account balance is $%.2lf.\n", current_bank_balance);
	}

}





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

int display_return_menu(void) {
	int input = 0;
	printf("What would you like to do?\n");
	printf("1. Play again.\n");
	printf("2. Return to Main Menu.\n");
	scanf("%d", &input);
	return(input);
}




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

void display_splash_screen(void) {
	printf("***************************************************************\n");
	printf("**  .d8888b.  8888888b.         d8888 8888888b.   .d8888b.   **\n");
	printf("** d88P  Y88b 888   Y88b       d88888 888   Y88b d88P  Y88b  **\n");
	printf("** 888    888 888    888      d88P888 888    888 Y88b.       **\n");
	printf("** 888        888   d88P     d88P 888 888   d88P  ^Y888b.    **\n");
	printf("** 888        8888888P^     d88P  888 8888888P^      ^Y88b.  **\n");
	printf("** 888    888 888 T88b     d88P   888 888              ^888  **\n");
	printf("** Y88b  d88P 888  T88b   d8888888888 888        Y88b  d88P  **\n");
	printf("**  ^Y8888P^  888   T88b d88P     888 888         ^Y8888P^   **\n");
	printf("***************************************************************\n");
}




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

void display_dice_art(int dice_value) {
	int random_assignment = 0;
	random_assignment = rand() % 2;
	if (dice_value == 1) {
		printf("+---------+\n");
		printf("|         |\n");
		printf("|    O    |\n");
		printf("|         |\n");
		printf("+---------+\n\n");
	}
	else if (dice_value == 2) {
		if (random_assignment == 0) {
			printf("+---------+\n");
			printf("|      O  |\n");
			printf("|         |\n");
			printf("|  O      |\n");
			printf("+---------+\n\n");
		}
		else {
			printf("+---------+\n");
			printf("|  O      |\n");
			printf("|         |\n");
			printf("|      O  |\n");
			printf("+---------+\n\n");
		}
	}
	else if (dice_value == 3) {
		if (random_assignment == 0) {
			printf("+---------+\n");
			printf("|      O  |\n");
			printf("|    O    |\n");
			printf("|  O      |\n");
			printf("+---------+\n\n");
		}
		else {
			printf("+---------+\n");
			printf("|  O      |\n");
			printf("|    O    |\n");
			printf("|      O  |\n");
			printf("+---------+\n\n");
		}
	}
	else if (dice_value == 4) {
		printf("+---------+\n");
		printf("|  O   O  |\n");
		printf("|         |\n");
		printf("|  O   O  |\n");
		printf("+---------+\n\n");
	}
	else if (dice_value == 5) {
		printf("+---------+\n");
		printf("|  O   O  |\n");
		printf("|    O    |\n");
		printf("|  O   O  |\n");
		printf("+---------+\n\n");
	}
	else {
		printf("+---------+\n");
		printf("|  O   O  |\n");
		printf("|  O   O  |\n");
		printf("|  O   O  |\n");
		printf("+---------+\n\n");
	}
}


