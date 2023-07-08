#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;

  cin >> N;

  int sum_l[N] = {};    // armazena a soma de cada linha
  int sum_c[N] = {};    // armazena a soma de cada coluna
  int d_principal = 0;  // armazena a soma da diagonal principal
  int d_secundaria = 0; // armazena a soma da diagonal secundaria

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int num;

      cin >> num;

      sum_l[i] += num;
      sum_c[j] += num;

      if (i == j)
        d_principal += num;

      if (i + j == N - 1)
        d_secundaria += num;
    }
  }

  bool ok = true;

  if (d_principal != d_secundaria)
    ok = false;

  for (int i = 0; i < N; i++)
  {
    if (d_principal != sum_l[i] or d_principal != sum_c[i])
      ok = false;
  }

  if (ok)
    cout << d_principal << endl;
  else
    cout << -1 << endl;

  return 0;
}
