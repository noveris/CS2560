// CS2560_Project2_B.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Page 809 Patient Fees Program

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class PatientAccount {
private:
	int daily_rate = 500;
	int days_spent;
	int charges;
public:
	PatientAccount() {
		days_spent = 0;
		charges = 0;
	}
	void add_charges(int amount) {
		charges += amount;
	}

	int get_charges() {
		return charges;
	}
};

class Surgery {
private:
	int charges[5] = { 400, 50, 2000, 100, 750 };
	string procedures[5] = { "Arthroscopic", "Hernia", "Neurological", "Orthopedic", "Outpatient" };
public:
	int get_cost(int p) {
		return charges[p];
	}
	string get_name(int p) {
		return procedures[p];
	}
	void charge(PatientAccount &the_patient, int p) {
		the_patient.add_charges(charges[p]);
	}
};

class Pharmacy {
private:
	int charges[5] = { 10, 20, 30, 40, 50 };
	string products[5] = { "Mucinex", "Tylenol", "Aspirin", "Motrin", "Benadryl" };
public:
	int get_cost(int p) {
		return charges[p];
	}
	string get_name(int p) {
		return products[p];
	}
	void charge(PatientAccount &the_patient, int p) {
		the_patient.add_charges(charges[p]);
	}
};

int main() {
	PatientAccount the_account;
	Surgery the_surgery;
	Pharmacy the_pharmacy;

	cout << "Created new patient account.\n";

	//Menu
	int choice = -1;
	cout << "Please choose a surgery: \n";
	for (int i = 0; i < 5; i++) {
		cout << "[" << i << "] " << the_surgery.get_name(i) << "\t" << the_surgery.get_cost(i) << "\n";
	}

	cin >> choice;
	the_surgery.charge(the_account, choice);

	cout << "Please choose a medicine: \n";
	for (int i = 0; i < 5; i++) {
		cout << "[" << i << "] " << the_pharmacy.get_name(i) << "\t" << the_pharmacy.get_cost(i) << "\n";
	}
	cin >> choice;

	cout << "Checking out the patient...\n";
	the_pharmacy.charge(the_account, choice);

	cout << "Cost: " << the_account.get_charges();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu