#include "craps.h"

/********************************************************************************************************
* Function: print_game_rules
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prints a clear, multi-line summary of standard Craps rules to stdout. This provides the
* user an overview of the come-out roll, how a point is established, and win/loss conditions.
* Input parameters: (none)
* Returns: void – no value is returned; the function only produces console output.
* Preconditions: stdout is available; caller expects immediate console I/O.
* Postconditions: The rules text has been written to stdout. No program state is modified.
********************************************************************************************************/
void print_game_rules(void) {
    printf("Welcome to the game of Craps!\n\n"
        "Here are the rules:\n"
        "1. A player rolls two dice. Each die has six faces, numbered 1 through 6.\n"
        "2. After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n"
        "3. On the first roll (called the 'come-out roll'):\n"
        "   - If the sum is 7 or 11, the player wins.\n"
        "   - If the sum is 2, 3, or 12, the player loses (craps out).\n"
        "   - If the sum is 4, 5, 6, 8, 9, or 10, that number becomes the player's 'point.'\n"
        "4. To win after a point is established, the player must continue rolling the dice until they roll their point value again.\n"
        "5. The player loses if a 7 is rolled before rolling the point again.\n\n"
        "Good luck and have fun!\n");
}

/********************************************************************************************************
* Function: get_bank_balance
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prompts the user to enter an initial positive bank balance and loops until a valid value
* (> 0) is provided. The validated value is returned to initialize gameplay funds.
* Input parameters: (none) – reads from stdin via scanf.
* Returns: double – the validated initial bank balance (> 0).
* Preconditions: stdin is available and provides numeric input; locale uses '.' as decimal separator.
* Postconditions: Returns a strictly positive balance to the caller. No global state is changed.
********************************************************************************************************/
double get_bank_balance(void) {
    double balance = 0;
    printf("Please enter your bank balance.\n");
    do {
        scanf("%lf", &balance);
        if (balance <= 0) {
            printf("Invalid entry, please enter a balance greater than 0.\n");
        }
    } while (balance <= 0);
    return balance;
}

/********************************************************************************************************
* Function: get_wager_amount
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prompts the user to enter a wager and validates that it is non-negative (>= 0). Useful for
* workflows that later check the wager against the current bank balance.
* Input parameters: (none) – reads from stdin via scanf.
* Returns: double – a wager amount greater than or equal to zero.
* Preconditions: stdin is available and provides numeric input; caller will separately verify affordability.
* Postconditions: A non-negative wager value is returned. No other state is modified.
********************************************************************************************************/
double get_wager_amount(void) {
    double wager = 0;
    printf("Please enter your wager.\n");
    do {
        scanf("%lf", &wager);
        if (wager < 0) {
            printf("Invalid wager, please enter a value greater than or equal to 0.\n");
        }
    } while (wager < 0);
    return wager;
}

/********************************************************************************************************
* Function: check_wager_amount
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Verifies that the player's wager does not exceed their available balance. If invalid, a
* message is printed. This function is intended to be used in a validation loop.
* Input parameters:
*   - wager (double): The amount the player wishes to bet.
*   - balance (double): The player's current available funds.
* Returns: int – non-zero (true) if wager <= balance; 0 (false) otherwise.
* Preconditions: Both amounts are non-negative real numbers.
* Postconditions: If invalid, an explanatory message has been printed; no other state is changed.
********************************************************************************************************/
int check_wager_amount(double wager, double balance) {
    if (wager > balance) {
        printf("Your wager is invalid, it must be less than or equal to your balance of $%.2lf.\n", balance);
    }
    return wager <= balance;
}

/********************************************************************************************************
* Function: roll_die
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Simulates rolling a single fair six-sided die using rand(). Values range from 1 to 6.
* Input parameters: (none)
* Returns: int – an integer uniformly distributed in [1, 6].
* Preconditions: srand() has ideally been called earlier to seed the PRNG; RAND_MAX is implementation-defined.
* Postconditions: No state is modified beyond rand()’s internal state.
********************************************************************************************************/
int roll_die(void) {
    return rand() % 6 + 1;
}

