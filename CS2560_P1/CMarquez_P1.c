/* 
 * File:   CMarquez_P1.c
 * Author: Carlos
 *
 * Created on February 24, 2019, 7:39 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int ticket_entry = 0;
    int ticket_prices[15];
    
    while ((ticket_entry != 1) && (ticket_entry != 2)) {
        printf("1. Enter ticket prices manually\n");
        printf("2. Read ticket prices from file prices.txt\n");
        printf("Select an option: ");
        scanf("%d", &ticket_entry);
    }
    if (ticket_entry == 1) {
        //Ask user for seat prices per row or read from file
        printf("Enter ticket prices by row:\n");
        for (int i = 0; i < 15; i++) {
            printf("Row %d: $", i+1);
            scanf("%d", &ticket_prices[i]);
        }
    } else if (ticket_entry == 2) {
        //read prices from prices.txt
        printf("Reading from prices.txt...\n");
        FILE *fp;
        fp = fopen("prices.txt", "r");
        for (int i = 0; i < 15; i++) {
            fscanf(fp, "%d", &ticket_prices[i]);
            printf("Row %d: $%d\n", i+1, ticket_prices[i]);
        }
    }
    
    
    //Create arrays to track seating chart
    char seating_chart[15][30];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 30; j++) {
            seating_chart[i][j] = '#';
        }
    }
    
    //Use while loop to display and track seating chart, track ticket sales
    //Option to view ticket sales
    //Input validation on seat numbers when selling
    //Option to see list of seats sold, seats available per row, seats available in auditorium
    int user_exit = 0;
    int ticket_revenue = 0;
    int seats_available = 450;
    while(user_exit == 0) {
        //Print current seating chart
        printf("                  Seats              \n");
        printf("       123456789012345678901234567890\n");
        for (int i = 0; i < 15; i++) {
            printf("Row %2d ",i + 1);
            for (int j = 0; j < 30; j++) {
                printf("%c", seating_chart[i][j]);
            }
            printf("\n");
        }
        
        //Print menu and present to user
        int user_choice = 0;
        printf("\n");
        printf("1. Record ticket purchase\n");
        printf("2. View ticket sales\n");
        printf("3. View seat statistics\n");
        printf("4. Exit the program\n");
        
        printf("Choose an option: ");
        scanf("%d", &user_choice);
        
        //Sell ticket
        if (user_choice == 1) {
            int valid_seat = 0;
            int row_num = 0;
            int col_num = 0;
            while (valid_seat == 0) {
                valid_seat = 1;
                //Get seat and row
                printf("Enter row #: ");
                scanf("%d", &row_num);
                printf("Enter column #: ");
                scanf("%d", &col_num);
                
                row_num--;
                col_num--;
                
                //Validate the choice
                //Simple range check
                if ((row_num < 0)||(row_num > 15)) {
                    valid_seat = 0;
                }
                if ((col_num < 0)||(col_num > 30)) {
                    valid_seat = 0;
                }
                
                //Check value at row_num, col_num
                if (valid_seat == 1) {
                    if (seating_chart[row_num][col_num] == '#') { //Empty seat
                        printf("Sold seat %d-%d\n", row_num + 1, col_num + 1);
                        //Add to revenue based on row
                        printf("Row seat price: $%d\n", ticket_prices[row_num]);
                        ticket_revenue += ticket_prices[row_num];
                        //Change character to reflect sale
                        seating_chart[row_num][col_num] = '*';
                        //decrement available seats
                        seats_available--;
                    } else if (seating_chart[row_num][col_num] == '*') { //Taken seat
                        printf("That seat is taken. Please choose another.\n");
                    }
                } else {
                    printf("Invalid seat choice. Please enter another.\n");
                }
            }
        //Print revenue
        } else if (user_choice == 2) {
            printf("Current ticket revenue: %d", ticket_revenue);
        //View seat statistics
        } else if (user_choice == 3) {
            printf("\nSeat Statistics: \n");
            printf("Seats sold: %d\n", 450 - seats_available);
            
            printf("Seats available by row: \n");
            //Loop and print # of # in a row
            for (int i = 0; i < 15; i++) {
                int free_seats = 0;
                for (int j = 0; j < 30; j++) {
                    if (seating_chart[i][j] == '#') {
                        free_seats++;
                    }
                }
                printf("Row %2d: %d\n", i+1, free_seats);
            }
            
            printf("Seats available in auditorium: %d\n", seats_available);
        //Exit program
        } else if (user_choice == 4) {
            user_exit = 1;
        }
        
        //Print a few newlines for separation
        printf("\n\n");
    }    
    return (EXIT_SUCCESS);
}

