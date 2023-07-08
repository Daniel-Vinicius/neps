#include <bits/stdc++.h>

using namespace std;

// soma do quadrado mágico ou -1 caso o quadrado não seja mágico.
// as linhas, colunas e diagonais têm a mesma soma.

int main()
{
  int dimensions = 0;
  cin >> dimensions;

  int somaLinha[dimensions] = {};
  int somaColuna[dimensions] = {};
  int somaDiagonalPrincipal = 0;
  int somaDiagonalSecundaria = 0;

  for (int i = 0; i < dimensions; i++)
  {
    for (int j = 0; j < dimensions; j++)
    {
      int n = 0;
      cin >> n;

      somaLinha[i] += n;
      somaColuna[j] += n;

      if (i == j)
        somaDiagonalPrincipal += n;
      if (i + j == dimensions - 1)
        somaDiagonalSecundaria += n;
    }
  }

  bool ok = true;

  if (somaDiagonalPrincipal != somaDiagonalSecundaria)
    ok = false;

  for (int i = 0; i < dimensions; i++)
  {
    if (somaDiagonalPrincipal != somaLinha[i] or somaDiagonalPrincipal != somaColuna[i])
      ok = false;
  }

  if (ok)
  {
    cout << somaDiagonalPrincipal << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}
