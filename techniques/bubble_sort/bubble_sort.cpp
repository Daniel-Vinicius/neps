#include <bits/stdc++.h>

using namespace std;

int main()
{
  // O(n²)
  int arraySize;
  cin >> arraySize;

  int array[arraySize];

  cout << "Unsorted Array" << endl;
  for (int k = 0; k < arraySize; k++)
  {
    int n;
    cin >> n;
    array[k] = n;
    cout << array[k] << " ";
  }
  cout << endl;

  // para cada n do array ele percorre todas as outras posições para garantir de que está ordenado, se não estiver ele troca
  for (int i = 0; i < arraySize; i++)
  {
    for (int j = 0; j < arraySize - 1; j++)
    {
      if (array[j] > array[j + 1]) // > ascending, < descending
      {
        swap(array[j], array[j + 1]);
      }
    }
  }

  cout << "Sorted Array" << endl;
  for (int i = 0; i < arraySize; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
