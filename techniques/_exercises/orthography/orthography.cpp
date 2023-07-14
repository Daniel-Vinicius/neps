#include <bits/stdc++.h>

using namespace std;

// Retirar uma letra de A.
// Adicionar uma letra a A, em qualquer posição.
// Trocar qualquer letra de A por outra letra, na mesma posição.

// O serviço de busca definiu que a palavra P fornecida pelo usuário pode se referir a uma palavra
// D do dicionário se está a uma distância de no máximo 2 de D.

// Exemplos:
// A palavra ‘tu’ pode se referir à palavra do dicionário ‘tubo’, realizando duas vezes a operação 2.

// para cada palavra digitada verifica se
// tamanho da palavra digitada - LCS dela com a palavra do dicionário[i] <= 2
// answer[i].push(palavraDicionario)

int lcs(char *x, char *y, int n, int m, vector<vector<int>> &dp)
{
  if (m == 0 || n == 0)
    return 0;

  if (x[n - 1] == y[m - 1])
    return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);

  if (dp[n][m] != -1)
    return dp[n][m];

  return dp[n][m] = max(lcs(x, y, n, m - 1, dp), lcs(x, y, n - 1, m, dp));
}

void processa(string dicionario, string digitada, int dicionarioStrLen, int digitadaStrLen, vector<vector<string>> &ans, int dp_i)
{
  char x[dicionarioStrLen];
  for (int i = 0; i < dicionarioStrLen; i++)
    x[i] = dicionario.at(i);

  char y[digitadaStrLen];
  for (int i = 0; i < digitadaStrLen; i++)
    y[i] = digitada.at(i);

  vector<vector<int>> dp(dicionarioStrLen + 1, vector<int>(digitadaStrLen + 1, -1));
  int commonSequence = lcs(x, y, dicionarioStrLen, digitadaStrLen, dp);

  // cout << "dicionario: " << dicionario << " ";
  // cout << digitadaStrLen << " " << commonSequence << " " << digitadaStrLen - commonSequence << endl;

  if (digitadaStrLen - commonSequence < 2)
  {
    ans[dp_i].push_back(dicionario);
  }
}

int main()
{

  // N -> qtd dicionario
  // M -> qtd digitada
  int N, M;
  cin >> N >> M;
  vector<string> palavrasDicionario;
  vector<string> palavrasDigitadas;
  vector<vector<string>> ans(M, vector<string>(N));

  for (int i = 0; i < N; i++)
  {
    string palavra;
    cin >> palavra;
    palavrasDicionario.push_back(palavra);
  }

  for (int i = 0; i < M; i++)
  {
    string palavra;
    cin >> palavra;
    palavrasDigitadas.push_back(palavra);

    for (int j = 0; j < N; j++)
      processa(palavrasDicionario[j], palavra, palavrasDicionario[j].length(), palavra.length(), ans, i);
  }

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

// Output:

// pato
// (espaço em branco)
// pato pateta
