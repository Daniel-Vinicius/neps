#include <bits/stdc++.h>

using namespace std;

struct Consulta
{
  int inicio;
  int fim;
};

int main()
{

  int n;
  cin >> n;

  stack<Consulta> consultas_possiveis;

  for (int i = 0; i < n; i++)
  {
    int inicio, fim;
    cin >> inicio >> fim;
    Consulta consulta = {inicio, fim};

    if (consultas_possiveis.size() > 0)
    {
      if (consulta.inicio >= consultas_possiveis.top().fim)
      {
        consultas_possiveis.push(consulta);
      }
    }
    else
    {
      consultas_possiveis.push(consulta);
    }
  }

  cout << consultas_possiveis.size() << endl;

  return 0;
}
