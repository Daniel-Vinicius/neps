#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> adj[N];

  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  };

  int in_degree[N];
  for (int i = 0; i < N; i++)
    in_degree[i] = 0;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < adj[i].size(); j++)
      in_degree[adj[i][j]]++;

  // as tarefas com menor índice tem prioridade
  priority_queue<int, vector<int>, greater<int>> q;

  for (int i = 0; i < N; i++)
    if (in_degree[i] == 0)
      q.push(i);

  vector<int> sorting;

  while (!q.empty())
  {
    int current = q.top();
    q.pop();
    sorting.push_back(current);

    for (int i = 0; i < adj[current].size(); i++)
    {
      int neighbour = adj[current][i];
      in_degree[neighbour]--;

      if (in_degree[neighbour] == 0)
        q.push(neighbour);
    }
  }

  if (sorting.size() != N)
  {
    cout << "*" << endl;
    return 0;
  }

  for (int i = 0; i < sorting.size(); i++)
    cout << sorting[i] << endl;

  return 0;
}
