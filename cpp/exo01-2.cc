#include <iostream>
using namespace std;

main()
{
  cout << "Entrez votre age :" << endl; // Affichage de la question
  int age;                              // declaration
  cin >> age;                           // Lecture de la reponse

  int annee(2005-age);                 // declaration et initialisation

  /* Affichage de l'annee */
  cout << "Vous etes ne(e) vers l'annee " << annee << endl;
}
