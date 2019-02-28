/* 
 * File:   hw3.c
 * Author: Carlos
 *
 * Created on February 24, 2019, 7:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

int* reverse_array(int array_size, int orig_array[]) {
    int *new_array = malloc(array_size * sizeof(int));
    
    int j = 0;
    for (int i = array_size - 1; i >= 0; i--) {
        new_array[i] = orig_array[j];
        j++;
    }
    
    return new_array;
}

int main(int argc, char** argv) {
    int user_choice = 0;
    
    //GEOMETRY CALCULATOR
    while (user_choice != 4) {
        printf("Geometry Calculator\n\n");
        printf("1. Calculate the Area of a Circle\n");
        printf("2. Calculate the Area of a Rectangle\n");
        printf("3. Calculate the Area of a Triangle\n");
        printf("4. Quit\n\n"); //Moves on to the next program
        printf("Enter your choice (1-4): ");
        
        scanf("%d", &user_choice);
        if ((user_choice > 0)&&(user_choice < 5)) {
            if (user_choice == 1) {
                float circle_radius;
                printf("Enter circle radius: ");
                scanf("%f", &circle_radius);
                if (circle_radius >= 0) {
                    printf("Area: %f\n", (3.14159 * circle_radius * circle_radius));
                } else {
                    printf("Error - invalid input.");
                }
            } else if (user_choice == 2) {
                float rect_l;
                float rect_w;
                printf("Enter length: ");
                scanf("%f", &rect_l);
                printf("Enter width: ");
                scanf("%f", &rect_w);
                if ((rect_l >= 0) && (rect_w >= 0)) {
                    printf("Area: %f\n", (rect_l * rect_w));
                } else {
                    printf("Error - invalid input.");
                }
            } else if (user_choice == 3) {
                float tri_b;
                float tri_h;
                printf("Enter base: ");
                scanf("%f", &tri_b);
                printf("Enter height: ");
                scanf("%f", &tri_h);
                if ((tri_b >= 0) && (tri_h >= 0)) {
                    printf("Area: %f\n", (0.5 * tri_b * tri_h));
                } else {
                    printf("Error - invalid input.");
                }
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
    
    
    //POPULATION
    int pop_start;
    float birth_rate;
    float death_rate;
    int years;
    int valid_input = 0;
    
    while (valid_input == 0) {
        printf("\nPopulation Calculator\n");
        printf("Enter starting size: ");
        scanf("%d", &pop_start);
        printf("Enter birth rate: ");
        scanf("%f", &birth_rate);
        printf("Enter death rate: ");
        scanf("%f", &death_rate);
        printf("Enter number of years to run: ");
        scanf("%d", &years);
        
        if ((pop_start > 2) && (birth_rate > 0) && (death_rate > 0) && (years >= 1)) {
            printf("Start: %d\n", pop_start);
            for (int i = 0; i < years; i++) {
                int new_pop = pop_start + (birth_rate * pop_start) - (death_rate * pop_start);
                printf("Year %5d: %d\n", i+1, new_pop);
                pop_start = new_pop;
            }
            valid_input = 1;
        } else {
            printf("Invalid input.\n");
        }
    }
    
    //TIC-TAC-TOE GAME
    
    
    //REVERSE ARRAY
    //Found this on page 546 of 8th edition
    printf("\n\n");
    printf("REVERSE ARRAY\n");
    int array_size = 10;
    int orig_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Original Array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", orig_array[i]);
    }
    printf("\n");
    
    int *new_array = reverse_array(array_size, orig_array);
    printf("Reversed Array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

