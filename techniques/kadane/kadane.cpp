#include <bits/stdc++.h>

using namespace std;

// O(n)
int main()
{
  vector<int> V = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int maxSum = V[0];
  int currentSum = V[0];
  for (int i = 1; i < V.size(); i++)
  {
    currentSum += max(currentSum + V[i], V[i]);
    maxSum = max(maxSum, currentSum);
  }

  cout << maxSum << endl;

  return 0;
}
