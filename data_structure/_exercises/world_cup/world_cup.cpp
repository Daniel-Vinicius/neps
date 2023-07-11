#include <bits/stdc++.h>

using namespace std;

// Quebrar o problema em partes menores:
// a) Ler os resultados dos jogos da fase final.
// b) Armazenar os resultados em uma estrutura de dados adequada.
// c) Identificar os vencedores de cada partida e armazená-los para a próxima fase.
// d) Repetir o processo para todas as fases até chegar ao campeão.
// e) Imprimir a equipe campeã.

// Temos 4 fases mais as equipes iniciais
// Cada fase temos vários vencedores

int main()
{
  /*
  Nessa linha, é declarado um vetor de vetores chamado vencedores com tamanho 5.
  Cada vetor interno armazenará as equipes vencedoras de uma fase específica.
  */
  vector<char> vencedores[5];

  for (char i = 'A'; i <= 'P'; i++)
  {
    vencedores[0].push_back(i); // preenchendo as oitavas
  }

  for (int fase = 1; fase <= 4; fase++)
  {
    // O loop interno percorre os vencedores da fase anterior, de dois em dois, representando os confrontos entre as equipes.
    for (int i = 0; i < vencedores[fase - 1].size(); i += 2)
    {
      int equipe1 = vencedores[fase - 1][i];
      int equipe2 = vencedores[fase - 1][i + 1];

      int gols1, gols2;

      cin >> gols1 >> gols2;

      if (gols1 > gols2)
      {
        vencedores[fase].push_back(equipe1);
      }
      else
      {
        vencedores[fase].push_back(equipe2);
      }
    }
  }

  // fase 4 é a final
  cout << vencedores[4][0] << endl;

  return 0;
}
