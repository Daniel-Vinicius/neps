#include <iostream>
#include <queue>

using namespace std;

int main()
{
  queue<int> q;
  q.push(1); // O(1)
  q.push(2);
  q.push(3);

  // front -> mais antigo - O(1)
  // back -> mais novo - O(1)
  cout << q.front() << " " << q.back() << endl;

  q.pop(); // remove mais antigo - O(1)
  cout << q.front() << " " << q.back() << endl;

  // size -> tamanho fila - O(1)
  cout << q.size() << endl;

  return 0;
}
