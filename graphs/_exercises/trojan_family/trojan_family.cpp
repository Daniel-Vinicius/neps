#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
  int n;
  vector<int> *list;
  bool is_undirected;

  bool *visited = NULL;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->list = new vector<int>[n + 10];
    this->is_undirected = is_undirected;
  };

  void add_edge(int A, int B)
  {
    this->list[A].push_back(B);
    if (this->is_undirected)
    {
      this->list[B].push_back(A);
    }
  };

  int count_components()
  {
    delete this->visited;
    this->visited = new bool[this->n];

    int qtd_components = 0;

    for (int i = 1; i <= n; i++) // conta a partir de 1 pq o zero não é populado
    {
      if (!this->visited[i])
      {
        this->dfs(i);
        qtd_components++;
      }
    }

    return qtd_components;
  }

  void dfs(int current)
  {
    this->visited[current] = true;

    for (int i = 0; i < this->list[current].size(); i++)
    {
      int neighbour = this->list[current][i];

      if (!this->visited[neighbour])
        this->dfs(neighbour);
    }
  }
};

int main()
{
  // N_elementos(nodes), // M -> edges
  int N, M;
  cin >> N >> M;

  Graph familias = Graph(N);

  for (int i = 1; i <= M; i++)
  {
    int a, b = 0;
    cin >> a >> b;
    familias.add_edge(a, b);
  }

  int ans = familias.count_components();

  cout << ans << endl;

  return 0;
}
