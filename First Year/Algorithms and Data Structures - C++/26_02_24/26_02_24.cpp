/*
 * 5  5  5  5  5
 * 0  4  4  4  4
 * 0  0  3  3  3
 * 0  0  0  2  2
 * 0  0  0  0  1
 *
 */

#include <iostream>
using namespace std;

int main(int arg, char* argv[])
{
	setlocale(LC_ALL, "bg");
	const int N = 5;
	int i, j;
	int a[N][N];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = 0;

	for (i = 0; i < N; i++)
		for (j = i; j < N; j++)
		{
			a[i][j] = N - i;

		}

	//print
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)

			cout << a[i][j] << "\t";

		cout << "\n";
	}
	system("pause");
	return 0;
}


