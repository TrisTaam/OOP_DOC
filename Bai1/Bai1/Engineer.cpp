#include "Engineer.h"

Engineer::Engineer() {
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "KS" + tmp;
}

Engineer::Engineer(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, string branch,int numOfExp) :Person(name, age, gender, address, phone, homeTown, coefficientsSalary, numOfWork) {
	this->branch = branch;
	this->numOfExp = numOfExp;
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "CN" + tmp;
}

string Engineer::getId() {
	return id;
}

void Engineer::setId(string id) {
	this->id = id;
}

string Engineer::getBranch() {
	return branch;
}

void Engineer::setBranch(string branch) {
	this->branch = branch;
}

int Engineer::getNumOfExp() {
	return numOfExp;
}

void Engineer::setNumOfExp(int numOfExp) {
	this->numOfExp = numOfExp;
}

void Engineer::takeInfo() {
	Person::takeInfo();
	cout << "Branch: "; getline(cin, branch);
	cout << "Years of Experience: "; cin >> numOfExp; cin.ignore();
}

void Engineer::displayInfo() {
	Person::displayInfo();
	cout << "Id: " << id << "\n";
	cout << "Branch: " << branch << "\n";
	cout << "Years of Experience: " << numOfExp << "\n";
}

int Engineer::getSalary() {
	return numOfExp * Person::getSalary();
}