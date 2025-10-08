#include "Header.h"

int getAllStarAppearance(void) {
	char response = 0;
	int bonus = 0;
	printf("Did the player appear in the All-Star game? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 25000;
		break;
	case 'Y':
		bonus = 25000;
		break;
	default:
		break;
	}
	return(bonus);
}

int getRegularSeasonMVP(void) {
	char response = 0;
	int bonus = 0;
	printf("Did the player win Regular Season MVP? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 75000;
		break;
	case 'Y':
		bonus = 75000;
		break;
	default:
		break;
	}
	return(bonus);
}

char getCharInput(void) {
	char input = 0;
	scanf(" %c", &input);
	return(input);
}

int getWorldSeriesMVP(void) {
	char response = 0;
	int bonus = 0;
	printf("Did the player win World Series MVP? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 100000;
		break;
	case 'Y':
		bonus = 100000;
		break;
	default:
		break;
	}
	return(bonus);
}

int getGoldGloveRecipient(void) {
	char response = 0;
	int bonus = 0;
	printf("Did the player win the Golden Glove Award? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 50000;
		break;
	case 'Y':
		bonus = 50000;
		break;
	default:
		break;
	}
	return(bonus);
}

int getSilverSluggerRecipient(void) {
	char response = 0;
	int bonus = 0;
	printf("Did the player win the Silver Slugger Award? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 35000;
		break;
	case 'Y':
		bonus = 35000;
		break;
	default:
		break;
	}
	return(bonus);
}

int getHomeRunChampRecipient(void) {
	char response = 0;
	int bonus = 0;
	printf("Was the player the Home Run Champion? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 25000;
		break;
	case 'Y':
		bonus = 25000;
		break;
	default:
		break;
	}
	return(bonus);
}

int getBattingAverageChampRecipient(void) {
	char response = 0;
	int bonus = 0;
	printf("Was the player the Batting Average Champion? y/n\n");
	response = getCharInput();
	switch (response) {
	case 'y':
		bonus = 25000;
		break;
	case 'Y':
		bonus = 25000;
		break;
	default:
		break;
	}
	return(bonus);
}

int computeBaseballBonus(void) {
	int bonus = 0;
	bonus = getAllStarAppearance() + getRegularSeasonMVP() + getWorldSeriesMVP() +
		getGoldGloveRecipient() + getSilverSluggerRecipient() + getHomeRunChampRecipient() +
		getBattingAverageChampRecipient();
	return(bonus);
}

void displayBonus(int bonus) {
	printf("The player's bonus is %d.\n", bonus);
}

void runTaskTwo(void) {
	int bonus = 0;
	bonus = computeBaseballBonus();
	displayBonus(bonus);
}