#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>

#define MC 2000

using namespace std;

queue<int> queueBFS;
map<string, int> mapWikiPagesToNumber;

string pageA, pageB;
int startPage, finalPage, currentPage, N, numberOfPages;
int v[MC], tab[MC][MC]; // Vetor de distâncias e matriz de adjacência

int main()
{
  fill(v, v + MC, -1);      // Inicialização do vetor de distâncias com -1 (valor padrão para páginas não visitadas)
  fill(tab[0], tab[MC], 0); // Inicialização da matriz de adjacência com zeros (indicando a ausência de conexões)
  numberOfPages = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> pageA >> pageB;
    if (mapWikiPagesToNumber.count(pageA) == 0)
      mapWikiPagesToNumber[pageA] = numberOfPages++;
    if (mapWikiPagesToNumber.count(pageB) == 0)
      mapWikiPagesToNumber[pageB] = numberOfPages++;
    tab[mapWikiPagesToNumber[pageA]][mapWikiPagesToNumber[pageB]] = 1;
  }

  string P, A;
  cin >> P >> A;

  startPage = mapWikiPagesToNumber[P];
  finalPage = mapWikiPagesToNumber[A];

  // Cria as referências sequenciais na matriz de adjacência tab, garantindo que todas as páginas tenham conexões sequenciais entre si.
  // Isso é feito para que seja possível navegar sequencialmente de uma página para outra, na ordem alfabética das páginas.
  map<string, int>::iterator it = mapWikiPagesToNumber.begin();
  currentPage = (*it).second;
  it++;
  for (; it != mapWikiPagesToNumber.end(); it++)
  {
    int nextPage = (*it).second;
    tab[currentPage][nextPage] = tab[nextPage][currentPage] = 1;
    currentPage = nextPage;
  }

  currentPage = startPage;
  v[startPage] = 0; // Define a distância da página inicial para ela mesma como 0
  while (currentPage != finalPage)
  {
    for (int i = 0; i < numberOfPages; i++)
      if (tab[currentPage][i] && v[i] == -1)
      {
        v[i] = v[currentPage] + 1;
        queueBFS.push(i);
      }
    if (queueBFS.empty())
      break;
    currentPage = queueBFS.front();
    queueBFS.pop(); // Remove a página atual da fila, pois já foi visitada
  }
  cout << v[currentPage] << endl; // Imprime a menor distância da página onde Paulo está até a página editada por André

  return 0;
}
