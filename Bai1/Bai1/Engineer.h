#pragma once
#include "Person.h"

class Engineer :public Person {
private:
	string id;
	string branch;
	int numOfExp;
public:
	static int numId;
	Engineer();
	Engineer(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, string branch, int numOfExp);
	string getId();
	void setId(string id);
	string getBranch();
	void setBranch(string branch);
	int getNumOfExp();
	void setNumOfExp(int numOfExp);
	void takeInfo();
	void displayInfo();
	int getSalary();
};