#pragma once
#include "Worker.h"
#include "Engineer.h"
#include "Guard.h"

class Manager {
private:
	vector<Worker*> worker;
	vector<Engineer*> engineer;
	vector<Guard*> guard;
public:
	Manager();
	Manager(vector<Worker*> worker, vector<Engineer*> engineer, vector<Guard*> guard);
	vector<Worker*> getWorker();
	void setWorker(vector<Worker*> worker);
	vector<Engineer*> getEngineer();
	void setEngineer(vector<Engineer*> engineer);
	vector<Guard*> getGuard();
	void setGuard(vector<Guard*> guard);
	void addWorker();
	void addEngineer();
	void addGuard();
};