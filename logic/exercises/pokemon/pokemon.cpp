#include <bits/stdc++.h>

using namespace std;

int main()
{
  int candyQuantity;
  cin >> candyQuantity;
  int firstPokemon, secondPokemon, thirdPokemon;
  cin >> firstPokemon >> secondPokemon >> thirdPokemon;

  if (candyQuantity >= firstPokemon + secondPokemon + thirdPokemon)
  {
    cout << 3 << endl;
    return 0;
  }

  int smallerPokemon = min(min(firstPokemon, secondPokemon), thirdPokemon);
  int biggerPokemon = max(max(firstPokemon, secondPokemon), thirdPokemon);
  int midPokemon = 0;
  if (smallerPokemon != firstPokemon && biggerPokemon != firstPokemon)
    midPokemon = firstPokemon;
  if (smallerPokemon != secondPokemon && biggerPokemon != secondPokemon)
    midPokemon = secondPokemon;
  if (smallerPokemon != thirdPokemon && biggerPokemon != thirdPokemon)
    midPokemon = thirdPokemon;

  if (candyQuantity >= smallerPokemon + midPokemon)
  {
    cout << 2 << endl;
    return 0;
  }
  if (candyQuantity >= smallerPokemon)
  {
    cout << 1 << endl;
    return 0;
  }
  else
  {
    cout << 0 << endl;
  }

  return 0;
}
