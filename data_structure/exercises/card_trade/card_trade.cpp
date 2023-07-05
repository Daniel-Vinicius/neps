#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n_cartas_A;
  int n_cartas_B;
  int counter[100005][2] = {};

  cin >> n_cartas_A >> n_cartas_B;

  for (int i = 0; i < n_cartas_A; i++)
  {
    int carta;
    cin >> carta;
    // marco que alice tem a carta
    counter[carta][0] = 1;
  }

  for (int i = 0; i < n_cartas_B; i++)
  {
    int carta;
    cin >> carta;
    // marco que beatriz tem a carta
    counter[carta][1] = 1;
  }

  int counterAlice = 0, counterBeatriz = 0;

  for (int i = 1; i <= 100000; i++)
  {
    if (counter[i][0] == 1 && !counter[i][1])
      counterAlice++;
    if (counter[i][1] == 1 && !counter[i][0])
      counterBeatriz++;
  }

  cout << min(counterAlice, counterBeatriz) << endl;

  return 0;
}
