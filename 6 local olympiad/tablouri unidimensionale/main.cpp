#include <iostream>

using namespace std;

int arr[255];

int fr[1024];

int main()
{
    int n;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }



    for(int i=0; i<n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
