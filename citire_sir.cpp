#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    return number_of_divisors(n) == 2;
}

int number_of_divisors(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (is_divisible(n, i))
        {
        count++;
        }
    }
    return count;
}

int is_divisible(int a, int b)
{
  return (a % b == 0);
}

int main()
{

    // fie vectorul [1,4,6,8,9,11,15,18,21,25,30]
    // sa se introduca numerul 16 in vector astfel incat vectorul sa ramana sortat
    int arr[30] = {1, 4, 6, 8, 9, 11, 15, 18, 21, 25, 30};
    int n = 11; // numarul de elemente din vector
    int num = 16; // numarul de introdus
    int pos = 0; // pozitia unde se va introduce numarul
    for( int i = 0; i < n; i++)
    {
        if (num < arr[i])
        {
            pos = i;
            break;
        }
    }

    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    n++; // incrementam numarul de elemente din vector
    // afisam vectorul
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


}