#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int parent[MAXN], _size[MAXN];

int find(int v)
{
  if (parent[v] == v)
    return v;
  return parent[v] = find(parent[v]);
}

void merge(int v, int u)
{
  v = find(v);
  u = find(u);

  if (v == u)
    return;

  if (_size[v] >= _size[u])
  {
    parent[u] = v;
    _size[v] += _size[u];
  }
  else
  {
    parent[v] = u;
    _size[u] += _size[v];
  }
}

void init_dsu(int n)
{
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    _size[i] = 1;
  }
}

struct Edge
{
  int a, b, w;
  Edge(int a, int b, int w)
  {
    this->a = a;
    this->b = b;
    this->w = w;
  }

  bool operator<(Edge e) const { return this->w < e.w; }
};

class Graph
{
public:
  int n;
  vector<Edge> edges;

  Graph(int n)
  {
    this->n = n;
  }

  void add_edge(int a, int b, int w)
  {
    Edge edge = Edge(a, b, w);
    this->edges.push_back(edge);
  }

  int kruskal()
  {
    int mst_cost = 0;
    init_dsu(this->n);
    sort(this->edges.begin(), this->edges.end());

    for (int i = 0; i < this->edges.size(); i++)
    {
      int a = this->edges[i].a, b = this->edges[i].b;
      if (find(a) != find(b))
      {
        merge(a, b);
        mst_cost = mst_cost + this->edges[i].w;
      }
    }

    return mst_cost;
  }
};

int main()
{
  int N, M;
  cin >> N >> M;

  Graph roads = Graph(N);

  for (int i = 0; i < M; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    roads.add_edge(a, b, w);
  }

  cout << roads.kruskal() << endl;

  return 0;
}
