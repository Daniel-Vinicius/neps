#include <bits/stdc++.h>

using namespace std;

// Imprima um único inteiro, a quantidade de números inteiros positivos menores ou iguais a N que não são divisíveis por nenhum número na lista.

// % num != 0

bool isDivisible(long long int n, vector<long long int> numsToTest)
{
  for (int i = 0; i < numsToTest.size(); i++)
  {
    if (n % numsToTest[i] == 0)
    {
      return true;
    }
  }

  return false;
}

int main()
{

  long long int N, K;
  cin >> N >> K;

  vector<long long int> numsToTest(K);
  for (int i = 0; i < K; i++)
    cin >> numsToTest[i];

  long long int ans = 0;

  for (long long int i = numsToTest[1]; i > 0; i--)
  {
    // cout << i << " " << i << numsToTest[0] << "\n";
    if (i > numsToTest[0])
    {
      ans++;
      continue;
    }
    if (isDivisible(i, numsToTest) == false)
    {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// vector<ll> primes;
// ll n, k, ans;
// void solve(ll prod, int tamanho, int i){
// 	if(i >= k or n/prod == 0) return;
// 	if((tamanho + 1) % 2 == 0) ans += n/(prod*primes[i]);
// 	else ans -= n/(prod*primes[i]);
// 	solve(prod*primes[i], tamanho + 1, i + 1); // COLOCA
// 	solve(prod, tamanho, i+1); // NAO COLOCA
// }
// int32_t main(){
// 	ios::sync_with_stdio(false); cin.tie(0);
// 	cin>>n>>k;
// 	primes.resize(k);
// 	for(int i = 0; i < k; i++) cin>>primes[i];
// 	solve(1, 1, 0);
// 	cout<<n-ans<<"\n";
// }
