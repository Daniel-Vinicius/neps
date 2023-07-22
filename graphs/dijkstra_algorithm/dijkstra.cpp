#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000010;

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

  // O(M * log(M))
  vector<int> dijkstra(int s)
  {
    vector<int> dist; // dist[i] = menor caminho entre s e i encontrado até agora
    dist.resize(this->n);

    priority_queue<pair<int, int>> pq;

    bool mark[this->n]; // mark[i] = true, se e somente se, nós já tivermos achado o menor caminho entre s e i

    for (int i = 0; i < this->n; i++)
    {
      dist[i] = INF;
      mark[i] = false;
    }

    dist[s] = 0;
    pq.push({0, s});

    for (int k = 0; k < this->n; k++)
    {
      int current;

      while (true) // Acha o vértice desejado
      {
        current = pq.top().second; // Pega o topo da nossa priority queue
        pq.pop();                  // Remove o topo da nossa priority queue

        if (!mark[current]) // Checa se o vértice atual não está marcado
          break;
      }

      mark[current] = true;

      for (int j = 0; j < this->adj[current].size(); j++)
      {
        int neighbour = this->adj[current][j].first;
        int w = this->adj[current][j].second;

        if (dist[neighbour] > dist[current] + w)
        {
          dist[neighbour] = dist[current] + w;
          pq.push({-dist[neighbour], neighbour}); // coloca o oposto para manter ordem não crescente
        }
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
