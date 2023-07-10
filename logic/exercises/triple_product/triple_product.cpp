#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;
  cin >> n;
  vector<long int> v(n);
  for (int i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    v.push_back(e);
  }

  long long int ans1 = v[v.size() - 1] * v[v.size() - 2] * v[v.size() - 3];
  long long int ans2 = v[v.size() - v.size() / 2] * v[(v.size() - v.size() / 2) + 1] * v[v.size() - 1];

  cout << max(ans1, ans2) << endl;

  return 0;
}
