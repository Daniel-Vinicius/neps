#include <bits/stdc++.h>

using namespace std;
int i = 0;

int Ia, Ib;
int Fa, Fb;

int inverte(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void button1()
{
  i++;
  Ia = inverte(Ia);
}

void button2()
{
  i++;
  Ib = inverte(Ib);
  Ia = inverte(Ia);
}

int main()
{
  cin >> Ia >> Ib >> Fa >> Fb;

  if (Ib == Fb)
  {
    if (Ia == Fa)
    {
      cout << 0 << endl;
      return 0;
    }

    button1();
    cout << 1 << endl;
    return 0;
  }

  button2();
  if (Ia != Fa)
  {
    button1();
  }

  cout << i << endl;

  return 0;
}
