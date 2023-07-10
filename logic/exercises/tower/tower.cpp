#include <bits/stdc++.h>

using namespace std;

// Ele definiu o peso de uma posição (i,j) como sendo a soma de todos os números que estejam na linha i com todos os números da coluna
// j, mas sem somar o número que está exatamente na posição (i,j). Quer dizer, se uma torre estiver na posição
// (i,j), o peso da posição é a soma de todas as posições que essa torre poderia atacar.

// Seu programa deve produzir uma única linha, contendo um único inteiro, o peso máximo entre todas as posições do tabuleiro.

// 20 minutes

int main()
{

  int dimensions;
  cin >> dimensions;

  int board[dimensions][dimensions];
  for (int i = 0; i < dimensions; i++)
  {
    for (int j = 0; j < dimensions; j++)
    {
      int n = 0;
      cin >> n;
      board[i][j] = n;
      // cout << n << " ";
    }
    // cout << endl;
  }

  int sumOfLines[dimensions];
  int sumOfColumns[dimensions];
  for (int i = 0; i < dimensions; i++)
  {
    int sumLine = 0;
    int sumColumn = 0;
    for (int j = 0; j < dimensions; j++)
    {
      sumLine += board[i][j];
      sumColumn += board[j][i];
    }
    sumOfLines[i] = sumLine;
    sumOfColumns[i] = sumColumn;
    // cout << sumOfLines[i] << endl;
    // cout << sumOfColumns[i] << endl;
  }

  int maxWeight = 0;
  for (int i = 0; i < dimensions; i++)
  {
    for (int j = 0; j < dimensions; j++)
    {
      int n = board[i][j];
      int weight = (sumOfLines[i] - n) + (sumOfColumns[j] - n);

      if (weight > maxWeight)
      {
        maxWeight = weight;
      }
    }
  }

  cout << maxWeight << endl;

  return 0;
}
