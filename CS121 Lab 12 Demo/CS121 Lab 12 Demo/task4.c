#include "header.h"


void runTaskFour(void) {
	int posts[NUMBER_DISKS][NUMBER_POSTS] = { 0 };
	displayRules();
	initializePosts(posts);
	solveHanoi(posts, NUMBER_DISKS, 0, 2, 1);
}

void initializePosts(int posts[][NUMBER_POSTS]) {
	for (int i = 0; i < NUMBER_DISKS; ++i) {
		int j = 0;
		posts[i][j] = i + 1;
	}
}

void displayRules(void) {
	printf("Tower of Hanoi is a puzzle game involving several disks of varying size on three\n");
	printf("posts. The objective is to move every disk from one post to another without ever\n");
	printf("placing any disk on top of a smaller disk. You may only access the top disk on a\n");
	printf("post at any time, and you may only transfer one disk at a time. The numbers displayed\n");
	printf("are the sizes of the disks at those positions. The number of disks is at least three\n");
	printf("and may not exceed 20. The number of disks is defined in header.h as NUMBER_DISKS.\n");
	system("pause");
}

void displayPosts(int posts[][NUMBER_POSTS]) {
	system("cls");
	for (int i = 0; i < NUMBER_POSTS; ++i) {
		printf("    Post %d", i);
	}
	printf("\n");
	for (int i = 0; i < NUMBER_DISKS; ++i) {
		for (int j = 0; j < NUMBER_POSTS; ++j) {
			printf("      %d   ", posts[i][j]);
		}
		printf("\n");
	}
}

void moveDisk(int posts[][NUMBER_POSTS], int source, int destination) {
	int disk = -1;
	int found = 0, inserted = 0;
	for (int i = 0; !found && i < NUMBER_DISKS; i++) {
		if (posts[i][source] != 0) {
			disk = posts[i][source];
			posts[i][source] = 0;
			found = 1;
		}
	}
	for (int i = NUMBER_DISKS - 1; !inserted && i >= 0; i--) {
		if (posts[i][destination] == 0) {
			posts[i][destination] = disk;
			inserted = 1;
		}
	}
	displayPosts(posts);
	system("pause");
}

void solveHanoi(int posts[][NUMBER_POSTS], int numberOfDisks, int source, int destination, int helper) {
	if (numberOfDisks == 1) {
		moveDisk(posts, source, destination);
	}
	else {
		solveHanoi(posts, numberOfDisks - 1, source, helper, destination);
		moveDisk(posts, source, destination);
		solveHanoi(posts, numberOfDisks - 1, helper, destination, source);
	}
}