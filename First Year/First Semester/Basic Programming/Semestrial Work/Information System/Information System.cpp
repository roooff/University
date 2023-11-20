#include <iostream>
#include <string>
using namespace std;
nt choice;

struct Disciplines
{
	string name;
	int grade;
};
struct Students
{
	int facultyNumber;
	int socialSecurityNumber;
	string firstName;
	string middName;
	string gender;
	int age;
	string status;
	Disciplines disciplines[5];

};
// Adding students
const int maxStudents = 30;
Students students[maxStudents];
int currentStudents = 0;
void AddStudent()
{
	int numStudentsToAdd;
	cout << "Enter the number of students to add: ";
	cin >> numStudentsToAdd;

	if (currentStudents + numStudentsToAdd > maxStudents) {
		cout << "Cannot add more students than available space!" << endl;
		return;
	}

	for (int i = 0; i < numStudentsToAdd; ++i) {
		if (currentStudents >= maxStudents) {
			cout << "No more space for students!" << endl;
			break;
		}
		Students newStudent;
		cout << "Enter faculty number: " << endl;
		cin >> newStudent.facultyNumber;
		cout << "Enter social security number: " << endl;
		cin >> newStudent.socialSecurityNumber;
		cout << "Enter first name: " << endl;
		cin >> newStudent.firstName;
		cout << "Enter middle name: " << endl;
		cin >> newStudent.middName;
		cout << "Gender?: " << endl;
		cin >> newStudent.gender;
		cout << "Enter age: " << endl;
		cin >> newStudent.age;
		cout << "Enter status: " << endl;
		cin >> newStudent.status;
		cout << "Enter information for 5 disciplines (name and grade):" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << "Discipline " << i + 1 << " name: ";
			cin >> newStudent.disciplines[i].name;
			cout << "Grade for " << newStudent.disciplines[i].name << ": ";
			cin >> newStudent.disciplines[i].grade;

		}
		students[currentStudents] = newStudent;
		currentStudents++;
		cout << "Student added successfully!" << endl;
		break;
	}
}



//Menu 
bool exit = false;
void DisplayMenu() {
	cout << "Menu:" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Display all students" << endl;
	cout << "3. Search for students" << endl;
	cout << "4. Sort students by name" << endl;
	cout << "5. Work with external file" << endl;
	cout << "6. Exit" << endl;
}
void DisplayAllStudents() {
	if (currentStudents == 0) {
		cout << "No students in the database." << endl;
		return;
	}

	cout << "List of all students:" << endl;
	cout << "==============================================================================" << endl;
	cout << "Faculty # | SSN | First Name | Middle Name | Gender | Age | Status | Disciplines" << endl;
	cout << "==============================================================================" << endl;

	for (int i = 0; i < currentStudents; ++i) {
		cout << students[i].facultyNumber << "\t"
			<< students[i].socialSecurityNumber << "\t"
			<< students[i].firstName << "\t"
			<< students[i].middName << "\t"
			<< students[i].gender << "\t"
			<< students[i].age << "\t"
			<< students[i].status << "\t";

		for (int j = 0; j < 5; ++j) {
			cout << students[i].disciplines[j].name << ": " << students[i].disciplines[j].grade << " | ";
		}
		cout << endl;
	}
	cout << "==============================================================================" << endl;
}
int main() {
	char choice = '0';

	while (choice != '6') {
		DisplayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			AddStudent();
			break;
		case '2':
			DisplayAllStudents();
			break;
			// Implement cases for other functionalities (search, sort, file operations)
		case '6':
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
			break;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

