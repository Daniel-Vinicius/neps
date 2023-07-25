#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
  int n; // Número de vértices
  vector<int> *adj;
  bool is_undirected;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->adj = new vector<int>[n];
    this->is_undirected = is_undirected;
  }

  void add_edge(int u, int v)
  {
    this->adj[u].push_back(v);
    if (this->is_undirected)
    {                            // Se o grafo não for direcionado
      this->adj[v].push_back(u); // Adicionamos uma aresta de v para u
    }
  }

  // Kahn Algorithm -> O(N + M)
  vector<int> topological_sort()
  {
    int in_degree[this->n];

    for (int i = 0; i < this->n; i++) // Inicializamos os vértices
      in_degree[i] = 0;

    for (int i = 0; i < this->n; i++)
      for (int j = 0; j < (int)this->adj[i].size(); j++)
        in_degree[this->adj[i][j]]++;

    queue<int> q;

    for (int i = 0; i < this->n; i++)
      if (in_degree[i] == 0)
        q.push(i);

    vector<int> sorting;

    while (!q.empty())
    {
      int current = q.front(); // Escolhe um vértice com grau de entrada igual a 0
      q.pop();

      sorting.push_back(current);

      for (int i = 0; i < (int)this->adj[current].size(); i++) // Remove current de G
      {
        int neighbor = this->adj[current][i];

        in_degree[neighbor]--;

        if (in_degree[neighbor] == 0) // Checa se o grau de entrada do vizinho se tornou igual a 0
          q.push(neighbor);
      }
    }

    return sorting;
  }
};

int main()
{
  int n, m;

  cin >> n >> m;

  Graph graph(n, false);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph.add_edge(u, v);
  }

  vector<int> sorting = graph.topological_sort();

  cout << "Ordenação topológica: ";

  for (int i = 0; i < (int)sorting.size(); i++)
    cout << sorting[i] << " ";
}
