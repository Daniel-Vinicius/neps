#include <bits/stdc++.h>

using namespace std;

// Todo funcionário leva 1 minuto para subir ou descer um andar.

// Ans: número total de minutos a serem gastos com o melhor posicionamento possível da máquina.

// this exercise was solved in 19:43 min and seconds

int main()
{
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  int ansA1 = 0;
  int ansA2 = 0;
  int ansA3 = 0;
  ansA1 = 4 * A3 + 2 * A2;
  ansA2 = 2 * A1 + 2 * A3;
  ansA3 = 4 * A1 + 2 * A2;

  cout << min(min(ansA1, ansA2), ansA3) << endl;

  return 0;
}
