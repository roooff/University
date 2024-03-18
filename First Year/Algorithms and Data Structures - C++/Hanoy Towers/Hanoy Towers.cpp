#include <iostream>
using namespace std;
void hanoj(char A, char C, char B, int n);
int main()
{
	char A = 'A', B = 'B', C = 'C';
	int n;
	cout << "Enter the disk's number n:";
	cin >> n;
	hanoj(A, C, B, n);
	return 0;
}
void hanoj(char A, char C, char B, int n)
{
	if (n == 1)
		cout << "Move the disk 1 from " << A << " to " << C << endl;
	else
	{
		hanoj(A, B, C, n - 1);
		cout << "Move the disk " << n << " from " << A << " to " << C << endl;
		hanoj(B, C, A, n - 1);
	}
}
