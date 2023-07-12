#include <iostream>
using namespace std;

const int MAXN = 200;

// O(n) -> Dynamic Programming Recursiva com Memoization
// Se comparar com o backtracking saímos de uma complexidade exponencial para uma linear
// Isso foi possível devido ao uso da memoization e da dynamic programming, não fazendo recálculos desnecessários
// Aqui é muito mais fácil conseguir calcular números maiores da sequência como 50 por exemplo, que eram extremamente lentos de se calcular no algoritmo anterior

long long int dp[MAXN]; // dp[i] = i-ésimo termo da sequência de Fibonacci
// Inicialmente, todos os valores da dp são 0

long long int solve(long long int i)
{
  if (dp[i] != 0) // Primeiro passo
    return dp[i];

  if (i == 1 || i == 2) // Segundo passo
    return 1;

  dp[i] = solve(i - 1) + solve(i - 2); // Terceiro passo
  return dp[i];
}

int main()
{
  int n;

  cin >> n;

  cout << "N-ésimo termo de Fibonacci: " << solve(n) << endl;
}