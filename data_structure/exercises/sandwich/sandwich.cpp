#include <bits/stdc++.h>

using namespace std;

// pegar uma sequência contínua de pedaços, ou pegar pedaços das extremidades.

int main()
{
  int n_pedacos;
  int qtd_sanduiche;

  cin >> n_pedacos >> qtd_sanduiche;

  map<int, int> map_pedacos;
  for (int i = 0; i < n_pedacos; i++)
  {
    int j;
    cin >> j;
    map_pedacos.insert({i, j});
  }

  int ans = 0;
  int counter = 0;
  auto iterator = map_pedacos.begin();
  while (counter != qtd_sanduiche)
  {
    if (counter > qtd_sanduiche)
    {
      break;
    }

    counter += iterator->second;
    iterator++;

    if (counter == qtd_sanduiche)
    {
      ans++;
    }
  }

  int counter2 = 0;
  auto iterator2 = map_pedacos.end();
  iterator--;

  while (counter2 != qtd_sanduiche)
  {
    if (counter2 > qtd_sanduiche)
    {
      break;
    }

    counter2 += iterator2->second;
    iterator2--;

    if (counter2 == qtd_sanduiche)
    {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
