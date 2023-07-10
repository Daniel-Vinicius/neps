#include <iostream>

using namespace std;

int totalNum;
int numAtual;
int maximo = 0;
int aparecimentoTotal[12];

bool mostrarEspaco = false;

int main()
{

  cin >> totalNum;

  for (int i = 0; i < totalNum; i++)
  {

    cin >> numAtual;

    aparecimentoTotal[numAtual - 1] += 1;

    if (aparecimentoTotal[numAtual - 1] > maximo)
      maximo = aparecimentoTotal[numAtual - 1];
  }

  for (int i = 0; i < 12; i++)
  {

    if (aparecimentoTotal[i] == maximo)
    {

      if (mostrarEspaco)
        cout << ' ';

      mostrarEspaco = true;

      cout << i + 1;
    }
  }

  cout << '\n';

  return 0;
}
