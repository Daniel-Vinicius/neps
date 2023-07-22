#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, MAX_S = 255;

int adj[MAX_S][MAX_S];

int main()
{
  int S, C, a, b, D;
  cin >> S >> C;
  for (int i = 0; i < C; i++)
  {
    cin >> a >> b >> D;
    adj[a][b] = D;
    adj[b][a] = D;
  }

  int dist[S + 1][S + 1];
  for (int i = 1; i <= S; i++)
  {
    for (int j = 1; j <= S; j++)
    {
      if (i == j)
        dist[i][j] = 0;
      else if (adj[i][j])
        dist[i][j] = adj[i][j];
      else
        dist[i][j] = INF;
    }
  }

  // * Floyd Warshall em si
  for (int k = 1; k <= S; k++)
    for (int i = 1; i <= S; i++)
      for (int j = 1; j <= S; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int ans = INF;
  for (int i = 1; i <= S; i++)
  {
    int maxd = 0;
    for (int j = 1; j <= S; j++)
      maxd = max(maxd, dist[i][j]);

    ans = min(ans, maxd);
  }

  // distância entre a cozinha e a sala mais distante -> (cozinha foi posicionada na sala onde essa distância é mínima)
  cout << ans << endl;
  return 0;
}
