#include <bits/stdc++.h>

using namespace std;

int search(int a[], int L, int R, int value)
{
  int mid = (L + R) / 2;

  if (L > R)   // Intervalo invalido
    return -1; // Valor não encontrado

  if (a[mid] == value) // O valor foi encontrado
    return a[mid];

  if (a[mid] < value) // Descarto o intervalo à esquerda
    return search(a, mid + 1, R, value);
  else // Descarto o intervalo à direita
    return search(a, L, mid - 1, value);
}

int main()
{
  int a[10] = {-4, 2, 5, 7, 40, 67, 88, 90, 91, 100};

  int x;
  cin >> x;

  if (search(a, 0, 9, x) == x)
  {
    cout << "x: " << x << " exists in the array!" << endl;
  }
  else
  {
    cout << "x: " << x << " does not exist in the array!" << endl;
  }

  return 0;
}
