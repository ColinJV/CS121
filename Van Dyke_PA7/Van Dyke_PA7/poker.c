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


/*************************************************************
* Function: shuffle()										*
* Date Created: Unk											*
* Date Last Modified:										*
* Description: Shuffles a deck of cards. Code from Deitel &	*
* Deitel.													*
* Input parameters:	None									*
* Output parameters: int wDeck[][13]						*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}


/*************************************************************
* Function: deal()											*
* Date Created: Unk											*
* Date Last Modified: 11/21/2023							*
* Description: Deals cards into a hand.	Returns the number	*
* of cards dealt so that subsequent calls can avoid dealing	*
* the same cards again. Code adapted from Deitel & Deitel.	*
* Input parameters: const int wDeck[][13], const char*		*
* wFace[], const char* wSuit[], int cards_to_deal			*
* Output parameters: int *cards_previously_dealt, Hand		*
* *player_hand												*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void deal(const int wDeck[][13], int *cards_previously_dealt, int cards_to_deal, Hand *player_hand)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = *cards_previously_dealt;   /* card counter */
	int players_card_index = 0;		/* location in a player's hand a card will be dealt to */
	int found = 0;

	/* deal each of the 52 cards */
	for (card = card + 1; card <= *cards_previously_dealt + cards_to_deal; card++)
	{
		found = 0;
		/* loop through rows of wDeck */
		for (row = 0; !found && row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; !found && column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					player_hand->cards_in_hand[players_card_index].face_value_index = column;
					player_hand->cards_in_hand[players_card_index].suit_index = row;
					++players_card_index;
					found = 1;
				}
			}
		}
	}
	// this is actually one higher than the actual number of cards dealt due to the increment of card at the end of the loop
	// this is intentionally left this way to act as a burn card
	*cards_previously_dealt = card;
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
* Function: get_positive_or_zero_integer_input()			*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 11/19/2023                            *
* Description: Scans for an non-negative integer input from *
* the user and returns its value if positive or zero.		*
* Input parameters: void									*
* Returns: int												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int get_positive_or_zero_integer_input(void) {
	int integer_result = 0, string_index = 0, temp = 0, valid = 0, error = 0;
	char input[10];
	do	{
		do {
			string_index = 0;
			error = 0;
			fgets(input, sizeof(input), stdin);
			while ((input[string_index] != '\0') && (input[string_index] != '\n') && error == 0) {
				temp = 0;
				if (isdigit(input[string_index])) {
					temp = input[string_index] - '0';
					integer_result = (integer_result * 10) + temp;
				}
				else if (!isdigit(input[string_index])) {
					error = 1;
				}
				++string_index;
			}
			if (error == 1) {
				puts("The provided input is invalid. Please try again.\n");
				integer_result = 0;
				temp = 0;
			}
		} while (error == 0 && input[string_index] != '\0' && input[string_index] != '\n');
		if (error == 0) {
			valid = 1;
		}
	} while (valid == 0);
	return(integer_result);
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
* Function: display_game_rules()	                        *
* Date Created: 10/16/2023                                  *
* Date Last Modified: 11/19/2023                            *
* Description: Displays the rules of 5-card draw.			*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: User requested rules to be displayed       *
* Postconditions: NA                                        *
*************************************************************/

void display_game_rules(void) {
	printf("Rules of Poker (5-Card Draw):\n");
	printf("Each player is dealt five cards. The strength of your hand is determined by the combination of cards.\n");
	printf("The strength of hands from least to greatest is as follows: high card, single pair, two pair, three-of-\n");
	printf("a-kind, straight (contiguous sequence of 5 cards), flush (all five cards are of one suit), full-house\n");
	printf("(three-of-a-kind and a pair), four-of-a-kind (four of one face value card and one other card called)\n");
	printf("a kicker), and a straight flush (a contiguous sequence of cards of the same suit). After the cards are\n");
	printf("dealt, each player may discard as many of their cards as they wish and draw until they have five total.\n");
	printf("After the draw, the player with the best hand wins. In the event two players have the same hand, the\n");
	printf("value of the cards in the hand determine the winner (e.g. Ace high flush beats a Queen high flush, pair");
	printf("of 10s beats a pair of 7s, etc.)");
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
* Function: display_splash_screen()							*
* Date Created: 10/16/2023                                  *
* Date Last Modified: 11/24/2023                            *
* Description: Displays "BATTLESHIP" in ASCII art generated *
* by textkool.com/en/ascii-art-generator					*
* Input parameters: void									*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_splash_screen(void) {
	printf("                                                                                 \n");
	printf("8 888888888o       ,o888888o.     8 8888     ,88' 8 8888888888   8 888888888o.   \n");
	printf("8 8888    `88.  . 8888     `88.   8 8888    ,88'  8 8888         8 8888    `88.  \n");
	printf("8 8888     `88 ,8 8888       `8b  8 8888   ,88'   8 8888         8 8888     `88  \n");
	printf("8 8888     ,88 88 8888        `8b 8 8888  ,88'    8 8888         8 8888     ,88  \n");
	printf("8 8888.   ,88' 88 8888         88 8 8888 ,88'     8 888888888888 8 8888.   ,88'  \n");
	printf("8 888888888P'  88 8888         88 8 8888 88'      8 8888         8 888888888P'   \n");
	printf("8 8888         88 8888        ,8P 8 888888<       8 8888         8 8888`8b       \n");
	printf("8 8888         `8 8888       ,8P  8 8888 `Y8.     8 8888         8 8888 `8b.     \n");
	printf("8 8888          ` 8888     ,88'   8 8888   `Y8.   8 8888         8 8888   `8b.   \n");
	printf("8 8888             `8888888P'     8 8888     `Y8. 8 888888888888 8 8888     `88. \n");
	printf("\n\n");
}


/*************************************************************
* Function: generate_frequency_table()						*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Generates a frequency table for the face		*
* values in a user's hand.									*
* Input parameters: Hand user_hand							*
* Output parameters: int frequency_table_faces				*
* Returns: void												*
* Preconditions: An integer array frequency table has been	*
* declared in the calling function							*
* Postconditions: None										*
*************************************************************/

void generate_frequency_tables(Hand *user_hand, int *frequency_table_faces, int *frequency_table_suits) {
	int index = 0;
	for (; index < HAND_SIZE; ++index) {
		++(frequency_table_faces[(user_hand->cards_in_hand[index].face_value_index)]);
	}
	for (index = 0; index < HAND_SIZE; ++index) {
		++(frequency_table_suits[(user_hand->cards_in_hand[index].suit_index)]);
	}
}


/*************************************************************
* Function: check_for_pair()								*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for a pair of cards, returns 1	*
* if a pair exists and 0 if a pair does not exist.			*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int pair (0 or 1)								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_pair(int *frequency_table_face_values) {
	int pair = 0, index = 0;
	for (; index < FACE_VALUES && !pair; ++index) {
		if (frequency_table_face_values[index] == 2) {
			pair = 1;
		}
	}
	return(pair);
}


/*************************************************************
* Function: check_for_two_pair()							*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for two pairs of cards, returns*
* 1 if two-pair exists and 0 if two-pair does not exist.	*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int two_pair (0 or 1)							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_two_pair(int *frequency_table_face_values) {
	int pair = 0, two_pair = 0, index = 0, first_pair_index = 0, second_index = 0;
	for (; index < FACE_VALUES && !pair; ++index) {
		if (frequency_table_face_values[index] == 2) {
			pair = 1;
			first_pair_index = index;
		}
	}
	for (; pair && !two_pair && second_index < FACE_VALUES; ++second_index) {
		if (frequency_table_face_values[second_index] == 2 && second_index != first_pair_index) {
			two_pair = 1;
		}
	}
	return(two_pair);
}


/*************************************************************
* Function: check_for_trips()								*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for three-of-a-kind, returns 1	*
* if trips exists and 0 if trips does not exist.			*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int trips (0 or 1)								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_trips(int *frequency_table_face_values) {
	int index = 0, trips = 0;

	for (; index < FACE_VALUES; ++index) {
		if (frequency_table_face_values[index] == 3) {
			trips = 1;
		}
	}	

	return(trips);
}


/*************************************************************
* Function: check_for_straight()							*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for a straight. Returns 1 if a	*
* straight exists and 0 if a straight does not exist.		*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int straight (0 or 1)							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_straight(int *frequency_table_face_values) {
	int straight = 0, index = 0, start_of_straight = 0, found = 0;

	/* checks for all straights except Wheel */
	for (index = 0; !found && index < FACE_VALUES - 4; ++index) {
		if (frequency_table_face_values[index] != 0) {
			found = 1;
			start_of_straight = index;
		}
	}
	if (frequency_table_face_values[start_of_straight] == 1 &&
		frequency_table_face_values[start_of_straight + 1] == 1 &&
		frequency_table_face_values[start_of_straight + 2] == 1 &&
		frequency_table_face_values[start_of_straight + 3] == 1 &&
		frequency_table_face_values[start_of_straight + 4] == 1) {
		straight = 1;
	}

	/* checks for Wheel if no other straight exists */
	if (!straight) {
		if (frequency_table_face_values[ACE] == 1 &&
			frequency_table_face_values[DEUCE] == 1 &&
			frequency_table_face_values[THREE] == 1 &&
			frequency_table_face_values[FOUR] == 1 &&
			frequency_table_face_values[FIVE] == 1) {
			straight = 1;
		}
	}
	return(straight);
}


/*************************************************************
* Function: check_for_flush()								*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for a flush. Returns 1 if a	*
* flush exists and 0 if a flush does not exist.				*
* Input parameters: int *frequency_table_suit_values		*
* Returns: int flush (0 or 1)								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_flush(int *frequency_table_suit_values) {
	int flush = 0, index = 0;
	for (; index < NUMBER_OF_SUITS && !flush; ++index) {
		if (frequency_table_suit_values[index] == 5) {
			flush = 1;
		}
	}
	return(flush);
}


/*************************************************************
* Function: check_for_full_house()							*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for a full house. Returns 1 if *
* a full house exists and 0 if a full house does not exist.	*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int full_house (0 or 1)							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_full_house(int *frequency_table_face_values) {
	int full_house = 0, pair = 0, trips = 0;

	pair = check_for_pair(frequency_table_face_values);
	trips = check_for_trips(frequency_table_face_values);

	if (pair && trips) {
		full_house = 1;
	}

	return(full_house);
}


/*************************************************************
* Function: check_for_quads()								*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Checks a hand for four-of-a-kind, returns 1	*
* if quads exists and 0 if quads does not exist.			*
* Input parameters: int frequency_table_face_values[]		*
* Returns: int quads (0 or 1)								*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_quads(int *frequency_table_face_values) {
	int index = 0, quads = 0;

	for (; index < FACE_VALUES; ++index) {
		if (frequency_table_face_values[index] == 4) {
			quads = 1;
		}
	}

	return(quads);
}


/*************************************************************
* Function: determine_hand_strength()						*
* Date Created: 11/21/2023                                  *
* Date Last Modified: 11/21/2023                            *
* Description: Determines the strength of a player's hand,	*
* returning a value in accordance with the Strength			*
* enumerated type.											*
* Input parameters: int *user_face_frequency_table, int		*
* *user_suit_frequency_table								*
* Returns: int strength										*
* Preconditions: Frequency tables have been generated		*
* Postconditions: None										*
*************************************************************/

int determine_hand_strength(int *user_face_frequency_table, int *user_suit_frequency_table) {
	int strength = HIGH_CARD;

	if (check_for_pair(user_face_frequency_table)) {
		if (check_for_two_pair(user_face_frequency_table)) {
			strength = TWO_PAIR;
		}
		else if (check_for_full_house(user_face_frequency_table)) {
			strength = FULL_HOUSE;
		}
		else strength = PAIR;
	}

	if (!strength && check_for_trips(user_face_frequency_table)) {
		if (check_for_full_house(user_face_frequency_table)) {
			strength = FULL_HOUSE;
		}
		else strength = THREE_OF_A_KIND;
	}

	if (!strength && check_for_straight(user_face_frequency_table)) {
		strength = STRAIGHT;
	}

	if (!strength && check_for_flush(user_suit_frequency_table)) {
		strength = FLUSH;
	}

	if (!strength && check_for_quads(user_face_frequency_table)) {
		strength = FOUR_OF_A_KIND;
	}

	if (check_for_straight(user_face_frequency_table) && check_for_flush(user_suit_frequency_table)) {
		strength = STRAIGHT_FLUSH;
	}

	return(strength);
}


/*************************************************************
* Function: display_hand_strength()							*
* Date Created: 11/24/2023                                  *
* Date Last Modified: 11/24/2023                            *
* Description: Displays the strength of a player's current	*
* hand.														*
* Input parameters: int strength, const char* hands[], int	*
* cpu_or_player												*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_hand_strength(int strength, const char* hands[], int cpu_or_player) {
	if (cpu_or_player == 0) {
		printf("The strength of the computer's hand is %s.\n", hands[strength]);
	}
	else {
		printf("The strength of your current hand is %s.\n", hands[strength]);
	}
}


/*************************************************************
* Function: cpu_draw_cards()								*
* Date Created: 11/24/2023                                  *
* Date Last Modified: 11/24/2023                            *
* Description: Determines which cards the CPU will draw		*
* depending on the strength of their hand and calls the		*
* draw() function with its required arguments.				*
* Input parameters: int cpu_strength, const int wDeck[][13],*
* int *cpu_face_frequency_table, int *cpu_suit_frequency_table,	*
* Hand *cpu_hand, int *cards_previously_dealt				*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void cpu_draw_cards(int cpu_strength, int *cpu_face_frequency_table, int *cpu_suit_frequency_table, Hand *cpu_hand, 
	const int wDeck[][13], int *cards_previously_dealt) {
	
	if (check_for_flush_draw(cpu_suit_frequency_table) && cpu_strength < TWO_PAIR) {
		int nonsuited_index = -1;
		nonsuited_index = find_nonsuited_card(cpu_hand);
		draw(wDeck, cards_previously_dealt, cpu_hand, nonsuited_index);
	}

	else if (cpu_strength == HIGH_CARD) {
		int lowest_index = 0;
		lowest_index = find_lowest_nonpair_card(cpu_hand);
		draw(wDeck, cards_previously_dealt, cpu_hand, lowest_index);
		draw(wDeck, cards_previously_dealt, cpu_hand, find_second_lowest_nonpair_card(cpu_hand, lowest_index));
	}
	
	else if (cpu_strength == PAIR) {
		draw(wDeck, cards_previously_dealt, cpu_hand, find_lowest_nonpair_card(cpu_hand));
	}

	else if (cpu_strength == TWO_PAIR) {
		int index = 0;
		for (; index < HAND_SIZE; ++index) {
			if (!makes_a_pair(index, cpu_hand)) {
				draw(wDeck, cards_previously_dealt, cpu_hand, index);
			}
		}
	}

	else if (cpu_strength == THREE_OF_A_KIND) {
		draw(wDeck, cards_previously_dealt, cpu_hand, find_lowest_nonpair_card(cpu_hand));
	}

	else if (cpu_strength == STRAIGHT) {}

	else if (cpu_strength == FLUSH) {}

	else if (cpu_strength == FULL_HOUSE) {}

	else if (cpu_strength == FOUR_OF_A_KIND) {
		// no one would ever do this in five card draw, I included it because it's funny
		int index = 0;
		for (; index < HAND_SIZE; ++index) {
			if (!makes_a_pair(index, cpu_hand) && 
				cpu_hand->cards_in_hand[index].face_value_index < TEN) {
				draw(wDeck, cards_previously_dealt, cpu_hand, index);
			}
		}
	}

	else if (cpu_strength == STRAIGHT_FLUSH) {}
}


/*************************************************************
* Function: draw()											*
* Date Created: Unk											*
* Date Last Modified: 11/24/2023							*
* Description: Deals cards into a provided index in a hand	*
* during the draw round. Adapted from Deitel & Deitel deal()*
* function.													*
* Input parameters: wFace[], const char* wSuit[], int		*
* card_index_drawn											*
* Output parameters: int *cards_previously_dealt, Hand		*
* *player_hand												*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void draw(const int wDeck[][13],int* cards_previously_dealt, Hand* player_hand, int card_index_drawn)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = *cards_previously_dealt;   /* card counter */
	int found = 0;

	found = 0;
	/* loop through rows of wDeck */
	for (row = 0; !found && row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; !found && column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == card)
			{
				/*printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');*/
				player_hand->cards_in_hand[card_index_drawn].face_value_index = column;
				player_hand->cards_in_hand[card_index_drawn].suit_index = row;
				found = 1;
			}
		}
	}
	// adding one here is intentional, it's a burn card
	*cards_previously_dealt = card + 1;
}


