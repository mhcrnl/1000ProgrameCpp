#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
  
const string nom_fichier("data.dat"); // le nom du fichier

int main()
{
  // le flot d'entree en provenance du fichier
  ifstream fichier(nom_fichier.c_str()); 

  if (fichier.fail()) {
    cerr << "Erreur: le fichier " << nom_fichier
         << " ne peut etre ouvert en lecture !" << endl;
  } else {
    // si l'ouverture s'est bien produite...

    string nom;       // les donnees a lire dans le fichier...
    unsigned int age; // ...pas necessaire de les initialiser

    unsigned int nb(0); // variables necessaires aux differents calculs
    unsigned int age_max(0); 
    unsigned int age_min(300); // je pense que 300 ans est assez large 
    double total(0.0);

    // On commence par l'affichage du cadre 
    cout << "+" 
         << setfill('-') << setw(18) << "+"
         << setfill('-') << setw(6)  << "+" << endl
         << setfill(' ');

    /*
     * Et on boucle directement sur la condition de lecture correcte
     * du couple <nom,age> (en fait, sur la condition de lecture
     * correcte de 'age', mais comme il n'est pas possible de lire
     * 'age' si la lecture de 'nom' a echoue...
     */

    do {
      fichier >> nom >> age;

      if (!fichier.fail()) {
        // mise a jour des variables utilisees pour les calculs finaux 
        ++nb;
        total += age;
        if (age_min > age) age_min = age;
        if (age_max < age) age_max = age;

        // --------------------------------------------------
        // AFFICHAGE
        // --------------------------------------------------

        cout.setf(ios::left);  // on definit un alignement a gauche;

        // le nom sur 15 caracteres, en chaine de taille fixe
        cout << "| " << setw(15) << nom;

        /*  Pour l'affichage de l'age, on enleve le modificateur 
         * 'alignement a gauche'
         */
        cout.unsetf(ios::left);

        // affiche l'age sur 3 caracteres
        cout << " | " << setw(3) << age << " |" << endl;
      }
    } while (!fichier.eof());

    // --------------------------------------------------
    // Partie finale
    // --------------------------------------------------

    fichier.close();  // ne pas oublier de fermer le fichier

    cout << "+" 
         << setfill('-') << setw(18) << "+"
         << setfill('-') << setw(6)  << "+" << endl
         << setfill(' ');

    // les infos 'finales' ...
    cout.setf(ios::left); 
    cout << setw(18) << "  age minimum" << ": ";
    cout.unsetf(ios::left); 
    cout << setw(3) << age_min << endl;

    cout.setf(ios::left); 
    cout << setw(18) << "  age maxmimal" << ": ";
    cout.unsetf(ios::left); 
    cout << setw(3) << age_max << endl;

    cout << setw(2) << nb << " personnes, age moyen : "
         << setw(4) << setprecision(3) << (total / nb) << " ans"
         << endl;
  }
  return 0;
}
