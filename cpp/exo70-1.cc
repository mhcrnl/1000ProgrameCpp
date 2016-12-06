#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------------------------
// declaration de la classe generique
template<typename type> class Matrice;

// --------------------------------------------------------------------
// operateur generique d'affichage pour la classe Matrice
template<typename type>
ostream& operator<<(ostream& output,  const Matrice<type>& M)
{
  for (unsigned int i(0); i < M.size(); ++i) {
    for (unsigned int j(0); j < M[i].size(); ++j)
      output << M[i][j] << " ";
    output << endl;
    }
  return output;
}

// --------------------------------------------------------------------
// operateur generique de saisie
template<typename type>
istream& operator>>(istream& input, Matrice<type>& M)
{
  const unsigned int lignes(M.size());

  if (lignes != 0) {
    const unsigned int colonnes(M[0].size());

    M.clear();
    for (unsigned int i(0); i < lignes; ++i) {
      M.push_back(vector<type>(colonnes));

      for (unsigned int j(0); j < colonnes; ++j) {
        input >> M[i][j];
      }
    }
  }

  return input;
}

// --------------------------------------------------------------------
// definition de la classe generique Matrice
template<typename type>
class Matrice : public vector< vector<type> > {
public:
  // un nouveau type pour les exceptions
  enum error { WRONG_SIZES };

  Matrice() {}
  Matrice(unsigned int n, unsigned int m, type val = type())
    : vector<vector<type> >(n, vector<type>(m, val)) {}
  virtual ~Matrice() {}

  Matrice& operator*=(const Matrice&) throw (error);
  Matrice  operator*(const Matrice& right) const {
    return (Matrice(*this) *= right);
  }
};

// --------------------------------------------------------------------
template<typename type>
Matrice<type>& Matrice<type>::operator*=(const Matrice<type>& M2)
 throw (error)
{
  if ((*this)[0].size() != M2.size()) throw WRONG_SIZES;

  Matrice M1(*this);

  clear();
  for (unsigned int i(0); i < M1.size(); ++i) {
    push_back(vector<type>(M2[0].size()));

    for (unsigned int j(0); j < M2[0].size(); ++j) {
      (*this)[i][j] = type(); // = 0
      for (unsigned int k(0); k < M2.size(); ++k)
        (*this)[i][j] += M1[i][k] * M2[k][j];
    }
  }

  return *this;
}

// --------------------------------------------------------------------
Matrice<double> saisie_matrice() {
  cout << "Saisie d'une matrice :" << endl;
  cout << "  Nombre de lignes : ";
  unsigned int n;
  cin >> n;
  cout << "  Nombre de colonnes : ";
  unsigned int m;
  cin >> m;

  Matrice<double> M(n,m);
  cout << "Entrez la matrice :" << endl;
  cin >> M;

  return M;
}

// --------------------------------------------------------------------
int main()
{
  Matrice<double> M1(saisie_matrice());
  Matrice<double> M2(saisie_matrice());
  Matrice<double> M;

  try {
    M = M1 * M2;
    cout << "Resultat :" << endl << M << endl;
  }
  catch (Matrice<double>::error e) {
    switch (e) {
    case Matrice<double>::WRONG_SIZES:
      cerr << "Multiplication de matrices impossible !" << endl;
      break;
    }
  }

  return 0;
}
