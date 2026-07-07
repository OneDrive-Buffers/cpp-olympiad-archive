#include <iostream>
using namespace std;

int v[100]; // Global array


void procedure()
{
    v[0] = 42; // Modify global array
    cout << "This is a simple procedure." << endl;
    // Call the swap function
    int a = 5, b = 10;
    swap(a, b);
    cout << "After swap inside procedure: a = " << a << ", b = "
            << b << endl;

}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    arr[0] = 99; // Modify local array
}


int main()
{
    int arr[100]; // Local array, shadows global array
    int x = 5;
    int y = 10;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
