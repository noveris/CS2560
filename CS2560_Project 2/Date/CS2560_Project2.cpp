#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//Assumes all months have 30 days, and that each year has 360 days.
class Date {
private:
	int month, day, year;
	string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
public:
	Date(int m, int d, int y) {
		month = m;
		day = d;
		year = y;
	}

	void print_eu() {
		cout << day << " " << months[month - 1] << " " << year << "\n";
	}

	void print_long() {
		cout << months[month - 1] << " " << day << ", " << year << "\n";
	}

	void print_slash() {
		cout << month << "/" << day << "/" << year << "\n";
	}

	Date operator++() {
		++day;
		fix_date();
		return *this;
	}

	Date operator++(int) {
		Date temp(month, day, year);
		day++;
		fix_date();
		return temp;
	}

	Date operator--() {
		--day;
		fix_date();
		return *this;
	}
	
	Date operator--(int) {
		Date temp(month, day, year);
		day--;
		fix_date();
		return temp;
	}

	void fix_date() {
		if (day > 30) {
			day = 1;
			month++;
		}

		if (day < 1) {
			day = 30;
			month--;
		}

		if (month > 12) {
			month = 1;
			year++;
		}

		if (month < 1) {
			month = 12;
			year--;
		}
	}

	int operator - (const Date &right) {
		int add_days = 0;
		
		add_days += ((year - right.year) * 360);
		add_days += ((month - right.month) * 360);
		add_days += (day - right.day);

		return add_days;
	}

	friend ostream &operator << (ostream &strm, const Date &obj) {
		strm << obj.month << "/" << obj.day << "/" << obj.year << "\n";
		return strm;
	}

	friend istream &operator >> (istream &strm, Date &obj) {
		cout << "Month: ";
		strm >> obj.month;

		cout << "Day: ";
		strm >> obj.day;

		cout << "Year: ";
		strm >> obj.year;

		return strm;
	}
};

int main() {
	Date the_date(12, 29, 2019);
	the_date.print_slash();
	the_date.print_eu();
	the_date.print_long();

	cout << "\nOperator Overloads:\n";

	//Increment
	cout << "Increment\n";
	the_date.print_slash();
	++the_date;
	the_date.print_slash();
	the_date++;
	the_date.print_slash();

	//Decrement
	cout << "\nDecrement\n";
	the_date.print_slash();
	--the_date;
	the_date.print_slash();
	the_date--;
	the_date.print_slash();
	
	//Subtraction
	cout << "\nSubtraction\n";
	cout << "12/29/2019 - 12/10/2019: ";
	Date sub_date(12, 10, 2019);
	int num_days = the_date - sub_date;
	cout << num_days << "\n";
	
	//Stream Insertion
	cout << "\nStream Insertion: \n";
	cout << the_date;
	
	//Stream Extraction
	cout << "\nStream Extraction: \n";
	cin >> sub_date;
	sub_date.print_slash();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
