#include <bits/stdc++.h>

using namespace std;

// 15 minutos

int main()
{
  int n_celulas;
  cin >> n_celulas;

  vector<int> celulas = {};
  for (int i = 0; i < n_celulas; i++)
  {
    int celula;
    cin >> celula;
    celulas.push_back(celula);
  }

  vector<int> mines = {};
  for (int i = 0; i < n_celulas; i++)
  {
    int lastMine = 0;
    int currentMine = 0;
    int nextMine = 0;
    if (i != 0)
    {
      lastMine = celulas[i - 1];
    }
    if (i != n_celulas - 1)
    {
      nextMine = celulas[i + 1];
    }
    currentMine = celulas[i];
    int n_mines = lastMine + currentMine + nextMine;
    mines.push_back(n_mines);

    cout << mines[i] << endl;
  }

  return 0;
}
