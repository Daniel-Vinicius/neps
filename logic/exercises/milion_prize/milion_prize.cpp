#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n_dias;
  cin >> n_dias;

  int acessos = 0;

  for (int i = 0; i < n_dias; i++)
  {
    int acessoDia = 0;
    cin >> acessoDia;
    acessos += acessoDia;

    if (acessos >= 1000000)
    {
      cout << (i + 1) << endl;
      return 0;
    }
  }

  return 0;
}
