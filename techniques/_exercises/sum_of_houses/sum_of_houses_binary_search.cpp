#include <bits/stdc++.h>
using namespace std;

int n, k, i, x;
vector<int> v;

int binary_search(int x)
{
  int r = n - 1;
  int l = 0;
  int m;
  while (r >= l)
  {
    m = (r + l) / 2;
    if (v[m] == x)
    {
      return m;
    }
    else if (v[m] < x)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
  return -1;
};

int main()
{
  cin >> n;
  for (i = 0; i < n; i++)
  {
    cin >> x;
    v.push_back(x);
  }
  cin >> k;
  for (i = 0; i < n; i++)
  {
    // v[i] + v[j] = K
    // v[j] = K - v[i]
    int search = binary_search(k - v[i]);
    if (search != -1)
    {
      cout << v[i] << " " << k - v[i] << endl;
      break;
    }
  }

  return 0;
}
