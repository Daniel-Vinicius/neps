#include <iostream>
using namespace std;

const int MAXN = 110;
const int INF = 1000000010;

// O(n³) -> Grafos direcionados com pesos (pode ter negativo, não pode ter ciclo negativo)
int main()
{
  int n, m;
  int dp[MAXN][MAXN][MAXN]; // dp[i][j][k] = menor caminho do vértice i para o vértice j de modo a que só possamos utilizar os vértices 1,2,...,k como vértices intermédios

  // Lê a quantidade de vértices e a quantidade de arestas
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        dp[i][j][0] = 0; // Primeiro caso base -> "O caminho mínimo de 1 para 1 é 0"
      else
        dp[i][j][0] = INF; // Terceiro caso base -> "Não há nenhum caminho de 3 para 1"
    }
  }

  for (int i = 0; i < m; i++)
  {
    int U, V, W;

    // Lê a descrição de uma aresta
    cin >> U >> V >> W;

    dp[U][V][0] = W; // Segundo caso base -> "O caminho mínimo de 1 para 2 é 1" (Própria aresta)
  }

  // That is, if the direct distance from the source to the destination is greater than the path through the vertex k, then the cell is filled with A[i][k] + A[k][j].
  // https://www.programiz.com/dsa/floyd-warshall-algorithm
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dp[i][j][n] == INF)
        cout << "Não há nenhum caminho de " << i << " para " << j << endl;
      else
        cout << "O caminho mínimo de " << i << " para " << j << " é " << dp[i][j][n] << endl;
    }
  }
}
