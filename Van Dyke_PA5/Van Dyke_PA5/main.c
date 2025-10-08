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

int main(void) {
	int input = 0;

	srand((unsigned int)time(NULL));
	display_splash_screen();

	do {
		
		do {
			display_main_menu();
			input = get_integer_input();
			clear_screen();
		} while (input < 1 || input > 3);

		if (input == 1) {
			display_game_rules();
		}

		else if (input == 2) {

			int round = 1, turn = 0, dice[MAX_DICE] = { 0 }, dice_frequency[7] = { 0 },
				temporary_score[SCORING_FIELDS] = { 0 }, player1_score[SCORING_FIELDS] = { 0 },
				player2_score[SCORING_FIELDS] = { 0 }, player1_score_mirror[SCORING_FIELDS] = { 0 },
				player2_score_mirror[SCORING_FIELDS] = { 0 }, dice_count = 0, roll_count = 0,
				reroll = -1, saved_dice_count = 0, player1_total = 0, player2_total = 0;

			do {
				turn = 0;
				player1_total = 0;
				player2_total = 0;

				do {
					reset_array(dice, MAX_DICE);
					turn++;
					display_whose_turn(turn);
					press_any_key();
					clear_screen();
					roll_count = 0;

					do {
						dice_count = MAX_DICE - saved_dice_count;
						reroll = 0;
						reset_array(temporary_score, SCORING_FIELDS);
						reset_array(dice_frequency, 7);
						roll_dice(dice, dice_count);
						++roll_count;
						count_dice_frequency(dice, dice_frequency);
						display_dice_values(dice);

						if (turn == 1) {
							calculate_temporary_score(dice, dice_frequency, temporary_score, player1_score_mirror, player1_score);
							display_temporary_score(temporary_score, player1_score_mirror);
						}
						else if (turn == 2) {
							calculate_temporary_score(dice, dice_frequency, temporary_score, player2_score_mirror, player2_score);
							display_temporary_score(temporary_score, player2_score_mirror);
						}

						saved_dice_count = 0;
						if (roll_count < 3)	{
							reroll = prompt_for_reroll();
						}
						if (reroll == 1) {
							reset_some_dice(dice);							
						}

						bubble_sort(dice, MAX_DICE);
						saved_dice_count = how_many_saved_dice(dice);

					} while ((reroll == 1) && (roll_count < 3));

					press_any_key();
					clear_screen();
					display_dice_values(dice);
					if (turn == 1){ 
						display_temporary_score(temporary_score, player1_score_mirror);
						select_score(temporary_score, player1_score, player1_score_mirror);
					}
					else if (turn == 2) {
						display_temporary_score(temporary_score, player2_score_mirror);
						select_score(temporary_score, player2_score, player2_score_mirror);
					}
					
					saved_dice_count = 0;
				} while (turn < 2);

				display_scoreboard_both(player1_score, player2_score, SCORING_FIELDS, &player1_total, &player2_total, round);
				round++;

			} while (round < 14);
			
			display_winner(&player1_total, &player2_total);
		}
	} while (input != 3);

	return(0);
}