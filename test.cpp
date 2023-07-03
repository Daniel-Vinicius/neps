#include <iostream>
#include <cmath>

int main()
{
  int n = 122;
  int root = 1;

  while (root * root <= n)
  {
    root++;
  }

  root--;

  std::cout << "A raiz quadrada de " << n << " é: " << root << std::endl;

  return 0;
}
