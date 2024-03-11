
#include <iostream>
using namespace std;
int main()
{
    int a[5][5] = {
        10,11,12,13,14,
        21,22,23,24,25,
        26,27,28,29,30,
        31,32,33,34,35,
        36,37,38,39,40 };
    int b[5][5];
    int c[5][5];
    int d[5][5];
    for (int i = 0; i < 5; i++)
    {
        for ( int j = 0; j < 5; j++)

            cout << a[i][j] << "\t";

        cout << "\n";
    }
    //Inverting the matrix
    // 14,13,12,11,10
    // 25,24,23,22,21
    // 30,29,28,27,26
    // 35,34,33,32,31
    // 40,39,38,37,36
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            // Swap elements in each row
            int temp = a[i][j];
            a[i][j] = a[i][4 - j];
            a[i][4 - j] = temp;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)

            cout << b[i][j] << "\t";

        cout << "\n";
    }
}

