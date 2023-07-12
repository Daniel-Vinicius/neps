#include <bits/stdc++.h>

using namespace std;

// Geralmente quando for problema de dp, já testa o código no extremo antes de enviar
const int MAXN = 30 + 1;

int dp[MAXN];

// 12 minutes

int solveFiboSequence(int i)
{
  if (dp[i] != -1)
    return dp[i];

  if (i == 0 or i == 1)
    return 1;

  dp[i] = solveFiboSequence(i - 1) + solveFiboSequence(i - 2);

  return dp[i];
}

int main()
{
  int n;
  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << solveFiboSequence(n) << endl;

  return 0;
}
