#include <bits/stdc++.h>

using namespace std;

int main()
{
  int qtdCartas, qtdTrocas;
  cin >> qtdCartas >> qtdTrocas;

  int cartas[qtdCartas][2] = {};
  pair<int, int> trocas[qtdTrocas] = {};

  // cartas para cima
  for (int i = 0; i < qtdCartas; i++)
    cin >> cartas[i][1];

  // cartas para baixo
  for (int i = 0; i < qtdCartas; i++)
    cin >> cartas[i][0];

  for (int k = 0; k < qtdTrocas; k++)
  {
    int i, j;
    cin >> i >> j;
    trocas[k] = make_pair(i - 1, j - 1);

    for (int m = trocas[k].first; m <= trocas[k].second; m++)
      swap(cartas[m][1], cartas[m][0]);
  }

  for (int i = 0; i < qtdCartas; i++)
  {
    cout << cartas[i][1] << " ";
  }
  cout << endl;

  return 0;
}