/*************************************************************
* Function: prompt_for_draw()								*
* Date Created: 11/24/2023                                  *
* Date Last Modified: 11/24/2023                            *
* Description: Prompts the player for which cards they wish	*
* to redraw.												*
* Input parameters:	void									*
* Returns: int input										*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int prompt_for_redraw(void) {
	int input = 0;
	printf("Enter a card to redraw. You may redraw, at most, three cards. If none, enter 0.\n");
	input = get_positive_or_zero_integer_input();
	return(input);
}


/*************************************************************
* Function: display_hand()									*
* Date Created: 11/24/2023                                  *
* Date Last Modified: 11/24/2023                            *
* Description: Displays the five cards in a player's hand.	*
* Input parameters:	Hand *user_hand, const char wFace[],	*
* const char* wSuit[], int cpu_or_player					*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_hand(Hand *user_hand, const char* wFace[], const char* wSuit[], int cpu_or_player) {
	int index = 0;
	if (cpu_or_player == 0) {
		printf("Computer's Hand:\n");
	}
	else if (cpu_or_player == 1) {
		printf("Your Hand:\n");
	}
	for (; index < HAND_SIZE; ++index) {
		printf("Card %d: %5s of %-8s\n", index + 1, wFace[user_hand->cards_in_hand[index].face_value_index], wSuit[user_hand->cards_in_hand[index].suit_index]);
	}
}


/*************************************************************
* Function: player_redraw()									*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Allows the player to redraw up to three cards*
* to their hand, does not allow drawing the same card slot	*
* multiple times.											*
* Input parameters:	Hand user_hand, const int wDeck[][13],	*
* int *cards_previously_dealt								*
* Returns: void												*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void player_redraw(Hand* user_hand, const int wDeck[][13], int* cards_previously_dealt) {
	int draw_1 = 0, draw_2 = 0, draw_3 = 0, draw_4 = 0, draw_5 = 0, redraw_input = 0, cards_drawn = 0;
	do {
		redraw_input = prompt_for_redraw();
		if (redraw_input == 1) {
			if (!draw_1) {
				draw(wDeck, cards_previously_dealt, user_hand, redraw_input - 1);
				draw_1 = 1;
				++cards_drawn;
			}
			else {
				printf("You cannot draw for a card you have already redrawn.\n");
			}
		}
		else if (redraw_input == 2) {
			if (!draw_2) {
				draw(wDeck, cards_previously_dealt, user_hand, redraw_input - 1);
				draw_2 = 1;
				++cards_drawn;
			}
			else {
				printf("You cannot draw for a card you have already redrawn.\n");
			}
		}
		else if (redraw_input == 3) {
			if (!draw_3) {
				draw(wDeck, cards_previously_dealt, user_hand, redraw_input - 1);
				draw_3 = 1;
				++cards_drawn;
			}
			else {
				printf("You cannot draw for a card you have already redrawn.\n");
			}
		}
		else if (redraw_input == 4) {
			if (!draw_4) {
				draw(wDeck, cards_previously_dealt, user_hand, redraw_input - 1);
				draw_4 = 1;
				++cards_drawn;
			}
			else {
				printf("You cannot draw for a card you have already redrawn.\n");
			}
		}
		else if (redraw_input == 5) {
			if (!draw_5) {
				draw(wDeck, cards_previously_dealt, user_hand, redraw_input - 1);
				draw_5 = 1;
				++cards_drawn;
			}
			else {
				printf("You cannot draw for a card you have already redrawn.\n");
			}
		}
	} while (redraw_input && cards_drawn < 3);
}


/*************************************************************
* Function: check_for_flush_draw()							*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Checks a frequency table to see if a player	*
* is on a flush draw. Returns 1 if yes, 0 if no.			*
* Input parameters:	int suit_frequency_table				*
* Returns: int flush_draw (0 or 1)							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int check_for_flush_draw(int* suit_frequency_table) {
	int index = 0, flush_draw = 0;
	for (; index < NUMBER_OF_SUITS; ++index) {
		if (suit_frequency_table[index] == 4) {
			flush_draw = 1;
		}
	}
	return(flush_draw);
}


/*************************************************************
* Function: find_nonsuited_card()							*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Searches a hand for a nonsuited card.		*
* Returns the index where it is located.					*
* Input parameters:	Hand *user_hand							*
* Returns: int flush_draw (0 or 1)							*
* Preconditions: The player whose hand is input is on a 	*
* flush draw (i.e. check_for_flush_draw() returns 1)		*
* Postconditions: None										*
*************************************************************/

