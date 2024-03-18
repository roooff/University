// For Loop - Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
    int main()
    {

        int n;
        cout << "\nInput the integer: ";
        cin >> n;

        long long factorial = 1;

        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }

        cout << "\n" << n << "! = " << factorial << endl;
        return 0;
    }

