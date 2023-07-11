#include <bits/stdc++.h>

using namespace std;

#define MAXN 10100

struct Consulta
{
  int inicio;
  int fim;
};

bool compara(Consulta a, Consulta b)
{
  return a.fim < b.fim;
};

int main()
{

  int n;
  cin >> n;

  // = {}, pra por padrão setar tudo como 0
  Consulta consultas[MAXN] = {};

  // popula vetor
  for (int i = 1; i <= n; i++)
  {
    cin >> consultas[i].inicio >> consultas[i].fim;
  }

  // ordeno as consultas pelo horário de fim
  // pointer/iterator das posições inicio e fim (it sorts only between)
  // consultas+1 é um pointer. Ex: 0x7fff4d569218, e consultas sozinho também é.
  // Binary function that accepts two elements in the range as arguments
  sort(consultas + 1, consultas + n + 1, compara);

  int horario_livre = 0;
  int qtd = 0;

  // for each
  for (Consulta consulta : consultas)
  {
    // != pra nao contar os vazios gerados pelo MAXN
    if (consulta.inicio && consulta.fim != 0 && consulta.inicio >= horario_livre)
    {
      qtd++;
      horario_livre = consulta.fim;
    }
  }

  std::cout << qtd << std::endl;

  return 0;
}