/********************************************************************************************************
* Function: calculate_sum_dice
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Computes the sum of two die values without I/O or side effects.
* Input parameters:
*   - die1_value (int): result of first die roll
*   - die2_value (int): result of second die roll
* Returns: int – sum of the two dice.
* Preconditions: Inputs should each be in the range [1, 6] for realistic dice semantics.
* Postconditions: Pure function; no state changes.
********************************************************************************************************/
int calculate_sum_dice(int die1_value, int die2_value) {
    return die1_value + die2_value;
}

/********************************************************************************************************
* Function: roll_dice
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Rolls two dice via roll_die(), sums them via calculate_sum_dice(), prints the total, and
* returns the sum. Encapsulates the common "roll and announce" step of gameplay.
* Input parameters: (none)
* Returns: int – the total of two six-sided dice in [2, 12].
* Preconditions: rand() seeded for better randomness; stdout available for printing.
* Postconditions: Sum printed to stdout; no other state modified.
********************************************************************************************************/
int roll_dice(void) {
    int die1 = 0, die2 = 0;
    die1 = roll_die();
    die2 = roll_die();

    int sum = calculate_sum_dice(die1, die2);
    printf("You rolled a %d.\n", sum);
    return sum;
}

/********************************************************************************************************
* Function: is_win_loss_or_point
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Determines the outcome of the come-out roll. Returns WIN for 7/11, LOSS for 2/3/12, and
* CONTINUE to indicate a point should be established.
* Input parameters:
*   - sum_dice (int): the total from the initial (come-out) roll.
* Returns: int – WIN, LOSS, or CONTINUE (symbolic constants from craps.h).
* Preconditions: sum_dice should be within [2, 12].
* Postconditions: Pure classification; no state changes.
********************************************************************************************************/
int is_win_loss_or_point(int sum_dice) {
    if (sum_dice == 7 || sum_dice == 11) {
        return WIN;
    }
    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
        return LOSS;
    }
    else return CONTINUE;
}

/********************************************************************************************************
* Function: is_point_loss_or_neither
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: After a point is established, evaluates a subsequent roll: WIN if sum equals the point,
* LOSS if sum is 7, CONTINUE otherwise.
* Input parameters:
*   - sum_dice (int): the total rolled this turn
*   - point_value (int): the previously established point
* Returns: int – WIN, LOSS, or CONTINUE (constants from craps.h).
* Preconditions: sum_dice, point_value in [2, 12] with point_value reflecting prior state.
* Postconditions: Pure classification; no state changes.
********************************************************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value) {
    if (sum_dice == point_value) {
        return WIN;
    }
    else if (sum_dice == 7) {
        return LOSS;
    }
    else return CONTINUE;
}

/********************************************************************************************************
* Function: adjust_bank_balance
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Adjusts the player's bank balance by either adding or subtracting the wager amount depending
* on the outcome flag.
* Input parameters:
*   - bank_balance (double): current funds
*   - wager_amount (double): amount to add/subtract
*   - add (int): non-zero to add (win); zero to subtract (loss)
* Returns: double – updated bank balance after adjustment.
* Preconditions: bank_balance and wager_amount are non-negative.
* Postconditions: Returns a new balance; original value passed by value is unmodified.
********************************************************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add) {
    if (add) {
        return bank_balance + wager_amount;
    }
    else return bank_balance - wager_amount;
}

/********************************************************************************************************
* Function: display_menu
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prints the main menu to stdout, showing options to play, view rules, or exit.
* Input parameters: (none)
* Returns: void – menu text is printed to stdout.
* Preconditions: stdout is available.
* Postconditions: Menu lines written to stdout; no state changes.
********************************************************************************************************/
void display_menu(void) {
    printf("Welcome to Craps\n"
        "1. Play Craps\n"
        "2. Display Rules\n"
        "3. Exit\n");
}

