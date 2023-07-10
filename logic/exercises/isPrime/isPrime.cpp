#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int n = 0;
  cin >> n;

  int numbersToTest[5] = {2, 3, 5, 7, 11};
  int moduleObtained;

  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
  {
    cout << 'S' << endl;
    return 0;
  }
  else if (n == 1)
  {
    cout << 'N' << endl;
    return 0;
  }

  for (int i = 0; i < 6; i++)
  {
    moduleObtained = n % numbersToTest[i];
    if (moduleObtained == 0)
    {
      cout << 'N' << endl;
      return 0;
    }
  }

  cout << 'S' << endl;
  return 0;
}
