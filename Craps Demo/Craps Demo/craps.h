#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN 1
#define LOSS 0
#define CONTINUE -1
#define PLAY_GAME 1
#define PRINT_RULES 2
#define EXIT_GAME 3
#define YES 1
#define NO 0
#define TRUE 1
#define FALSE 0

void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int roll_dice(void);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add);
void display_menu(void);
int get_main_menu_input(void);
void run_craps_program(void);
void play_craps(void);
double get_valid_wager(double bank_balance);
int prompt_user_to_play_again(double bank_balance);
double play_one_round(double wager, double bank_balance, double initial_bank_balance);
int execute_come_out_roll(void);
double player_wins(double wager, double bank_balance);
double player_loses(double wager, double bank_balance);
int execute_subsequent_roll(int point);
void execute_user_choice(int user_choice);
void display_chatter_message(double bank_balance, double initial_balance, double wager, int player_won, int roll_count);
void display_ongoing_game_chatter(double wager, int roll_count, double bank_balance, double initial_balance);
void display_player_won_chatter(double wager, int roll_count, double bank_balance, double initial_balance);
void display_player_lost_chatter(double wager, int roll_count, double bank_balance, double initial_balance);

#endif