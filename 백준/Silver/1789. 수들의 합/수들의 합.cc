#include <iostream>

using namespace std;

typedef unsigned long long int ll;

int main()
{
  ll n, temp = 0, cnt = 0;
  cin >> n;
  for (int i = 1;; i++)
  {
      temp += i;
      if (temp > n)
          break;
      else
          cnt++;
  }
  cout << cnt;
}