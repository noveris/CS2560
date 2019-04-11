#include "pch.h"
#include <iostream>
#include <string>
#include <exception>

/*• The Employee class should throw an exception named InvalidEmployeeNumber
when it receives an employee number that is less than 0 or greater than 9999.
• The ProductionWorker class should throw an exception named InvalidShift
when it receives an invalid shift.
• The ProductionWorker class should throw an exception named InvalidPayRate
when it receives a negative number for the hourly pay rate*/

class Employee {
private:
	std::string name;
	int employee_num;
	int hire_date;
public:
	Employee() {

	}
	class InvalidEmployeeNumber {};

	std::string get_name() {
		return name;
	}
	void set_name(std::string new_name) {
		name = new_name;
	}

	int get_num() {
		return employee_num;
	}
	void set_num(int new_num) {
		if ((new_num >= 0) && (new_num <= 9999)) {
			employee_num = new_num;
		}
		else {
			throw InvalidEmployeeNumber();
		}
	}

	int get_date() {
		return hire_date;
	}
	void set_date(int new_date) {
		hire_date = new_date;
	}
};

class ProductionWorker : public Employee {
private:
	int shift;
	double pay_rate;
public:
	ProductionWorker() {

	}
	class InvalidShift {};
	class InvalidPayRate {};

	int get_shift() {
		return shift;
	}
	void set_shift(int new_shift) {
		if ((new_shift == 1) || (new_shift == 2)) {
			shift = new_shift;
		}
		else {
			throw InvalidShift();
		}
	}

	double get_pay() {
		return pay_rate;
	}
	double set_pay(double new_pay) {
		if (new_pay >= 0) {
			pay_rate = new_pay;
		}
		else {
			throw InvalidPayRate();
		}
	}
};

int main()
{
	std::cout << "Testing exception program...\n";
	ProductionWorker* test_prod = new ProductionWorker();
	
	std::cout << "Testing InvalidEmployeeNumber...\n";
	try {
		test_prod->set_num(1000000);
	}
	catch (ProductionWorker::InvalidEmployeeNumber) {
		std::cout << "Invalid value 1000000 caught.\n";
	}

	std::cout << "Testing InvalidShift...\n";
	try {
		test_prod->set_shift(3);
	}
	catch (ProductionWorker::InvalidShift) {
		std::cout << "Invalid shift 3 caught.\n";
	}

	std::cout << "Testing InvalidPayRate...\n";
	try {
		test_prod->set_pay(-0.1452);
	}
	catch (ProductionWorker::InvalidPayRate) {
		std::cout << "Invalid value -0.1452 caught.\n";
	}

}