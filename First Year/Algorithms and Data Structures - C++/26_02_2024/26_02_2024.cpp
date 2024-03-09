/*
 * 5  5  5  5  5
 * 5  4  4  4  5
 * 5  4  3  4  5
 * 5  4  4  4  5
 * 5  5  5  5  5
 *
 */

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "bg");
	const int N = 5;
	int i, j;
	int a[N][N];


	for (j = 0; j <= N / 2; j++)
		for (i = j; i < N - j; i++)
		{
			a[j][i] = N - j;
			a[i][N - 1 - j] = N - j;
			a[N - 1 - j][i] = N - j;
			a[i][j] = N - j;
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

