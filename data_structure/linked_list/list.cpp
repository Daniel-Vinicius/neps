// #include <bits/stdc++.h>

#include <iostream>
// Biblioteca com a implementação da lista
#include <list>

using namespace std;

int main()
{
  list<int> l = {1, 2, 3};
  // O auto é o tipo automático do C++, ou seja, ele é resolvido em tempo de compilação
  auto firstItem = l.begin();
  // precisa do * porque begin retorna um ponteiro
  cout << *firstItem << endl; // O(1) => 1

  list<string> listOfNames = {"Daniel", "Carlos", "Ana"};
  auto lastItem = listOfNames.end();
  // lastItem tem a referência para o final da lista (NULL)
  // Vamos acessar o último elemento da lista, para isso, basta retroceder o point 1 posição
  lastItem--;
  cout << *lastItem << endl; // O(1) => "Ana"

  list<int> list3 = {1, 2, 3};
  cout << list3.size() << endl;
  // Apagando a lista
  list3.clear();
  cout << list3.size() << endl;

  // insert() --> O(1), porém buscar o elemento a para realizar a inserção é O(n)
  list<int> listTest = {1, 2, 3};
  auto pointer = listTest.begin(); // isso retorna um ponteiro
  int pos = 1;
  // mover o ponteiro até a segunda posição
  while (pos != 2)
  {
    pos++;
    pointer++;
  }

  listTest.insert(pointer, 10);

  // imprimindo lista através de um for each
  for (auto element : listTest)
    cout << element << " ";
  cout << "<-- insert()" << endl;

  // erase() --> O(1), porém buscar o elemento a para realizar a inserção é O(n)
  pos = 1;
  auto pointer2 = listTest.begin();
  while (pos != 4)
  {
    pos++;
    pointer2++;
  }

  listTest.erase(pointer2); // apagando o 3, elemento na posição 4

  // imprimindo lista através de um for each
  for (auto element : listTest)
    cout << element << " ";
  cout << "  <-- erase()" << endl;

  // Erase Carlos from listOfNames
  pos = 1;
  auto pointerCarlos = listOfNames.begin();
  while (pos != 2)
  {
    pos++;
    pointerCarlos++;
  }
  listOfNames.erase(pointerCarlos);

  // imprimindo lista através de um for each
  for (auto element : listOfNames)
    cout << element << " ";
  cout << "  <-- Não tem mais Carlos" << endl;

  return 0;
}
