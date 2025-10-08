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

#include "battleship.h"

int main(void) {
	srand((unsigned int)time(NULL));

	int input = 0, game_count = 1;
	FILE* output_stream = fopen("battleship.log", "w");

	do	{
		int player = 0;

		display_splash_screen();
		do {
			display_main_menu();
			input = get_integer_input();
		} while (input < 1 || input > 3);

		if (input == 1) {
			display_game_rules();
			press_any_key();
			clear_screen();
		}

		if (input == 2) {
			clear_screen();

			int victory = 0, whose_turn = 0, manual = -1, turn = 1;
			char player_board[MAX_ROWS][MAX_COLUMNS] = { '\0' },
				player_mirror[MAX_ROWS][MAX_COLUMNS] = { '\0' },
				cpu_board[MAX_ROWS][MAX_COLUMNS] = { '\0' },
				cpu_mirror[MAX_ROWS][MAX_COLUMNS] = { '\0' };
			Stats player_stats = { 0, 0, 0, 0.0, 0, 0 }, 
				cpu_stats = { 0, 0, 0, 0.0, 0, 0 };
			Ship player_ships[NUMBER_OF_SHIPS] = {
				{ "Carrier", 'C', 5, CARRIER_SIZE },
				{ "Battleship", 'B', 4, BATTLESHIP_SIZE },
				{ "Cruiser", 'R', 3, CRUISER_SIZE },
				{ "Submarine", 'S', 3, SUBMARINE_SIZE },
				{ "Destroyer", 'D', 2, DESTROYER_SIZE } },
				cpu_ships[NUMBER_OF_SHIPS] = {
				{ "Carrier", 'C', 5, CARRIER_SIZE },
				{ "Battleship", 'B', 4, BATTLESHIP_SIZE },
				{ "Cruiser", 'R', 3, CRUISER_SIZE },
				{ "Submarine", 'S', 3, SUBMARINE_SIZE },
				{ "Destroyer", 'D', 2, DESTROYER_SIZE } };
			Target coordinates = { -1, -1 };

			initialize_character_array(player_board, MAX_ROWS, MAX_COLUMNS);
			initialize_character_array(player_mirror, MAX_ROWS, MAX_COLUMNS);
			initialize_character_array(cpu_board, MAX_ROWS, MAX_COLUMNS);
			initialize_character_array(cpu_mirror, MAX_ROWS, MAX_COLUMNS);

			manual = prompt_ship_placement();
			if (manual == 1) {
				place_ships_manually(player_board, player_ships);
			}
			if (manual == 0) {
				place_ships_randomly(player_board, player_ships);
			}
			print_board(player_board, MAX_ROWS, MAX_COLUMNS);
			press_any_key();
			clear_screen();

			copy_character_array(player_mirror, player_board);
			place_ships_randomly(cpu_board, cpu_ships);

			whose_turn = coin_flip();
			player = whose_turn % 2 + 1;
			do {
				while ((player == 1) && !victory) {
					display_whose_turn(player);
					log_turn(turn, output_stream);

					int hit = -1;

					display_interface(cpu_mirror, player_mirror);
					coordinates = get_valid_player_target(cpu_mirror);          // <----- comment this line out if your fingers get tired
					// coordinates = get_valid_somewhat_smart_cpu_target(cpu_mirror);     // <---- uses the somewhat smart AI to select a target for the player. Handy if you just want to hold Enter until someone wins.
					display_target(player, coordinates);
					log_target(player, coordinates, output_stream);

					hit = check_shot(cpu_board, coordinates);
					update_displayed_boards(player_mirror, cpu_mirror, coordinates, hit, player);
					display_interface(cpu_mirror, player_mirror);
					display_hit_miss(hit);

					if (hit) {
						int damaged_ship = -1, ship_sunk = 0;
						damaged_ship = find_which_ship(cpu_board, coordinates, &player_stats, cpu_ships, player, output_stream);
						ship_sunk = check_for_sunk(cpu_ships, damaged_ship, &player_stats, player, output_stream);
						if (ship_sunk) {
							victory = check_for_victory(cpu_ships);
						}
					}
					if (!hit) {
						shot_miss_actions(&player_stats, player, output_stream);
					}
					if (victory) {
						log_victory(player, output_stream);
						player_stats.won_or_lost = victory;
					}
					if (!victory) {
						++whose_turn;
						++turn;
						player = whose_turn % 2 + 1;
					}
					press_any_key();
				}

				while ((player == 2) && !victory) {
					display_whose_turn(player);
					log_turn(turn, output_stream);

					int hit = -1;
					
					display_interface(cpu_mirror, player_mirror);
					/* coordinates = get_valid_cpu_target(player_mirror);    <--- this finds targets completely randomly, left it here in case you want to test against a CPU that isn't making quasi-good decisions
																				  completely random is around 18-25% accurate on average, the "smart" algorithm can be as accurate as 35-40% if it gets lucky */

					coordinates = get_valid_somewhat_smart_cpu_target(player_mirror);    // <------ comment this out if using the line above
					display_target(player, coordinates);
					log_target(player, coordinates, output_stream);
					
					hit = check_shot(player_mirror, coordinates);
					update_displayed_boards(player_mirror, cpu_mirror, coordinates, hit, player);
					display_interface(cpu_mirror, player_mirror);
					display_hit_miss(hit);

					if (hit) {
						int damaged_ship = -1, ship_sunk = 0;
						damaged_ship = find_which_ship(player_board, coordinates, &cpu_stats, player_ships, player, output_stream);
						ship_sunk = check_for_sunk(player_ships, damaged_ship, &cpu_stats, player, output_stream);
						if (ship_sunk) {
							victory = check_for_victory(player_ships);
						}
					}
					if (!hit) {
						shot_miss_actions(&cpu_stats, player, output_stream);
					}
					if (victory) {
						log_victory(player, output_stream);
						cpu_stats.won_or_lost = victory;
					}
					if (!victory) {
						++whose_turn;
						++turn;
						player = whose_turn % 2 + 1;
					}
					press_any_key();
				}
			} while (victory == 0);

			if (victory == 1) {
				display_winner(player);
			}
			calculate_hit_percentage(&player_stats);
			calculate_hit_percentage(&cpu_stats);
			log_end_data(player_stats, cpu_stats, game_count, turn, output_stream);
			++game_count;
		}
	} while (input != 3);

	fclose(output_stream);
	return(0);
}