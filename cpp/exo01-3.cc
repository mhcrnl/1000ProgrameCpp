#include <iostream>
using namespace std;

main()
{
  cout << "Entrez votre age :" << endl; // Affichage de la question
  int age;                              // declaration
  cin >> age;                           // Lecture de la reponse

  /* Affichage de l'annee */
  cout << "Vous etes ne(e) vers l'annee " << 2005-age << endl;
}
