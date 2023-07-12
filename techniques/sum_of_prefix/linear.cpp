#include <iostream>
using namespace std;

const int MAXN = 1010; // A quantidade máxima de elementos que esperamos ler

// O(n)
int main()
{
  int n, q;
  int v[MAXN];

  // Lendo o tamanho da sequência e a quantidade de perguntas respectivamente
  cin >> n >> q;

  // Lendo todos os inteiros e armazenando no vetor v
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i = 0; i < q; i++)
  {
    int L, R;

    // Lendo o intervalo da i-esima pergunta
    cin >> L >> R;

    int sum = 0;

    for (int j = L; j <= R; j++) // Calculando a soma dos elementos do intervalo [L,R]
      sum += v[j];

    cout << "Soma do intervalo: " << sum << endl;
  }
}
