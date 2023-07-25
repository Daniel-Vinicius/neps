#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 28;

int N;
vector<int> adj[MAXN];

int dist[MAXN];
int root = 1;

void dfs(int v, int p)
{
  dist[v] = dist[p] + 1;
  if (v == root)
    dist[v] = 0;

  for (auto u : adj[v])
  {
    if (u == p)
      continue;
    dfs(u, v);
  }
}

int find_diameter()
{
  dfs(root, 0);

  int furthest = 0;
  for (int i = 1; i <= N; i++)
  {
    if (dist[i] > dist[furthest])
      furthest = i;
  }

  memset(dist, 0, sizeof(dist));
  root = furthest;
  dfs(root, 0);

  int diameter = 0;
  for (int i = 1; i <= N; i++)
    diameter = max(diameter, dist[i]);

  return diameter;
}

int main()
{

  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = find_diameter();
  cout << ans << endl;
}
