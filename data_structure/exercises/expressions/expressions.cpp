#include <bits/stdc++.h>

using namespace std;

int occurrencesOfCharacter(string sample, char findIt)
{
  vector<int> characterLocations;
  for (int i = 0; i < sample.size(); i++)
    if (sample[i] == findIt)
      characterLocations.push_back(sample[i]);

  return characterLocations.size();
}

char cadeiaBemDefinida(string cadeia)
{
  char definicao = 'S';

  // a quantidade fechamentos de um caractere deve ser a mesma que a quantidade de abertura e vice versa
  if (occurrencesOfCharacter(cadeia, '[') != occurrencesOfCharacter(cadeia, ']') | occurrencesOfCharacter(cadeia, '(') != occurrencesOfCharacter(cadeia, ')') | occurrencesOfCharacter(cadeia, '{') != occurrencesOfCharacter(cadeia, '}'))
  {
    definicao = 'N';
  }

  for (int i = 0; i < cadeia.size(); i++)
  {
    if (definicao == 'N')
    {
      break;
    }

    char caractere = cadeia.at(i);
    // sempre que tenho uma abertura preciso achar um fechamento e vice versa

    if (caractere == '{')
    {
      int fechamentoIndex = cadeia.find_last_of('}');
      if (fechamentoIndex == string::npos | fechamentoIndex < i)
      {
        definicao = 'N';
      }
    }

    if (caractere == '}')
    {
      int aberturaIndex = cadeia.find_first_of('{');
      if (aberturaIndex == string::npos || aberturaIndex > i)
      {
        definicao = 'N';
      }
    }

    if (caractere == '(')
    {
      int fechamentoIndex = cadeia.find_last_of(')');
      if (fechamentoIndex == string::npos | fechamentoIndex < i)
      {
        definicao = 'N';
      }
    }

    if (caractere == ')')
    {
      int aberturaIndex = cadeia.find_first_of('(');
      if (aberturaIndex == string::npos || aberturaIndex > i)
      {
        definicao = 'N';
      }
    }
    if (caractere == '[')
    {
      int fechamentoIndex = cadeia.find_last_of(']');
      if (fechamentoIndex == string::npos | fechamentoIndex < i)
      {
        definicao = 'N';
      }
    }

    if (caractere == ']')
    {
      int aberturaIndex = cadeia.find_first_of('[');
      if (aberturaIndex == string::npos || aberturaIndex > i)
      {
        definicao = 'N';
      }
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