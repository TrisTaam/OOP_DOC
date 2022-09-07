#include "Manager.h"

Manager::Manager() {};

Manager::Manager(vector<Worker*> worker, vector<Engineer*> engineer, vector<Guard*> guard) {
	this->worker = worker;
	this->engineer = engineer;
	this->guard = guard;
}

vector<Worker*> Manager::getWorker() {
	return worker;
}

void Manager::setWorker(vector<Worker*> worker) {
	this->worker = worker;
}

vector<Engineer*> Manager::getEngineer() {
	return engineer;
}

void Manager::setEngineer(vector<Engineer*> engineer) {
	this->engineer = engineer;
}

vector<Guard*> Manager::getGuard() {
	return guard;
}

void Manager::setGuard(vector<Guard*> guard) {
	this->guard = guard;
}

void Manager::addWorker() {
	Worker* tmp = new Worker();
	tmp->takeInfo();
	worker.push_back(tmp);
	cout << worker.size() << "\n";
}

void Manager::addEngineer() {
	Engineer* tmp = new Engineer();
	tmp->takeInfo();
	engineer.push_back(tmp);
}

void Manager::addGuard() {
	Guard* tmp = new Guard();
	tmp->takeInfo();
	guard.push_back(tmp);
}
