#include <iostream>

using namespace std;

int main()
{
  int H, P, F, D;
  cin >> H >> P >> F >> D;

  while (true)
  {

    if (F == H)
    {
      cout << "S" << endl;
      break;
    }

    if (F == P)
    {
      cout << "N" << endl;
      break;
    }

    if (D == -1)
    {
      if (F > 0)
        F--;
      else
        F = 15;
    }
    else if (D == 1)
      if (F < 15)
        F++;
      else
        F = 0;
  }

  return 0;
}
