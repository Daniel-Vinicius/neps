#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
  int n; // Número de vértices
  vector<int> *adj;
  bool is_undirected;

  int *dist = NULL;
  int *parent = NULL; // parent[i] = pai do i-ésimo vértice
  bool *visited = NULL;

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

  vector<int> get_centers()
  {
    int A = this->get_farthest(0);
    int B = this->get_farthest(A);

    int diameter = this->dist[B];

    vector<int> path; // Esse vector irá armazenar o caminho entre A e B

    while (A != B)
    {
      path.push_back(B);
      B = this->parent[B];
    }

    path.push_back(A); // Nós precisamos adicionar o último vértice ao nosso caminho

    vector<int> centers; // Esse vector irá armazenar os nossos centros

    if (diameter % 2 == 0)
      centers.push_back(path[diameter / 2]);
    else
    {
      centers.push_back(path[diameter / 2]);
      centers.push_back(path[(diameter + 1) / 2]);
    }

    return centers;
  }

  int get_farthest(int node)
  {
    delete this->dist;
    delete this->parent;
    delete this->visited;

    this->dist = new int[this->n];
    this->parent = new int[this->n];
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
        this->parent[neighbour] = current; // Atualiza o pai de neighbour para current
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

  vector<int> centers = graph.get_centers();

  cout << "Número de centros: " << centers.size() << endl;
  cout << "Centros: ";

  for (int i = 0; i < (int)centers.size(); i++)
    cout << centers[i] << " ";

  cout << endl;
}
