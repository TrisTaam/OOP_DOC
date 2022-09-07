#pragma once
#include "Header.h"

class Person {
private:
	string name;
	int age;
	string gender;
	string address;
	string phone;
	string homeTown;
	int coefficientsSalary;
	int numOfWork;
public:
	Person();
	Person(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork);
	string getName();
	void setName(string name);
	string getGender();
	void setGender(string gender);
	string getAddress();
	void setAddress(string address);
	string getPhone();
	void setPhone(string phone);
	string getHomeTown();
	void setHomeTown(string homeTown);
	int getCoefficientsSalary();
	void setCoefficientsSalary(int coefficientsSalary);
	int getNumOfWork();
	void setNumOfWork(int numOfWork);
	void takeInfo();
	void displayInfo();
	int getSalary();
};
