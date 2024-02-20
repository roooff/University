#include <fstream>
#include<iomanip>
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
	string lastName;
	string gender;
	int age = 0;
	string status;
	float gPA = 0.00;
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
	cout << "Faculty Number\tSocial Security Number\tFirst Name\tLast Name\tGender\tAge\tStatus" << endl;
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
	cout << "Enter the status (Active/lastName/Graduated): ";
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
	cout << "Enter the minimum grade for Basic Programming: ";
	cin >> minGrade;
	cout << "Enter the maximum grade for Basic Programming: ";
	cin >> maxGrade;

	bool found = false;
	cout << "Students with grade in range " << minGrade << " - " << maxGrade << " for Basic Progeamming :" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		if (students[i].disciplines[0].grade >= minGrade && students[i].disciplines[0].grade <= maxGrade) {
			cout << "Faculty Number: " << students[i].facultyNumber << ", Name: " << students[i].firstName << " " << students[i].lastName << ", Grade: " << students[i].disciplines[0].grade << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "No students found with grade in the specified range for Basic Programming " << endl;
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
void SaveStudentsToFile() {
	ofstream outFile("save_students.txt");

	if (outFile.is_open()) {
		for (int i = 0; i < currentStudents; ++i) {
			outFile << students[i].facultyNumber << " "
				<< students[i].socialSecurityNumber << " "
				<< students[i].firstName << " "
				<< students[i].lastName << " "
				<< students[i].gender << " "
				<< students[i].age << " "
				<< students[i].status << " "
				<< students[i].gPA << " ";

			for (int j = 0; j < 5; ++j) {
				outFile << students[i].disciplines[j].name << " "
					<< students[i].disciplines[j].grade << " ";
			}
			outFile << endl;
		}
		outFile.close();
		cout << "Student data saved to file successfully." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
void LoadStudentsFromFile() {
	ifstream inFile("save_students.txt");

	if (inFile.is_open()) {
		currentStudents = 0;
		while (!inFile.eof() && currentStudents < maxStudents) {
			inFile >> students[currentStudents].facultyNumber
				>> students[currentStudents].socialSecurityNumber
				>> students[currentStudents].firstName
				>> students[currentStudents].lastName
				>> students[currentStudents].gender
				>> students[currentStudents].age
				>> students[currentStudents].status
				>> students[currentStudents].gPA;

			for (int j = 0; j < 5; ++j) {
				inFile >> students[currentStudents].disciplines[j].name
					>> students[currentStudents].disciplines[j].grade;
			}
			currentStudents++;
		}
		inFile.close();
		cout << "Student data loaded from file successfully." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
void UpdateGradesAndAverage() {
	int facNumber;
	cout << "Enter the faculty number of the student: ";
	cin >> facNumber;
	for (int i = 0; i < currentStudents; i++)
	{
		if (facNumber == students[i].facultyNumber)
		{
			if (students[i].status == "Dropped" && students[i].status == "Graduated")
			{
				cout << "Student is not activly styding here , can't modify details" << endl;

			}
			else
			{
				bool grades = true;
				while (grades)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << "Enter Grade for : " << students[i].disciplines[j].name << " between 2-6" << endl;
						cin >> students[i].disciplines[j].grade;
						if (students[i].disciplines[j].grade != 2 && students[i].disciplines[j].grade != 3 && students[i].disciplines[i].grade != 4 &&
							students[i].disciplines[j].grade != 5 && students[i].disciplines[j].grade != 6)
						{
							cout << "Invalid grade! Try again." << endl;
							i--;
						}
						else
						{
							cout << "Grade for " << students[i].disciplines[i].name << " added succssefully " << endl;
							grades = false;
						}

					}
					float totalGrade = 0.0;
					for (int j = 0; j < 5; ++j) {
						totalGrade += students[i].disciplines[j].grade;
					}
					students[i].gPA = totalGrade / 5.00;
					cout<< "GPA now is:"<< students[i].gPA << endl;
				}
			}
			
		}
		else
		{

			cout << "Student with faculty number " << facNumber << " not found." << endl;
			i = currentStudents;
		}
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
				cout << "Enter the new status (Active/Dropped/Graduated): ";
				cin >> newStatus;
				if (newStatus == "Active" || newStatus == "Dropped") {
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
			
			do {
				cout << "Enter faculty number: " << endl;
				cin >> newStudent.facultyNumber;

				// Check for duplicate faculty number
				bool facultyExists = false;
				for (int i = 0; i < currentStudents; i++) {
					if (newStudent.facultyNumber == students[i].facultyNumber) {
						cout << "This faculty number already exists! Try again." << endl;
						facultyExists = true;
						break;
					}
				}
				if (facultyExists) {
					continue; // Restart the loop for a new faculty number
				}
				break; // Break out of the loop if faculty number is unique
			} while (true);
			bool sSNExists = true;
			while (sSNExists) {
				cout << "Enter social security number: " << endl;
				cin >> newStudent.socialSecurityNumber;
				sSNExists = false;

				for (int i = 0; i < currentStudents; i++) {
					if (newStudent.socialSecurityNumber == students[i].socialSecurityNumber) {
						cout << "This social security number already exists! Try again." << endl;
						sSNExists = true;
						break;
					}
					
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
			bool status = true;
			while (status)
			{
				cout << "Enter status: Active|Dropped|Graduated" << endl;
				cin >> newStudent.status;
				if (newStudent.status != "Active" && newStudent.status != "Dropped" && newStudent.status != "Graduated")
				{
					cout << "Invalid status, try again:" << endl;

				}
				else
				{
					cout << "Status added successfully! " << endl;
					status = false;
				}
			}
			students[currentStudents] = newStudent;
			currentStudents++;
			cout << "Student added successfully!" << endl;
			cout << "Disciplines: " << endl;
			newStudent.disciplines[0].name = "Basic Programming";
			newStudent.disciplines[1].name = "Mathematics";
			newStudent.disciplines[2].name = "English";
			newStudent.disciplines[3].name = "Digital Logic";
			newStudent.disciplines[4].name = "Electronics";
			
			int grade = 0;
				for (int i = 0; i < 5; ++i)
				{
					cout << "Enter Grade for : " << newStudent.disciplines[i].name << " between 2-6" << endl;
					cin >> newStudent.disciplines[i].grade;
					if (newStudent.disciplines[i].grade != 2&& newStudent.disciplines[i].grade != 3 && newStudent.disciplines[i].grade != 4 &&
						newStudent.disciplines[i].grade != 5 && newStudent.disciplines[i].grade != 6 )
					{
						cout << "Invalid grade! Try again." << endl;
						i--;
					}
					else
					{
						cout << "Grade for " << newStudent.disciplines[i].name << " added succssefully " << endl;
						grade += newStudent.disciplines[i].grade;
						
					}
					
				}
				newStudent.gPA = grade / 5.00;
			

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

	cout << "| Faculty Number | Social Security Number | First Name | Last Name | Gender | Age | Status | Average Grade |" << endl;
	for (int i = 0; i < currentStudents; ++i) {
		cout << "|" << setw(10) << students[i].facultyNumber << "|" << setw(20) << students[i].socialSecurityNumber << "|"
			<< setw(15) << students[i].firstName << "|" << setw(15) << students[i].lastName << "|" << setw(10) << students[i].gender << "|"
			<< setw(5) << students[i].age << " |" << setw(10) << students[i].status << " |" << setw(10) << students[i].gPA << "|" << endl;
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
	LoadStudentsFromFile();
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
			LoadStudentsFromFile();
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		case '7':
			SaveStudentsToFile();
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
	atexit(SaveStudentsToFile);
	return 0;
}
