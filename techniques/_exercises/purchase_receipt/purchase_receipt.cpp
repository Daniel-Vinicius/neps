#include <bits/stdc++.h>

using namespace std;

// O termo "dp" é uma abreviação comum para "dynamic programming"
int dp[110][22][110];
int r, k;

int solve(int value, int quant, int smaller)
{
  if (dp[value][quant][smaller] != -1)
    return dp[value][quant][smaller];

  // value == 0 -> valor total foi alcançado
  // quant == 0 -> quantidade de produtos total foi alcançada
  // se ambos foram alcançados -> 1 pq é uma combinação válida
  if (value == 0)
  {
    if (quant == 0)
    {
      return dp[value][quant][smaller] = 1;
    }
    else
    {
      return dp[value][quant][smaller] = 0;
    }
  }
  else
  {
    if (quant == 0)
    {
      return dp[value][quant][smaller] = 0;
    }
  }

  dp[value][quant][smaller] = 0;

  for (int i = 1; i < min(value + 1, smaller); i++)
  {
    dp[value][quant][smaller] += solve(value - i, quant - 1, i);
  }

  return dp[value][quant][smaller];
}

int main()
{
  cin >> r >> k;

  // inicializa tudo com -1
  memset(dp, -1, sizeof(dp));

  cout << solve(r, k, r + 1) << "\n";

  return 0;
}
