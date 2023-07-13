#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll dp[1010][1010];
int n, k;

// Bottom-up
// Para resolver o exercício vamos utilizar um DP tal que,
// dp[i][j] representa o número de sequência de tamanho i, que terminam com exatamente
// j 1′ s consecutivos e satisfazem a restrição do problema(ou seja, j < K).

int main()
{
  cin >> n >> k;

  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < min(i + 1, k); j++)
    {
      dp[i + 1][0] += dp[i][j];
      dp[i + 1][0] = dp[i + 1][0] % MOD;
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + 1] = dp[i + 1][j + 1] % MOD;
    }
  }

  int ans = 0;
  for (int i = 0; i < k; i++)
    ans = (ans + dp[n][i]) % MOD;

  cout << ans << "\n";

  return 0;
}