int find_nonsuited_card(Hand* user_hand) {
	int index = 0, found = 0, nonsuited_index = -1;
	for (; !found && index < HAND_SIZE - 2; ++index) {
		if (user_hand->cards_in_hand[index].suit_index != user_hand->cards_in_hand[index + 1].suit_index &&
			user_hand->cards_in_hand[index].suit_index != user_hand->cards_in_hand[index + 2].suit_index) {
			nonsuited_index = index;
			found = 1;
		}
	}
	for (; !found && index < HAND_SIZE; ++index) {
		if (user_hand->cards_in_hand[index].suit_index != user_hand->cards_in_hand[index - 1].suit_index &&
			user_hand->cards_in_hand[index].suit_index != user_hand->cards_in_hand[index - 2].suit_index) {
			nonsuited_index = index;
			found = 1;
		}
	}
	return(nonsuited_index);
}


/*************************************************************
* Function: find_lowest_nonpair_card()						*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Searches a hand for the lowest card that		*
* does not form a pair or three of a kind or quads. Returns	*
* the index of that card.									*
* Input parameters:	Hand *user_hand							*
* Returns: int lowest_index									*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_lowest_nonpair_card(Hand* user_hand) {
	int index = 0, lowest_index = -1, lowest_value = 15;
	for (; index < HAND_SIZE; ++index) {
		if (!makes_a_pair(index, user_hand)) {
			if (user_hand->cards_in_hand[index].face_value_index < lowest_value) {
				lowest_value = user_hand->cards_in_hand[index].face_value_index;
				lowest_index = index;
			}
		}
	}
	return(lowest_index);
}


/*************************************************************
* Function: makes_a_pair()									*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Searches a hand to determine if the card at	*
* the provided index makes a pair with any other card. If	*
* yes, returns 1. If no, returns 0.							*
* Input parameters:	Hand *user_hand, int index				*
* Returns: int pair											*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int makes_a_pair(int index, Hand* user_hand) {
	int pair = 0, comparison_index = 0;
	for (comparison_index = 0; !pair && comparison_index < HAND_SIZE; ++comparison_index) {
		if (user_hand->cards_in_hand[index].face_value_index == user_hand->cards_in_hand[comparison_index].face_value_index &&
			index != comparison_index) {
			pair = 1;
		}
	}
	return(pair);
}


/*************************************************************
* Function: find_second_lowest_nonpair_card()				*
* Date Created: 11/25/2023                                  *
* Date Last Modified: 11/25/2023                            *
* Description: Searches a hand for the 2nd lowest card that	*
* does not form a pair or three of a kind or quads. Returns	*
* the index of that card.									*
* Input parameters:	Hand *user_hand, int index_of_lowest	*
* Returns: int second_lowest_index							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_second_lowest_nonpair_card(Hand* user_hand, int index_of_lowest) {
	int index = 0, second_lowest_index = -1, second_lowest_value = 15;
	for (; index < HAND_SIZE; ++index) {
		if (!makes_a_pair(index, user_hand)) {
			if (user_hand->cards_in_hand[index].face_value_index < second_lowest_value &&
				index != index_of_lowest) {
				second_lowest_value = user_hand->cards_in_hand[index].face_value_index;
				second_lowest_index = index;
			}
		}
	}
	return(second_lowest_index);
}


/*************************************************************
* Function: reset_frequency_table()							*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Resets all values of a frequency table to	*
* zero.														*
* Input parameters: int size								*
* Output parameters: int *frequency_table					*
* Returns: void												*
* Preconditions: An integer array frequency table has been	*
* declared in the calling function							*
* Postconditions: None										*
*************************************************************/

