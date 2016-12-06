#include <iostream>
using namespace std;

int variable(10); // ceci est une variable globale

int main()
{
  { // ici nous avons un nouveau bloc : disons bloc1
    int variable(5); // variable locale a bloc1
    cout << "Un, la variable vaut : " << variable << endl;
    // affiche 5
  }

  { // ici nous avons un nouveau bloc : bloc2
    // mais il ne definit pas de variable "variable"
    // L'appel ci-dessous fait donc appel a la variable globale
    cout << "Deux, la variable vaut : " << variable << endl;
    // affiche 10
  }

  // ici un bloc "for" avec une variable locale au bloc
  for (int variable(0); variable < 3; ++variable) {
    cout << "Trois, la variable vaut : " << variable << endl;
    // affiche 0, 1, 2
  }

  // encore la variable globale car aucune variable "variable"
  // n'est definie au niveau de ce bloc (main())
  cout << "Quatre, la variable vaut : " << variable << endl;
  // affiche 10

  // ici un autre bloc "for", mais attention il NE declare PAS la
  // variable "variable" (c'est ici une affectation, pas une
  // declaration) et donc il utilise la variable GLOBALE
  for (variable = 0; variable < 3; ++variable) {
    cout << "Cinq, la variable vaut : " << variable << endl;
    // affiche 0, 1, 2
  }

  // c'est toujours la variable GLOBALE dont il s'agit ici mais
  // elle a ete modifiee par le for precedent et sa valeur est donc 3,
  // la valeur qui a fait sortir du "for".
  cout << "Six, la variable vaut : " << variable << endl;
  // affiche 3
  return 0;
}
