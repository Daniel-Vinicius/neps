#include <bits/stdc++.h>

using namespace std;

// 26 minutes

void merge(int start, int end, vector<int> &array, int asc_desc)
{
  int mid = (start + end) / 2;
  int p1 = start;
  int p2 = mid + 1;

  vector<int> S;

  while (p1 <= mid && p2 <= end)
  {
    if (array[p1] <= array[p2])
    {
      if (asc_desc == 1)
      {
        S.push_back(array[p1]);
        p1++;
      }
      else
      {
        S.push_back(array[p2]);
        p2++;
      }
    }
    else
    {
      if (asc_desc == 1)
      {
        S.push_back(array[p2]);
        p2++;
      }
      else
      {
        S.push_back(array[p1]);
        p1++;
      }
    }
  }

  while (p1 <= mid)
  {
    S.push_back(array[p1]);
    p1++;
  }

  while (p2 <= end)
  {
    S.push_back(array[p2]);
    p2++;
  }

  for (int i = 0; i < S.size(); i++)
  {
    array[start + i] = S[i];
  }
}

void mergeSort(int start, int end, vector<int> &array, int asc_desc)
{
  int mid = (start + end) / 2;

  if (start < end)
  {
    mergeSort(start, mid, array, asc_desc);
    mergeSort(mid + 1, end, array, asc_desc);
    merge(start, end, array, asc_desc);
  }
}

int main()
{
  int N;
  cin >> N;
  vector<int> array;

  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;
    array.push_back(n);
  }

  mergeSort(0, N - 1, array, 1);

  for (int i = 0; i < N; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
