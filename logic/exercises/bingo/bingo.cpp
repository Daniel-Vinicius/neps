#include <bits/stdc++.h>

using namespace std;

vector<int> counter;    // counter[c]: quantos números ja marcados na cartela c
vector<int> vencedores; // cartelas vencedoras, em ordem

int main()
{
  int n_cartelas;
  int tamanho_cartela;
  int U;
  cin >> n_cartelas >> tamanho_cartela >> U;

  vector<vector<int>> cartelas;
  cartelas = vector<vector<int>>(n_cartelas);
  counter = vector<int>(n_cartelas, 0);

  for (int i = 0; i < n_cartelas; i++)
  {
    for (int j = 0; j < tamanho_cartela; j++)
    {
      int n;
      cin >> n;
      cartelas[i].push_back(n);
    }
  }

  for (int i = 1; i <= U && vencedores.empty(); i++)
  {
    int n;
    cin >> n;
    for (int j = 0; j < n_cartelas; j++)
    {
      for (int k = 0; k < tamanho_cartela; k++)
      {
        if (cartelas[j][k] == n)
        {
          if (++counter[j] == tamanho_cartela)
          {
            vencedores.push_back(j);
          }
          break;
        }
      }
    }
  }

  for (int c : vencedores)
  {
    cout << c + 1 << " ";
  }
  cout << endl;

  return 0;
}