/********************************************************************************************************
* Function: get_main_menu_input
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Reads an integer selection from stdin and validates it is within [1, 3]. Keeps prompting
* until a valid choice is entered.
* Input parameters: (none) – reads from stdin via scanf.
* Returns: int – a valid menu choice {1, 2, 3}.
* Preconditions: stdin provides numeric input; caller expects blocking user interaction.
* Postconditions: Returns a valid menu choice; no other state is changed.
********************************************************************************************************/
int get_main_menu_input(void) {
    int input = 0;
    do {
        scanf("%d", &input);
        if (input < 1 || input > 3) {
            printf("Invalid input, please enter 1, 2, or 3.\n");
        }
    } while (input < 1 || input > 3);
    return input;
}

/********************************************************************************************************
* Function: run_craps_program
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Drives the main program loop: displays the menu, collects a selection, and dispatches to
* the appropriate action via execute_user_choice(). Repeats until EXIT_GAME is chosen.
* Input parameters: (none)
* Returns: void – controls overall program flow via repeated user interaction.
* Preconditions: Symbolic constants (e.g., EXIT_GAME) are defined in craps.h; stdin/stdout are available.
* Postconditions: Returns only when the user selects EXIT_GAME; no persistent state is stored here.
********************************************************************************************************/
void run_craps_program(void) {
    int user_choice;
    do {
        display_menu();
        user_choice = get_main_menu_input();
        execute_user_choice(user_choice);
    } while (user_choice != EXIT_GAME);
}

/********************************************************************************************************
* Function: execute_user_choice
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Dispatches a validated menu option to the corresponding action: start a game, print rules,
* or do nothing for exit. Acts as a simple command handler.
* Input parameters:
*   - user_choice (int): expected to be one of {PLAY_GAME, PRINT_RULES, EXIT_GAME}.
* Returns: void – side effects include launching gameplay or printing rules.
* Preconditions: user_choice is validated; symbolic constants are defined in craps.h.
* Postconditions: For PLAY_GAME, play_craps() is invoked; for PRINT_RULES, rules are printed; for EXIT, no-op.
********************************************************************************************************/
void execute_user_choice(int user_choice) {
    switch (user_choice) {
    case PLAY_GAME:
        play_craps();
        break;
    case PRINT_RULES:
        print_game_rules();
        break;
    default:
        break;
    }
}

/********************************************************************************************************
* Function: get_valid_wager
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prompts for a wager and loops until the amount is affordable given the current bank balance.
* Internally uses get_wager_amount() and check_wager_amount().
* Input parameters:
*   - bank_balance (double): the player’s current funds used to validate affordability.
* Returns: double – a non-negative wager that satisfies wager <= bank_balance.
* Preconditions: stdin available; bank_balance >= 0.
* Postconditions: Returns a valid wager without mutating the provided bank balance.
********************************************************************************************************/
double get_valid_wager(double bank_balance) {
    double wager = 0;
    int valid = 0;

    do {
        wager = get_wager_amount();
        valid = check_wager_amount(wager, bank_balance);
    } while (!valid);
    return wager;
}

/********************************************************************************************************
* Function: play_craps
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: High-level game session driver. Obtains an initial bank balance, then repeatedly:
* (1) obtains a valid wager, (2) plays one round via play_one_round(), and (3) asks the user whether to
* continue, terminating if funds are depleted or the user selects NO.
* Input parameters: (none)
* Returns: void – manages multi-round interaction; prints results and updates local bank balance.
* Preconditions: stdin/stdout available; constants YES/NO defined; supporting functions are operational.
* Postconditions: Session ends when user declines to continue or bank balance <= 0; no global state is stored.
********************************************************************************************************/
void play_craps(void) {
    double initial_bank_balance = get_bank_balance();
    double current_bank_balance = initial_bank_balance;
    int user_choice = 0;

    do {
        double wager = get_valid_wager(current_bank_balance);
        current_bank_balance = play_one_round(wager, current_bank_balance, initial_bank_balance);
        user_choice = prompt_user_to_play_again(current_bank_balance);
    } while (user_choice != NO);
}

