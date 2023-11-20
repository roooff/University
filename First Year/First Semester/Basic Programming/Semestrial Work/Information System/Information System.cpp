#include <iostream>
#include <string>
using namespace std;
int choice;
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
const int maxStudents = 30;
Students students[maxStudents];
int currentStudents = 0;
void AddStudent() {
	int studentsToAdd = 0;
	cout << "Enter the number of students to add: ";
	cin >> studentsToAdd;

	for (int k = 0; k < studentsToAdd; ++k) {
		if (currentStudents < maxStudents) {
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
			students[currentStudents] = newStudent;
			currentStudents++;
			cout << "Student added successfully!" << endl;
		}
		else {
			cout << "No more space for students!" << endl;
			break; // Exit the loop if the maximum limit is reached
		}
	}
}
void SortStudentsByMiddleName() {
	if (currentStudents == 0) {
		cout << "No students in the database." << endl;
		return;
	}

	// Selection sort algorithm to sort students by middle name
	for (int i = 0; i < currentStudents - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < currentStudents; ++j) {
			if (students[j].middName < students[minIndex].middName) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			// Swap students if needed
			Students temp = students[i];
			students[i] = students[minIndex];
			students[minIndex] = temp;
		}
	}

	// Display the sorted list of students
	cout << "Students sorted by middle name in alphabetical order:" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		cout << "Name: " << students[i].firstName << " " << students[i].middName << endl;
		// Display other student details as needed
	}
}

void SearchStudentsByGradeRange() {
	int minGrade, maxGrade;
	string subjectName = "Basic Programming";

	cout << "Enter the minimum grade for Basic Programming: ";
	cin >> minGrade;
	cout << "Enter the maximum grade for Basic Programming: ";
	cin >> maxGrade;

	bool found = false;
	cout << "Students with grade in range " << minGrade << " - " << maxGrade << " for subject " << subjectName << ":" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (students[i].disciplines[j].name == subjectName && students[i].disciplines[j].grade >= minGrade && students[i].disciplines[j].grade <= maxGrade) {
				cout << "Faculty Number: " << students[i].facultyNumber << ", Name: " << students[i].firstName << " " << students[i].middName << ", Grade: " << students[i].disciplines[j].grade << endl;
				found = true;
				break; // Only display each student once
			}
		}
	}

	if (!found) {
		cout << "No students found with grade in the specified range for subject " << subjectName << endl;
	}
}
void SearchStudentsByPoorGrades() {
	int weakGrade = 2; // Weak grade

	bool found = false;
	cout << "Students with at least one subject graded as " << weakGrade << ":" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		bool studentFound = false; // Flag to check if the student has at least one subject with Weak 2 grade
		for (int j = 0; j < 5; ++j) {
			if (students[i].disciplines[j].grade == weakGrade) {
				studentFound = true;
				break; // If Weak 2 grade is found for the student, no need to check further
			}
		}
		if (studentFound) {
			cout << "Faculty Number: " << students[i].facultyNumber << ", Name: " << students[i].firstName << " " << students[i].middName << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "No students found with at least one subject graded as " << weakGrade << endl;
	}
}




void DisplayAllStudents() {
	if (currentStudents == 0) {
		cout << "No students in the database." << endl;
		return;
	}

	cout << "Students' list:" << endl;
	cout << "========================================================================================================================================================================================================================================================" << endl;
	cout << "Faculty #\t| SSN\t| First Name\t| Middle Name\t| Gender\t| Age\t| Status\t| Discipline 1\t| Grade 1\t| Discipline 2\t| Grade 2\t| Discipline 3\t| Grade 3\t| Discipline 4\t| Grade 4\t| Discipline 5\t| Grade 5" << endl;
	cout << "========================================================================================================================================================================================================================================================" << endl;

	for (int i = 0; i < currentStudents; ++i) {
		cout << students[i].facultyNumber << "\t\t| " << students[i].socialSecurityNumber << "\t| "
			<< students[i].firstName << "\t\t| " << students[i].middName << "\t\t| "
			<< students[i].gender << "\t\t| " << students[i].age << "\t| "
			<< students[i].status << "\t| ";

		for (int j = 0; j < 5; ++j) {
			if (j < 5) {
				cout << students[i].disciplines[j].name << "\t| " << students[i].disciplines[j].grade;
				if (j != 4) {
					cout << "\t| ";
				}
			}
			else {
				cout << "\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t|\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t|\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t| \t\t| \t|";
			}
		}
		cout << endl;
	}

	cout << "========================================================================================================================================================================================================================================================" << endl;
}

void DisplayMenu() {
	cout << "Menu:" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Display all students" << endl;
	cout << "3. Search students by grade range for Basic Programming" << endl;
	cout << "4. Search students with at least one subject graded as Weak 2" << endl;
	cout << "5. Sort students by middle name" << endl;
	cout << "6. Exit" << endl;
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
		case '3':
			SearchStudentsByGradeRange(); // Function to search by grade range for Basic Programming
			break;
		case '4':
			SearchStudentsByPoorGrades(); // Function to search for students with Weak 2 grade
			break;
		case '5':
			SortStudentsByMiddleName(); // Function to sort students by middle name
			break;
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
