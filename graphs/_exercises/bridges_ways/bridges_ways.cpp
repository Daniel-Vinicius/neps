#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAXN = 10010;

class Graph
{
public:
  int n;
  vector<pair<int, int>> *list;

  Graph(int n)
  {
    this->n = n;
    this->list = new vector<pair<int, int>>[this->n];
  };

  void add_edge(int a, int b, int weight)
  {
    this->list[a].push_back({b, weight});
    this->list[b].push_back({a, weight});
  };

  vector<int> dijsktra(int s)
  {
    vector<int> dist;
    dist.resize(this->n);

    bool mark[this->n];

    for (int i = 0; i < this->n; i++)
    {
      dist[i] = INF;
      mark[i] = false;
    }

    dist[s] = 0;

    for (int k = 0; k < this->n; k++)
    {
      int cur = -1;
      for (int i = 0; i < this->n; i++)
      {
        if (mark[i])
          continue;

        if (cur == -1 or dist[i] < dist[cur])
          cur = i;
      }

      mark[cur] = true;

      for (int i = 0; i < this->list[cur].size(); i++)
      {
        int neighbour = this->list[cur][i].first;
        int weight = this->list[cur][i].second;

        dist[neighbour] = min(dist[neighbour], dist[cur] + weight);
      }
    }

    return dist;
  };
};

int main()
{
  // n_pilares, n_pontes
  int N, M;
  cin >> N >> M;
  N += 2;
  Graph bridges = Graph(N);
  for (int i = 0; i < M; i++)
  {
    int a, b, w = 0;
    cin >> a >> b >> w;
    bridges.add_edge(a, b, w);
  }

  vector<int> dist = bridges.dijsktra(0);

  cout << dist[N - 1] << endl;

  return 0;
}
