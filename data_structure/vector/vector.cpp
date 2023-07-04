#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> _v)
{
  for (auto n : _v)
  {
    cout << n << " ";
  }
  cout << endl;
};

int main()
{

  vector<int> v = {1, 2, 3};

  auto ptr = v.begin(); // O(1)

  cout << *ptr << endl;

  // end(): retorna um ponteiro (referência) para o final do vector, note que não estamos nos referindo ao último elemento, mas sim a referência na memória que indica o final do vector.
  auto ptr2 = v.end();
  ptr2--; // 3
  // ptr2--; // 2

  cout << *ptr2 << endl;

  cout << "size(): " << v.size() << endl;
  v.resize(10, 0);
  cout << "resize(), new size is: " << v.size() << endl; // O(n)

  print(v);

  v.clear(); // O(n)
  cout << "size(): " << v.size() << endl;

  v.push_back(7); // insere no final
  v.push_back(5); // O(1)
  print(v);

  v.insert(v.begin() + 1, 6); // colocando o 6 entre o 7 e o 5
  v.insert(v.begin() + 3, 1); // O(n)

  print(v);               // 7 6 5 1
  v.erase(v.begin() + 3); // O(n)
  v.erase(v.begin() + 0); // O(n)
  print(v);               // 6 5
  v.pop_back();           // remove no final O(1)
  print(v);               // 6

  cout << v[0] << endl; // 6

  return 0;
}
