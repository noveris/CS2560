#pragma once
#include <vector>
#include <string>

namespace BigNumbers {
	class BigNumber {
	private:
		//Numbers are stored in reverse - 123 = [3, 2, 1]
		std::vector<int> theVector;
		bool isPositive = true;
	public:
		//Default constructor
		BigNumber();

		//Constructor from int
		BigNumber(int i);

		//Constructor from vector
		BigNumber(std::vector<int> v);

		//Returns this + num
		BigNumber operator + (BigNumber& num);

		//Returns this - num
		BigNumber operator - (BigNumber& num);

		//Returns this * num
		BigNumber operator * (BigNumber& num);

		//Returns this / num
		BigNumber operator / (BigNumber& num);

		//Returns this % num
		BigNumber operator % (BigNumber& num);

		std::string toString();

		int length();

		int get(int i);

		BigNumber simplify();

		//Turns positive if true, negative if false
		void setPositive(bool b);

		std::vector<int> reverse_vector(std::vector<int> theVector);
	};
}