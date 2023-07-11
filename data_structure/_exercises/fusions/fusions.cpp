#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

int parent[MAXN], _size[MAXN];

int find(int value)
{
  // cout << "value: " << value << " parent[value]: " << parent[value] << endl;
  if (parent[value] == value)
  {
    return value;
  }
  return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
  int parent_i = find(i);
  int parent_j = find(j);

  if (parent_i == parent_j)
  {
    return;
  }
  // cout << parent[parent_i] << " " << parent[parent_j] << endl;
  // cout << parent_i << " " << parent_j << endl;

  if (_size[parent_i] >= _size[parent_j])
  {
    // j se junta ao conjunto de i
    parent[parent_j] = parent_i;
    _size[parent_i] += _size[parent_j];
  }

  if (_size[parent_j] >= _size[parent_i])
  {
    // i se junta ao conjunto de j
    parent[parent_i] = parent_j;
    _size[parent_i] += _size[parent_j];
  }

  // cout << parent[parent_i] << " " << parent[parent_j] << endl;
  // cout << parent_i << " " << parent_j << endl;
}

int main()
{

  int n_bancos;
  int n_operacoes;

  cin >> n_bancos >> n_operacoes;
  // ans: se cada consulta se refere ao mesmo banco -> S ou N

  for (int i = 0; i < n_bancos; i++)
  {
    // os bancos são o conjunto e inicialmente cada banco é seu próprio pai
    _size[i] = 1;
    parent[i] = i;
  }

  for (int i = 0; i < n_operacoes; i++)
  {
    char tipo;
    int cod1, cod2;

    cin >> tipo >> cod1 >> cod2;

    if (tipo == 'F')
    {
      merge(cod1, cod2);
    }

    if (tipo == 'C')
    {
      if (find(cod1) == find(cod2))
      {
        cout << 'S' << endl;
      }
      else
      {
        cout << 'N' << endl;
      }
    }
  }

  return 0;
}
