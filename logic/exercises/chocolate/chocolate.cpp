#include <bits/stdc++.h>
using namespace std;

int N;
int X1, Y1, X2, Y2;

int quadrante(int X, int Y)
{
  if (X > N / 2 && Y > N / 2)
    return 1;
  if (X <= N / 2 && Y > N / 2)
    return 2;
  if (X <= N / 2 && Y <= N / 2)
    return 3;
  else
    return 4;
}

int main()
{

  cin >> N;
  cin >> X1 >> Y1 >> X2 >> Y2;
  if (quadrante(X1, Y1) == quadrante(X2, Y2))
  {
    cout << "N" << endl;
  }
  else
  {
    cout << "S" << endl;
  }
}
