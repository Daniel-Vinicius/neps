#include <bits/stdc++.h>

using namespace std;

// kadane interval max sum -> O(n)

int main()
{
  int n_jogos, conjunto = 0;
  while (cin >> n_jogos && n_jogos != 0)
  {
    conjunto++;
    vector<int> goalDifference(n_jogos);
    for (int i = 0; i < n_jogos; ++i)
    {
      int x, y;
      cin >> x >> y;
      goalDifference[i] = (x - y);
    }

    int currentSum = 0, maxSum = -1e9;
    for (int k = 0; k < n_jogos; ++k)
    {
      currentSum += goalDifference[k];
      maxSum = max(maxSum, currentSum);
      currentSum = max(currentSum, 0);
    }

    int i = 0, j = 0;
    pair<int, int> ans = {0, 0};
    currentSum = 0;

    for (int k = 0; k < n_jogos; ++k)
    {
      currentSum += goalDifference[k];
      if (currentSum == maxSum && j - i >= ans.second - ans.first)
        ans = {i, j};

      if (currentSum < 0)
        i = j = k + 1;
      else
        j++;
      currentSum = max(currentSum, 0);
    }

    cout << "Teste " << conjunto << endl;
    if (maxSum <= 0)
      cout << "nenhum";
    else
      cout << ans.first + 1 << " " << ans.second + 1;
    cout << endl
         << endl;
  }

  return 0;
}
