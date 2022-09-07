#include "Worker.h"

Worker::Worker() {
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "CN" + tmp;
}

Worker::Worker(string name, int age, string gender, string address, string phone, string homeTown, int coefficientsSalary, int numOfWork, int level):Person(name,age,gender,address,phone,homeTown,coefficientsSalary,numOfWork){
	this->level = level;
	numId++;
	string tmp = to_string(numId);
	while (tmp.size() < 3) tmp = "0" + tmp;
	id = "CN" + tmp;
}

string Worker::getId() {
	return id;
}

void Worker::setId(string id) {
	this->id = id;
}

int Worker::getLevel() {
	return level;
}

void Worker::setLevel(int level) {
	this->level = level;
}

void Worker::takeInfo() {
	Person::takeInfo();
	cout << "Level: "; cin >> level; cin.ignore();
}

void Worker::displayInfo() {
	Person::displayInfo();
	cout << "Id: " << id << "\n";
	cout << "Level: " << level << "\n";
}

int Worker::getSalary() {
	return level * this->Person::getSalary();
}