void reset_frequency_table(int* frequency_table, int size) {
	int index = 0;
	for (; index < size; ++index) {
		frequency_table[index] = 0;
	}
}


/*************************************************************
* Function: decide_winner()									*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Determines a winning hand and decides tie-	*
* breakers if necessary. Returns 1 for player win, 0 for 	*
* CPU win, -1 for tie.										*
* Input parameters: int cpu_strength, int player_strength,	*
* Hand *player_hand, Hand *cpu_hand, int *cpu_face_frequency_table,	*
* int *player_face_frequency_table							*
* Output parameters: none									*
* Returns: int winner										*
* Preconditions: draw_round == 2							*
* Postconditions: None										*
*************************************************************/

int decide_winner(int cpu_strength, int player_strength, Hand* cpu_hand, Hand* player_hand, 
	int *cpu_face_frequency_table, int *player_face_frequency_table) {
	int winner = 10;

	if (player_strength > cpu_strength) {
		winner = 1;
	}
	else if (cpu_strength > player_strength) {
		winner = 0;
	}
	else {
		if (cpu_strength == HIGH_CARD) {
			int highest_player_value = 0, highest_cpu_value = 0;

			highest_player_value = find_highest_nonpair_card(player_hand);
			highest_cpu_value = find_highest_nonpair_card(cpu_hand);

			if (highest_player_value > highest_cpu_value) {
				winner = 1;
			}
			else if (highest_cpu_value > highest_player_value) {
				winner = 0;
			}
			else if (highest_cpu_value == highest_player_value) {
				winner = -1;
			}
		}
		else if (cpu_strength == PAIR) {
			int highest_cpu_pair = -1, highest_player_pair = -1;

			highest_cpu_pair = find_highest_paired_value(cpu_face_frequency_table);
			highest_player_pair = find_highest_paired_value(player_face_frequency_table);

			if (highest_cpu_pair > highest_player_pair) {
				winner = 0;
			}
			else if (highest_player_pair > highest_cpu_pair) {
				winner = 1;
			}
			else if (highest_player_pair == highest_cpu_pair) {
				int highest_cpu_card = 0, highest_player_card = 0;

				highest_cpu_card = find_highest_nonpair_card(cpu_hand);
				highest_player_card = find_highest_nonpair_card(player_hand);
				
				if (highest_player_card > highest_cpu_card) {
					winner = 1;
				}
				else if (highest_cpu_card > highest_player_card) {
					winner = 0;
				}
				else if (highest_cpu_card == highest_player_card) {
					winner = -1;
				}
			}
		}
		else if (cpu_strength == TWO_PAIR) {
			int highest_cpu_pair = -1, highest_player_pair = -1;

			highest_cpu_pair = find_highest_paired_value(cpu_face_frequency_table);
			highest_player_pair = find_highest_paired_value(player_face_frequency_table);

			if (highest_cpu_pair > highest_player_pair) {
				winner = 0;
			}
			else if (highest_player_pair > highest_cpu_pair) {
				winner = 1;
			}
			else if (highest_player_pair == highest_cpu_pair) {
				int second_player_pair = 0, second_cpu_pair = 0;

				second_player_pair = find_second_highest_paired_value(player_face_frequency_table, highest_player_pair);
				second_cpu_pair = find_second_highest_paired_value(cpu_face_frequency_table, highest_cpu_pair);

				if (second_player_pair > second_cpu_pair) {
					winner = 1;
				}
				else if (second_cpu_pair > second_player_pair) {
					winner = 0;
				}
				else if (second_cpu_pair == second_player_pair) {
					int player_kicker = 0, cpu_kicker = 0;

					player_kicker = find_highest_nonpair_card(player_hand);
					cpu_kicker = find_highest_nonpair_card(cpu_hand);

					if (player_kicker > cpu_kicker) {
						winner = 1;
					}
					else if (cpu_kicker > player_kicker) {
						winner = 0;
					}
					else if (cpu_kicker == player_kicker) {
						winner = -1;
					}
				}
			}
		}
		else if (cpu_strength == THREE_OF_A_KIND) {
			int player_trips = -1, cpu_trips = -1;

			player_trips = find_highest_paired_value(player_face_frequency_table);
			cpu_trips = find_highest_paired_value(cpu_face_frequency_table);

			if (player_trips > cpu_trips) {
				winner = 1;
			}
			else if (cpu_trips > player_trips) {
				winner = 0;
			}
		}
		else if (cpu_strength == STRAIGHT) {
			int player_high_card = -1, cpu_high_card = -1;

			player_high_card = find_highest_nonpair_card(player_hand);
			cpu_high_card = find_highest_nonpair_card(cpu_hand);

			if (player_high_card > cpu_high_card) {
				winner = 1;
			}
			else if (cpu_high_card > player_high_card) {
				winner = 0;
			}
			else if (cpu_high_card == player_high_card) {
				winner = -1;
			}
		}
		else if (cpu_strength == FLUSH) {
			int player_high_card = -1, cpu_high_card = -1;

			player_high_card = find_highest_nonpair_card(player_hand);
			cpu_high_card = find_highest_nonpair_card(cpu_hand);

			if (player_high_card > cpu_high_card) {
				winner = 1;
			}
			else if (cpu_high_card > player_high_card) {
				winner = 0;
			}
			else if (cpu_high_card == player_high_card) {
				winner = -1;
			}
		}
		else if (cpu_strength == FULL_HOUSE) {
			int player_trips = -1, cpu_trips = -1;

			player_trips == find_highest_trips(player_face_frequency_table);
			cpu_trips == find_highest_trips(cpu_face_frequency_table);

			if (player_trips > cpu_trips) {
				winner = 1;
			}
			else if (cpu_trips > player_trips) {
				winner = 0;
			}
		}
		else if (cpu_strength == FOUR_OF_A_KIND) {
			int player_quads = -1, cpu_quads = -1;

			player_quads == find_highest_trips(player_face_frequency_table);
			cpu_quads == find_highest_trips(cpu_face_frequency_table);

			if (player_quads > cpu_quads) {
				winner = 1;
			}
			else if (cpu_quads > player_quads) {
				winner = 0;
			}
		}
		else if (cpu_strength == STRAIGHT_FLUSH) {
			int player_high_card = -1, cpu_high_card = -1;

			player_high_card = find_highest_nonpair_card(player_hand);
			cpu_high_card = find_highest_nonpair_card(cpu_hand);

			if (player_high_card > cpu_high_card) {
				winner = 1;
			}
			else if (cpu_high_card > player_high_card) {
				winner = 0;
			}
			else if (cpu_high_card == player_high_card) {
				winner = -1;
			}
		}
	}
	return(winner);
}


