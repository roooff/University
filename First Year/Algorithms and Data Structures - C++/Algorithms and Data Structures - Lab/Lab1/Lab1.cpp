#include <iostream>
using namespace std;
int main()
{
	// Declaring arrays and marker
	int marker = 9;
	int  a[2][2];
	
	
	cout  << "2D Array Input: " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Array[" << i << "][" << j << "]=  ";
			cin >> a[i][j];
		}
	}
	

	for (int  i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//Right & Left
			if (j==0 && j<2 )
			{
				if (a[i][j] == a[i][j+1])
				{
					a[i][j] = marker;
					a[i][j + 1] = marker;
				}
				if (j!=0)
				{
					if (a[i][j] == a[i][j - 1])
					{
						a[i][j] = marker;
						a[i][j - 1] = marker;
					}
				}
				
			}
			//Up & Down
				if (i>-1 && i <2)
				{
					if (a[i][j] == a[i+1][j])
					{
						a[i][j] = marker;
						a[i + 1][j] = marker;
						
					}
					if (i> 0)
					{
						if (a[i][j] == a[i - 1][j])
						{
							a[i - 1][j] = marker;
							a[i][j] = marker;
							
						}
					}
				}

				marker++;
		}
			
			
	}
		
		cout<< "2D Array Output: " << endl;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << "\t" << a[i][j];
			}
			cout << endl;
		}
	}
	

