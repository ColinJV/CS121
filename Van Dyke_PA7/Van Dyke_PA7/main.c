/******************************************************************
* Programmer: Colin Van Dyke
* Class: CptS 121, Fall 2023; Lab Section 09, Lecture 02
* Programming Assignment: PA7
* Date: November 19, 2023
* Description: This program implements a game of Five Card Draw
* with no betting. The user is the first player and the computer
* played user (CPU) is always the dealer and the second player.
* The deck is shuffled and each player is dealt 5 cards. First the
* player may choose to replace up to three cards, then the CPU will
* choose to replace cards depending on the strength of its hand and
* the likelihood of making a better hand (e.g. the computer will
* only pursue flush draws if it has four suited cards, the computer
* will not pursue hands that break its made hand such as discarding
* part of a Full House to make Four-of-a-kind.) After each player
* has drawn, the hands are revealed, and the player with the highest
* hand wins. At this point the game returns to the main menu and may
* be played again or the user may quit.
******************************************************************/

#include "poker.h"

int main(void)
{
	int input = 0;
	do {
		do {
			clear_screen();
			display_splash_screen();
			display_main_menu();
			input = get_positive_or_zero_integer_input();
		} while (input > 3 || input < 1);

		if (input == 1) {
			display_game_rules();
			press_any_key();
		}

		if (input == 2) {
			/* initialize suit array */
			const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

			// I moved Ace from the first position to the last position in this array
			// I know we weren't supposed to change this part of the example code but Aces are only low 
			// in a Wheel straight, and my function to find straights specifically looks for a Wheel.
			// It works better this way, otherwise it'd be really hard to stop the CPU from discarding
			// Aces when it's looking for bad cards to replace and that triggers me as a poker player

			/* initialize face array */
			const char* face[13] = { "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
				"Nine", "Ten", "Jack", "Queen", "King", "Ace" };

			/* initialize hands array */
			const char* hands[9] = { "High Card", "Pair", "Two Pair", "Three of a Kind", "Straight", 
				"Flush", "Full House", "Four of a Kind", "Straight Flush" };

			/* initalize deck array */
			int deck[4][13] = { 0 };

			/* initialize player & CPU hands and frequency tables */
			Hand player_hand[HAND_SIZE] = { 0 };
			Hand cpu_hand[HAND_SIZE] = { 0 };
			int player_face_frequency_table[FACE_VALUES] = { 0 },
				player_suit_frequency_table[NUMBER_OF_SUITS] = { 0 },
				cpu_face_frequency_table[FACE_VALUES] = { 0 },
				cpu_suit_frequency_table[NUMBER_OF_SUITS] = { 0 };
			int player = 1, cpu = 0;

			int cards_dealt = 0;
			int player_strength = 0, cpu_strength = 0;
			int draw_round = 0;
			int winner = 10;

			srand((unsigned int)time(NULL)); /* seed random-number generator */

			shuffle(deck);
			deal(deck, &cards_dealt, HAND_SIZE, &player_hand);
			deal(deck, &cards_dealt, HAND_SIZE, &cpu_hand);

			do {
				++draw_round;
				reset_frequency_table(player_face_frequency_table, FACE_VALUES);
				reset_frequency_table(player_suit_frequency_table, NUMBER_OF_SUITS);
				reset_frequency_table(cpu_face_frequency_table, FACE_VALUES);
				reset_frequency_table(cpu_suit_frequency_table, NUMBER_OF_SUITS);

				generate_frequency_tables(player_hand, player_face_frequency_table, player_suit_frequency_table);
				generate_frequency_tables(cpu_hand, cpu_face_frequency_table, cpu_suit_frequency_table);

				player_strength = determine_hand_strength(player_face_frequency_table, player_suit_frequency_table);
				cpu_strength = determine_hand_strength(cpu_face_frequency_table, cpu_suit_frequency_table);
				
				display_hand(player_hand, face, suit, player);
				display_hand_strength(player_strength, hands, player);

				if (draw_round == 1) {
					player_redraw(&player_hand, deck, &cards_dealt);
					cpu_draw_cards(cpu_strength, cpu_face_frequency_table, cpu_suit_frequency_table, &cpu_hand, deck, &cards_dealt);
				}

			} while (draw_round == 1);

			display_hand(cpu_hand, face, suit, cpu);
			display_hand_strength(cpu_strength, hands, cpu);

			winner = decide_winner(cpu_strength, player_strength, cpu_hand, player_hand, cpu_face_frequency_table, player_face_frequency_table);
			display_winner(winner, cpu_strength, player_strength, hands);

			press_any_key();
			clear_screen();
		}

	} while (input != 3);
}