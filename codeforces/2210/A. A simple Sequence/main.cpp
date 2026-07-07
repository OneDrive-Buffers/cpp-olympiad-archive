#include <iostream>
using namespace std;


int t;

int n;

int sols[101];

void print()
{
  for (size_t i = 0; i < n; i++) {
    std::cout << sols[i];
  }
  std::cout << endl;
}

bool valid(int k)
{
  for (size_t i = 0; i < k; i++) {
    if (sols[k] == sols[i]) {
      return false;
    }
  }
  return true;
}

bool solution(int k)
{
  return k == n-1;
}

void backtrack(int k)
{
  for (size_t i = 1; i <= n; i++) {
    sols[k]=i;
    if(valid(k))
      if(solution(k))
        print();
      else
        backtrack(k+1);
  }
}

int main (int argc, char *argv[]) {

  cin >> t;

  for (int i = 0; i < t; i++) {

    cin >> n;

    backtrack(0);

    }



  return 0;
}
