#include <iostream>
using namespace std;

class EnsembleFini {
public:
  EnsembleFini(unsigned int p) : p(p) {}
protected:
  unsigned int p;
};

class Groupe : public EnsembleFini {
public:
  Groupe(unsigned int p) : EnsembleFini(p) {}

  unsigned int add(unsigned int x, unsigned int y) const {
    return (x+y) % p;
  }
};

class Anneau : public Groupe {
public:
  Anneau(unsigned int p) : Groupe(p) {}
  unsigned int mult(unsigned int x, unsigned int y) const {
    return (x*y) % p;
  }
};

class Corps : public Anneau {
public:
  Corps(unsigned int p) : Anneau(p) {}
  unsigned int inv(unsigned int x) const;
  unsigned int div(unsigned int x, unsigned int y) const {
    return mult(x, inv(y));
  }
};

unsigned int Corps::inv(unsigned int x) const {
  // algorithme d'Euclide

  if (x != 0) {
    int prev_u(1), y(p), u(0), new_u, q, r;

    while (y != 1) {
      q = x/y;
      r = x%y;
      x = y;
      y = r;
      new_u = prev_u - q * u;
      prev_u = u;
      u = new_u;
    }

    return (u + p) % p; // u%p seul n'est pas correct car ne
                        // fonctionne pas pour des questions de signe
  }

  else
    return 0; // mieux: lever une exception ici
}


int main()
{
  Corps k(5); // c'est le corps Z/5Z

  cout << "0 + 1 = " << k.add(0, 1)  << endl;
  cout << "3 + 3 = " << k.add(3, 3)  << endl;
  cout << "3 * 2 = " << k.mult(3, 2) << endl;
  cout << "1/2 = "   << k.inv(2)     << endl;
  cout << "3 * 4 = " << k.mult(3, 4) << endl;

  return 0;
}
