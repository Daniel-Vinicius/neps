#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

// O(n log n)
int main()
{
  int n;
  int v[MAXN], dp[MAXN], opt[MAXN], ind[MAXN];

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  dp[0] = -INF;

  for (int i = 1; i <= n; i++)
    dp[i] = INF;

  for (int i = 0; i < n; i++)
  {
    int p = lower_bound(dp, dp + n + 1, v[i]) - dp; // upper_bound se pode ter elementos iguais

    ind[p] = i;
    dp[p] = v[i];
    opt[i] = ind[p - 1];
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
    if (dp[i] < INF)
      ans = i;

  cout << "Tamanho da maior subsequência crescente: " << ans << endl;

  vector<int> LIS;

  int curIndex = ind[ans];

  for (int i = ans; i > 0; i--)
  {
    LIS.push_back(curIndex);
    curIndex = opt[curIndex];
  }

  reverse(LIS.begin(), LIS.end());

  cout << "Subsequência ótima: ";

  for (int i = 0; i < (int)LIS.size(); i++)
    cout << v[LIS[i]] << " ";

  cout << endl;
}
