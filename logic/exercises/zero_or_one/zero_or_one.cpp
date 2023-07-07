#include <bits/stdc++.h>

using namespace std;

int main()
{

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && a == c)
  {
    cout << '*' << endl;
    return 0;
  }

  if (a != b && a != c)
  {
    cout << 'A' << endl;
    return 0;
  }

  if (b != a && b != c)
  {
    cout << 'B' << endl;
    return 0;
  }

  if (c != b && c != a)
  {
    cout << 'C' << endl;
    return 0;
  }

  return 0;
}
