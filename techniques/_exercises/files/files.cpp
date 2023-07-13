#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, b;
  cin >> n >> b;

  vector<int> val(n);

  for (int i = 0; i < n; i++)
    cin >> val[i];

  sort(val.begin(), val.end());

  int ans = n;

  vector<bool> mark(n, false);

  int j = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (mark[i])
      continue;
    while (j >= 0 && val[j] + val[i] > b)
      j--;
    if (j > i)
    {
      mark[i] = mark[j] = true;
      ans--;
      j--;
    }
  }

  cout << ans << endl;

  return 0;
}
