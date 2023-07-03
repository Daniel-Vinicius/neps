#include <bits/stdc++.h>

using namespace std;

// pilha
// fazer isso até que n_apresentador esteja vazio
// percorrer o numero(string)
// pegar o menor inteiro convertido e cortar ele
// cortar quantas vezes a qtd diz para apagar
// cada vez que fizer isso colocar o resultado na pilha maior premio
// printar o maior premio

int main()
{
  stack<string> qtd_digitos_qtd_apagar;
  stack<string> n_apresentador;
  stack<string> maior_premio;

  bool keep = true;
  while (keep)
  {
    string digito;
    getline(cin, digito);

    if (digito == "0 0")
    {
      keep = false;
      break;
    }

    qtd_digitos_qtd_apagar.push(digito);

    string n;
    cin >> n;
    n_apresentador.push(n);

    cin.ignore();
  }

  for (int i = 0; i < n_apresentador.size(); i++)
  {
    string numeroAtual = n_apresentador.top();
    vector<int> algarismos = {};

    for (int i = 0; i < numeroAtual.size(); i++)
    {
      char algarismo = numeroAtual.at(i);
      int convertido = algarismo - '0';
      algarismos.push_back(convertido);
    }

    vector<int> digitosParaApagar = {};
    int qtd_para_apagar = qtd_digitos_qtd_apagar.top().at(2) - '0';
    qtd_digitos_qtd_apagar.pop();

    for (int i = 0; i < qtd_para_apagar; i++)
    {
      auto min = min_element(algarismos.begin(), algarismos.end());
      digitosParaApagar.push_back(*min);
      int indexOfMinElement = distance(begin(algarismos), min);
      algarismos.erase(algarismos.begin() + indexOfMinElement);
    }

    for (int i = 0; i < digitosParaApagar.size(); i++)
    {
      int nApagarIndex = numeroAtual.find_first_of(numeroAtual.substr(digitosParaApagar.at(i)));
      cout << nApagarIndex << endl;
      numeroAtual.erase(nApagarIndex, 1);
    }

    cout << numeroAtual << endl;

    n_apresentador.pop();
  }

  // while (!qtd_digitos_qtd_apagar.empty())
  // {
  //   cout << qtd_digitos_qtd_apagar.top() << endl;
  //   qtd_digitos_qtd_apagar.pop();
  // }
  // while (!n_apresentador.empty())
  // {
  //   cout << n_apresentador.top() << endl;
  //   n_apresentador.pop();
  // }

  return 0;
}
