#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

// classe representant un ensemble fini d'éléments
// Ceux qui connaissent la STL préfèront ici utiliser set<>
class EnsembleFini : private vector<char> {
public:
  EnsembleFini() {}
  EnsembleFini(char taille);

  void ajoute(char);
  void supprime(char);
  bool element(char);
};

EnsembleFini::EnsembleFini(char taille) {
  if (taille > char(256) - 'a') taille = char(256) - 'a';
  for (char element('a'); char(size()) < taille; push_back(++element));
}

bool EnsembleFini::element(char x) {
  bool absent(true);
  for (unsigned int i(0); (i < size()) && absent; ++i)
    if ((*this)[i] == x) absent = false;
  return !absent;
}

void EnsembleFini::ajoute(char x) {
  if (!element(x)) push_back(x);
}

void EnsembleFini::supprime(char x) {
  unsigned int i;
  for (i = 0; (i < size()) && ((*this)[i] != x); ++i);
  if (i < size()) {
    ++i;
    while (i < size()) (*this)[i-1] = (*this)[i];
    pop_back();
  }
}

class Groupe : public EnsembleFini {
public:
  Groupe(char (*f)(char, char) = 0) { add = f;}
  Groupe(char taille, char (*f)(char, char) = 0) : EnsembleFini(taille)
  { add = f; }

  void setadd(char (*f)(char, char)) { add = f; }
  char (*add)(char, char);
};

class Anneau : public Groupe {
public:
  Anneau() : Groupe() { mult = 0; }
  Anneau(char (*f)(char, char), char (*g)(char, char))
    : Groupe(f) { mult = g; }
  Anneau(char taille) : Groupe(taille) { mult = 0; }
  Anneau(char taille, char (*f)(char, char), char (*g)(char, char)) 
    : Groupe(taille, f) { mult = g; }

  void setmult(char (*f)(char, char)) { mult = f; }
  char (*mult)(char, char);
};

class Corps : public Anneau {
public:
  Corps() : Anneau() { inv = 0; }
  Corps(char (*f)(char, char), char (*g)(char, char), char (*h)(char))
    : Anneau(f,g) { inv = h; }
  Corps(char taille) : Anneau(taille) { inv = 0; }
  Corps(char taille, char (*f)(char, char), char (*g)(char, char), 
        char (*h)(char)) 
    : Anneau(taille, f, g) { inv = h; }

  void setinv(char (*f)(char)) { inv = f; }
  char (*inv)(char);
  char div(char x, char y) const { return mult(x, inv(y)); }
};

char add1(char x, char y) {
  if (x == 'a') // element neutre
    return y;

  if (y == 'a') // element neutre
    return x;

  switch (x) {
  case 'b':
    switch (y) {
    case 'b': return 'a';
    case 'c': return 'e';
    case 'd': return 'f';
    case 'e': return 'c';
    case 'f': return 'd';
    }
  case 'c':
    switch (y) {
    case 'b': return 'd';
    case 'c': return 'a';
    case 'd': return 'b';
    case 'e': return 'f';
    case 'f': return 'e';
    }
  case 'd':
    switch (y) {
    case 'b': return 'c';
    case 'c': return 'f';
    case 'd': return 'e';
    case 'e': return 'a';
    case 'f': return 'b';
    }
  case 'e':
    switch (y) {
    case 'b': return 'f';
    case 'c': return 'b';
    case 'd': return 'a';
    case 'e': return 'd';
    case 'f': return 'c';
    }
  case 'f':
    switch (y) {
    case 'b': return 'e';
    case 'c': return 'd';
    case 'd': return 'c';
    case 'e': return 'b';
    case 'f': return 'a';
    }
  default:
    return 'a'; // lever une exception ici
  }
}

int main()
{
  Groupe S3(6, add1);

  cout << "a + b + b = " << S3.add('a', S3.add('b', 'b')) << endl;
  cout << "c + d + e = " << S3.add('c', S3.add('d', 'e')) << endl;

  return 0;
}
