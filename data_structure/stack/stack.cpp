#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> pilha;

  pilha.push(1); // O(1)
  pilha.push(2);
  pilha.push(3);
  pilha.push(4);

  cout << pilha.top() << endl;
  pilha.pop();

  cout << pilha.top() << endl;
  pilha.pop();

  cout << "size(): " << pilha.size() << endl;
  cout << endl;
  cout << "swap()" << endl;

  stack<int> pares;
  stack<int> impares;
  pares.push(2);
  pares.push(4);
  pares.push(6);
  impares.push(1);
  impares.push(3);
  impares.push(5);

  pares.swap(impares);

  cout << "pares: " << endl;
  while (!pares.empty())
  {
    cout << pares.top() << " ";
    pares.pop();
  }
  cout << endl;

  cout << "impares: " << endl;
  while (!impares.empty())
  {
    cout << impares.top() << " ";
    impares.pop();
  }
  cout << endl;

  return 0;
}