/********************************************************************************************************
* Function: play_one_round
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Executes a single round of Craps. Performs the come-out roll, determines immediate WIN/LOSS
* or establishes a point, then continues rolling until WIN/LOSS is decided. Adjusts and returns the updated
* bank balance based on the wager and outcome.
* Input parameters:
*   - wager (double): amount to add/subtract on win/loss
*   - bank_balance (double): current funds prior to the round
*   - initial_bank_balance (double): original player bank balance when the game started
* Returns: double – updated bank balance after resolving the round.
* Preconditions: wager >= 0 and wager <= bank_balance on entry; related constants defined in craps.h.
* Postconditions: Returned balance reflects the outcome (+/- wager). No globals modified.
********************************************************************************************************/
double play_one_round(double wager, double bank_balance, double initial_bank_balance) {
    int game_over = FALSE;
    int dice = execute_come_out_roll();
    int point = dice;
    int rolls = 1;
    int player_won = is_win_loss_or_point(dice);

    do {
        if (player_won == CONTINUE) {
            rolls++;
            player_won = execute_subsequent_roll(point);
            display_chatter_message(bank_balance, initial_bank_balance, wager, player_won, rolls);
        }
        else if (player_won) {
            bank_balance = player_wins(wager, bank_balance);
            display_chatter_message(bank_balance, initial_bank_balance, wager, player_won, rolls);
            game_over = TRUE;
        }
        else {
            bank_balance = player_loses(wager, bank_balance);
            display_chatter_message(bank_balance, initial_bank_balance, wager, player_won, rolls);
            game_over = TRUE;
        }
    } while (!game_over);
    return bank_balance;
}

/********************************************************************************************************
* Function: execute_come_out_roll
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Performs and returns the sum for the come-out roll using roll_dice(). Printing is handled
* by roll_dice().
* Input parameters: (none)
* Returns: int – sum of the two dice for the come-out roll.
* Preconditions: rand() seeded for better randomness; stdout available for prints from roll_dice().
* Postconditions: No state changes beyond I/O in roll_dice().
********************************************************************************************************/
int execute_come_out_roll(void) {
    int dice = roll_dice();
    return(dice);
}

/********************************************************************************************************
* Function: prompt_user_to_play_again
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Asks the user if they wish to play another round (1 = YES, 0 = NO). If the bank balance is
* zero or negative, automatically returns NO. Otherwise, repeatedly prompts until a valid response is given.
* Input parameters:
*   - bank_balance (double): used to short-circuit continuation when funds are depleted.
* Returns: int – YES (1) or NO (0).
* Preconditions: stdin/stdout available; constants YES and NO defined in craps.h.
* Postconditions: On valid input, returns a canonical YES/NO; prints feedback for invalid entries.
********************************************************************************************************/
int prompt_user_to_play_again(double bank_balance) {
    int input = 0;
    if (bank_balance <= 0) {
        printf("You are out of money and cannot play anymore. Good-bye!\n");
        return NO;
    }
    else {
        printf("Would you like to play again? Enter 1 for yes, 0 for no.\n");

        do {
            scanf("%d", &input);
            if (input != YES && input != NO) {
                printf("Your input was not recognized, please enter 1 for yes and 0 for no.\n");
            }
        } while (input != YES && input != NO);
    }
    return input;
}

