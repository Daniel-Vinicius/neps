#include <bits/stdc++.h>

using namespace std;

// O segredo vai depender de quantas vezes cada um dos dez inteiros entre 0 e 9 vai aparecer dentro do controle.
// Por exemplo, suponha que o dono deslize o controle da posição inicial 1 até a posição 9, depois para a posição 4, depois para a posição 11 e por fim até a posição 13.
// Veja que o inteiro 1, por exemplo, vai aparecer seis vezes dentro do controle; e o inteiro 9 vai aparecer quatro vezes.
// Dada a sequência de inteiros na barra e a sequência de posições entre as quais o dono desliza o controle, começando da posição inicial 1,
// seu programa deve contar quantas vezes cada inteiro, entre 0 e 9, vai aparecer dentro do controle.

int prefixSum[10][100010];
int total[10];

int main()
{
  int sequenceSize, secretSize;
  cin >> sequenceSize >> secretSize;

  for (int i = 1; i <= sequenceSize; i++)
  {
    int x;
    cin >> x;

    prefixSum[x][i]++;

    for (int j = 0; j < 10; j++)
    {
      prefixSum[j][i] += prefixSum[j][i - 1];
      // cout << "j: " << j << " i: " << i << " i - 1: " << i - 1 << endl;
      // cout << prefixSum[j][i] << " " << prefixSum[j][i - 1] << endl;
    }

    // cout << endl;
    // cout << "x: " << x << " i: " << i << endl;
    // cout << prefixSum[x][i] << endl;
  }

  int lastPosition = 0;
  for (int i = 0; i < secretSize; i++)
  {
    int currentPosition;
    cin >> currentPosition;

    for (int j = 0; j <= 9; j++)
    {
      if (currentPosition > lastPosition)
        total[j] += prefixSum[j][currentPosition] - prefixSum[j][lastPosition];
      else
        total[j] += prefixSum[j][lastPosition - 1] - prefixSum[j][currentPosition - 1];
    }

    lastPosition = currentPosition;
  }

  for (int i = 0; i < 10; i++)
    cout << total[i] << " ";
  cout << endl;

  return 0;
}
