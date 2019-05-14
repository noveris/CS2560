#include "stdafx.h"
#include "BigNumbers.h"
#include <iostream>

namespace BigNumbers {
	BigNumber::BigNumber() {
	}

	//Constructor from int
	BigNumber::BigNumber(int i) {
		//Turn i into a string
		std::string stringVal = std::to_string(i);
		//Push back int of each character to the vector
		for (int i = stringVal.length() - 1; i >= 0; i--) {
			theVector.push_back(stringVal.at(i) - 48);
		}
	}

	//Constructor from vector
	BigNumber::BigNumber(std::vector<int> v) {
		for (int i = v.size() - 1; i >= 0; i--) {
			theVector.push_back(v.at(i));
		}
	}

	//Returns this + num
	BigNumber BigNumber::operator + (BigNumber& num) {
		std::vector<int> resultVector;

		//Loop over the vector
		//Each item will be a single digit

		for (int i = num.length(); i >= 0; i--) {
			int addedVal = this->get(i) + num.get(i);
			resultVector.push_back(addedVal);
			//std::cout << this->get(i) << " + " << num.get(i) << " = " << addedVal << std::endl;
		}

		BigNumber result(resultVector);
		return result.simplify();
	}

	//Returns this - num
	BigNumber BigNumber::operator - (BigNumber& num) {
		std::vector<int> resultVector;

		for (int i = num.length(); i >= 0; i--) {
			int subbedVal = this->get(i) - num.get(i);
			resultVector.push_back(subbedVal);
			//std::cout << this->get(i) << " - " << num.get(i) << " = " << subbedVal << std::endl;
		}

		BigNumber result(resultVector);
		return result.simplify();
	}

	//Returns this * num
	BigNumber BigNumber::operator * (BigNumber& num) {
		BigNumber result;
		BigNumber dec(1);

		std::vector<int> copyvec;
		for (int i = theVector.size() - 1; i >= 0; i--) {
			copyvec.push_back(theVector.at(i));
		}
		BigNumber inc(copyvec);

		//for (int& i : theVector) {
		//	std::cout << i;
		//}
		//std::cout << std::endl;
		//for (int& i : copyvec) {
		//	std::cout << i;
		//}

		while (num.toString() != "1") {
			//std::cout << num.length() << " " << num.toString() << std::endl;
			num = num - dec;
			result = result + inc;
			//std::cout << result.toString() <<std::endl;
		}
		if (num.toString() == "1") {
			result = result + inc;
		}
		return result;
	}

	//Returns this / num
	BigNumber BigNumber::operator / (BigNumber& num) {
		BigNumber result;
		BigNumber dec(1);
		std::vector<int> copyvec;
		for (int i = theVector.size() - 1; i >= 0; i--) {
			copyvec.push_back(theVector.at(i));
		}
		BigNumber sub(copyvec);
		while (num.toString() != "1") {
			//std::cout << num.length() << " " << num.toString() << std::endl;
			num = num - dec;
			result = result - sub;
			//std::cout << result.toString() <<std::endl;
		}
		if (num.toString() == "1") {
			result = result - sub;
		}
		return result;
	}

	//Returns this % num
	BigNumber BigNumber::operator % (BigNumber& num) {
		BigNumber result;
		return result;
	}

	//Simplify the digits of the vector to ensure nothing is more than 9 or less than 0
	BigNumber BigNumber::simplify() {
		bool simplified = false;
		std::vector<int> resultVector;

		if (theVector.size() > 1) {
			//Loop over vector and simplify.
			for (int i = 0; i < theVector.size(); i++) {
				//std::cout << std::to_string(theVector.at(i));
				int val = theVector.at(i);
				//if the value is greater than 10, increment the next place over
				if (val > 9) {
					int tens = val / 10;
					int rem = val % 10;
					theVector.at(i) = rem;
					//std::cout << i << " " << theVector.size() << std::endl;
					if (i == theVector.size() - 1) {
						theVector.push_back(tens);
					}
					else {
						theVector.at(i + 1) = theVector.at(i + 1) + tens;
					}
					simplified = true;
				}
				//if the value is less than 0, decrement the next place over
				if (val < 0) {
					int tens = abs(val / 10);
					tens++;
					int carry = (tens * 10);
					theVector.at(i) += carry;
					if (i == theVector.size() - 1) {
						int numpush = 0 - tens;
						theVector.push_back(numpush);
					}
					else {
						theVector.at(i + 1) -= tens;
					}
					simplified = true;
				}
			}
		}

		//If there are any leading zeros in theVector, remove them.
		//In reverse order, this is the last elem
		if ((theVector.size() > 1) && (theVector.at(theVector.size() - 1) == 0)) {
			simplified = true;
			theVector.pop_back();
		}

		//Store reverse of theVector in resultVector
		for (int i = theVector.size() - 1; i >= 0; i--) {
			resultVector.push_back(theVector.at(i));
		}

		//Generate new big number with the result
		BigNumber result(resultVector);
		if (simplified) {
			return result.simplify();
		}
		else {
			return result;
		}
	}

	std::string BigNumber::toString() {
		std::string result;

		for (int i = theVector.size() - 1; i >= 0; i--) {
			result += std::to_string(theVector.at(i));
		}

		return result;
	}

	int BigNumber::length() {
		return theVector.size();
	}

	int BigNumber::get(int i) {
		if (i < theVector.size()) {
			return theVector.at(i);
		}
		else {
			return 0;
		}
	}

	void BigNumber::setPositive(bool b) {
		if (b) {
			isPositive = true;
		}
		else {
			isPositive = false;
		}
	}
}