
#include <iostream>
using namespace std;

unsigned int bidule(unsigned int x, unsigned int y)
{
  unsigned int z(0);

  while (y >= 1) {
    if ((y % 2) == 0) {
      x = x * 2;

      // ...code manquant 1...
        y=y/2;
    } else {
      z = z + x;

      // ...code manquant 2...
        y=y-1;
    }
  }
  return z + 1;
}

int main()
{
  unsigned int a(3);
  cout << "Resultat : " << bidule(a + 2, 2 * a) << endl;
  return 0;
  }
