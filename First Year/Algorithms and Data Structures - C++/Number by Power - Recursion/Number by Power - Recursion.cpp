#include <iostream>
using namespace std;

int power(int num, int pow) {
    if (pow == 0) {
        return 1;
    }
    else {
        return num * power(num, pow - 1); 
    }
}

int main() {
    int num, pow;
    cout << "Enter the desired number: " << endl;
    cin >> num;
    cout << "Enter the power: " << endl;
    cin >> pow;

    int result = power(num, pow);
    cout << num << " to the power of " << pow << " is: " << result << endl;
    return 0;
}

