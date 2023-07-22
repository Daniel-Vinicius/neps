#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000010; // Um número muito grande para representar o infinito positivo

class Graph
{
public:
  int n;                       // Número de vértices
  vector<pair<int, int>> *adj; // Armazena um pair com o vizinho e o peso
  bool is_undirected;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->adj = new vector<pair<int, int>>[n];
    this->is_undirected = is_undirected;
  }

  void add_edge(int u, int v, int w)
  {
    this->adj[u].push_back({v, w});
    if (this->is_undirected)
    {                                 // Se o grafo não for direcionado
      this->adj[v].push_back({u, w}); // Adicionamos a aresta de v para u
    }
  }

  // O(N² + M)
  vector<int> dijkstra(int s)
  {
    vector<int> dist; // dist[i] = menor caminho entre s e i encontrado até agora
    dist.resize(this->n);

    bool mark[this->n]; // mark[i] = true, se e somente se, nós já tivermos achado o menor caminho entre s e i

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
        if (mark[i]) // Se o i-ésimo vértice estiver marcado, ele não pode ser o vértice desejado
          continue;

        if (cur == -1 || dist[i] < dist[cur])
          cur = i;
      }

      // Marca o vértice desejado como true
      mark[cur] = true;

      for (int i = 0; i < this->adj[cur].size(); i++)
      {
        int neighbour = this->adj[cur][i].first;
        int w = this->adj[cur][i].second;

        // Atualiza a menor distância entre s e neighbour
        dist[neighbour] = min(dist[neighbour], dist[cur] + w);
      }
    }
    return dist;
  }
};

int main()
{
  int n, m, s;

  // Lê o número de vértices, o número de arestas e a fonte
  cin >> n >> m >> s;

  Graph graph(n);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;

    // Lê a descrição de uma aresta
    cin >> u >> v >> w;

    graph.add_edge(u, v, w);
  }

  vector<int> dist = graph.dijkstra(s);

  for (int i = 0; i < n; i++)
    cout << "A distância entre " << s << " e " << i << " é " << dist[i] << endl;
}
