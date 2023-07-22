#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;

const int mxn = 1e3 + 5, inf = 1e7 + 100;

int n, m, dist[mxn];
vector<ii> graph[mxn];
bool visited[mxn];

void dijkstra()
{
  for (int i = 0; i < n; i++)
  {
    dist[i] = inf;
    visited[i] = 0;
  }

  dist[0] = 0;

  priority_queue<ii, vector<ii>, greater<ii>> pq;

  pq.push({0, 0});

  while (!pq.empty())
  {
    int i = pq.top().second;
    pq.pop();

    if (visited[i])
      continue;

    visited[i] = true;

    for (ii neighbour : graph[i])
    {
      int node = neighbour.second;
      int weight = neighbour.first;

      if (dist[node] > dist[i] + weight)
      {
        dist[node] = dist[i] + weight;
        pq.push({dist[node], node});
      }
    }
  }
}

int main(void)
{
  cin >> n >> m;
  // adicionamos 2 para contar o pilar final e inicial
  n += 2;

  for (int i = 0; i < m; i++)
  {
    int x, y, weight;
    cin >> x >> y >> weight;
    graph[x].pb({weight, y});
    graph[y].pb({weight, x});
  }

  dijkstra();

  // retorno a menor distância da última ponte
  cout << dist[n - 1] << endl;
  return 0;
}
