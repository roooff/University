#include <iostream>
using namespace std;
long f(int n);//prototype

	int main()
{
	int n;
	cout << "\nInput the integer:";
	cin >> n;
	cout << "\n" << n << "! = " << f(n);
	return 0;
}
long f(int n)
{
	if (n > 0)
		return (n * f(n - 1));
	else
		return(1);
}


