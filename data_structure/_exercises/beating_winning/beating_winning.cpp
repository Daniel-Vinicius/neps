#include <bits/stdc++.h>

using namespace std;

int n, d;
string numero_apresentador, maior_premio;

int main()
{
  while (cin >> n >> d) // Enquanto houver coisas pra ler
  {
    if (n == 0 && d == 0)
      return 0;

    cin >> numero_apresentador;

    int erased = 0;
    for (char cur : numero_apresentador)
    {
      // algoritmo guloso
      // O algoritmo guloso é apropriado quando uma solução ótima pode ser construída por meio de escolhas locais ótimas em cada etapa.
      // O problema deve ter a propriedade de subestrutura ótima, o que significa que uma solução global ótima pode ser alcançada combinando soluções ótimas para subproblemas menores.
      while (maior_premio.size() > 0 && cur > maior_premio.back() && erased < d)
      {
        maior_premio.pop_back();
        erased++;
      }

      // n - d é o tamanho da resposta
      if (maior_premio.size() < n - d)
        maior_premio.push_back(cur); // append
    }

    cout << maior_premio << "\n";

    numero_apresentador.clear();
    maior_premio.clear();
  }

  return 0;
}