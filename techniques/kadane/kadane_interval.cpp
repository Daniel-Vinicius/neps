#include <iostream>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000010;

int n;
int v[MAXN], dp[MAXN], opt[MAXN]; // opt[i] = índice mais a esquerda menor ou igual a i, armazena começo do maior intervalo

int main()
{

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  dp[0] = v[0];
  opt[0] = 0;

  for (int i = 1; i < n; i++)
  {
    // Calculando opt[i]
    if (v[i] >= dp[i - 1] + v[i])
      opt[i] = i; // onde começa soma
    else
      opt[i] = opt[i - 1]; // mantém

    dp[i] = max(v[i], dp[i - 1] + v[i]);
  }

  int answer = -INF;
  int indexMaxDp = 0;

  for (int i = 0; i < n; i++)
  {
    if (dp[i] > answer)
    {
      answer = dp[i]; // Pegando a maior dp
      indexMaxDp = i; // Pegando o índice da maior dp
    }
  }

  cout << "Soma: " << answer << endl;
  cout << "Intervalo: [" << opt[indexMaxDp] << ", " << indexMaxDp << "]" << endl;
}