/********************************************************************************************************
* Function: player_wins
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Applies a winning outcome by adding the wager to the bank balance and printing the result.
* Input parameters:
*   - wager (double): amount to add
*   - bank_balance (double): current funds
* Returns: double – updated bank balance after crediting the wager.
* Preconditions: wager >= 0; stdout available; WIN constant is non-zero for adjust_bank_balance().
* Postconditions: Prints a win message and the new balance; returns adjusted funds.
********************************************************************************************************/
double player_wins(double wager, double bank_balance) {
    bank_balance = adjust_bank_balance(bank_balance, wager, WIN);
    printf("You win!\n"
        "Your new bank balance is $%.2lf.\n", bank_balance);
    return bank_balance;
}

/********************************************************************************************************
* Function: player_loses
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Applies a losing outcome by subtracting the wager from the bank balance and printing the
* result.
* Input parameters:
*   - wager (double): amount to subtract
*   - bank_balance (double): current funds
* Returns: double – updated bank balance after debiting the wager.
* Preconditions: wager >= 0; stdout available; LOSS constant is zero for adjust_bank_balance().
* Postconditions: Prints a loss message and the new balance; returns adjusted funds.
********************************************************************************************************/
double player_loses(double wager, double bank_balance) {
    bank_balance = adjust_bank_balance(bank_balance, wager, LOSS);
    printf("You lose.\n"
        "Your new bank balance is $%.2lf.\n", bank_balance);
    return bank_balance;
}

/********************************************************************************************************
* Function: execute_subsequent_roll
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Rolls the dice after a point has been established and evaluates the outcome relative to the
* point. Internally prints the roll (via roll_dice()) and returns WIN/LOSS/CONTINUE.
* Input parameters:
*   - point (int): the active point established during the come-out resolution
* Returns: int – WIN if sum == point, LOSS if sum == 7, CONTINUE otherwise.
* Preconditions: point is a valid craps total (4,5,6,8,9,10 typically, though function is general).
* Postconditions: No state changes beyond the printing performed by roll_dice().
********************************************************************************************************/
int execute_subsequent_roll(int point) {
    int dice = roll_dice();
    return is_point_loss_or_neither(dice, point);
}

/********************************************************************************************************
* Function: display_chatter_message
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Determines which chatter message function to call based on the current game state.
* It delegates to display_ongoing_game_chatter(), display_player_won_chatter(), or
* display_player_lost_chatter() depending on whether the player is still rolling, has won, or lost.
* Input parameters:
*   - bank_balance (double): the player’s current balance
*   - initial_balance (double): the player’s starting balance from the beginning of the session
*   - wager (double): the player’s most recent bet amount
*   - player_won (int): a status constant indicating CONTINUE, WIN, or LOSS
*   - roll_count (int): how many rolls have occurred in the current round
* Returns: void – prints an appropriate chatter message to stdout.
* Preconditions: player_won must correspond to a valid constant (e.g., CONTINUE, WIN, LOSS).
* Postconditions: Calls exactly one of the chatter display functions; prints to stdout.
********************************************************************************************************/
void display_chatter_message(double bank_balance, double initial_balance, double wager, int player_won, int roll_count) {
    if (player_won == CONTINUE) {
        display_ongoing_game_chatter(wager, roll_count, bank_balance, initial_balance);
    }
    else if (player_won) {
        display_player_won_chatter(wager, roll_count, bank_balance, initial_balance);
    }
    else {
        display_player_lost_chatter(wager, roll_count, bank_balance, initial_balance);
    }
}

