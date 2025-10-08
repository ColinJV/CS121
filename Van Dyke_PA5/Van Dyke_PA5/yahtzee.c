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





#include "yahtzee.h"


/*************************************************************
* Function: display_game_rules()	                        *
* Date Created: 10/16/2023                                  *
* Date Last Modified: 10/16/2023                            *
* Description: Prints the rules of craps to the screen		*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: User requested rules to be displayed       *
* Postconditions: NA                                        *
*************************************************************/

void display_game_rules(void) {
	printf("\nRules of Yahtzee:\n");
	printf("The scorecard used for Yahtzee is composed of two sections: an upper section and a lower section. A\n");
	printf("total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper\n");
	printf("section consists of boxes that are scored by summing the value of the dice matching the faces of the\n");
	printf("box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is\n");
	printf("12. Once a player has chosen to score a box, it may not be changed and the combination is no longer\n");
	printf("in play for future rounds.If the sum of the scores in the upper section is greater than or equal to\n");
	printf("63, then 35 more points are added to the player's overall score as a bonus. The lower section\n");
	printf("contains a number of poker-like combinations. See the table provided below.\n\n");
	printf("     Name                         Combination                         Score\n");
	printf("Three-of-a-kind          Three dice with the same face         Sum of all 5 dice\n");
	printf("Four-of-a-kind            Four dice with the same face         Sum of all 5 dice\n");
	printf(" Full house               One pair and three-of-a-kind                  25\n");
	printf("Small straight               A sequence of four dice                    30\n");
	printf("Large straight               A sequence of five dice                    40\n");
	printf("  Yahtzee                 Five dice with the same face                  50\n");
	printf("  Chance                Any sequence of dice (catch all)       Sum of all 5 dice\n\n");
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

void display_splash_screen(void) {
	printf("oooooo   oooo       .o.       ooooo   ooooo ooooooooooooo  oooooooooooo oooooooooooo oooooooooooo \n");
	printf(" `888.   .8'       .888.      `888'   `888' 8'   888   `8 d'^^^^^^d888' `888'     `8 `888'     `8 \n");
	printf("  `888. .8'       .8^888.      888     888       888            .888P    888          888         \n");
	printf("   `888.8'       .8' `888.     888ooooo888       888           d888'     888oooo8     888oooo8    \n");
	printf("    `888'       .88ooo8888.    888     888       888         .888P       888    ^     888    ^    \n");
	printf("     888       .8'     `888.   888     888       888        d888'    .P  888       o  888       o \n");
	printf("    o888o     o88o     o8888o o888o   o888o     o888o     .8888888888P  o888ooooood8 o888ooooood8 \n\n\n");
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

void display_whose_turn(int turn) {
	printf("It's Player %d's turn!\n", turn);
}




/*************************************************************
* Function: get_char_input()								*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/17/2023                            *
* Description: Prompts the user to press any key to			*
* continue.
* Input parameters: void									*
* Returns: int												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int press_any_key(void) {
	system("pause");
	return(1);
}




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

void roll_dice(int* dice_array, int number_of_dice) {
	int roll_count = 0;
	for (; (roll_count < number_of_dice); roll_count++) {
		dice_array[roll_count] = roll_die();
	}
}



/*************************************************************
* Function: prompt_for_reroll()								*
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

int prompt_for_reroll(void) {
	char input = '\0';
	int reroll = -1;
	do {
		do {
			printf("Would you like to reroll any dice? Y/N: \n");
			scanf(" %c", &input);
		} while ((input != 'Y') && (input != 'y') && (input != 'N') && (input != 'n'));

		switch (input) {
		case 'Y': {
			reroll = 1;
			break;
		}
		case 'y': {
			reroll = 1;
			break;
		}
		case 'N': {
			reroll = 0;
			break;
		}
		case 'n': {
			reroll = 0;
			break;
		}
		}
	} while (reroll < 0 || reroll > 1);
	return(reroll);
}







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

void display_dice_values(const int* dice) {
	int number = 0;
	for (; number < MAX_DICE; number++) {
		printf("Die %d: %d\n", number + 1, dice[number]);
		display_dice_art(dice[number]);
	}
}






/*************************************************************
* Function: count_dice_faces()								*
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

void count_dice_frequency(const int* dice, int* dice_frequency) {
	int index = 0;
	for (; index < MAX_DICE; ++index) {
		++dice_frequency[dice[index]];
	}
}



/*************************************************************
* Function: frequency_search()								*
* Date Created: 10/17/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Searches an integer array for a value.		*
* Increments found for each instance of the integer it		*
* finds. Returns found.										*
* Input parameters: int *array, int array_size, int target	*
* Returns: int found		                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

int frequency_search(const int* array, int array_size, int target) {
	int index = 0, found = 0;
	while (index < array_size) {
		if (target == array[index]) {
			++found;
		}
		++index;
	}
	return(found);
}





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

int sequential_search(const int* array, int array_size, int target) {
	int index = 0, found = 0;
	while ((index < array_size) && !found) {
		found = (target == array[index]);
		++index;
	}
	return(found);
}





/*************************************************************
* Function: calculate_bonus()								*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Sums the contents of the face value scores	*
* and, if the sum is >= 63, assigns BONUS_POINTS to bonus.	*
* Input parameters: int *array								*
* Output parameters: none									*
* Returns: int bonus		                                *
* Preconditions: Array size is greater than or equal to 6	*
* Postconditions: NA                                        *
*************************************************************/

int calculate_bonus(int* array) {
	int index = 0, score = 0, bonus = 0;
	while (index < 6) {
		score += array[index];
		++index;
	}
	if (score >= 63) {
		bonus = BONUS_POINTS;
	}
	return(bonus);
}




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

void display_scoreboard_both(int *player1_score, int *player2_score, int array_size, int *player1_total, int *player2_total, int round) {
	int player1_bonus = 0, player2_bonus = 0;
	player1_bonus = calculate_bonus(player1_score);
	player2_bonus = calculate_bonus(player2_score);
	*player1_total = calculate_sum_score(player1_score, array_size) + player1_bonus;
	*player2_total = calculate_sum_score(player2_score, array_size) + player2_bonus;
	printf("                  End of Round %d!\n", round);
	printf("                             Player 1              Player 2  \n\n");
	printf("   Sum of 1s                   %2d                     %2d	 \n", player1_score[0], player2_score[0]);
	printf("   Sum of 2s                   %2d                     %2d     \n", player1_score[1], player2_score[1]);
	printf("   Sum of 3s                   %2d                     %2d     \n", player1_score[2], player2_score[2]);
	printf("   Sum of 4s                   %2d                     %2d     \n", player1_score[3], player2_score[3]);
	printf("   Sum of 5s                   %2d                     %2d     \n", player1_score[4], player2_score[4]);
	printf("   Sum of 6s                   %2d                     %2d     \n", player1_score[5], player2_score[5]);
	printf("     Bonus                     %2d                     %2d     \n", player1_bonus, player2_bonus);
	printf(" Three of a kind               %2d                     %2d     \n", player1_score[6], player2_score[6]);
	printf(" Four of a kind                %2d                     %2d     \n", player1_score[7], player2_score[7]);
	printf("   Full House                  %2d                     %2d     \n", player1_score[8], player2_score[8]);
	printf(" Small Straight                %2d                     %2d     \n", player1_score[9], player2_score[9]);
	printf(" Large Straight                %2d                     %2d     \n", player1_score[10], player2_score[10]);
	printf("    Yahtzee                    %2d                     %2d     \n", player1_score[11], player2_score[11]);
	printf("     Chance                    %2d                     %2d     \n\n", player1_score[12], player2_score[12]);
	printf("     Total                    %3d                    %3d     \n", *player1_total, *player2_total);
	press_any_key();
	clear_screen();
}





/*************************************************************
* Function: calculate_sum_score()							*
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

int calculate_sum_score(int* array, int size) {
	int index = 0, score = 0;
	while (index < size) {
		score += array[index];
		++index;
	}
	return(score);
}





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

void display_winner(int *player1_score, int *player2_score) {
	if (*player1_score > *player2_score) {
		printf("Player 1 Wins, %d to %d!\n", *player1_score, *player2_score);
	}
	if (*player2_score > *player1_score) {
		printf("Player 2 Wins, %d to %d!\n", *player2_score, *player1_score);
	}
	if (*player1_score == *player2_score){
		printf("It's a tie! Well played!\n");
	}
	press_any_key();
	clear_screen();
}






/*************************************************************
* Function: calculate_temporary_score()						*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Populates an array with the available scores	*
* that are based on the player's dice rolls and previous	*
* selections.
* Input parameters: int *dice, int *dice_frequency, int		*
* *score_mirror, int *player_score							*
* Output parameters: int *temporary_score					*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void calculate_temporary_score(int* dice, int* dice_frequency, int* temporary_score, int* score_mirror, int *player_score) {
	// sum of 1s
	if (score_mirror[0] != 1) {
		temporary_score[0] = dice_frequency[1];
	}
	if (score_mirror[0] == 1) {
		temporary_score[0] = 0;
	}

	// sum of 2s
	if (score_mirror[1] != 1) {
		temporary_score[1] = 2 * dice_frequency[2];
	}
	if (score_mirror[1] == 1) {
		temporary_score[1] = 0;
	}

	// sum of 3s
	if (score_mirror[2] != 1) {
		temporary_score[2] = 3 * dice_frequency[3];
	}
	if (score_mirror[2] == 1) {
		temporary_score[2] = 0;
	}
	
	// sum of 4s
	if (score_mirror[3] != 1) {
		temporary_score[3] = 4 * dice_frequency[4];
	}
	if (score_mirror[3] == 1) {
		temporary_score[3] = 0;
	}

	// sum of 5s
	if (score_mirror[4] != 1) {
		temporary_score[4] = 5 * dice_frequency[5];
	}
	if (score_mirror[4] == 1) {
		temporary_score[4] = 0;
	}

	// sum of 6s
	if (score_mirror[5] != 1) {
		temporary_score[5] = 6 * dice_frequency[6];
	}
	if (score_mirror[5] == 1) {
		temporary_score[5] = 0;
	}

	// three of a kind
	if (score_mirror[6] != 1) {
		if (sequential_search(dice_frequency, 7, 3) == 1) {
			temporary_score[6] = calculate_sum_score(dice, 5);
		}
		else if (sequential_search(dice_frequency, 7, 4) == 1) {
			temporary_score[6] = calculate_sum_score(dice, 5);
		}
		else if (sequential_search(dice_frequency, 7, 5) == 1) {
			temporary_score[6] = calculate_sum_score(dice, 5);
		}
	}
	if (score_mirror[6] == 1) {
		temporary_score[6] = 0;
	}


	// four of a kind
	if (score_mirror[7] != 1)	{
		if (sequential_search(dice_frequency, 7, 4) == 1) {
			temporary_score[7] = calculate_sum_score(dice, 5);
		}
		else if (sequential_search(dice_frequency, 7, 5) == 1) {
			temporary_score[7] = calculate_sum_score(dice, 5);
		}
	}
	if (score_mirror[7] == 1) {
		temporary_score[7] = 0;
	}

	// full house
	if (score_mirror[8] != 1)	{
		if ((sequential_search(dice_frequency, 7, 3) == 1) &&
			(sequential_search(dice_frequency, 7, 2) == 1)) {
			temporary_score[8] = 25;
		}
	}
	if (score_mirror[8] == 1) {
		temporary_score[8] = 0;
	}

	// small straight
	if (score_mirror[9] != 1)	{
		if (((dice_frequency[1] >= 1) && (dice_frequency[2] >= 1) && (dice_frequency[3] >= 1) && (dice_frequency[4] >= 1)) ||
			((dice_frequency[2] >= 1) && (dice_frequency[3] >= 1) && (dice_frequency[4] >= 1) && (dice_frequency[5] >= 1)) ||
			((dice_frequency[3] >= 1) && (dice_frequency[4] >= 1) && (dice_frequency[5] >= 1) && (dice_frequency[6] >= 1))) {
			temporary_score[9] = 30;
		}
	}
	if (score_mirror[9] == 1) {
		temporary_score[9] = 0;
	}

	// large straight
	if (score_mirror[10] != 1)	{
		if (((dice_frequency[1] >= 1) && (dice_frequency[2] >= 1) && (dice_frequency[3] >= 1) && (dice_frequency[4] >= 1) && (dice_frequency[5] >= 1)) ||
			((dice_frequency[2] >= 1) && (dice_frequency[3] >= 1) && (dice_frequency[4] >= 1) && (dice_frequency[5] >= 1) && (dice_frequency[6] >= 1))) {
			temporary_score[10] = 40;
		}
	}
	if (score_mirror[10] == 1) {
		temporary_score[10] = 0;
	}

	// yahtzee
	if (score_mirror[11] != 1)	{
		if ((dice_frequency[1] == 5) || (dice_frequency[2] == 5) || (dice_frequency[3] == 5) ||
			(dice_frequency[4] == 5) || (dice_frequency[5] == 5) || (dice_frequency[6] == 5)) {
			temporary_score[11] = 50;
		}
	}
	if (score_mirror[11] == 1) {
		temporary_score[11] == 0;
	}

	// chance
	if (score_mirror[12] != 1)	{
		temporary_score[12] = calculate_sum_score(dice, 5);
	}
	if (score_mirror[12] == 1) {
		temporary_score[12] = 0;
	}
}






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

void display_temporary_score(int *temporary_score, int *score_mirror) {
	printf("                           Score     \n\n");
	if (score_mirror[0] == 0) {
		printf("1.  Sum of 1s               %2d       \n", temporary_score[0]);
	}
	if (score_mirror[1] == 0) {
		printf("2.  Sum of 2s               %2d       \n", temporary_score[1]);
	}
	if (score_mirror[2] == 0) {
		printf("3.  Sum of 3s               %2d       \n", temporary_score[2]);
	}
	if (score_mirror[3] == 0) {
		printf("4.  Sum of 4s               %2d       \n", temporary_score[3]);
	}
	if (score_mirror[4] == 0) {
		printf("5.  Sum of 5s               %2d       \n", temporary_score[4]);
	}
	if (score_mirror[5] == 0) {
		printf("6.  Sum of 6s               %2d       \n", temporary_score[5]);
	}
	if (score_mirror[6] == 0) {
		printf("7.  Three of a kind         %2d       \n", temporary_score[6]);
	}
	if (score_mirror[7] == 0) {
		printf("8.  Four of a kind          %2d       \n", temporary_score[7]);
	}
	if (score_mirror[8] == 0) {
		printf("9.  Full House              %2d       \n", temporary_score[8]);
	}
	if (score_mirror[9] == 0) {
		printf("10. Small Straight          %2d       \n", temporary_score[9]);
	}
	if (score_mirror[10] == 0) {
		printf("11. Large Straight          %2d       \n", temporary_score[10]);
	}
	if (score_mirror[11] == 0) {
		printf("12. Yahtzee                 %2d       \n", temporary_score[11]);
	}
	if (score_mirror[12] == 0) {
		printf("13. Chance                  %2d       \n\n", temporary_score[12]);
	}
}







/*************************************************************
* Function: reset_some_dice()								*
* Date Created: 10/19/2023                                  *
* Date Last Modified: 10/19/2023                            *
* Description: Iterates through dice and asks the user if	*
* they wish to reroll. If the user answers yes, resets the	*
* value in dice[] to 0										*
* Input parameters:	none									*
* Output parameters: int *dice								*
* Returns: void				                                *
* Preconditions: reroll = 1									*
* Postconditions: NA                                        *
*************************************************************/

void reset_some_dice(int* dice) {
	int all = -1, reroll_selection = 0;
	char input = '\0';
	do {
		do {
			printf("Would you like to reroll all of the dice? Y/N: \n");
			scanf(" %c", &input);
		} while ((input != 'Y') && (input != 'y') && (input != 'N') && (input != 'n'));

		switch (input) {
		case 'Y': {
			all = 1;
			break;
		}
		case 'y': {
			all = 1;
			break;
		}
		case 'N': {
			all = 0;
			break;
		}
		case 'n': {
			all = 0;
			break;
		}
		}
	} while ((all < 0) || (all > 1));
	if (all == 1) {
		reset_array(dice, MAX_DICE);
	}
	else if (all == 0) {
		do {
			printf("Enter a die to reroll. When done, enter 0.\n");
			scanf("%d", &reroll_selection);
			if ((reroll_selection > 0) && (reroll_selection < 6)) {
				dice[reroll_selection - 1] = 0;
				printf("Die %d has been reset!\n", reroll_selection);
			}
		} while (reroll_selection != 0);
	}
}





/*************************************************************
* Function: bubble_sort()									*
* Date Created: 10/20/2023                                  *
* Date Last Modified: 10/20/2023                            *
* Description: Sorts the values in an array in ascending	*
* order.													*
* Input parameters:	int array_size							*
* Output parameters: int *dice								*
* Returns: void				                                *
* Preconditions: NA											*
* Postconditions: NA                                        *
*************************************************************/

void bubble_sort(int* array, int array_size) {
	int index = 0, passes = 0, temp = 0;
	for (; passes < array_size; passes++) {
		for (index = 0; index + 1 < array_size - passes; index++) {
			if (array[index] > array[index + 1]) {
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
		}
	}
}







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

int how_many_saved_dice(int* dice){
	int saved_dice = 0;
	saved_dice = MAX_DICE - frequency_search(dice, MAX_DICE, 0);
	return(saved_dice);
}







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

reset_array(int* array, int array_size) {
	int index = 0;
	while (index < array_size) {
		array[index] = 0;
		++index;
	}
}








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

select_score(int *temporary_score, int *player_score, int *score_mirror) {
	int input = 0, invalid = 0;
	do	{
		do {
			printf("Enter the integer for which score you would like to save (e.g.\n"
				"enter 3 to save Sum of Threes, enter 10 to save Small Straight, etc.\n");
			scanf("%d", &input);
		} while (input < 1 || input > 13);
		invalid = score_mirror[input - 1];
		if (invalid == 1) {
			printf("This scoring field has been used previously. Please enter another value.\n");
		}
	} while (invalid == 1);
	player_score[input - 1] = temporary_score[input - 1];
	printf("Score assigned to Row %d!\n", input);
	++score_mirror[input - 1];
	press_any_key();
	clear_screen();
}