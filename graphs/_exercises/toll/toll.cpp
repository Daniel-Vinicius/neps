#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CITIES = 51;
int num_cities, num_roads, starting_city, max_tolls;
int dist[MAX_CITIES], queue[MAX_CITIES], front_queue, back_queue;
bool adj[MAX_CITIES][MAX_CITIES];

int main()
{
  int city1, city2, test_num = 1, i, front;
  while (cin >> num_cities >> num_roads >> starting_city >> max_tolls && num_cities > 0)
  {
    // Inicializa a matriz de adjacência com valores falsos (sem conexões entre cidades)
    memset(adj, false, sizeof(adj));
    while (num_roads--)
    {
      cin >> city1 >> city2;
      // Marca as conexões bidirecionais entre cidades na matriz de adjacência
      adj[city1][city2] = adj[city2][city1] = true;
    }
    // Inicializa o vetor de distâncias com -1 (valor padrão para cidades não visitadas)
    memset(dist, -1, sizeof(dist));
    // Define a distância da cidade inicial para ela mesma como 0
    dist[starting_city] = 0;
    queue[0] = starting_city;
    front_queue = 0;
    back_queue = 1;
    while (front_queue < back_queue && dist[queue[front_queue]] < max_tolls)
    {
      front = queue[front_queue];
      // Percorre todas as cidades para verificar as conexões com a cidade atual (front)
      for (i = 1; i <= num_cities; i++)
      {
        // Verifica se existe uma conexão direta (estrada) entre a cidade atual (front) e a cidade i
        // E se a cidade i ainda não foi visitada (dist[i] == -1)
        if (adj[front][i] && dist[i] == -1)
        {
          // Se atende aos critérios, adiciona a cidade i à fila para visitar posteriormente
          // e atualiza a distância para a cidade i a partir da cidade inicial (front)
          queue[back_queue++] = i;
          dist[i] = dist[front] + 1;
        }
      }
      // Move para a próxima cidade na fila
      front_queue++;
    }
    // Imprime o número do teste atual
    cout << "Teste " << test_num++ << endl;
    // Imprime todas as cidades (exceto a cidade inicial) que podem ser visitadas,
    // respeitando o limite de pedágios estabelecido pelo Sr. Juca (max_tolls)
    for (i = 1; i <= num_cities; i++)
    {
      if (i != starting_city && dist[i] != -1)
      {
        cout << i << " ";
      }
    }
    cout << endl
         << endl;
  }

  return 0;
}
