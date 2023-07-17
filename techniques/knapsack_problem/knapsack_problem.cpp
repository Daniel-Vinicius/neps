#include <bits/stdc++.h>

using namespace std;

void knapsack(vector<int> W, vector<int> V, int capacity)
{
  int N = W.size();

  int dp[N + 1][capacity + 1] = {};
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++)
  {
    int w = W[i - 1];
    int v = V[i - 1];

    for (int sz = 1; sz <= capacity; sz++)
    {
      dp[i][sz] = dp[i - 1][sz]; // Consider not picking this element

      // Consider including the current element and see if this would be more profitable
      if (sz >= w && dp[i - 1][sz - w] + v > dp[i][sz])
      {
        dp[i][sz] = dp[i - 1][sz - w] + v;
      }
    }
  }

  int size = capacity;
  vector<pair<int, int>> itemsSelected;
  for (int i = N; i > 0; i--)
  {
    // If it's different so ths element was selected
    if (dp[i][size] != dp[i - 1][size])
    {
      int indexSelected = i - 1;
      itemsSelected.push_back(make_pair(W[indexSelected], V[indexSelected]));
      size -= W[indexSelected];
    }
  }
  reverse(itemsSelected.begin(), itemsSelected.end());
  cout << "Items Selected: " << endl;
  for (int i = 0; i < itemsSelected.size(); i++)
  {
    pair<int, int> item = itemsSelected[i];
    cout << "Item " << i + 1 << " -->"
         << " weight: " << item.first << " value: " << item.second << endl;
  }

  cout << endl
       << "Final weight and value" << endl;
  cout << capacity - size << " " << dp[N][capacity] << endl;

  // return dp[N][capacity]; // 8
}

int main()
{
  int N, S;
  cin >> N >> S;

  vector<int> W(N);
  vector<int> V(N);

  for (int i = 0; i < N; i++)
  {
    int weight, value;
    cin >> weight >> value;
    W.push_back(weight);
    V.push_back(value);
  }

  knapsack(W, V, S);

  return 0;
}
