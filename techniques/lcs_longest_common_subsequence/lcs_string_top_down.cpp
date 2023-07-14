// A Top-Down DP implementation
// of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1],
// Y[0..n-1]
int lcs(char *X, char *Y, int m, int n,
        vector<vector<int>> &dp)
{
  if (m == 0 || n == 0)
    return 0;
  if (X[m - 1] == Y[n - 1])
    return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

  // caso já foi calculado
  if (dp[m][n] != -1)
    return dp[m][n];

  // máximo entre horizontal e vertical vizinhas
  return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

// Driver code
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  int m = strlen(X);
  int n = strlen(Y);

  // Cria uma matriz dp com m + 1 linhas e n + 1 colunas, inicializada com -1
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  cout << "Length of LCS is " << lcs(X, Y, m, n, dp) << endl;
  // LCS is GTAB

  return 0;
}
