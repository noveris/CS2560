// BigNumbers_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>
#include "BigNumbers.h"

//int main() {
//	BigNumbers::BigNumber test4(1);
//	BigNumbers::BigNumber test5(2);
//	BigNumbers::BigNumber test3 = test4 + test5;
//	std::cout << test3.toString();
//}

//When you create a BigNumber from a vector, you must use simplify() after

TEST(BigNumber, declareBlank) {
	BigNumbers::BigNumber testNum;
	ASSERT_STREQ(testNum.toString().c_str(), "");
}

TEST(BigNumber, declareFromInt) {
	BigNumbers::BigNumber testNum(123456789);
	ASSERT_STREQ(testNum.toString().c_str(), "123456789");
}

TEST(BigNumber, declareFromVector) {
	std::vector<int> testVector;
	for (int i = 0; i < 9; i++) {
		testVector.push_back(i);
	}
	BigNumbers::BigNumber testNum(testVector);
	testNum = testNum.simplify();
	ASSERT_STREQ(testNum.toString().c_str(), "12345678");
}

TEST(BigNumber, sizeFunction) {
	BigNumbers::BigNumber testNum(123456789);
	ASSERT_TRUE(testNum.length() == 9);
}

TEST(BigNumber, addNumbers) {
	BigNumbers::BigNumber testNum1(123);
	BigNumbers::BigNumber testNum2(77);
	BigNumbers::BigNumber testNum3 = testNum1 + testNum2;
	ASSERT_STREQ(testNum3.toString().c_str(), "200");
}

TEST(BigNumber, subNumbers) {
	BigNumbers::BigNumber testNum1(200);
	BigNumbers::BigNumber testNum2(77);
	BigNumbers::BigNumber testNum3 = testNum1 - testNum2;
	ASSERT_STREQ(testNum3.toString().c_str(), "123");
}

TEST(BigNumber, multNumbers) {
	BigNumbers::BigNumber testNum1(25);
	BigNumbers::BigNumber testNum2(40);
	BigNumbers::BigNumber testNum3 = testNum1 * testNum2;
	ASSERT_STREQ(testNum3.toString().c_str(), "1000");
}

//TEST(BigNumber, divNumbers) {
//	BigNumbers::BigNumber testNum1(1000);
//	BigNumbers::BigNumber testNum2(25);
//	BigNumbers::BigNumber testNum3 = testNum1 / testNum2;
//	ASSERT_STREQ(testNum3.toString().c_str(), "40");
//
//}
//
//int main() {
//	BigNumbers::BigNumber testNum1(1000);
//	BigNumbers::BigNumber testNum2(25);
//	BigNumbers::BigNumber testNum3 = testNum1 / testNum2;
//}