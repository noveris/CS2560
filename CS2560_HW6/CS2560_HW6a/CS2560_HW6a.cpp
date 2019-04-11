#include "pch.h"
#include <iostream>
#include <string>

template<typename T>
T minimum(const T & a, const T & b) {
	return (a < b ? a : b);
}

template<typename T>
T maximum(const T & a, const T & b) {
	return (a > b ? a : b);
}

int main()
{
	//Maximum
	std::cout << "Maximum\n";
	//Int
	std::cout << "int: Maximum(1,2): " << maximum<int>(1, 2) << "\n";
	//String
	std::cout << "string: Maximum(\'String\', \'Small\'): " << maximum<std::string>("String", "Small") << "\n";
	//Double
	std::cout << "double: Maximum(3.14159, 1.00001): " << maximum<double>(3.14159, 1.00001) << "\n\n";

	//Minimum
	std::cout << "Minimum\n";
	//Int
	std::cout << "int: Minimum(1,2): " << minimum<int>(1, 2) << "\n";
	//String
	std::cout << "string: Minimum(\'String\', \'Small\'): " << minimum<std::string>("String", "Small") << "\n";
	//Double
	std::cout << "double: Minimum(3.14159, 1.00001): " << minimum<double>(3.14159, 1.00001) << "\n";
}