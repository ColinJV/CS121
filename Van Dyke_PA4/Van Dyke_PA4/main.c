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

#include "craps.h"

int main(void) {

	// Declares int input_main, a variable set by an input on the main menu.
	// If the player inputs 3 on the main menu, the loop completes and the game exits.
	int input_main = 0;

	// Sets seed for rand()
	srand((unsigned int)time(NULL));

	display_splash_screen();

	// Full game loop. Executes once and repeats when the player chooses to return
	// to the main menu. Terminates when the player inputs "3" on the main menu.
	do {



		// Main menu loop. Executes recursively until the player inputs a valid value: 1,2,3
		// Inputting a character value like 'f' or '=' completely breaks this and causes the
		// print list to print infinitely until you close the terminal manually and I have no
		// idea how to fix this, but Andy said it wasn't required so.
		do {
			printf("1. Play Game\n");
			printf("2. Display Rules\n");
			printf("3. Quit\n");
			scanf("%d", &input_main);
		} while ((input_main < 1) || (input_main > 3));

		// Displays game rules if player main menu input was 2
		if (input_main == 2) {
			print_game_rules();
		}

		// Primary gameplay section.
		else if (input_main == 1) {
			double initial_bank_balance = 0.0, current_bank_balance = 0.0;

			initial_bank_balance = get_bank_balance();
			current_bank_balance = initial_bank_balance;

			double wager_amount = 0.0, wager_update = 0.0;
			int input_secondary = 0;

			// Declares integer variables for win condition, the player's point,
			// and roll_count, which counts the number of times the dice have been
			// rolled since the player's most recent win or loss.
			int win_condition = 0, player_point = 0, roll_count = 0;

			// Primary gameplay loop. Executes once and repeats until player chooses to quit
			// to the main menu. Contains a nested gameplay loop and a subsequent section that
			// manipulates the player's bank balance if the player won.
			do {

				// Nested gameplay loop. Obtains wager, rolls dice, increments dice counter,
				// and checks to determine if win conditions have been met. If win conditions
				// have been met, the loop terminates. If win conditions have not been met, the
				// nested gameplay loop repeats, updating the wager amount and bank balance and
				// continuing to roll dice until the player wins or loses.
				do{


					// Get wager loop. Gets a wager from the player, repeats until the wager
					// is less than the player's bank balance.
					int valid_wager = 0;
					do{
						wager_update = get_wager_amount(roll_count);
						valid_wager = check_wager_amount(wager_update, current_bank_balance);
					} while (valid_wager == 0);

					current_bank_balance = adjust_bank_balance_wager(current_bank_balance, wager_update);
					wager_amount = update_wager_amount(wager_amount, wager_update);

					// Dice rolling gameplay section		
					int die1 = 0, die2 = 0, sum_dice = 0, text_rng = 0;

					text_rng = roll_die();					
					die1 = roll_die();
					die2 = roll_die();

					if (text_rng > 3) {
						print_big_spender_chatter(current_bank_balance, wager_amount);
						print_bet_more_chatter(current_bank_balance, wager_amount);
					}
					else {
						print_high_rolls_chatter(roll_count);
					}

					sum_dice = calculate_sum_dice(die1, die2);
					roll_count++;

					display_dice_totals(die1, die2, sum_dice);

					// Assigns value to win_condition that varies based on roll_count
					// and sum_dice. Assignment of 1 or 0 will terminate the loop.
					if (roll_count == 1) {
						win_condition = first_dice_roll(sum_dice);
						if (win_condition == -1) {
						player_point = sum_dice;
					}
				}
				else {
					win_condition = determine_win_state(sum_dice, player_point);
				}

				// Exits the dice rolling loop
				} while ((win_condition > 1) || (win_condition < 0));

				// If the player wins, returns their wager plus their winnings to their account.
				if (win_condition == 1) {
					current_bank_balance = adjust_bank_balance_win(current_bank_balance, wager_amount);
				}

				display_win_loss_condition(win_condition, wager_amount, current_bank_balance);
				print_cash_in_chatter(current_bank_balance, initial_bank_balance);
				print_broke_chatter(initial_bank_balance, current_bank_balance);

				// Resets wager_amount and roll_count
				wager_amount = 0;
				roll_count = 0;

				input_secondary = display_return_menu();

			} while (input_secondary != 2);
		}
	} while (input_main != 3);

	return(0);
}


