#include <bits/stdc++.h>

using namespace std;

// set

// unica troca

// n_maximo trocas

int main()
{
  int n_cartas_A;
  int n_cartas_B;

  cin >> n_cartas_A >> n_cartas_B;

  set<int> cartasA;
  set<int> cartasB;
  map<int, int> trocasA;
  map<int, int> trocasB;

  for (int i = 0; i < n_cartas_A; i++)
  {
    int c;
    cin >> c;
    cartasA.insert(c);
  }

  for (int i = 0; i < n_cartas_B; i++)
  {
    int c;
    cin >> c;
    cartasB.insert(c);
  }

  int n_maximo_trocas = 0;

  for (int i = 0; i < cartasA.size(); i++)
  {
    int a = 0;
    auto cardA = cartasA.begin();
    while (a != i)
    {
      cardA++;
      a++;
    }

    if (cartasB.find(*cardA) == cartasB.end() && trocasA.find(*cardA) == trocasA.end())
    {
      for (int i = 0; i < n_cartas_B; i++)
      {
        int b = 0;
        auto cardB = cartasB.begin();
        while (b != i)
        {
          cardB++;
          b++;
        }

        if (cartasA.find(*cardB) == cartasA.end())
        {
          trocasA.insert({*cardA, *cardB});
          trocasB.insert({*cardB, *cardA});
          n_maximo_trocas++;
        }
      }
    }
  }

  cout << min(trocasA.size(), trocasB.size()) << endl;

  // auto pointer = cartasA.begin();
  // for (int i = 0; i < n_cartas_A; i++)
  // {
  //   cout << *pointer << " ";
  //   pointer++;
  // }

  // cout << endl;

  // auto pointer2 = cartasB.begin();
  // for (int i = 0; i < n_cartas_B; i++)
  // {
  //   cout << *pointer2 << " ";
  //   pointer2++;
  // }
  // cout << endl;

  return 0;
}
