#include "Person.h"

Person::Person() {
	this->name = "";
	this->age = 0;
	this->gender = "";
	this->address = "";
	this->phone = "";
	this->homeTown = "";
	this->coefficientsSalary = 0;
	this->numOfWork = 0;
};

Person::Person(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork) {
	this->name= name;
	this->age = age;
	this->gender = gender;
	this->address = address;
	this->phone = phone;
	this->homeTown = homeTown;
	this->coefficientsSalary = coefficientsSalary;
	this->numOfWork= numOfWork;
}

string Person::getName() {
	return name;
}

void Person::setName(string name) {
	this->name = name;
}

string Person::getGender() {
	return gender;
}

void Person::setGender(string gender) {
	this->gender = gender;
}

string Person::getAddress() {
	return address;
}

void Person::setAddress(string address) {
	this->address = address;
}

string Person::getPhone() {
	return phone;
}

void Person::setPhone(string phone) {
	this->phone = phone;
}

string Person::getHomeTown() {
	return homeTown;
}

void Person::setHomeTown(string homeTown) {
	this->homeTown = homeTown;
}

int Person::getCoefficientsSalary() {
	return coefficientsSalary;
}

void Person::setCoefficientsSalary(int coefficientsSalary) {
	this->coefficientsSalary = coefficientsSalary;
}

int Person::getNumOfWork() {
	return numOfWork;
}

void Person::setNumOfWork(int numOfWork) {
	this->numOfWork = numOfWork;
}

void Person::takeInfo() {
	cout << "Name: "; cin.ignore(); getline(cin, name);
	cout << "Age: "; cin >> age; cin.ignore();
	cout << "Gender: "; getline(cin, gender);
	cout << "Address: "; getline(cin, address);
	cout << "Phone Number: "; cin >> phone; cin.ignore();
	cout << "HomeTown: "; getline(cin, homeTown);
	cout << "Salary's Coefficient: "; cin >> coefficientsSalary; cin.ignore();
	cout << "Number of Working: "; cin >> numOfWork; cin.ignore();
}

void Person::displayInfo() {
	cout << "Name: " << name << "\n";
	cout << "Age: " << age << "\n";
	cout << "Gender: " << gender << "\n";
	cout << "Address: " << address << "\n";
	cout << "Phone Number: " << phone << "\n";
	cout << "HomeTown: " << homeTown << "\n";
}

int Person::getSalary() {
	return numOfWork * coefficientsSalary;
}