/********************************************************************************************************
* Function: display_ongoing_game_chatter
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Displays a randomly flavored or context-specific message while a round is still in progress.
* It analyzes the player’s current wager, roll count, and how their balance compares to the initial balance
* to select a comment that fits the ongoing state of the game.
* Input parameters:
*   - wager (double): amount the player bet for the current round
*   - roll_count (int): the number of rolls made so far in this round
*   - bank_balance (double): current amount of money the player has
*   - initial_balance (double): the starting balance from the beginning of the session
* Returns: void – prints one thematic message to stdout.
* Preconditions: bank_balance and initial_balance must be non-negative; roll_count >= 1.
* Postconditions: Prints a message matching the game context; no state changes occur.
********************************************************************************************************/
void display_ongoing_game_chatter(double wager, int roll_count, double bank_balance, double initial_balance) {
    if (roll_count == 1 && (bank_balance < (initial_balance * 0.5))) {
        printf("You've lost a lot of money. Brave of you to continue...\n");
    }
    else if (roll_count == 1 && (wager > bank_balance * 0.5)) {
        printf("Ok, big spender, save some for the Uber home.\n");
    }
    else if (bank_balance < initial_balance) {
        printf("90%% of gamblers quit right before they win.\n");
    }
    else if (wager > bank_balance * 0.5) {
        printf("It's like the man always said, no risk it, no biscuit.\n");
    }
    else if (bank_balance > initial_balance) {
        printf("Quitting while you're ahead is always an effective strategy.\n");
    }
    else {
        printf("Keep rollin, rollin, rollin...");
    }
    system("pause");
}

/********************************************************************************************************
* Function: display_player_won_chatter
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Prints a contextual congratulatory message after the player wins a round.
* The specific message depends on the size of the wager relative to their balance,
* how long the round took, and how the current balance compares to the initial balance.
* Input parameters:
*   - wager (double): amount bet in the round that was just won
*   - roll_count (int): number of rolls it took to achieve the win
*   - bank_balance (double): player’s current total funds
*   - initial_balance (double): player’s starting session balance
* Returns: void – prints a congratulatory or humorous message to stdout.
* Preconditions: bank_balance and initial_balance are non-negative; wager <= bank_balance.
* Postconditions: Prints exactly one message reflecting the win context.
********************************************************************************************************/
void display_player_won_chatter(double wager, int roll_count, double bank_balance, double initial_balance) {
    if (wager == (bank_balance * 0.5)) {
        printf("You doubled up on that one.\n");
    }
    else if (wager >= (bank_balance * 0.3)) {
        printf("You just won big. Will you cash in your chips, or can we comp you at the breakfast buffet?\n");
    }
    else if (initial_balance < bank_balance) {
        printf("You're an all time winner, which means things can only go down from here. Time to go check out Penn and Teller, yeah?\n");
    }
    else if (roll_count >= 10) {
        printf("Took you long enough.\n");
    }
    else {
        printf("You're a lucky fella.\n");
    }
    system("pause");
}

/********************************************************************************************************
* Function: display_player_lost_chatter
* Date Created: 10/22/2025
* Date Last Modified: 10/22/2025
* Description: Displays a context-aware message after the player loses a round.
* It uses wager size, roll count, and the player’s remaining funds relative to their initial balance
* to produce an appropriate tone (sympathetic, humorous, or teasing).
* Input parameters:
*   - wager (double): amount bet in the losing round
*   - roll_count (int): number of rolls that occurred in this round
*   - bank_balance (double): current remaining funds
*   - initial_balance (double): player’s starting balance for the session
* Returns: void – prints a message describing or reacting to the loss.
* Preconditions: bank_balance, initial_balance >= 0; wager >= 0.
* Postconditions: Prints a single loss-related message; no other state is affected.
********************************************************************************************************/
void display_player_lost_chatter(double wager, int roll_count, double bank_balance, double initial_balance) {
    if (bank_balance == 0) {
        printf("That round wiped you out.\n");
    }
    else if (wager < (initial_balance * 0.2)) {
        printf("Habibi, trust, you want to cash out and go check out the bar.\n");
    }
    else if (wager > bank_balance) {
        printf("You just lost over half your roll, that can't feel great.\n");
    }
    else if (bank_balance > (initial_balance * 0.5)) {
        printf("Hey, it happens, but you're still doing ok. Roll again?\n");
    }
    else if (roll_count > 10) {
        printf("It must be a bummer to spend that much time rolling only to lose it like that.\n");
    }
    else {
        printf("Thank you for contributing to the Culinary Union Local 226 Retirement Fund.\n");
    }
    system("pause");
}
