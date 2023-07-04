#include <bits/stdc++.h>

using namespace std;

// priority_queue

struct Jogador
{
  string nome;
  int habilidade;

  Jogador(string nome, int habilidade) : nome(nome), habilidade(habilidade) {}
};

struct CompareSkill
{
  bool operator()(const Jogador &p1, const Jogador &p2) const
  {
    return p1.habilidade < p2.habilidade;
  }
};

bool sortPlayersAlphabetically(Jogador &p1, Jogador &p2)
{
  return p1.nome < p2.nome;
};

int main()
{
  int qtd_jogadores, n_times;
  cin >> qtd_jogadores >> n_times;

  string name;
  int skill;

  priority_queue<Jogador, vector<Jogador>, CompareSkill> jogadores;

  // times é um vetor de vetor de jogadores com tamanho do número de times, é uma matriz
  vector<Jogador> times[n_times];

  // populo jogadores, enquanto tiver coisas pra ler (name e skill sao sobrescritas)
  while (cin >> name >> skill)
  {
    jogadores.push(Jogador(name, skill));
  }

  // coloco jogadores nos times, usando a lógica de sempre escolher o melhor disponível
  int lastIndex = 0;
  for (int i = 1; !jogadores.empty(); i++)
  {
    int time = i - lastIndex;
    Jogador j = jogadores.top();
    times[time - 1].push_back(j);

    jogadores.pop();

    if (time == n_times)
    {
      lastIndex = i;
    }
  }

  for (int i = 0; i < n_times; i++)
  {
    cout << "Time " << i + 1 << endl;

    // ordena por ordem alfabética cada um dos times
    sort(times[i].begin(), times[i].end(), sortPlayersAlphabetically);

    // imprime jogadores em ordem alfabética
    for (int j = 0; j < times[i].size(); j++)
    {
      Jogador jogador = times[i][j];
      cout << jogador.nome << endl;
    }
    cout << endl;
  }

  return 0;
}
