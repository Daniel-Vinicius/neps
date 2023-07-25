#include <bits/stdc++.h>
using namespace std;

// Combinando as duas partes
// A primeira parte se encontra em [l, (l+r)/2]
// A segunda parte se encontra em [(l+r)/2,r]
void merge(int l, int r, vector<int> &x)
{
  int mid = (l + r) / 2;
  vector<int> S;

  int p1 = l;       // p1 aponta para o primeiro elemento da sequencia 1
  int p2 = mid + 1; // p2 aponta para o primeiro elemento da sequencia 2

  while (p1 <= mid && p2 <= r)
  {
    if (x[p1] <= x[p2])
    {
      S.push_back(x[p1]);
      p1++;
    }
    else
    {
      S.push_back(x[p2]);
      p2++;
    }
  }
  // Se ainda sobrarem elementos na parte 1
  while (p1 <= mid)
  {
    S.push_back(x[p1]);
    p1++;
  }
  // Se ainda sobrarem elementos na parte 2
  while (p2 <= r)
  {
    S.push_back(x[p2]);
    p2++;
  }

  // Agora, deveremos passar todos os valores de S para o vetor x
  for (int i = 0; i < S.size(); i++)
  {
    x[l + i] = S[i];
  }
  // Agora o intervalo [l,r] em x está ordenado
}

// Passando x por referencia
// [l,r] = intervalo que precisa ser ordenado
void mergeSort(int l, int r, vector<int> &x)
{

  int mid;
  // Se l == r ou l > r, o intervalo ja estará
  // Ordenado por padrão
  if (l < r)
  {
    mid = (l + r) / 2;
    mergeSort(l, mid, x);     // Ordena a primeira parte
    mergeSort(mid + 1, r, x); // Ordena a segunda
    merge(l, r, x);           // Combina as duas partes
  }
}

int main()
{

  vector<int> x = {9, 4, 2, 1, -3, 1, 7, 19, 32, 23, -17};

  int N = (int)x.size();

  cout << "Unsorted array" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << x[i] << " ";
  }
  cout << endl;

  // 0 = inicio do intervalo no meu vetor que quero ordenar
  // N-1 = ultima posição do intervalo que quero ordenar no vetor
  mergeSort(0, N - 1, x);

  cout << "Sorted array" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << x[i] << " ";
  }
  cout << endl;
}
