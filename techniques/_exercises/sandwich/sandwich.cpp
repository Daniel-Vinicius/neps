#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  int N, D;
  cin >> N >> D;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int ans1 = 0; // Variável para contar as sequências contíguas com soma igual a D
  int l = 0, r = 0;
  int soma = 0;

  // Percorre o vetor A utilizando a técnica dos dois ponteiros (Janela deslizante)
  while (l < N)
  {
    // Move o ponteiro direito (r) para a direita enquanto a soma for menor ou igual a D
    while (r < N && soma + A[r] <= D)
    {
      soma += A[r];
      r += 1;
    }

    // Se a soma dos comprimentos dos pedaços for igual a D, incrementa o contador
    if (soma == D)
      ans1++;

    // Reduz a janela movendo o ponteiro esquerdo (l) para a direita
    soma -= A[l];
    l += 1;
  }

  vector<int> Pref(N), Suf(N); // Vetores para armazenar as somas de prefixo e sufixo

  int acc = 0;
  for (int i = 0; i < N; i++)
  {
    acc += A[i];
    Pref[i] = acc; // Calcula as somas de prefixo
  }

  acc = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    acc += A[i];
    Suf[i] = acc; // Calcula as somas de sufixo
  }

  map<int, int> SufCount; // Mapa para contar as ocorrências das somas de sufixo

  int ans2 = 0; // Variável para contar as sequências contíguas com soma igual a D usando as extremidades
  for (int i = N - 2; i >= 0; i--)
  {
    SufCount[Suf[i + 1]] += 1; // Incrementa o contador para a soma de sufixo atual
    if (Pref[i] > D)
      continue; // Se a soma de prefixo for maior que D, passa para a próxima iteração

    ans2 += SufCount[D - Pref[i]]; // Incrementa o contador com o número de ocorrências das somas de sufixo correspondentes
  }

  cout << ans1 + ans2 << endl; // Imprime o resultado total

  return 0;
}
