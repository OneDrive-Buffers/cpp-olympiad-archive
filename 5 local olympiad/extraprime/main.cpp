#include <iostream>
#include <fstream> // aici am inclus libraria fstream.
using namespace std;

ifstream fin("extraprime.in");   //aici am declarat input file stream numit fin fisierul "extraprime.in";
ofstream fout("extraprime.out"); //aici am declarat output file stream numit fout fisierul "extraprime.out";

int main()
{
    int a;
    int b;
    fin >> a;
    fin >> b;

    int contor = 0;
    int minim = -1; int maxim = -1;

    for(int i = a ; i <= b ; i = i+1)
    {
        // verific daca i este prim
        int prim = 1;
        for(int d = 2; d < i; d = d+1)
        {
            if ( i % d == 0 )
            {
                prim = 0;
            }
        }

        if( prim == 1 )
        {
            // incep sa verific daca numarul este superprim

            int copie = i;
            int superprim = 1;
            while(copie != 0)
            {

                copie = copie / 10;

                for ( int d = 2; d < copie; d++)
                {
                    if ( copie % d == 0 )
                    {
                        superprim = 0;
                    }
                }
            }
            if(superprim == 1)
            {
                contor ++;
            }
            if(superprim == 1 && minim == -1)
            {
                minim = i;
            }
            if(superprim == 1)
            {
                maxim = i;
            }
        }
    }
`
    fout << contor;
    fout << " ";
    fout << minim;
    fout << " ";
    fout << maxim;

    return 0;
}
