#include <bits/stdc++.h>

using namespace std;

// recebe pedido -> verifica se tem
// tem -> envia
// não tem -> cria 2, envia 1 e guarda outra

int main()
{
  int n_consultas_estoque;
  cin >> n_consultas_estoque;
  set<int> estoque;
  int n_tacos_fabricados = 0;

  for (int i = 0; i < n_consultas_estoque; i++)
  {
    int comprimentoTaco;
    cin >> comprimentoTaco;

    if (estoque.find(comprimentoTaco) != estoque.end())
    {
      estoque.erase(comprimentoTaco);
      continue;
    }

    n_tacos_fabricados += 2;
    estoque.insert(comprimentoTaco);
  }

  cout << n_tacos_fabricados << endl;

  return 0;
}
