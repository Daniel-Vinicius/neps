#include <iostream>
#include <queue>

using namespace std;

int main()
{
  // Declarando uma Fila de Prioridade
  // less -> maior no topo (default)
  // greater -> menor no topo
  priority_queue<int, vector<int>, less<int>> pq;

  // a inserção em si é O(1), mas a estrutura precisa determinar se o elemento no topo deve mudar, segundo o critério de comparação da estrutura, e isso é feito em O(logn)
  pq.push(7);
  pq.push(5);
  pq.push(1); // O(log n)
  pq.push(4);

  cout << "size(): " << pq.size() << endl;
  // O elemento no topo: O(1)
  cout << "top(): " << pq.top() << endl;

  cout << "pop()" << endl;
  pq.pop(); // O(log n) remove o elemento no topo

  // O(1)
  cout << "size(): " << pq.size() << endl;
  cout << "top(): " << pq.top() << endl;

  return 0;
}
