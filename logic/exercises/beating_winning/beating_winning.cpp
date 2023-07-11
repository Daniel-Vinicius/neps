#include <bits/stdc++.h>

using namespace std;

// did not passed 36 minutes

int main()
{
  int N, D;
  string n;
  while (cin >> N >> D >> n && N != 0 && D != 0)
  {
    vector<char> numbersSorted;
    for (int i = 0; i < n.size(); i++)
    {
      numbersSorted.push_back(n[i]);
    }
    sort(numbersSorted.begin(), numbersSorted.end());

    for (int j = 0; j < D; j++)
    {
      n.erase(n.find(numbersSorted[j]), 1);
    }
    cout << n << endl;
  }

  return 0;
}
