#include <iostream>
using namespace std;

const int MAXN = 1000010;

int parent[MAXN], _size[MAXN];

int find(int value)
{
  if (parent[value] == value)
    return value;
  return parent[value] = find(parent[value]);
}

void merge(int i, int j)
{
  i = find(i);
  j = find(j);

  if (i == j)
    return;

  if (_size[i] >= _size[j])
  {
    parent[j] = i;
    _size[i] += _size[j];
  }
  else
  {
    parent[i] = j;
    _size[j] += _size[i];
  }
}

// Almost O(1) - DSU (Disjoint Set Union) ou Union Find
int main()
{
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
  {
    _size[i] = 1;
    parent[i] = i;
  }

  for (int i = 0; i < q; i++)
  {
    int type, a, b;
    cin >> type >> a >> b;

    if (type == 1)
    {
      merge(a, b);
      cout << "Merge between: " << a << " and " << b << endl;
    }
    else
    {
      if (find(a) == find(b))
        cout << a << " and " << b << " are in same sets" << endl;
      else
        cout << a << " and " << b << " are in different sets" << endl;
    }
  }
}