/*Да се състави програма (функция),
 *която запълва с числа елементите на матрицата по следния начин
 * 0  20  19  17  14
 * 1   0  18  16  13
 * 2   5   0  15  12
 * 3   6   8   0  11
 * 4   7   9  10   0
 *
 */

#include <iostream>
using namespace std;

int main(int arg, char* argv[])
{
	setlocale(LC_ALL, "bg");
	int i, j, n, k;
	n = 5;
	int a[n][n];
	k = 0;
	for (i = 0; i < n; i++)
	{
		a[i][i] = 0;
	}
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			a[j][i] = ++k;
		}
	for (i = n - 1; i > 0; i--)
		for (j = i - 1; j >= 0; j--)
		{
			a[j][i] = ++k;
		}
	//print
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)

			cout << a[i][j] << "\t";

		cout << "\n";
	}
	system("pause");
	return 0;
}
