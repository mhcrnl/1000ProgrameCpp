#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<double> > Matrice;

Matrice& lire_matrice(Matrice& lue);
void     affiche_matrice(const Matrice& M);
Matrice& multiplication(const Matrice& M1, const Matrice& M2, Matrice& resultat);

// --------------------------------------------------------------------
int main()
{
  Matrice M1, M2, M;
  lire_matrice(M1);
  lire_matrice(M2);

  if (M1[0].size() != M2.size())
    cout << "Multiplication de matrices impossible !" << endl;
  else {
    cout << "Resultat :" << endl;
    affiche_matrice(multiplication(M1, M2, M));
  }
  return 0;
}
// --------------------------------------------------------------------
Matrice& lire_matrice(Matrice& M)
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

  M.clear();
  for (unsigned int i(0); i < lignes; ++i) {
    M.push_back(vector<double>(colonnes));

    for (unsigned int j(0); j < colonnes; ++j) {
      cout << "  M[" << i+1 << "," << j+1 << "]=";
      cin >> M[i][j];
    }
  }

  return M;
}

// --------------------------------------------------------------------
Matrice& multiplication(const Matrice& M1, const Matrice& M2, Matrice& prod)
{
  prod.clear();
  for (unsigned int i(0); i < M1.size(); ++i) {
    prod.push_back(vector<double>(M2[0].size(), 0.0));

    for (unsigned int j(0); j < M2[0].size(); ++j) {
      for (unsigned int k(0); k < M2.size(); ++k)
        prod[i][j] += M1[i][k] * M2[k][j];
    }
  }

  return prod;
}

// --------------------------------------------------------------------
void  affiche_matrice(const Matrice& M)
{
  for (unsigned int i(0); i < M.size(); ++i) {
    for (unsigned int j(0); j < M[i].size(); ++j)
      cout << M[i][j] << " ";
    cout << endl;
  }
}
