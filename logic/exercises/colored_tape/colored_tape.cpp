#include <bits/stdc++.h>

using namespace std;

// O quadrado Q, então, deve ser colorido com o tom cuja numeração corresponde à distância determinada (quadrado mais próximo de tom 0)
// Se a distância for maior ou igual a 9, o quadrado deve ser colorido com o tom 9

// Seu programa deve colorir e imprimir a fita quadriculada dada na entrada.

// 25 minutes

int main()
{

  int nSquaresTape;
  cin >> nSquaresTape;

  vector<int> tape;
  vector<int> zeroToneIndexes;
  for (int i = 0; i < nSquaresTape; i++)
  {
    int square;
    cin >> square;
    tape.push_back(square);

    if (square == 0)
    {
      zeroToneIndexes.push_back(i);
    }
  }

  for (int i = 0; i < nSquaresTape; i++)
  {
    if (tape[i] == 0)
    {
      continue;
    }
    int smallerDistance = 10000;
    for (int j = 0; j < zeroToneIndexes.size(); j++)
    {
      int distance = abs(i - zeroToneIndexes[j]);
      if (distance < smallerDistance)
      {
        smallerDistance = distance;
      };
      // cout << "i: " << i << " zeroToneIndexes[j]: " << zeroToneIndexes[j] << " distance: " << distance << endl;
    }

    if (smallerDistance >= 9)
    {
      tape[i] = 9;
    }
    else
    {
      tape[i] = smallerDistance;
    }
  }

  for (int i = 0; i < nSquaresTape; i++)
  {
    cout << tape[i] << " ";
  }
  cout << endl;

  return 0;
}
