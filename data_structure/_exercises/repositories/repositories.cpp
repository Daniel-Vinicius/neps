#include <bits/stdc++.h>

using namespace std;

// map

int main()
{
  int n_total_programasInstalados;
  int n_total_programasDisponiveis;
  map<int, int> programas;
  map<int, int> programasAlterados;

  cin >> n_total_programasInstalados >> n_total_programasDisponiveis;

  int n_programa, n_versao;
  while (cin >> n_programa >> n_versao)
  {
    if (programas.find(n_programa) != programas.end())
    {
      int curVersion = programas[n_programa];
      if (curVersion < n_versao)
      {
        programas[n_programa] = n_versao;
        programasAlterados[n_programa] = n_versao;
      }
    }
    else
    {
      // n_total_programasInstalados <= 0 significa que a partir daqui são novos programas sendo instalados
      if (n_total_programasInstalados <= 0)
      {
        programasAlterados.insert({n_programa, n_versao});
      }

      programas.insert({n_programa, n_versao});
      n_total_programasInstalados--;
    }
  }

  auto iteratorFirstElement = programasAlterados.begin();
  for (int i = 0; i < programasAlterados.size(); i++)
  {
    cout << iteratorFirstElement->first << " " << iteratorFirstElement->second << endl;
    iteratorFirstElement++;
  }

  return 0;
}