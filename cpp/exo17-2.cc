#include <iostream>
#include <string>
using namespace std;

double scalaire(double u[], double v[], unsigned int taille);
void saisie(const string& titre, double vecteur[],  unsigned int taille);

int main()
{
  const unsigned int N_MAX(10);
  double a[N_MAX];
  double b[N_MAX];

  unsigned int n;
  do {
    cout << "Quelle taille pour les vecteurs [1 a " << N_MAX <<"] ? ";
    cin >> n;
  } while ((n < 1) || (n > N_MAX));

  saisie("premier", a, n);
  saisie("second",  b, n);

  cout << "le produit scalaire de a par b vaut "
       << scalaire(a, b, n) << endl;
}

// --------------------------------------------------------

double scalaire(double u[], double v[], unsigned int taille)
{
  double somme(0.0);
  for (unsigned int i(0); i < taille; ++i)
    somme += u[i] * v[i];
  return somme;
}

// --------------------------------------------------------

void saisie(const string& titre, double vecteur[], unsigned int taille)
{
  cout << "Saisie du " << titre << " vecteur :" << endl;
  for (unsigned int i(0); i < taille; ++i) {
    cout << " coordonnee " << i+1 << " = ";
    cin >> vecteur[i];
  }
}
