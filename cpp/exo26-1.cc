#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<double> > Matrice;

Matrice*  lire_matrice();
void      affiche_matrice(const Matrice* M);
Matrice*  multiplication(const Matrice* M1, const Matrice* M2);

int main()
{
  Matrice* M1(0);
  Matrice* M2(0);
  Matrice* M(0);

  M1 = lire_matrice();
  M2 = lire_matrice();

  if ((*M1)[0].size() != (*M2).size())
    cout << "Multiplication de matrices impossible !" << endl;
  else {
    cout << "Resultat :" << endl;
    M = multiplication(M1, M2);
    delete M1;
    delete M2;
    affiche_matrice(M);
    delete M;
  }
  return 0;
}

// --------------------------------------------------------------------
Matrice* lire_matrice()
{
  cout << "Saisie d'une matrice :" << endl;

  unsigned int lignes;
  do {
    cout << "  Nombre de lignes : ";
    cin >> lignes;
  } while (lignes < 1);

  unsigned int colonnes;
  do {
    cout << "  Nombre de colonnes : ";
    cin >> colonnes;
  } while (colonnes < 1);

  Matrice* M(new Matrice(lignes, vector<double>(colonnes)));

  for (unsigned int i(0); i < lignes; ++i)
    for (unsigned int j(0); j < colonnes; ++j) {
      cout << "  M[" << i+1 << "," << j+1 << "]=";
      cin >> (*M)[i][j];
    }

  return M;
}

// --------------------------------------------------------------------
Matrice* multiplication(const Matrice* M1, const Matrice* M2)
{
  Matrice* prod(new Matrice((*M1).size(), (*M2)[0].size()));

  for (unsigned int i(0); i < (*M1).size(); ++i)
    for (unsigned int j(0); j < (*M2)[0].size(); ++j) {
      (*prod)[i][j] = 0.0;
      for (unsigned int k(0); k < (*M2).size(); ++k)
        (*prod)[i][j] += (*M1)[i][k] * (*M2)[k][j];
    }

  return prod;
}

// --------------------------------------------------------------------
void affiche_matrice(const Matrice* M)
{
  for (unsigned int i(0); i < (*M).size(); ++i) {
    for (unsigned int j(0); j < (*M)[i].size(); ++j)
      cout << (*M)[i][j] << " ";
    cout << endl;
    }
}
