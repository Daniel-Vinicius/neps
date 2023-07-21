#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500;

int main()
{
  int n_cities, n_roads, start_city, max_toll; // As cidades são identificadas por inteiros de 1 a n_cities
  int conjunto = 0;
  while (cin >> n_cities >> n_roads >> start_city >> max_toll && n_cities != 0 && n_roads != 0)
  {
    conjunto++;

    vector<int> citiesGraph[MAXN];
    memset(citiesGraph, 0, sizeof citiesGraph);
    for (int i = 1; i <= n_roads; i++)
    {
      int x, y;
      cin >> x >> y;
      citiesGraph[x].push_back(y);
      citiesGraph[y].push_back(x);
    }

    int layer[MAXN];
    bool visited[MAXN];

    for (int i = 0; i < n_cities; i++)
    {
      visited[i] = false;
      layer[i] = 0;
    }

    int l = max_toll;

    queue<int> q;
    q.push(start_city);
    visited[start_city] = true;

    while (!q.empty() && l >= 0)
    {
      int current = q.front();
      q.pop();
      l--;

      for (int i = 0; i < citiesGraph[current].size(); i++)
      {
        int neighbour = citiesGraph[current][i];

        if (!visited[neighbour])
        {
          q.push(neighbour);
          visited[neighbour] = true;
          layer[neighbour] = layer[current] + 1;
        }
      }
    }

    // encontre cada cidade (que não a cidade onde eles estão) que possa ser visitada por eles, dada a restrição de que o Sr. Juca deseja pagar no máximo
    // P pedágios (considerando apenas a viagem de ida).

    cout << "Teste " << conjunto << endl;

    for (int i = 1; i <= n_cities; i++)
    {
      // cout << i << " layer[i]: " << layer[i] << endl;
      if (layer[i] > 0 && layer[i] <= max_toll)
        cout << i << " ";
    }

    cout << endl;
    cout << endl;
  }

  return 0;
}
