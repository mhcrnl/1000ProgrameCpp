#include <iostream>
#include <string>
using namespace std;

typedef unsigned int entier;

int demander_nombre(int min, int max);
entier factorielleIterative(entier n);
entier factorielleRecursive(entier n);

// --------------------------------------------------------------------
int main()
{
  char rep;

  do {
    int n(demander_nombre(0,12));
    cout << "Methode iterative :" << endl;
    cout << "    " << n << "! = " << factorielleIterative(entier(n))
         << endl;
    cout << "Methode recursive :" << endl;
    cout << "    " << n << "! = " << factorielleRecursive(entier(n))
         << endl;

    do {
      cout << "Voulez-vous recommencer [o/n] ? ";
      cin >> rep;
    } while ((rep != 'o') && (rep != 'n'));
  } while (rep == 'o');

  return 0;
}

/* --------------------------------------------------------------------
 * Calcule de facon iterative la factorielle d'un nombre entier positif
 * Entree : le nombre n dont on veut calculer la factorielle
 * Sortie : n!
 * ----------------------------------------------------------------- */
entier factorielleIterative(entier n)
{
  entier fact(1);
  for (entier i(2); i <= n; ++i)
    fact *= i;
  return fact;
}

/* --------------------------------------------------------------------
 * Calcule de facon recursive la factorielle d'un nombre entier positif
 * Entree : le nombre n dont on veut calculer la factorielle
 * Sortie : n!
 * ----------------------------------------------------------------- */
entier factorielleRecursive(entier n)
{
  if (n == 0)
    return 1;
  else
    return (n * factorielleRecursive(n-1));
}

/* --------------------------------------------------------------
 * fonction demandant a l'utilisateur un nombre compris
 * dans un intervalle [a, b], ou superieur ou egal a a
 * si b < a.
 * Entree : les deux nombres a et b definissant l'intervalle
 * Sortie : le nombre saisi par l'utilisateur
 * -------------------------------------------------------------- */
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
