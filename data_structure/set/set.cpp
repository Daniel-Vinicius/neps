#include <iostream>
#include <set>

using namespace std;

int main()
{
  // sem duplicatas, ordem crescente, imutável, apenas remoção e adição, O(log n)
  set<int> st;

  st.insert(10);
  st.insert(1);
  st.insert(4);
  st.insert(6);
  st.insert(1); // não insere novamente, retornará uma referência para o elemento que já foi inserido.

  st.erase(4); // Como os elementos do Set também são sua própria chave podemos simplesmente passar como parâmetro para a função erase qual elemento desejamos remover, caso ele exista, ele será removido.

  auto pointer = st.begin(); // O(1)

  cout << *pointer << endl; // menor elemento, no caso 1, mas caso o set fosse set<int, greater<int>> st; retornaria 10

  auto pointerEnd = st.end(); // O(1)
  pointerEnd--;

  cout << *pointerEnd << endl;
  cout << "size(): " << st.size() << endl;

  st.clear(); // O(n)

  if (st.find(10) != st.end())
    cout << "10 existe" << endl;
  else
    cout << "10 não existe" << endl;

  return 0;
}
