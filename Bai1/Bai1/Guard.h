#pragma once
#include "Person.h"

class Guard :public Person {
private:
	string id;
	string area;
public:
	static int numId;
	Guard();
	Guard(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, string area);
	string getId();
	void setId(string id);
	string getArea();
	void setArea(string branch);
	void takeInfo();
	void displayInfo();
	int getSalary();
};