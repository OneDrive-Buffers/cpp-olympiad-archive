/*

Se citesc doua numere intregi x si y. 
Sa se determine perechile de divizori ai numarului x*y 
cu conditia ca primul divizor este par si strict mai mic decat cel de-al doilea divizor.
*/


#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if ( n % 2 == 0 )
	{
		for ( int i = 2; i <= n / 2; i+=2)
		{
			if ( n % i == 0 )
			{
				for ( int j = i + 1; j <= n; j++ )
				{
					if ( n % j == 0 )
					{
						cout << i << " " << j << endl;
					}
				}
			}
		}
	}
}