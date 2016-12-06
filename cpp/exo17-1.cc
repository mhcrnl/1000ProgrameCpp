#include <iostream>
using namespace std;

double scalaire(double u[], double v[], int taille);

int main()
{
  const int N_MAX(10);
  double a[N_MAX];
  double b[N_MAX];

  int n;
  do {
    cout << "Quelle taille pour les vecteurs [1 à " << N_MAX <<"] ? ";
    cin >> n;
  } while ((n < 1) || (n > N_MAX));

  cout << "Saisie du premier vecteur :" << endl;
  for (int i(0); i < n; ++i) {
    cout << " a[" << i << "] = ";
    cin >> a[i];
  }

  cout << "Saisie du second vecteur :" << endl;
  for (int i(0); i < n; ++i) {
    cout << " b[" << i << "] = ";
    cin >> b[i];
  }

  cout << "le produit scalaire de a par b vaut "
       << scalaire(a, b, n) << endl;
  return 0;
}

double scalaire(double u[], double v[], int taille)
{
  double somme(0.0);
  for (int i(0); i < taille; ++i)
    somme += u[i] * v[i];
  return somme;
}
