#include <bits/stdc++.h>

using namespace std;

int footToInt(char foot)
{
  if (foot == 'D')
  {
    return 0;
  }
  else
  {
    return 1;
  }
};

int boots[31][2] = {};
int main()
{
  int n_boots;
  cin >> n_boots;

  for (int i = 0; i < n_boots; i++)
  {
    int size = 0;
    char foot;
    cin >> size >> foot;
    boots[size][footToInt(foot)] += 1;
  }

  int n_pairs = 0;
  for (int i = 30; i < 61; i++)
  {
    n_pairs += min(boots[i][0], boots[i][1]);
  }

  cout << n_pairs << endl;

  return 0;
}
