#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
const int INF = 0x3f3f3f3f;

int N, M;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

bool isValid(int i, int j)
{
  if (i >= 0 && i < N && j >= 0 && j < M && !visited[i][j] && grid[i][j] != 2)
  {
    return true;
  }
  return false;
}

void bfs(int start_i, int start_j)
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      dist[i][j] = INF;

  dist[start_i][start_j] = 0;

  queue<pair<int, int>> q;
  q.push({start_i, start_j});

  while (!q.empty())
  {
    int current_i = q.front().first, current_j = q.front().second;
    q.pop();
    visited[current_i][current_j] = true;

    for (int k = 0; k < 4; k++)
    {
      int next_i = current_i + di[k], next_j = current_j + dj[k];
      if (isValid(next_i, next_j) && dist[next_i][next_j] > dist[current_i][current_j] + 1) // a distancia do next é infinito por padrão
      {
        dist[next_i][next_j] = dist[current_i][current_j] + 1;
        q.push({next_i, next_j});
      }
    }
  }
}

int main()
{
  cin >> N >> M;

  int inicio_i, inicio_j;
  vector<pair<int, int>> salas_saida;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 3)
      {
        inicio_i = i;
        inicio_j = j;
      }
      else if (grid[i][j] == 0)
      {
        salas_saida.push_back({i, j});
      }
    }
  }

  bfs(inicio_i, inicio_j);

  int resposta = INF;
  for (auto sala : salas_saida)
  {
    // dist tem todas as distâncias da posição inicial até outra posição
    resposta = min(resposta, dist[sala.first][sala.second]);
    // pega a menor distância entre as distâncias da entrada para a saída
  }

  cout << resposta << endl;
}
