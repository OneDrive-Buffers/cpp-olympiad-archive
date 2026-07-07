#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("smartphone.in");
ofstream fout("smartphone.out");

int main()
{

    int c;
    int n;

    fin >> c;
    fin >> n;

    if(c == 1)
    {
        int maxim = 0;
        for ( int i = 1; i<=n; i++ )
        {
            int telefon;
            fin>> telefon;

            if(telefon > maxim)
            {
                maxim = telefon;
            }
        }
        fout << maxim;
    }
    if (c == 2)
    {



    }




    return 0;
}
