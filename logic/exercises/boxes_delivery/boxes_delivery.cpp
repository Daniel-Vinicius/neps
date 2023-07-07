#include <iostream>

using namespace std;

int vecCaixas[3];

bool caixa1e2em3, caixa1em3, caixa2em3, caixa1em2;

int main()
{

  for (int i = 0; i < 3; i++)
    cin >> vecCaixas[i];

  caixa1e2em3 = (vecCaixas[0] + vecCaixas[1]) < vecCaixas[2];
  caixa1em3 = vecCaixas[0] < vecCaixas[2];
  caixa2em3 = vecCaixas[1] < vecCaixas[2];
  caixa1em2 = vecCaixas[0] < vecCaixas[1];

  if (caixa1e2em3 || (caixa1em2 && caixa2em3))
    cout << 1 << '\n';

  else if ((caixa2em3 && !caixa1em2) || (!caixa2em3 && caixa1em2))
    cout << 2 << '\n';

  else
    cout << 3 << '\n';

  return 0;
}
