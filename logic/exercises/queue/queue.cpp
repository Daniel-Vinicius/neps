#include <bits/stdc++.h>

using namespace std;

int includes(vector<int> array, int item)
{
  auto itemFound = std::find(std::begin(array), std::end(array), item);

  if (itemFound != std::end(array))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{

  int n_pessoas_fila;
  cin >> n_pessoas_fila;

  vector<int> filaOriginal;
  vector<int> pessoasSairam;
  for (int i = 0; i < n_pessoas_fila; i++)
  {
    int n;
    cin >> n;
    filaOriginal.push_back(n);
  }

  int n_pessoas_deixaram_fila;
  cin >> n_pessoas_deixaram_fila;
  for (int i = 0; i < n_pessoas_deixaram_fila; i++)
  {
    int n;
    cin >> n;
    pessoasSairam.push_back(n);
  }

  for (int i = 0; i < n_pessoas_fila; i++)
  {
    int n = filaOriginal[i];
    if (includes(pessoasSairam, n) == 0)
    {
      cout << n << " ";
    }
  }
  cout << endl;

  return 0;
}
