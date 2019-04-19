// CS2560_Midterm2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Carlos M. CS2560.02
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

class Human {
private:
	std::string name;
	int age;
	char sex;
	Human();
protected:
	Human(std::string n, int a, char s) {
		name = n;
		age = a;
		sex = s;
	}
	virtual ~Human() {};
public:
	std::string getName() {
		return name;
	}
	void setName(std::string n) {
		name = n;
	}

	int getAge() {
		return age;
	}
	int setAge(int a) {
		age = a;
	}

	char getSex() {
		return sex;
	}
	char setSex(char s) {
		sex = s;
	}
};

class Parent;
class Child : public Human {
private:
	std::string momName;
	std::string dadName;
	int allowance;
	Child();
public:
	Child(std::string n, int a, char s, std::string m, std::string d) : Human(n, a, s), allowance(0) {
		momName = m;
		dadName = d;
	}
	int getAllowance() {
		return allowance;
	}
	void printParent() {
		std::cout << "Mom: " << momName << std::endl;
		std::cout << "Dad: " << dadName << std::endl;
	}
	friend class Parent;
};

class Parent : public Human {
private:
	std::vector<std::string> children;
	Parent();
public:
	Parent(std::string name, int age, char sex) : Human(name, age, sex) {

	}
	void printChild() {
		//Print Children Vector
		for (size_t i = 0; i < children.size(); i++) {
			std::cout << children.at(i) << std::endl;
		}
	}
	void setChild(Child c) {
		//Insert name in children vector
		children.push_back(c.getName());
	}
	void setChildAllowance(int allowance, Child c) {
		//Verify child is in children vector
		bool isChild = false;
		for (size_t i = 0; i < children.size(); i++) {
			if (children.at(i) == c.getName()) {
				isChild = true;
				//Change private var allowance of child
				c.allowance = allowance;
			}
		}
	}
};

void printInfo(Human &h) {
	std::cout << h.getName() << std::endl;
	std::cout << h.getAge() << std::endl;
	std::cout << h.getSex() << std::endl;
}

int main() {
	Parent Homer("Homer", 36, 'M');
	Parent Marge("Marge", 34, 'F');
	Child Lisa("Lisa", 12, 'F', "Marge", "Homer");
	Child Bart("Bart", 10, 'M', "Marge", "Homer");
	Child Maggie("Maggie", 3, 'F', "Marge", "Homer");

	Homer.setChild(Lisa);
	Homer.setChild(Bart);
	Homer.setChild(Maggie);

	Marge.setChild(Lisa);
	Marge.setChild(Bart);
	Marge.setChild(Maggie);

	//Homer set bart allowance to 5
	Homer.setChildAllowance(5, Bart);

	std::cout << "Bart's allowance: " << Bart.getAllowance() << std::endl;
	std::cout << "Bart's Parents: " << std::endl;
	Bart.printParent();
	
	printInfo(Marge);
	printInfo(Lisa);
}