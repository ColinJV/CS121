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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define HAND_SIZE 5
#define NUMBER_OF_SUITS 4
#define FACE_VALUES 13

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Face { DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Strength { HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };

typedef struct card {
	int face_value_index;
	int suit_index;
} Card;

typedef struct hand {
	Card cards_in_hand[HAND_SIZE];
} Hand;


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

void shuffle(int wDeck[][13]);


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

void deal(const int wDeck[][13], int* cards_previously_dealt, int cards_to_deal, Hand* player_hand);


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

int get_positive_or_zero_integer_input(void);


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
* Function: display_game_rules()	                        *
* Date Created: 10/16/2023                                  *
* Date Last Modified: 11/19/2023                            *
* Description: Displays the rules of 5-card draw.			*
* Input parameters: void				                    *
* Returns: void				                                *
* Preconditions: User requested rules to be displayed       *
* Postconditions: NA                                        *
*************************************************************/

void display_game_rules(void);


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

void display_splash_screen(void);


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

void generate_frequency_tables(Hand* user_hand, int* frequency_table_faces, int* frequency_table_suits);


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

int check_for_pair(int* frequency_table_face_values);


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

int check_for_two_pair(int* frequency_table_face_values);


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

int check_for_trips(int* frequency_table_face_values);


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

int check_for_straight(int* frequency_table_face_values);


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

int check_for_flush(int* frequency_table_suit_values);


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

int check_for_full_house(int* frequency_table_face_values);


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

int check_for_quads(int* frequency_table_face_values);


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

int determine_hand_strength(int* user_face_frequency_table, int* user_suit_frequency_table);


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

void display_hand_strength(int strength, const char* hands[], int cpu_or_player);


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

void cpu_draw_cards(int cpu_strength, int* cpu_face_frequency_table, int* cpu_suit_frequency_table, Hand* cpu_hand,
	const int wDeck[][13], int* cards_previously_dealt);


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

void draw(const int wDeck[][13], int* cards_previously_dealt, Hand* player_hand, int card_index_drawn);


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

int prompt_for_redraw(void);


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

void display_hand(Hand* user_hand, const char* wFace[], const char* wSuit[], int cpu_or_player);


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

void player_redraw(Hand* user_hand, const int wDeck[][13], int* cards_previously_dealt);


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

int check_for_flush_draw(int* suit_frequency_table);


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

int find_nonsuited_card(Hand* user_hand);


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

int find_lowest_nonpair_card(Hand* user_hand);


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

int makes_a_pair(int index, Hand* user_hand);


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

int find_second_lowest_nonpair_card(Hand* user_hand, int index_of_lowest);


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

void reset_frequency_table(int* frequency_table, int size);


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
	int* cpu_face_frequency_table, int* player_face_frequency_table);


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

int find_highest_nonpair_card(Hand* user_hand);


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

int find_highest_paired_value(int* frequency_table_faces);


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

int find_second_highest_paired_value(int* frequency_table_faces, int highest_index);


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

int find_second_highest_nonpair_card(Hand* user_hand, int highest_index);


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

int find_highest_trips(int* frequency_table_faces);


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

void display_winner(int winner, int cpu_strength, int player_strength, const char* hands[]);