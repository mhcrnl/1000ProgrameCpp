#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const string nom_fichier("data.dat"); // le nom du fichier

int main()
{
  ofstream fichier(nom_fichier.c_str());  // le flot � destination du
                                          // fichier

  // on teste si l'ouverture du flot s'est bien realis�e
  if (fichier.fail()) {
    cerr << "Erreur: le fichier " << nom_fichier
         << " ne peut �tre ouvert en �criture !" << endl;
  } else {

    string nom;        // la donn�e "nom" � lire depuis le clavier
    unsigned int age;  // la donn�e "age" � lire depuis le clavier

    // it�ration sur les demandes � entrer
    do {
      cout << "Entrez un nom (CTRL+D pour terminer) : ";
      cin >> nom;
      if (!cin.eof()) {

        // L'utilisateur a bien saisi un nom, on peut donc lui demander
        // de saisir l'�ge.

        cout << "�ge : ";
        cin >> age;

        if (cin.fail()) {

          // on n'a pas r�ussi � lire un entier

          cout << "Je vous demande un �ge (nombre entier positif) pas "
               << "n'importe quoi !" << endl;
          cout << "Cet enregistrement est annul�." << endl;

          // On essaye de remettre le flot cin dans un �tat correct.
          // Pour cela :
          cin.clear();    // on "annule" l'�tat d'erreur
          string garbage; 
          getline(cin, garbage); // et on lit ce qui reste dans le flot
        } else {
          // �criture dans le fichier
          fichier << nom << ' ' << age << endl;
        }
      } else {
        cout << endl; // purisme pour aller � la ligne
      }
    } while (!cin.eof()); // et on continue tant que cin est lisible.

    fichier.close(); // fermeture du flot fichier
  }
  return 0;
}
