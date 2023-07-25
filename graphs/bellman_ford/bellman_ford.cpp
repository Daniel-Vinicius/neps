#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000010;

// Struct para representar uma aresta entre dois vértices em um grafo
struct Edge
{
  int u, v, w; // Aresta de u para v com peso w

  Edge(int u, int v, int w)
  {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

class Graph
{
public:
  int n;              // Número de vértices
  vector<Edge> edges; // Troca de lista de adjacência para lista de aresta
  bool is_undirected;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->is_undirected = is_undirected;
  }

  void add_edge(int u, int v, int w)
  {
    Edge e(u, v, w);    // Cria uma nova aresta
    edges.push_back(e); // Adiciona a nova aresta a nossa lista
  }

  // Algoritmo de Bellman-Ford -> O(M * N)
  vector<int> bellman_ford(int s)
  {
    vector<int> dist(this->n, INF);
    dist[s] = 0;

    for (int step = 0; step < n - 1; step++) // Simula os n - 1 passos
    {
      for (int i = 0; i < edges.size(); i++) // Itera por todas as arestas
      {
        int u = edges[i].u, v = edges[i].v;

        if (dist[u] != INF)                             // Checa se s alcança u
          dist[v] = min(dist[v], dist[u] + edges[i].w); // Relaxa a aresta atual
      }
    }

    for (int i = 0; i < edges.size(); i++) // detecta ciclos negativos
    {
      int u = edges[i].u, v = edges[i].v;

      if (dist[v] > dist[u] + edges[i].w)
        return vector<int>();
    }

    return dist;
  }
};

int main()
{
  int n, m, s;

  // Lê o número de vértices, o número de arestas e a fonte
  cin >> n >> m >> s;

  Graph graph(n, false);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;

    // Lê a descrição de uma aresta
    cin >> u >> v >> w;

    graph.add_edge(u, v, w);
  }

  vector<int> dist = graph.bellman_ford(s);

  if (dist.empty())
    cout << "O grafo tem um ciclo de peso negativo" << endl;
  else
  {
    for (int i = 0; i < n; i++)
      cout << "A distância entre " << s << " e " << i << " é " << dist[i] << endl;
  }
}
