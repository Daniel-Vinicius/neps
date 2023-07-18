#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int V, n;
  cin >> V >> n;

  vector<int> M(n);
  for (int i = 0; i < n; i++)
    cin >> M[i];

  vector<bool> dp(V + 1, false);
  dp[0] = true;

  for (int i = 0; i < n; i++)
  {
    for (int k = V - M[i]; k >= 0; k--) // pq 0 é o caso base, nesse loop não entra número negativo de k
    {
      // cout << k << " " << dp[k] << endl;
      if (dp[k] == true)
      {
        dp[k + M[i]] = true;
      }
    }
  }

  if (dp[V] == true)
    cout << "S" << endl;
  else
    cout << "N" << endl;

  return 0;
}
