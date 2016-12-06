#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int pgcd(int a, int b); // prototype
int demander_nombre(int min, int max);

int main()
{
  int a(demander_nombre(1,0));
  int b(demander_nombre(1,0));
  cout << "PGCD(" << a << "," << b << ")=" << pgcd(a,b) << endl;
  return 0;
}

// Definition de PCDG
int pgcd(int a, int b)
{
  int prev_u(1), prev_v(0), x(a), y(b), u(0), v(1);
  int new_u, new_v, q, r;

  cout << "Calcul du PGCD de " << a << " et " << b << endl;
  cout << endl;
  cout << setw(10) << 'x'
       << setw(10) << 'y'
       << setw(10) << 'u'
       << setw(10) << 'v'
       << endl;

    cout << setw(10) << x << setw(10) << y
         << setw(10) << u << setw(10) << v
         << endl;

  while (y != 0) {
    q = x/y;
    r= x%y;
    x = y;
    y = r;
    new_u = prev_u - u * q;
    prev_u = u;
    u = new_u;
    new_v = prev_v - v * q;
    prev_v = v;
    v = new_v;

    cout << setw(10) << x << setw(10) << y
         << setw(10) << u << setw(10) << v
         << endl;
  }

  return x;
}

// --------------------------------------------------------------
// fonction demandant a l'utilisateur un nombre compris
// dans un intervalle [a, b], ou superieur ou egal a a
// si b < a.
// Entree : les deux nombres a et b definissant l'intervalle
// Sortie : le nombre saisi par l'utilisateur
// --------------------------------------------------------------
int demander_nombre(int a, int b)
{
  int res;
  bool erreur;

  do {
    erreur = false;
    cout << "Entrez un nombre entier ";
    if (a >= b) cout << "superieur ou egal a " << a;
    else cout << "compris entre " << a << " et " << b;
    cout << " : ";
    cin >> res;
    erreur = cin.fail();
    if (erreur) {
      cout << "Je vous ai demande d'entrer un nombre, "
           << "pas du charabia !" << endl;
      cin.clear();            // remets cin dans un etat lisible
      string poubelle;
      getline(cin, poubelle); // lit toute la ligne (pour la "jeter")
    }
  } while (erreur || (res < a) || ((a < b) && (res > b)));
  return res;
}
