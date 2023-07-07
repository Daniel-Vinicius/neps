#include <bits/stdc++.h>

using namespace std;

//  Neste problema, dados os três tempos distintos de finalização da prova, dos três nadadores que ganharam medalhas,
//  seu programa deve dizer quem ganhou medalha de ouro, quem ganhou prata e quem ganhou bronze.

// T1, T2, T3
// N que ganhou ouro, prata e bronze

int main()
{
  set<int> temposNadadores;
  map<int, int> posicoes;
  for (int i = 0; i < 3; i++)
  {
    int t;
    cin >> t;
    temposNadadores.insert(t);
    posicoes.insert({t, i + 1});
  }

  for (int i = 0; i < 3; i++)
  {
    auto ptr = temposNadadores.begin();
    cout << posicoes.find(*ptr)->second << endl;
    temposNadadores.erase(*ptr);
  }

  return 0;
}
