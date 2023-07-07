#include <iostream>

using namespace std;

int main()
{
  int arr[10], mini = 99999;

  // Lendo os valores de entrada e guardando o menor valor
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
    mini = min(mini, arr[i]);
  }

  // Imprimindo o menor valor
  cout << "Menor: " << mini << endl;

  // Percorrendo todo o for, e imprimindo os índices os quais são igual ao menor valor lido
  cout << "Ocorrencias: ";
  for (int i = 0; i < 10; i++)
    if (arr[i] == mini)
      cout << i << ' ';

  cout << endl;

  // Percorrendo novamente todo o array, mas desta vez vendo se o valor atual é igual ao menor valor para
  // imprimir no lugar dele, -1
  for (int i = 0; i < 10; i++)
    if (arr[i] == mini)
      cout << -1 << ' ';
    else
      cout << arr[i] << ' ';

  cout << endl;
  return 0;
}
