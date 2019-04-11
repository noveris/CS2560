#include <iostream>
#include <vector>
#include <algorithm>

struct the_struct {
	void operator() (int the_num) {
		bool is_prime = true;
		
		//determine whether the number is prime
		//loop through numbers from 2 to n - 1 to check for primality
		for (int i = 2; i < the_num - 1; i++) {
			//if there is no remainder, the number is not prime.
			if (the_num % i == 0) {
				is_prime = false;
				break;
			}
		}

		//print the number if it's prime
		if (is_prime) {
			std::cout << the_num << " ";
		}
	}
} test_func;

int main()
{
	//Get integer > 1 from the user
	int test_val;
	std::cout << "Please enter an integer greater than 1: ";
	std::cin >> test_val;

	//Display all prime numbers LEQ to the number
	//Populate vector with all numbers from 2 to the value
	std::vector<int> all_nums;
	for (int i = 2; i <= test_val; i++) {
		all_nums.push_back(i);
	}

	//Use for_each to loop through the vector with a function object that displays the number if it is prime
	for_each(all_nums.begin(), all_nums.end(), test_func);

}
