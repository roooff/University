// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Employees
{
	string firstName;
	string lastName;
    double salary;
    float coefficient;


};

const int maxEmployees = 50;
Employees employee[maxEmployees];
int currEmployees = 0;
void Show()
{
	for(int i = 0; i <currEmployees; i++)
	{
		double finalSalary = employee[i].salary + employee[i].salary * employee[i].coefficient;
		cout << "Name :" << employee[i].firstName << " " << employee[i].lastName << " " << "Has a salary of :" << finalSalary << endl;
		
	}
}
void AddEmployee() {
	int employeesToAdd = 0;
	cout << "Enter the number of employes to add: ";
	cin >> employeesToAdd;

	for (int k = 0; k < employeesToAdd; ++k) {
		if (currEmployees < maxEmployees) {
			Employees newEmployee;
			cout << "Enter first name: " << endl;
			cin >> newEmployee.firstName;
			cout << "Enter last name: " << endl;
			cin >> newEmployee.lastName;
			cout << "What's your salary: " << endl;
			cin>> newEmployee.salary;
			cout<< "Coeficient?:" << endl;
			cin>> newEmployee.coefficient;
			// getline
			employee[currEmployees] = newEmployee;
			currEmployees++;
			cout << "Employee added successfully!" << endl;
		}
		else {
			cout << "No more space for new employess!" << endl;
			break;
		}
	}
}
void DisplayMenu() {
	cout << "Menu:" << endl;
	cout << "1. Add an employee" << endl;
	cout << "2. Show" << endl;
	cout << "3.Edit an employee" << endl;
	cout << "4.Exit" << endl;
}
void Edit()
{
	cout << "Pick and employee" << endl;
	int choice = 0;
	double newSalary;
	double newCoeficient;
	for (int  i = 0; i < currEmployees; i++)
	{
		cout<< i+1<< " " << employee[i].firstName << " " << employee[i].lastName << endl;
		cin >> choice;
		cout<< "Enter new salary for " << employee[choice - 1]. firstName << " "<< employee[choice - 1].firstName<< endl;
		cin >> newSalary;
		employee[choice-1].salary = newSalary;
		cout << "Enter new coeficient for " << employee[choice - 1].firstName << " " << employee[choice - 1].firstName << endl;
		cin >> newCoeficient;
		employee[choice - 1].coefficient = newCoeficient;
		cout << "Changes are made succesfully" << endl;
	}
}
	int main()
	{
		char choice = '0';

		while (choice != '6') {
			DisplayMenu();
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case '1':
				AddEmployee();
				break;
			case '2':
				Show();
				break;
			case '3':
				Edit();
				break;
			case '4':
				cout << "Bye";
				break;

			default:
				cout << "Invalid choice. Please enter a valid option." << endl;
				break;
			}
		}
	}



