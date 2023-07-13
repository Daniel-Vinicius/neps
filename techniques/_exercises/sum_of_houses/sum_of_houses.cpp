#include <bits/stdc++.h>

using namespace std;

int main()
{

  int N, K;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  cin >> K;
  int l = 0, r = N - 1;
  while (l <= r)
  {
    if (arr[l] + arr[r] == K)
    {
      cout << arr[l] << " " << arr[r] << endl;
      break;
    }
    else if (arr[l] + arr[r] < K)
    {
      l++;
    }
    else if (arr[l] + arr[r] > K)
    {
      r--;
    }
  }

  return 0;
}
