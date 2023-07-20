#include <bits/stdc++.h>

using namespace std;

int const INF = 10000010;

class Graph
{
public:
  int n; // Número de vértices
  vector<int> *adj;
  bool is_undirected;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->adj = new vector<int>[n + 10];
    this->is_undirected = is_undirected;
  }

  void add_edge(int u, int v)
  {
    this->adj[u].push_back(v);
    if (this->is_undirected)
    {                            // Se o grafo não for direcionado
      this->adj[v].push_back(u); // Nós adicionamos a aresta de v para u
    }
  };

  int count_components()
  {
    bool *visited = new bool[this->n];
    int qtd_components = 0;

    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        this->bfs(i, visited, new int[this->n]);
        qtd_components++;
      }
    }

    delete[] visited;
    return qtd_components;
  };

  int get_shortest_path(int A, int B)
  {
    int *layer = new int[this->n];
    bool *visited = new bool[this->n];

    bfs(A, visited, layer);
    int shortest_path = layer[B];

    delete[] visited;
    delete[] layer;

    if (shortest_path != 0)
      return shortest_path;
    else
      return INF;
  }

  void bfs(int source, bool *visited, int *layer)
  {
    for (int i = 0; i < this->n; i++)
    {
      visited[i] = false;
      layer[i] = 0;
    }

    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
      int current = q.front();
      q.pop();

      for (int i = 0; i < this->adj[current].size(); i++) // Itera por todos os vizinhos do vértice atual
      {
        int neighbour = this->adj[current][i];

        if (!visited[neighbour])
        {
          q.push(neighbour);
          visited[neighbour] = true;
          layer[neighbour] = layer[current] + 1;
        }
      }
    }
  }
};

int main()
{
  int n, m;

  // Lê o número de vértices e o número de arestas respectivamente
  cin >> n >> m;

  Graph graph(n);

  for (int i = 0; i < m; i++)
  {
    int U, V;

    // Lê a descrição de uma aresta
    cin >> U >> V;

    graph.add_edge(U, V);
  }

  cout << "graph.count_components(): " << graph.count_components() << endl;
  cout << "graph.get_shortest_path(0, 2): " << graph.get_shortest_path(0, 2) << endl;
}
