#include <iostream>
using namespace std;

main()
{
  int age;                              // declarations
  int annee;

  cout << "Entrez votre age :" << endl; // Affichage de la question
  cin >> age;                           // Lecture de la reponse
  annee = 2005 - age;                   // Calcul

  /* Affichage de l'annee */
  cout << "Vous etes ne(e) vers l'annee " << annee
       << endl;
}
