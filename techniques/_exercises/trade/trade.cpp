#include <iostream>

using namespace std;

const int MAXN = 100005;

// soma de prefixos

int main()
{
  int n, t, cima[MAXN], baixo[MAXN], operacoes[MAXN], somaprefixos[MAXN];

  cin >> n >> t;

  for (int i = 1; i <= n; i++)
  {
    cin >> cima[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> baixo[i];
  }

  for (int i = 0; i < t; i++)
  {
    int a, b;
    cin >> a >> b;
    operacoes[a]++;
    operacoes[b + 1]--;
  }

  somaprefixos[0] = 0;
  // usa as operações para calcular o soma prefixo e assim poder dizer quantas vezes cada carta foi virada.
  for (int i = 1; i <= n; i++)
  {
    somaprefixos[i] = somaprefixos[i - 1] + operacoes[i];
  }

  // se foi virada n par de vezes, é o mesmo que não virar
  for (int i = 1; i <= n; i++)
  {
    if (somaprefixos[i] % 2 == 0)
    {
      cout << cima[i] << " ";
    }
    else
    {
      cout << baixo[i] << " ";
    }
  }

  cout << endl;

  return 0;
}
