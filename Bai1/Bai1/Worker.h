#pragma once
#include "Person.h"

class Worker :public Person {
private:
	string id;
	int level;
public:
	static int numId;
	Worker();
	Worker(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, int level);
	string getId();
	void setId(string id);
	int getLevel();
	void setLevel(int level);
	void takeInfo();
	void displayInfo();
	int getSalary();
};