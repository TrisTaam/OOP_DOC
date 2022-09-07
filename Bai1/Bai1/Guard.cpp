#include "Guard.h"

Guard::Guard() {
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "BV" + tmp;
}

Guard::Guard(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, string area) :Person(name, age, gender, address, phone, homeTown, coefficientsSalary, numOfWork) {
	this->area = area;
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "CN" + tmp;
}

string Guard::getId() {
	return id;
}

void Guard::setId(string id) {
	this->id = id;
}

string Guard::getArea() {
	return area;
}

void Guard::setArea(string area) {
	this->area = area;
}

void Guard::takeInfo() {
	Person::takeInfo();
	cout << "Area: "; cin.ignore(); getline(cin, area);
}

void Guard::displayInfo() {
	Person::displayInfo();
	cout << "Id: " << id << "\n";
	cout << "Area: " << area << "\n";
}

int Guard::getSalary() {
	return Person::getSalary();
}