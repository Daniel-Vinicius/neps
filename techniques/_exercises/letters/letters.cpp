#include <bits/stdc++.h>
using namespace std;

int lis(string &v)
{
  vector<char> pilha;

  for (int i = 0; i < v.size(); i++)
  {
    vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);
    // int idx = distance(pilha.begin(), it); // Converte o iterador em um índice
    // cout << "Índice do iterador: " << idx << endl;

    if (it == pilha.end()) // caso seja o maior caractere até agora insere na pilha
      pilha.push_back(v[i]);
    else
      *it = v[i]; // caso tenha outro maior, substitui pelo mais recente (iterador atualiza vetor pilha direto)
  }

  return pilha.size();
}

string s;

int main()
{
  cin >> s;
  cout << lis(s) << endl;
}
