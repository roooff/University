#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int choice;

struct Disciplines
{
	string name;
	int grade = 0;
};
struct Students
{
	int facultyNumber = 0;
	int socialSecurityNumber = 0;
	string firstName;
	string middName;
	string gender;
	int age = 0;
	string status;
	float averageGrade = 0.00;
	Disciplines disciplines[5];

};
const int maxStudents = 30;
Students students[maxStudents];
int currentStudents = 0;
void BubbleSortByFacultyNumber(Students arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j].facultyNumber > arr[j + 1].facultyNumber) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void SelectionSortBySSN(Students arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j].socialSecurityNumber < arr[minIndex].socialSecurityNumber) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}
void DisplayStudents(Students arr[], int count) {
	cout << "Faculty Number\tSocial Security Number\tFirst Name\tMiddle Name\tGender\tAge\tStatus" << endl;
	for (int i = 0; i < count; ++i) {
		cout << arr[i].facultyNumber << "\t\t" << arr[i].socialSecurityNumber << "\t\t\t"
			<< arr[i].firstName << "\t\t" << arr[i].middName << "\t\t" << arr[i].gender << "\t"
			<< arr[i].age << "\t" << arr[i].status << endl;
	}
}
void FilterAndSortByGPARange() {
	float minGPA, maxGPA;
	cout << "Enter the minimum and maximum GPA range (min max): ";
	cin >> minGPA >> maxGPA;

	Students filteredStudents[maxStudents];
	int filteredCount = 0;
	for (int i = 0; i < currentStudents; ++i) {

		float totalGrade = 0.0;
		for (int j = 0; j < 5; ++j) {
			totalGrade += students[i].disciplines[j].grade;
		}
		float GPA = totalGrade / 5.0;

		if (GPA >= minGPA && GPA <= maxGPA) {
			filteredStudents[filteredCount++] = students[i];
		}
	}


	SelectionSortBySSN(filteredStudents, filteredCount);


	DisplayStudents(filteredStudents, filteredCount);
}
void FilterAndSortByStatus() {
	string status;
	cout << "Enter the status (Active/Interrupted/Graduated): ";
	cin >> status;

	Students filteredStudents[maxStudents];
	int filteredCount = 0;
	for (int i = 0; i < currentStudents; ++i) {
		if (students[i].status == status) {
			filteredStudents[filteredCount++] = students[i];
		}
	}


	BubbleSortByFacultyNumber(filteredStudents, filteredCount);


	DisplayStudents(filteredStudents, filteredCount);
}
void SortStudentsByMiddleName() {
	if (currentStudents == 0) {
		cout << "No students in the database." << endl;
		return;
	}


	for (int i = 0; i < currentStudents - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < currentStudents; ++j) {
			if (students[j].middName < students[minIndex].middName) {
				minIndex = j;
			}
		}
		if (minIndex != i) {

			Students temp = students[i];
			students[i] = students[minIndex];
			students[minIndex] = temp;
		}
	}


	cout << "Students sorted by middle name in alphabetical order:" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		cout << "Name: " << students[i].firstName << " " << students[i].middName << endl;

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
				break;
			}
		}
	}

	if (!found) {
		cout << "No students found with grade in the specified range for subject " << subjectName << endl;
	}
}
void SearchStudentsByPoorGrades() {
	int weakGrade = 2;

	bool found = false;
	cout << "Students with at least one subject graded as " << weakGrade << ":" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		bool studentFound = false;
		for (int j = 0; j < 5; ++j) {
			if (students[i].disciplines[j].grade == weakGrade) {
				studentFound = true;
				break;
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
void LoadStudentsFromFile() {
	ifstream inputFile("C:\\Users\\rooof\\Documents\\students.txt");

	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}


	while (!inputFile.eof()) {
		Students newStudent;
		inputFile >> newStudent.facultyNumber >> newStudent.socialSecurityNumber
			>> newStudent.firstName >> newStudent.middName
			>> newStudent.gender >> newStudent.age
			>> newStudent.status;

		for (int i = 0; i < 5; ++i) {
			inputFile >> newStudent.disciplines[i].name >> newStudent.disciplines[i].grade;
		}


		if (!inputFile.fail()) {
			students[currentStudents] = newStudent;
			currentStudents++;
		}
	}

	inputFile.close();
	cout << "Students' information loaded from the file 'students.txt'." << endl;
}
void SaveStudentsToFile() {
	ofstream outputFile("C:\\Users\\rooof\\Documents\\students.txt");

	if (!outputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}


	for (int i = 0; i < currentStudents; ++i) {
		outputFile << students[i].facultyNumber << " "
			<< students[i].socialSecurityNumber << " "
			<< students[i].firstName << " "
			<< students[i].middName << " "
			<< students[i].gender << " "
			<< students[i].age << " "
			<< students[i].status << " ";

		for (int j = 0; j < 5; ++j) {
			outputFile << students[i].disciplines[j].name << " "
				<< students[i].disciplines[j].grade << " ";
		}
		outputFile << endl;
	}

	outputFile.close();
	cout << "Students' information saved to the file 'students.txt'." << endl;
}
void LoadDataFromFile() {
	ifstream inputFile("students_data.txt");

	if (inputFile.is_open()) {
		while (inputFile >> students[currentStudents].facultyNumber >> students[currentStudents].socialSecurityNumber
			>> students[currentStudents].firstName >> students[currentStudents].middName
			>> students[currentStudents].gender >> students[currentStudents].age
			>> students[currentStudents].status) {
			for (int i = 0; i < 5; ++i) {
				inputFile >> students[currentStudents].disciplines[i].name >> students[currentStudents].disciplines[i].grade;
			}
			++currentStudents;
			if (currentStudents >= maxStudents) {
				cout << "Maximum student limit reached!" << endl;
				break;
			}
		}
		inputFile.close();
	}
	else {
		cout << "File not found or could not be opened!" << endl;
	}
}
void SaveDataToFile() {
	ofstream outputFile("students_data.txt");

	if (outputFile.is_open()) {
		for (int i = 0; i < currentStudents; ++i) {
			outputFile << students[i].facultyNumber << " " << students[i].socialSecurityNumber << " "
				<< students[i].firstName << " " << students[i].middName << " "
				<< students[i].gender << " " << students[i].age << " " << students[i].status << "\n";

			for (int j = 0; j < 5; ++j) {
				outputFile << students[i].disciplines[j].name << " " << students[i].disciplines[j].grade << " ";
			}
			outputFile << "\n";
		}
		outputFile.close();
	}
	else {
		cout << "File could not be created!" << endl;
	}
}
void UpdateGradesAndAverage() {
	int facNumber;
	cout << "Enter the faculty number of the student: ";
	cin >> facNumber;

	bool found = false;
	for (int i = 0; i < currentStudents; ++i) {
		if (students[i].facultyNumber == facNumber) {
			found = true;
			if (students[i].status == "Active") {
				float totalGrade = 0.0;
				int updated = 0;
				for (int j = 0; j < 5; ++j) {
					cout << "Enter grade for discipline " << students[i].disciplines[j].name << ": ";
					int newGrade;
					cin >> newGrade;
					if (newGrade >= 2 && newGrade <= 6) {
						totalGrade += newGrade;
						students[i].disciplines[j].grade = newGrade;
						++updated;
					}
				}
				students[i].averageGrade = totalGrade / updated;
				cout << "Updated grades and average grade for student with faculty number " << facNumber << endl;
			}
			else {
				cout << "Cannot update grades. The student's status is not Active." << endl;
			}
			break;
		}
	}
	if (!found) {
		cout << "Student with faculty number " << facNumber << " not found." << endl;
	}
}
void ChangeStatusByFacultyNumber() {
	int facNumber;
	cout << "Enter the faculty number of the student: ";
	cin >> facNumber;

	bool found = false;
	for (int i = 0; i < currentStudents; ++i) {
		if (students[i].facultyNumber == facNumber) {
			found = true;
			if (students[i].status != "Graduated") {
				string newStatus;
				cout << "Enter the new status (Active/Interrupted/Graduated): ";
				cin >> newStatus;
				if (newStatus == "Active" || newStatus == "Interrupted") {
					students[i].status = newStatus;
					cout << "Status updated for student with faculty number " << facNumber << endl;
				}
				else {
					cout << "Invalid status. Status remains unchanged." << endl;
				}
			}
			else {
				cout << "Cannot change status. The student's status is Graduated." << endl;
			}
			break;
		}
	}
	if (!found) {
		cout << "Student with faculty number " << facNumber << " not found." << endl;
	}
}
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
			for (int i = 0; i < sizeof(Students); i++)
			{
				if (newStudent.socialSecurityNumber == students[i].socialSecurityNumber)
				{
					cout << "This social security number already exists!" << endl;
					cout << "Enter social security number: " << endl;
					cin >> newStudent.socialSecurityNumber;

				}
			}
			cout << "Enter first name: " << endl;
			cin >> newStudent.firstName;
			cout << "Enter middle name: " << endl;
			cin >> newStudent.middName;
			cout << "Gender?: " << endl;
			cin >> newStudent.gender;
			cout << "Enter age: " << endl;
			cin >> newStudent.age;
			cout << "Enter status: (Active/Dropped out/Graduated) " << endl;
			cin >> newStudent.status;
			if (newStudent.status != "Active" || newStudent.status != "Dropped out" || newStudent.status != "Graduated")
			{
				cout << "Invalid status. Default status: Undefined";
				newStudent.status = "Undefined";
			}
			students[currentStudents] = newStudent;
			currentStudents++;
			cout << "Student added successfully!" << endl;
			cout << "Enter information for 5 disciplines (name and grade):" << endl;
			for (int i = 0; i < 5; ++i)
			{
				cout << "Discipline " << i + 1 << " name: ";
				cin >> newStudent.disciplines[i].name;
				cout << "Grade for " << newStudent.disciplines[i].name << ": ";
				cin >> newStudent.disciplines[i].grade;

			}

		}
		else {
			cout << "No more space for students!" << endl;
			break;
		}
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
	cout << "6. Save students' information to file" << endl;
	cout << "7. Load students' information from file" << endl;
	cout << "8. Filter students by status and sort by faculty number" << endl;
	cout << "9. Filter students by GPA range and sort by social security number" << endl;
	cout << "10. Update grades and average for a student" << endl;
	cout << "11. Change status for a student" << endl;
}
int main() {
	LoadDataFromFile();
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
			SearchStudentsByGradeRange();
			break;
		case '4':
			SearchStudentsByPoorGrades();
			break;
		case '5':
			SortStudentsByMiddleName();
			break;
		case '6':
			SaveStudentsToFile();
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		case '7':
			LoadStudentsFromFile();
			break;

		case '8':
			FilterAndSortByStatus();
			break;

		case '9':
			FilterAndSortByGPARange();
			break;
		case '10':
			UpdateGradesAndAverage();
			break;

		case '11':
			ChangeStatusByFacultyNumber();
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
			break;
		}
	}
	atexit(SaveDataToFile);
	return 0;
}
