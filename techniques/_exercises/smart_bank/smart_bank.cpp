#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_S = 5000;

int V[] = {2, 5, 10, 20, 50, 100};
int N[6];
int S;

int memo[6][MAX_S + 1];

int dp(int i, int s) // retorna quantidade distinta de saques possíveis a partir de `i` cédula e usando `s` como valor a sacar
{
  // já foram todas as células
  if (i == 6)
  {
    if (s == 0) // deu saque exato
      return 1;
    else
      return 0; // não deu saque
  }

  if (memo[i][s] != -1)
    return memo[i][s];

  memo[i][s] = 0;

  for (int k = 0; k <= N[i]; k++)
  {
    if (s - k * V[i] >= 0)
    {
      memo[i][s] += dp(i + 1, s - k * V[i]); // soma o valor retornado
    }
  }

  return memo[i][s];
}

// O(N*S) -> N é 6 nesse caso(número de cédulas * valor que se deseja sacar)
int main()
{

  cin >> S;
  for (int i = 0; i < 6; i++)
  {
    cin >> N[i];
  }

  memset(memo, -1, sizeof memo);

  // busca/calcula a partir de V[0], da primeira cédula, no caso a de 2 reais
  cout << dp(0, S) << endl;
  // cout << memo[0][S] << endl;

  // for (int i = 0; i < 6; i++)
  // {
  //   for (int j = 0; j < 22; j++)
  //   {
  //     cout << memo[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
