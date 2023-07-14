#include <iostream>
#include <string>

using namespace std;
// Retirar uma letra de A.
// Adicionar uma letra a A, em qualquer posição.
// Trocar qualquer letra de A por outra letra, na mesma posição.

// O serviço de busca definiu que a palavra P fornecida pelo usuário pode se referir a uma palavra
// D do dicionário se está a uma distância de no máximo 2 de D.

// Exemplos:
// A palavra ‘tu’ pode se referir à palavra do dicionário ‘tubo’, realizando duas vezes a operação 2.

string palavrasDicionario[1001], palavrasDigitadas[101];

// linhas -> o tamanho da palavra do dicionário
// colunas -> deslocamento da palavra digitada em relação à palavra do dicionário.
int distanceTable[22][6], n, m; // matriz bidimensional

// semelhante a lcs
int processWord(string &a, string &b)
{
  int sa = a.size(), sb = b.size();
  for (int i = 0; i <= 2; i++)
    distanceTable[0][i + 2] = i;

  for (int i = 1; i <= sa; i++)
  {
    for (int j = -2; j <= 2; j++)
    {
      if (i + j < 0 && i + j > sb)
        continue;
      if (i + j == 0)
      {
        distanceTable[i][j + 2] = i;
        continue;
      }

      if (a[i - 1] == b[i + j - 1])
        distanceTable[i][j + 2] = distanceTable[i - 1][j + 2];
      else
      {
        distanceTable[i][j + 2] = distanceTable[i - 1][j + 2] + 1;
        if (j != 2)
          distanceTable[i][j + 2] = min(distanceTable[i][j + 2], distanceTable[i - 1][j + 3] + 1);
        if (j != -2)
          distanceTable[i][j + 2] = min(distanceTable[i][j + 2], distanceTable[i][j + 1] + 1);
      }
    }
  }

  int distance = 10;
  for (int i = -2; i <= 2; i++)
  {
    if (sa + i < 0 || sa + i > sb)
      continue;
    distance = distanceTable[sa][i + 2] + sb - sa - i;
  }
  return (distance < 3);
}

int main()
{

  // N -> qtd dicionario
  // M -> qtd digitada
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> palavrasDicionario[i];
  for (int j = 0; j < m; j++)
    cin >> palavrasDigitadas[j];

  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      if (processWord(palavrasDicionario[i], palavrasDigitadas[j]))
        cout << palavrasDicionario[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
