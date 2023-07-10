#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> cartelas; // cartelas[n]: cartelas contendo numero n, em ordem
vector<int> counter;          // counter[c]: quantos números ja marcados na cartela c
vector<int> vencedores;       // cartelas vencedoras, em ordem

int main()
{
  int n_cartelas, tamanho_cartela, U;
  cin >> n_cartelas >> tamanho_cartela >> U;

  counter = vector<int>(n_cartelas + 1, 0);
  cartelas = vector<vector<int>>(U + 1);

  for (int c = 1; c <= n_cartelas; c++)
  {
    for (int j = 1; j <= tamanho_cartela; j++)
    {
      int n;
      cin >> n;
      cartelas[n].push_back(c);
    }
  }

  for (int i = 1; i <= U && vencedores.empty(); i++)
  {
    int n;
    cin >> n;
    for (int cartela : cartelas[n])
    {
      if (++counter[cartela] == tamanho_cartela)
      {
        vencedores.push_back(cartela);
      }
    }
  }

  for (int c : vencedores)
  {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}
