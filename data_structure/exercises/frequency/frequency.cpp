#include <bits/stdc++.h>

using namespace std;

int main()
{
  map<int, int> chamada;
  int qtd_registros;
  cin >> qtd_registros;

  // contar apenas os não repetidos
  int ans = 0;
  int n;
  while (cin >> n)
  {
    if (chamada.find(n) == chamada.end())
    {
      ans++;
    }
    chamada.insert({n, n});
  }

  cout << ans << endl;
  return 0;
}
