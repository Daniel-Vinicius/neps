#include <bits/stdc++.h>

using namespace std;

int N;
int test_set = 0;

int main()
{

  while (cin >> N && N != 0)
  {
    test_set++;

    map<string, int> namesToInt;
    map<int, string> intToNames;
    vector<int> adj[N];

    for (int i = 0; i < N; i++)
    {
      string name;
      cin >> name;
      namesToInt.insert({name, i});
      intToNames.insert({i, name});
    }

    for (int i = 0; i < N; i++)
    {
      string from;
      int qtd = 0;
      cin >> from >> qtd;
      for (int i = 0; i < qtd; i++)
      {
        string required_name;
        cin >> required_name;
        adj[namesToInt.at(from)].push_back(namesToInt.at(required_name));
      }
    }

    int in_degree[N];

    for (int i = 0; i < N; i++)
      in_degree[i] = 0;

    for (int i = 0; i < N; i++)
      for (int j = 0; j < adj[i].size(); j++)
        in_degree[adj[i][j]]++;

    queue<int> q;

    for (int i = 0; i < N; i++)
      if (in_degree[i] == 0)
        q.push(i);

    vector<string> ans;

    if (q.empty())
      ans.push_back("impossivel");

    while (!q.empty()) // Topological Sort -> O(N + M)
    {
      int current = q.front();
      q.pop();

      ans.push_back(intToNames.at(current));

      for (int i = 0; i < adj[current].size(); i++)
      {
        int neighbour = adj[current][i];
        in_degree[neighbour]--;

        if (in_degree[neighbour] == 0)
          q.push(neighbour);
      }
    }

    cout << "Teste " << test_set << endl;

    for (int i = ans.size() - 1; i >= 0; i--)
      cout << ans[i] << " ";

    cout << endl
         << endl;
  }

  return 0;
}
