#include <bits/stdc++.h>

using namespace std;

int main()
{

  int a, b, c;
  cin >> a >> b >> c;

  if ((c > b && b > a) || c > (a + b))
  {
    cout << 1 << endl;
    return 0;
  }

  if ((c > b && b <= a) || c == b && b > a)
  {
    cout << 2 << endl;
    return 0;
  }

  if (c == b && b == a)
  {
    cout << 3 << endl;
    return 0;
  }

  return 0;
}
