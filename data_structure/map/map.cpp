#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<char, int> mp;

  // Caso tente inserir dois elementos com uma mesma chave, por definição da estrutura, não será feita a segunda inserção de um elemento com chave repetida.
  // Ao invés disso, é retornado uma referência para o elemento que foi inserido primeiro.
  mp.insert({'a', 1}); // O(log n)
  mp.insert({'b', 2});
  mp.insert({'c', 3});

  auto iteratorFirstElement = mp.begin(); // O(1)
  auto iteratorLastElement = mp.end();    // O(1)
  iteratorLastElement--;

  cout << "Chave: " << iteratorFirstElement->first << iteratorFirstElement->second << endl;
  cout << "Chave: " << iteratorLastElement->first << iteratorLastElement->second << endl;
  cout << "size(): " << mp.size() << endl;

  mp.erase('c'); // O(log n)

  auto iteratorLastElement2 = mp.end(); // O(1)
  iteratorLastElement2--;
  cout << "erase('c'), new size: " << mp.size() << " - new last element: " << iteratorLastElement2->first << iteratorLastElement2->second << endl;

  mp.clear(); // O(n)
  cout << "clear(), new size: " << mp.size() << endl;

  mp.insert({'a', 1});
  mp.insert({'b', 2});
  mp.insert({'c', 3});

  cout << endl
       << "find('c')" << endl;

  if (mp.find('c') != mp.end()) // find() -> O(log n)
    cout << "c existe" << endl;
  else
    cout << "c não existe" << endl;

  // []: é o operador de acesso direto. O(log n)
  cout << endl
       << "[]:" << endl;
  cout << "acessar ['a'] -> " << mp['a'] << endl; // acessar

  mp['d'] = 4; // criar
  cout << "criar ['d'] = 4 -> " << mp['d'] << endl;

  mp['a'] = 5; // modificar
  cout << "modificar ['a'] = 5 -> " << mp['a'] << endl;

  //  função find, a diferença é que o [] quando o elemento não existe ele irá alocar espaço e criar o elemento no Mapa.
  //  Já o find não cria o elemento, assim o find não muda a estrutura, já o [] irá alterar.

  return 0;
}
