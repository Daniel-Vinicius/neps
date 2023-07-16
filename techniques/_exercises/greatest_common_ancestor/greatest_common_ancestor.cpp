#include <bits/stdc++.h>

// tamanho a - lcs
// tamanho b - lcs
// se não tiver lcs imprime tamanho a e b normal

using namespace std;

const int MAXN = 1010;
int dp[MAXN][MAXN];
int s1[MAXN], s2[MAXN];

int main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> s1[i];

  for (int i = 0; i < M; i++)
    cin >> s2[i];

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      if (s1[i - 1] != s2[j - 1])
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }

  int lcs = dp[N][M];
  cout << N - lcs << " " << M - lcs << endl;

  return 0;
}
