#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n_pessoas_fila;
  cin >> n_pessoas_fila;

  vector<int> filaOriginal;
  set<int> sairam;
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
    sairam.insert(n);
  }

  for (int i = 0; i < n_pessoas_fila; i++)
  {
    int n = filaOriginal[i];
    if (sairam.find(n) == sairam.end())
    {
      cout << n << " ";
    }
  }
  cout << endl;

  return 0;
}
