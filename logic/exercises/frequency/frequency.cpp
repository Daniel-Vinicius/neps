#include <bits/stdc++.h>

using namespace std;

// 5 minutes

int main()
{
  int n;
  cin >> n;

  set<int> chamada;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int number;
    cin >> number;
    if (chamada.find(number) == chamada.end())
    {
      ans++;
      chamada.insert(number);
    }
  }

  cout << ans << endl;

  return 0;
}
