/*
 * CS2560_Midterm.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Flicker
 */
//Multiplication table for integers
//Include row and column numbers separated from content
//Accept integer input for user for nxn table

#include <stdio.h>

int main() {
	printf("Multiplication Table\n");
	printf("Enter number for an n by n table: ");
	int user_input = 0;
	fflush(stdout);
	scanf("%d", &user_input);

	//print col numbers and separation line
	printf("\n\n");
	for (int i = 0; i < user_input; i++) {
		printf("\t%d", i+ 1);
	}

	printf("\n +------------------------------------------------------------------\n");

	//print row numbers and the multiplication table
	for (int i = 0; i < user_input; i++) {
		printf("%d|", i+1);
		//for loop for the multiplication of i + 1 * j + 1
		for (int j  = 0; j < user_input; j++) {
			printf("\t%d", ((i+1)*(j+1)));
		}
		printf("\n");
	}

}
