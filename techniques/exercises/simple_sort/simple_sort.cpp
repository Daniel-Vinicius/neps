#include <bits/stdc++.h>

using namespace std;

// 5 minutes

int main()
{
  long long int arraySize;
  cin >> arraySize;

  long long int array[arraySize];
  for (int i = 0; i < arraySize; ++i)
  {
    long long int n;
    cin >> n;
    array[i] = n;
  }

  for (int i = 0; i < arraySize; i++)
  {
    for (int j = 0; j < arraySize - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap(array[j], array[j + 1]);
      }
    }
  }

  for (int i = 0; i < arraySize; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
