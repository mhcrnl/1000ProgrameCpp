#include <iostream>
#include <string>
using namespace std;

unsigned int cherche(unsigned int borneInf, unsigned int borneSup);

const unsigned int MIN(1);
const unsigned int MAX(100);

// --------------------------------------------------------------------
int main()
{
  cout << "Pensez a un nombre entre " << MIN << " et " << MAX << "."
       << endl;
  cout << "Tapez sur 'Entree' quand vous etes pret(e)." << endl;
  string poubelle;
  getline(cin, poubelle);
  cout << endl << "Votre nombre etait " << cherche(MIN,MAX) << '.'
       << endl;
  return 0;
}

/* -------------------------------------------------------------------
 * Recherche d'un nombre par dichotomie dans un intervalle [a b]
 * Entree : les bornes de l'interval
 * Sortie : la solution
 * ----------------------------------------------------------------- */
unsigned int cherche(unsigned int a, unsigned int b)
{
  //  cout << "[ " << a << ", " << b << " ]" << endl;

  if (b < a) {
    cerr << "ERREUR: vous avez repondu de facon inconsistante !"
         << endl;
    return b;
  }

  unsigned int pivot((a+b)/2);
  char rep;

  do {
    cout << "Le nombre est il <, > ou = a " << pivot << " ? ";
    cin >> rep;
  } while ((rep != '=') && (rep != '<') && (rep != '>'));

  switch (rep) {
  case '=':
    return pivot;
  case '<':
    return cherche(a,pivot-1);
  case '>':
    return cherche(pivot+1,b);
  }
}
