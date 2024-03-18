#include <iostream>
// recursion example: 
using namespace std;
void rec(int i) {
	cout << i << " ";
	if (i > 0)
	{
		rec(i - 1);

	}
	cout <<i<<" ";
}
int main()
{
	rec(100000000000000000);
	return(0);
}


