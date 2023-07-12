#include <iostream>
using namespace std;

// O(2^n) Exponencial, não usa memoization nem dynamic programming
// https://recursion.vercel.app/

long long int backtracking(long long int i) // Essa função irá retornar o i-ésimo termo da sequência de Fibonacci
{
  if (i == 1 || i == 2)
    return 1; // Caso base da recursão
  // caso base é um caso em que não é preciso chamar a recursão para calcular

  return backtracking(i - 1) + backtracking(i - 2);
}

int main()
{
  int n;

  // Lê o índice do termo de Fibonacci que queremos saber
  cin >> n;

  cout << "N-ésimo termo de Fibonacci: " << backtracking(n) << endl;
}