#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n log n)

// Para o oitavo elemento 60:
// piles: [10, 22, 33, 41, 60]
// topIdxs: [0, 1, 2, 3, 4, 0, 0, 0]
// Tamanho da subsequência crescente (comprimento da pilha mais longa): 5
vector<int> lis(vector<int> &nums)
{
  int n = nums.size();
  vector<int> piles;      // vetor que representa as pilhas das subsequências crescentes
  vector<int> topIdxs(n); // vetor para armazenar os índices do topo das pilhas

  for (int i = 0; i < n; i++)
  {
    int num = nums[i];
    // A busca binária é usada para encontrar a posição correta onde o elemento atual deve ser inserido na subsequência. Isso é feito por meio da função lower_bound, que encontra o primeiro elemento maior do que o elemento atual na subsequência.
    auto it = lower_bound(piles.begin(), piles.end(), num);
    int idx = it - piles.begin(); // idx é a posição em que o elemento atual deve ser inserido no vetor piles, caso não exista um elemento igual a ele.
    topIdxs[i] = idx;
    if (it == piles.end())
      piles.push_back(num); // se o elemento atual for maior que todos os elementos nas pilhas, ele é adicionado como nova pilha
    else
      *it = num; // se o elemento atual pode ser inserido em uma pilha existente, ele substitui o elemento naquela posição
  }

  int len = piles.size();
  vector<int> result(len);
  for (int i = n - 1; i >= 0; i--) // back to front, "reverse"
  {
    if (topIdxs[i] == len - 1) // verifica se o elemento no índice i está no topo da pilha de maior comprimento
    {
      result[len - 1] = nums[i]; // adiciona o elemento à subsequência resultante
      len--;                     // decrementa o comprimento da subsequência
    }
  }

  return result; // retorna a subsequência crescente resultante
}

int main()
{
  vector<int> nums = {10, 22, 22, 33, 21, 50, 41, 60};
  vector<int> lisResult = lis(nums);

  cout << "Longest Increasing Subsequence: ";
  for (int num : lisResult)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
