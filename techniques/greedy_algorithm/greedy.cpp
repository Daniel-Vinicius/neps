#include <iostream>
using namespace std;

int main()
{
  int V, N;

  // Leia o número de moedas e o valor que queremos representar, respectivamente
  cin >> N >> V;

  int S[N];

  // Ler todas as moedas
  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
  }

  // Estratégia Gulosa
  int coins = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    while (V >= S[i])
    {
      coins += 1;
      V -= S[i];
    }
  }

  cout << coins << endl;
}
