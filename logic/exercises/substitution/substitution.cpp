#include <bits/stdc++.h>

using namespace std;

// 27 min

int main()
{
  vector<int> v;

  int menor = 100000;
  set<int> menorOcorrencias;
  int mO[10][10] = {};
  for (int i = 0; i < 10; i++)
  {
    int value;
    cin >> value;
    if (value < menor)
    {
      menor = value;
      mO[menor][i] = 1;
    }

    if (value == menor)
    {
      mO[menor][i] = 1;
    }

    v.push_back(value);
  }

  cout << "Menor: " << menor << endl;

  int n_ocorrencias = 0;

  for (int i = 0; i < 10; i++)
  {
    if (mO[menor][i] == 1)
    {
      n_ocorrencias++;
      menorOcorrencias.insert(i);
    }
  }

  cout << "Ocorrencias: ";
  for (int i = 0; i < n_ocorrencias; i++)
  {
    auto ptr = menorOcorrencias.begin();
    cout << *ptr << " ";
    v[*ptr] = -1;
    menorOcorrencias.erase(menorOcorrencias.begin());
  }
  cout << endl;

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  return 0;
}
