#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const string nom_fichier("data.dat"); // le nom du fichier

int main()
{
  ofstream fichier(nom_fichier.c_str());  // le flot à destination du
                                          // fichier

  // on teste si l'ouverture du flot s'est bien realisée
  if (fichier.fail()) {
    cerr << "Erreur: le fichier " << nom_fichier
         << " ne peut être ouvert en écriture !" << endl;
  } else {

    string nom;        // la donnée "nom" à lire depuis le clavier
    unsigned int age;  // la donnée "age" à lire depuis le clavier

    // itération sur les demandes à entrer
    do {
      cout << "Entrez un nom (CTRL+D pour terminer) : ";
      cin >> nom;
      if (!cin.eof()) {

        // L'utilisateur a bien saisi un nom, on peut donc lui demander
        // de saisir l'âge.

        cout << "âge : ";
        cin >> age;

        if (cin.fail()) {

          // on n'a pas réussi à lire un entier

          cout << "Je vous demande un âge (nombre entier positif) pas "
               << "n'importe quoi !" << endl;
          cout << "Cet enregistrement est annulé." << endl;

          // On essaye de remettre le flot cin dans un état correct.
          // Pour cela :
          cin.clear();    // on "annule" l'état d'erreur
          string garbage; 
          getline(cin, garbage); // et on lit ce qui reste dans le flot
        } else {
          // écriture dans le fichier
          fichier << nom << ' ' << age << endl;
        }
      } else {
        cout << endl; // purisme pour aller à la ligne
      }
    } while (!cin.eof()); // et on continue tant que cin est lisible.

    fichier.close(); // fermeture du flot fichier
  }
  return 0;
}
