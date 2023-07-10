#include <bits/stdc++.h>

using namespace std;

// 10 minutes

int main()
{
  int counterHowManyTimes100onSequency = 0;

  int sequencySize;
  cin >> sequencySize;

  vector<int> sequency;
  for (int i = 0; i < sequencySize; i++)
  {
    int n;
    cin >> n;
    sequency.push_back(n);

    if (i >= 2)
    {
      if (to_string(sequency[i - 2]) + to_string(sequency[i - 1]) + to_string(n) == "100")
      {
        counterHowManyTimes100onSequency++;
      }
    }
  }

  cout << counterHowManyTimes100onSequency << endl;

  return 0;
}
