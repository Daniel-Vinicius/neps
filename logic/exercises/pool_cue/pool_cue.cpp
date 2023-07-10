#include <bits/stdc++.h>

using namespace std;

// Cada vez que um cliente pede um taco de um dado comprimento, o Sr. Jorge primeiro verifica se ele tem um taco com esse comprimento no estoque.
// Se tem, ele envia o taco para o cliente. Se não tem, ele faz duas cópias do taco, envia uma para o cliente e guarda a outra no estoque.
// Assim, ele nunca tem no estoque mais do que um taco com um determinado comprimento.

// 7 minutes

int main()
{
  int n;
  cin >> n;

  set<int> estoque;
  int n_tacos_fabricados = 0;
  for (int i = 0; i < n; i++)
  {
    int taco;
    cin >> taco;

    if (estoque.find(taco) != estoque.end())
    {
      estoque.erase(taco);
      continue;
    }
    else
    {
      n_tacos_fabricados += 2;
      estoque.insert(taco);
    }
  }

  cout << n_tacos_fabricados << endl;

  return 0;
}