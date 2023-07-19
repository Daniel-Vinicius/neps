#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define endl '\n'

vector<vi> mobile;
int weight[100005];

int dfs(int v)
{
  if (mobile[v].size() == 0)
    return weight[v] = 1;

  int counter = 1;
  for (auto u : mobile[v])
    counter += dfs(u);

  return weight[v] = counter;
}

bool isBalanced(int v)
{
  if (mobile[v].size() == 0)
    return true;

  int current_weight = weight[mobile[v][0]];
  for (auto u : mobile[v])
  {
    if (current_weight != weight[u] or !isBalanced(u))
      return false;
  }

  return true;
}

int main()
{
  int n;
  cin >> n;
  mobile.resize(n + 1);
  while (n--)
  {
    int a, b;
    cin >> a >> b;
    mobile[b].push_back(a);
  }

  dfs(0);

  if (isBalanced(0))
    cout << "bem" << endl;
  else
    cout << "mal" << endl;

  return 0;
}
