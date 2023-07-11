#include <bits/stdc++.h>

using namespace std;

// 8 minutes

int main()
{

  int value;
  vector<int> S = {1, 5, 10, 25, 50, 100};
  cin >> value;

  int coins = 0;
  for (int i = 5; i >= 0; i--)
  {
    int coinValue = S[i];
    while (value >= coinValue)
    {
      value -= coinValue;
      coins++;
    }
  }

  cout << coins << endl;

  return 0;
}
