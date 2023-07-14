#include <bits/stdc++.h>

using namespace std;

// kadane -> O(n)
// 12 minutes
int main()
{
  int N;
  cin >> N;

  int arr[N] = {};
  cin >> arr[0];

  int ans = arr[0];
  int sum = arr[0];

  for (int i = 1; i < N; i++)
  {
    int n;
    cin >> n;

    sum = max(sum + n, n);
    ans = max(sum, ans);
  }

  cout << ans << endl;
  return 0;
}
