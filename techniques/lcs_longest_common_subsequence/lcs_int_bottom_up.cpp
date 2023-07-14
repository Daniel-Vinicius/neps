#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int main()
{
  int n, m;
  int dp[MAXN][MAXN]; // dp[i][j] = LCS entre os i primeiros números de A e os j primeiros de B
  int A[MAXN], B[MAXN];

  // Lê o tamanho das sequências A e B respectivamente
  cin >> n >> m;

  // Lê todos os inteiros da sequência A e armazena-os no vetor A
  for (int i = 0; i < n; i++)
    cin >> A[i];

  // Lê todos os inteiros da sequência B e armazena-os no vetor B
  for (int i = 0; i < m; i++)
    cin >> B[i];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // Calculando dp[i][j]
      if (A[i - 1] != B[j - 1])
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); // máximo entre horizontal e vertical vizinhas
      else
        dp[i][j] = dp[i - 1][j - 1] + 1; // diagonal superior esquerda + soma
    }
  }

  cout << "Size of the Longest Commom Subsequence: " << dp[n][m] << endl;

  vector<int> LCS; // A LCS será guardado nesse vector

  int i = n, j = m;

  while (i != 0 && j != 0)
  {
    if (A[i - 1] == B[j - 1]) // Horizontal e Vertical igual, deu match, significa que faz parte da LCS
    {
      LCS.push_back(A[i - 1]);
      i--; // Esquerda
      j--; // Sobe
      // Diagonal esquerda
    }
    else
    {
      if (dp[i - 1][j] > dp[i][j - 1]) // Decidindo qual é o melhor estado para ir
        i--;                           // se na esquerda for maior vai pra esquerda, caso contrário sobe
      else
        j--;
    }
  }

  // Revertendo a resposta
  reverse(LCS.begin(), LCS.end());

  cout << "Maior subsequência comum: ";

  for (int i = 0; i < LCS.size(); i++)
    cout << LCS[i] << " ";

  cout << endl;
}
