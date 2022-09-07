#include "Manager.h"

int Worker::numId = 0;
int Engineer::numId = 0;
int Guard::numId = 0;

int main() {
	Manager* manager=new Manager();
	int n;
	string tmp;
	while (1) {
		cout << "=================================================================================\n";
		cout << "1. Add a new worker\n";
		cout << "2. Add a new engineer\n";
		cout << "3. Add a new guard\n";
		cout << "4. Find someone\n";
		cout << "5. Display salary of someone\n";
		cout << "6. Exit\n";
		cout << "=================================================================================\n";
		cout << "Enter number: ";
		cin >> n;
		if (n == 1) manager->addWorker();
		else if (n == 2) manager->addEngineer();
		else if (n == 3) manager->addGuard();
		else if (n == 4) {
			cout << "Name: "; cin.ignore(); getline(cin, tmp);
			cout << "\n";
			if (!manager->getWorker().empty())
				foru(i, 0, manager->getWorker().size() - 1)
					if (manager->getWorker()[i]->getName() == tmp) {
						manager->getWorker()[i]->displayInfo();
						cout << "\n";
					}
			if (!manager->getEngineer().empty())
				foru(i, 0, manager->getEngineer().size() - 1)
					if (manager->getEngineer()[i]->getName() == tmp) {
						manager->getEngineer()[i]->displayInfo();
						cout << "\n";
					}
			if (!manager->getGuard().empty())
				foru(i, 0, manager->getGuard().size() - 1)
					if (manager->getGuard()[i]->getName() == tmp) {
						manager->getGuard()[i]->displayInfo();
						cout << "\n";
					}
		}
		else if (n == 5) {
			cout << "Name: "; cin.ignore(); getline(cin, tmp);
			cout << "\n";
			if (!manager->getWorker().empty())
				foru(i, 0, manager->getWorker().size() - 1)
				if (manager->getWorker()[i]->getName() == tmp) {
					manager->getWorker()[i]->displayInfo();
					cout << "Salary: " << manager->getWorker()[i]->getSalary() << "\n";
				}
			if (!manager->getEngineer().empty())
				foru(i, 0, manager->getEngineer().size() - 1)
				if (manager->getEngineer()[i]->getName() == tmp) {
					manager->getEngineer()[i]->displayInfo();
					cout << "Salary: " << manager->getEngineer()[i]->getSalary() << "\n";
				}
			if (!manager->getGuard().empty())
				foru(i, 0, manager->getGuard().size() - 1)
				if (manager->getGuard()[i]->getName() == tmp) {
					manager->getGuard()[i]->displayInfo();
					cout << "Salary: " << manager->getGuard()[i]->getSalary() << "\n";
				}
		}
		else break;
	}
}