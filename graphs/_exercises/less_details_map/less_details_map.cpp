#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct Edge
{
  int v, u, w;

  Edge(int v, int u, int w)
  {
    this->v = v;
    this->u = u;
    this->w = w;
  };

  bool operator<(Edge e) const { return this->w < e.w; }
};

int parent[MAXN], _size[MAXN];

int find(int value)
{
  if (parent[value] == value)
    return value;
  return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
  i = find(i);
  j = find(j);

  if (i == j)
    return;

  if (_size[i] >= _size[j])
  {
    parent[j] = i;
    _size[i] += _size[j];
  }
  else
  {
    parent[i] = j;
    _size[j] += _size[i];
  }
}

void init_dsu(int n)
{
  for (int i = 0; i < n; i++)
  {
    _size[i] = 1;
    parent[i] = i;
  }
}

class Graph
{
public:
  int n;
  vector<Edge> edges;

  Graph(int n)
  {
    this->n = n;
  };

  void add_edge(int v, int u, int w)
  {
    Edge edge = Edge(v, u, w);
    edges.push_back(edge);
  };

  int kruskal()
  {
    int mst_cost = 0;
    init_dsu(this->edges.size() + 1);
    sort(edges.begin(), edges.end());

    for (int i = 0; i < this->edges.size(); i++)
    {
      int v = edges[i].v, u = edges[i].u;
      if (find(v) != find(u))
      {
        merge(u, v);
        mst_cost = mst_cost + edges[i].w;
      }
    }

    return mst_cost;
  }
};

// kruskal
int main()
{
  int N, M;
  cin >> N >> M;

  Graph map = Graph(N);

  for (int i = 0; i < M; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    map.add_edge(u, v, w);
  }

  cout << map.kruskal() << endl;

  return 0;
}
