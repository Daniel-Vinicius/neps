#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
  int n; // Número de vértices
  vector<int> *adj;
  bool is_undirected;

  int *dist = NULL;     // dist[i] = distância entre i e a raiz atual
  bool *visited = NULL; // visited[i] = true, se e somente se nós já visitamos o i-ésimo vértice

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
      this->adj[v].push_back(u); // Nós adicionamos as arestas de v para u
    }
  }

  // O(N)
  int get_diameter()
  {
    int A = this->get_farthest(0); // Armazena o vértice mais distante de 0
    int B = this->get_farthest(A); // Armazena o vértice mais distante de A

    return this->dist[B];
  }

  int get_farthest(int node)
  {
    delete this->dist, this->visited;
    this->dist = new int[this->n];
    this->visited = new bool[this->n];

    this->dist[node] = 0;
    this->dfs(node);

    int max_dist = -1;
    int farthest_node = 0;

    for (int i = 0; i < this->n; i++)
    {
      if (max_dist < this->dist[i])
      {
        farthest_node = i;
        max_dist = this->dist[i];
      }
    }

    return farthest_node;
  }

  void dfs(int current)
  {
    this->visited[current] = true;

    for (int i = 0; i < this->adj[current].size(); i++)
    {
      int neighbour = this->adj[current][i];

      if (!this->visited[neighbour])
      {
        this->dist[neighbour] = this->dist[current] + 1;
        this->dfs(neighbour);
      }
    }
  }
};

int main()
{
  int n;
  cin >> n;

  Graph graph(n);

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    graph.add_edge(u, v);
  }

  int diameter = graph.get_diameter();

  cout << "Diameter: " << diameter << endl;
}
