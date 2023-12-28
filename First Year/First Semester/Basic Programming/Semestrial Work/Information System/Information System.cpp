#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
int choice;

struct Disciplines
{
	string name;
	int grade = 0;
}; 
struct Students
{
	int facultyNumber ;
	int socialSecurityNumber;
	string firstName;
	string lastName;
	string gender;
	int age;
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
			<< arr[i].firstName << "\t\t" << arr[i].lastName << "\t\t" << arr[i].gender << "\t"
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
			if (students[j].lastName < students[minIndex].lastName) {
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
		cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;

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
				cout << "Faculty Number: " << students[i].facultyNumber << ", Name: " << students[i].firstName << " " << students[i].lastName << ", Grade: " << students[i].disciplines[j].grade << endl;
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
			cout << "Faculty Number: " << students[i].facultyNumber << ", Name: " << students[i].firstName << " " << students[i].lastName << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "No students found with at least one subject graded as " << weakGrade << endl;
	}
}
void LoadStudentsFromFile() {
	ifstream inputFile("C:\\Users\\rooof\\Documents\\load_students.txt");

	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}


	while (!inputFile.eof()) {
		Students newStudent;
		inputFile >> newStudent.facultyNumber >> newStudent.socialSecurityNumber
			>> newStudent.firstName >> newStudent.lastName
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
			<< students[i].lastName << " "
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
	ifstream inputFile("C:\\Users\\rooof\\Documents\\load_students.txt");

	if (inputFile.is_open()) {
		while (inputFile >> students[currentStudents].facultyNumber >> students[currentStudents].socialSecurityNumber
			>> students[currentStudents].firstName >> students[currentStudents].lastName
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
			outputFile << students[i].facultyNumber << " | " << students[i].socialSecurityNumber << " | "
				<< students[i].firstName << " | " << students[i].lastName << " | "
				<< students[i].gender << " | " << students[i].age << " | " << students[i].status << "\n";

			for (int j = 0; j < 5; ++j) {
				outputFile << students[i].disciplines[j].name << " | " << students[i].disciplines[j].grade << " | ";
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
			for (int i = 0; i <currentStudents; i++)
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
			cout << "Enter last name: " << endl;
			cin >> newStudent.lastName;
			cout << "Gender?: " << endl;
			cin >> newStudent.gender;
			cout << "Enter age: " << endl;
			cin >> newStudent.age;
			cout << "Enter status: Active-1|Dropped out-2|Graduated-3 " << endl;
			int status = 0;
			cin >> status;
			switch (status)
			{
				case 1:
					newStudent.status = "Active";
					break;
				case 2:
					newStudent.status = "Dropped out";
					break;
				case 3:
					newStudent.status = "Graduated";
				break;
			default: 
				cout << "Invalid choice, status becomes Empty" << endl;
					newStudent.status = "Empty";
				break;
			}
			cin >> newStudent.status;

			
			students[currentStudents] = newStudent;
			currentStudents++;
			cout << "Student added successfully!" << endl;
			cout << "Disciplines: " << endl;
			newStudent.disciplines[0].name = "Basic Programming";
			newStudent.disciplines[1].name = "Mathematics";
			newStudent.disciplines[2].name = "English";
			newStudent.disciplines[3].name = "Digital Logic";
			newStudent.disciplines[4].name = "Electronics";

			for (int i = 0; i < 5; ++i)
			{
				cout << "Enter Grade for :" << newStudent.disciplines[i].name << endl;
				cin>> newStudent.disciplines[i].grade;
				cout<<"Grade for" << newStudent.disciplines[i].name << "added succssefully" << endl;
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

	cout << "| Faculty Number | Social Security Number | First Name | Middle Name | Last Name | Gender | Age | Status | Average Grade |" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		cout << "|" <<setw(10)<<students[i].facultyNumber << "|" << setw(20) << students[i].socialSecurityNumber << "|"
			<< setw(15) << students[i].firstName << "|" << setw(15) << students[i].lastName << "|" << setw(10) << students[i].gender << "|"
			<< setw(5) << students[i].age << " |" << setw(10) << students[i].status << " |" << setw(10) << students[i].averageGrade << "|" << endl;
	}
} // DONE

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
