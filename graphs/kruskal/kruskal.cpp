#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

// Struct para representar uma aresta entre dois vértices do grafo
struct Edge
{
  int u, v, w; // Aresta que liga os pontos u e v com peso w

  Edge(int u, int v, int w)
  {
    this->u = u;
    this->v = v;
    this->w = w;
  }

  bool operator<(Edge e) const { return this->w < e.w; } // Operador será usado pela função sort
};

// Implementação do DSU, reusado da aula de DSU
int parent[MAXN], _size[MAXN];

int find(int value)
{
  if (parent[value] == value)
    return value;
  return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
  i = find(i);
  j = find(j);

  if (i == j)
    return;

  if (_size[i] >= _size[j])
  {
    parent[j] = i;
    _size[i] += _size[j];
  }
  else
  {
    parent[i] = j;
    _size[j] += _size[i];
  }
}

void init_dsu(int n) // Inicializa o DSU com n vértices
{
  for (int i = 0; i < n; i++)
  {
    _size[i] = 1;
    parent[i] = i;
  }
}

class Graph
{
public:
  int n;              // Número de vértices
  vector<Edge> edges; // Trocado de lista de adjacência para lista de arestas
  bool is_undirected;

  Graph(int n, bool is_undirected = true)
  {
    this->n = n;
    this->is_undirected = is_undirected;
  }

  void add_edge(int u, int v, int w)
  {
    Edge e(u, v, w);    // Cria uma nova aresta
    edges.push_back(e); // Adiciona a nova aresta a nossa lista de arestas
  }

  // Algoritmo de Kruskal -> O(N + M ∗ log(M))
  int kruskal()
  {
    sort(this->edges.begin(), this->edges.end()); // Ordena as arestas por seu peso
    init_dsu(this->n);

    int mst_cost = 0;

    for (int i = 0; i < (int)this->edges.size(); i++) // Itera pela arestas
    {
      int u = this->edges[i].u, v = this->edges[i].v;

      if (find(u) != find(v)) // Checa se u e v estão em componentes diferentes
      {
        merge(u, v);
        mst_cost += this->edges[i].w; // Aumenta o custo da nossa MST
      }
    }

    return mst_cost;
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
    int u, v, w;

    // Lê a descrição de uma aresta
    cin >> u >> v >> w;

    graph.add_edge(u, v, w);
  }

  int mst_cost = graph.kruskal();

  cout << "MST (Minimum Spanning Tree) tem custo " << mst_cost << endl;
}
