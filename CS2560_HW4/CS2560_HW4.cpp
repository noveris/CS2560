// CS2560_HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Game of 21 using two 6-sided dice

#include "pch.h"
#include <iostream>
#include "Die.h"
using namespace std;

int main()
{
	cout << "A Game of 21\n";
	//Two six-sided dice
	Die die1(6);
	Die die2(6);

	cout << "Welcome to 21!\n";
	char user_roll = 'Y';

	int user_score = 0;
	int comp_score = 0;

	//While the user still wants to roll
	while (user_roll == 'Y') {
		cout << "Rolling the dice for the computer...";

		die1.roll();
		die2.roll();

		comp_score += die1.getValue();
		comp_score += die2.getValue();

		//Ask user to roll
		cout << "Your Score: " << user_score << "\n";
		cout << "Roll again? [Y/N]: ";

		cin >> user_roll;
		cout << "\n";

		if (user_roll == 'Y') {
			die1.roll();
			die2.roll();

			user_score += die1.getValue();
			user_score += die2.getValue();
		}
		else if (user_roll == 'N') {
			break;
		}

		if ((user_score > 21) || (comp_score > 21)) {
			break;
		}
	}
	//Game has completed.
	//Compare scores and decide winner
	int user_win = 0;
	cout << "Your Score: " << user_score << "\n";
	cout << "Computer Score: " << comp_score << "\n";

	if ((user_score > comp_score) && (user_score <= 21)) {
		user_win = 1;
		cout << "You won!\n";
	} else if ((comp_score > user_score) && (comp_score <= 21)) {
		user_win = 0;
		cout << "The computer won!\n";
	}
	else if (comp_score > 21) {
		user_win = 1;
		cout << "You won!\n";
	}
	else if (user_score > 21) {
		user_win = 0;
		cout << "The computer won!\n";
	}
	else {
		cout << "No winner for this game.\n";
	}

	cout << "\n\nParking Ticket Sim";

}
