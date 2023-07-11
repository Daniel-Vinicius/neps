#include <bits/stdc++.h>

using namespace std;

char cadeiaBemDefinida(string cadeia)
{
  char definicao = 'S';
  stack<char> cadeiaEmPilha;

  for (int i = 0; i < cadeia.size(); i++)
  {
    char caractere = cadeia.at(i);

    // sempre usar || em C++ para condições lógicas
    if (caractere == '{' || caractere == '(' || caractere == '[')
    {
      cadeiaEmPilha.push(caractere);
    }

    if ((caractere == '}' || caractere == ')' || caractere == ']') && cadeiaEmPilha.size() == 0)
    {
      definicao = 'N';
    }

    if (caractere == '}' && !cadeiaEmPilha.empty())
    {
      if (cadeiaEmPilha.top() == '{')
      {
        cadeiaEmPilha.pop();
      }
      else
      {
        definicao = 'N';
      }
    }

    if (caractere == ']' && !cadeiaEmPilha.empty())
    {
      if (cadeiaEmPilha.top() == '[')
      {
        cadeiaEmPilha.pop();
      }
      else
      {
        definicao = 'N';
      }
    }

    if (caractere == ')' && !cadeiaEmPilha.empty())
    {
      if (cadeiaEmPilha.top() == '(')
      {
        cadeiaEmPilha.pop();
      }
      else
      {
        definicao = 'N';
      }
    }

    if (i == cadeia.size() - 1 && cadeiaEmPilha.size() != 0)
    {
      definicao = 'N';
    }
  }

  return definicao;
};

int main()
{
  int n_instancias;
  cin >> n_instancias;

  stack<string> input; // cadeias
  stack<char> output;  // bem formada ou não

  for (int i = 0; i < n_instancias; i++)
  {
    string cadeia;
    cin >> cadeia;
    input.push(cadeia);
  }
  // cout << "size input: " << input.size() << endl;

  for (int i = 0; i < n_instancias; i++)
  {
    char definicao = cadeiaBemDefinida(input.top());
    input.pop();
    output.push(definicao);
  }

  // cout << "size output: " << output.size() << endl;

  while (!output.empty())
  {
    cout << output.top() << endl;
    output.pop();
  }

  return 0;
}