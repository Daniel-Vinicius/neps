#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int qtdMaximaFusoesBanco = 11;

int main()
{

  int n_bancos;
  int n_operacoes;

  cin >> n_bancos >> n_operacoes;

  int bancos[MAXN][qtdMaximaFusoesBanco] = {};
  // ans: se cada consulta se refere ao mesmo banco -> S ou N

  for (int i = 0; i < n_operacoes; i++)
  {
    char tipo;
    int cod1, cod2;

    cin >> tipo >> cod1 >> cod2;

    if (tipo == 'F')
    {
      bancos[cod1][0] = 1;  // bancos[code][0] guarda se já foi fundido
      bancos[cod1][1] += 1; // bancos[code][1] guarda quantas vezes já foi fundido
      bancos[cod1][bancos[cod1][1] + 2] = cod2;

      bancos[cod2][0] = 1;  // bancos[code][0] guarda se já foi fundido
      bancos[cod2][1] += 1; // bancos[code][1] guarda quantas vezes já foi fundido
      bancos[cod2][bancos[cod2][1] + 2] = cod1;
    }

    if (tipo == 'C')
    {
      if (bancos[cod1][0] == 0)
      {
        cout << 'N' << endl;
        continue;
      }

      if (bancos[cod1][0] == 1)
      {
        for (int j = 3; j < qtdMaximaFusoesBanco; j++)
        {
          if (bancos[cod1][j] == cod2)
          {
            cout << 'S' << endl;
            break;
          }

          else if (j == (qtdMaximaFusoesBanco - 1) && bancos[cod1][j] != cod2)
          {
            cout << 'N' << endl;
            break;
          }
        }
      }
    }
  }

  return 0;
}