/*************************************************************
* Function: find_highest_nonpair_card()						*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Searches a hand for the highest card that	*
* does not make a pair. Returns the value of that card.		*
* Input parameters:	Hand *user_hand							*
* Returns: int lowest_index									*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_highest_nonpair_card(Hand* user_hand) {
	int index = 0, highest_index = -1, highest_value = -1;
	for (; index < HAND_SIZE; ++index) {
		if (!makes_a_pair(index, user_hand)) {
			if (user_hand->cards_in_hand[index].face_value_index > highest_value) {
				highest_value = user_hand->cards_in_hand[index].face_value_index;
			}
		}
	}
	return(highest_value);
}

/*************************************************************
* Function: find_highest_paired_value()						*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Searches a hand for the highest index with a *
* pair or higher. Returns that index.						*
* Input parameters:	int *frequency_table_faces				*
* Returns: int highest_pair_index							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_highest_paired_value(int *frequency_table_faces) {
	int index = FACE_VALUES - 1, found = 0, highest_pair_index = -1;

	for (; index >= 0 && !found; --index) {
		if (frequency_table_faces[index] >= 2) {
			found = 1;
			highest_pair_index = index;
		}
	}
	return(highest_pair_index);
}


/*************************************************************
* Function: find_second_highest_paired_value()				*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Searches a hand for the second highest index *
* with a pair or higher. Returns that index.				*
* Input parameters:	int *frequency_table_faces, int			*
* highest_index												*
* Returns: int second_highest_pair_index					*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_second_highest_paired_value(int* frequency_table_faces, int highest_index) {
	int index = FACE_VALUES - 1, found = 0, second_highest_pair_index = -1;

	for (; index >= 0 && !found; --index) {
		if (frequency_table_faces[index] >= 2 && index != highest_index) {
			found = 1;
			second_highest_pair_index = index;
		}
	}
	return(second_highest_pair_index);
}


/*************************************************************
* Function: find_second_highest_nonpair_card()				*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Searches a hand for the second highest card	*
* that does not make a pair. Returns the index of that card.*
* Input parameters:	Hand user_hand, int highest_index		*
* Returns: int second_highest_index							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_second_highest_nonpair_card(Hand* user_hand, int highest_index) {
	int index = 0, second_highest_index = -1, second_highest_value = -1;
	for (; index < HAND_SIZE; ++index) {
		if (!makes_a_pair(index, user_hand)) {
			if (user_hand->cards_in_hand[index].face_value_index > second_highest_value &&
				index != highest_index) {
				second_highest_value = user_hand->cards_in_hand[index].face_value_index;
				second_highest_index = index;
			}
		}
	}
	return(second_highest_index);
}


/*************************************************************
* Function: find_highest_trips()							*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Searches a hand for the highest index with	*
* three of a kind or higher. Returns that index.			*
* Input parameters:	int *frequency_table_faces				*
* Returns: int highest_pair_index							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

int find_highest_trips(int* frequency_table_faces) {
	int index = FACE_VALUES - 1, found = 0, highest_trips_index = -1;

	for (; index >= 0 && !found; --index) {
		if (frequency_table_faces[index] >= 3) {
			found = 1;
			highest_trips_index = index;
		}
	}
	return(highest_trips_index);
}


/*************************************************************
* Function: display_winner()								*
* Date Created: 11/26/2023                                  *
* Date Last Modified: 11/26/2023                            *
* Description: Prints a message announcing a winner and the	*
* winning hand.												*
* Input parameters:	int winner, int cpu_strength, int		*
* player_strength, const char* hands						*
* Returns: int highest_pair_index							*
* Preconditions: None										*
* Postconditions: None										*
*************************************************************/

void display_winner(int winner, int cpu_strength, int player_strength, const char* hands[]) {
	if (winner == 1) {
		printf("You have won with a %s.\n", hands[player_strength]);
	}
	else if (winner == 0) {
		printf("The computer has won with a %s.\n", hands[cpu_strength]);
	}
	else if (winner == -1) {
		printf("You have tied with the computer. You both have a %s of similar strength.\n", hands[cpu_strength]);
	}
}