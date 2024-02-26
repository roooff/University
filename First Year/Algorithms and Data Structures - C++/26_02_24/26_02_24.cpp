// 26_02_24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
    const int rows = 6;  
    const int cols = 6;  

    int array[rows][cols];

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j) {
                array[i][j] = 0;  
            }
            else {
                
                array[i][j] = abs(i - j);
            }
        }
    }
}

//int main(){
//int matrix[5][5];
//int marker = 1;
//
//fo
//for (int i = 1; i < 5; i++)
//
//	
//
//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < 5; j++)
//	{
//
//		if (i == j)
//		{
//			matrix[i][j] = 0;
//		}
//
//	}
//
//}
//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < 5; j++)
//	{
//		cout << "\t" << matrix[i][j];
//	}
//	cout << endl;
//}
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
