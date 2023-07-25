#include <iostream>
#include <vector>
#include <queue> // Para a priority queue

using namespace std;

const int INF = 1000000010; // Número muito grande para representar o infinito positivo

class Graph
{
public:
  int n;                       // Número de vértices
  vector<pair<int, int>> *adj; // Armazena um pair com o vizinho e o peso dessa aresta
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
      this->adj[v].push_back({u, w}); // Nós adicionamos a aresta de v para u
    }
  }

  int prim()
  {
    vector<int> value; // value[i] = peso mínimo de uma aresta que tem uma ponta em um vértice marcado e a outra em i
    value.resize(this->n, INF);

    priority_queue<pair<int, int>> pq;

    bool mark[this->n]; // mark[i] = true se e somente se nós já tivermos incorporado v a nossa MST

    for (int i = 0; i < this->n; i++)
      mark[i] = false;

    int mst_cost = 0;

    value[0] = 0;    // Define o valor da nossa fonte para 0
    pq.push({0, 0}); // Adiciona a fonte a nossa priority queue

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

      // Adiciona o current na nossa MST
      mark[current] = true;
      mst_cost += value[current];

      for (int j = 0; j < this->adj[current].size(); j++)
      {
        int viz = this->adj[current][j].first;
        int w = this->adj[current][j].second;

        if (value[viz] > w)
        {
          value[viz] = w;
          pq.push({-value[viz], viz});
        }
      }
    }
    return mst_cost;
  }
};

int main()
{
  int n, m;

  // Lê o número de vértices e o número de arestas
  cin >> n >> m;

  Graph graph(n);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;

    // Lê a descrição de uma aresta
    cin >> u >> v >> w;

    graph.add_edge(u, v, w);
  }

  int mst_cost = graph.prim();

  cout << "MST tem custo " << mst_cost << endl;
}
