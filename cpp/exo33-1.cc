#include <iostream>
#include <string>
using namespace std;

typedef unsigned int entier;

int demander_nombre(int min, int max);
entier Fibonacci(entier n);
entier FibonacciIteratif(entier n);

// --------------------------------------------------------------------
int main()
{
  char rep;

  do {
    int n(demander_nombre(0, 40));
    cout << "Methode iterative :" << endl;
    cout << "    F(" << n << ") = " << FibonacciIteratif(entier(n))
         << endl;
    cout << "Methode recursive :" << endl;
    cout << "    F(" << n << ") = " << Fibonacci(entier(n)) << endl;

    do {
      cout << "Voulez-vous recommencer [o/n] ? ";
      cin >> rep;
    } while ((rep != 'o') && (rep != 'n'));
  } while (rep == 'o');

  return 0;
}

/* --------------------------------------------------------------------
 * Calcule de facon iterative le n-ieme nombre de Fibonacci.
 * Entree : le nombre n
 * Sortie : F(n)
 * ----------------------------------------------------------------- */
entier FibonacciIteratif(entier n)
{
  entier Fn(0);    // stocke F(i)  , initialise par F(0)
  entier Fn_1(Fn); // stocke F(i-1), initialise par F(0)
  entier Fn_2(1);  // stocke F(i-2), initialise par F(-1)

  for (entier i(1); i <= n; ++i) {
    Fn   = Fn_1 + Fn_2;    // pour n>=1 on calcule F(n)=F(n-1)+F(n-2)
    Fn_2 = Fn_1;           // et on decale...
    Fn_1 = Fn;
  }
  return Fn;
}

/* -------------------------------------------------------------------
 * Calcule de facon recursive le n-ieme nombre de Fibonacci.
 * Entree : le nombre n
 * Sortie : F(n)
 * ----------------------------------------------------------------- */
entier Fibonacci(entier n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return Fibonacci(n-1) + Fibonacci(n-2);
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
