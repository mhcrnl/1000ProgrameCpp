#include <iostream>
#include <vector>
using namespace std;

const unsigned int nb_etapes(13);

string pendu[nb_etapes] = {
  "\n\n\n\n\n__________",
  "\n  |\n  |\n  |\n  |\n__|_______",
  "\n  |\n  |\n  |\n  |\n_/|_______",
  "\n  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |   O\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |   O\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |  /\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |  / \\\n_/|\\______",
};

struct Joueur {
  string nom;
  int points;
  unsigned int etape;
};

bool bonne_lettre(char l, string& mot, string ref)
{
  bool retour = false;
  for (unsigned int i(0); i < ref.size(); ++i)
    if ((ref[i] == l) && (mot[i] != l)) {
      mot[i] = l;
      retour = true;
    }
  return retour;
}

int main()
{
  cout << "Nombre de joueurs : " << endl;
  unsigned int nb_joueurs;
  cin >> nb_joueurs;

  vector< Joueur > joueur(nb_joueurs);

  // saisie des noms des joueur et initialisation
  for (unsigned int i(0); i < nb_joueurs; ++i) {
    cout << "Nom du joueur " << i+1 << " : ";
    cin >> joueur[i].nom;
    joueur[i].points = 0;
    joueur[i].etape  = 0;
  }

  // nombre de joueurs pouvant encore jouer
  unsigned int pouvant_jouer(nb_joueurs);

  // jeu à tour de rôle
  for (unsigned int i(0); (i < nb_joueurs) && (pouvant_jouer > 0); ++i) {
    cout << "Au joueur " << joueur[i].nom << " (" << i+1
               << ") de proposer un mot." << endl;
    cout << "(Les autres joueurs ne regardent pas)" << endl;

    cout << "Entrez le mot proposé : ";
    string mot;
    cin >> mot;

    // efface l'écran de façon rudimentaire (40 lignes vides ici)
    for (int j(0); j < 40; ++j) cout << endl;

    // cree la forme affichée du mot à deviner
    string mot_trouve;
    for (unsigned int j(0); j < mot.size(); ++j) mot_trouve += '.';

    // le joueur posant le mot ne peut pas jouer ce tour ci
    // (mais ne le supprimer ici que si il peut encore potentiellement jouer)
    if (joueur[i].etape < nb_etapes)
      --(pouvant_jouer); 

    while ((mot_trouve != mot) && (pouvant_jouer > 0)) {
      for (unsigned int j(0);
           (j < nb_joueurs) && (mot_trouve != mot);
           ++j)
      {
        if ((j != i) && (joueur[j].etape < nb_etapes)) {
                cout << endl << "MOT : " << mot_trouve << endl;
          cout << "Joueur " << joueur[j].nom << " (" << j+1
               << ") proposez une lettre : ";
          char lettre;
          cin >> lettre;

          if (bonne_lettre(lettre, mot_trouve, mot)) {
            cout << "Bravo : " << mot_trouve << endl;
            if (mot_trouve == mot) {
              ++(joueur[j].points);
              cout << "-> GAGNÉ !" << endl;
            }
          } else {
            ++(joueur[j].etape);
            cout << "Pas de chance : " << endl;
            cout << pendu[joueur[j].etape-1] << endl;
            if (joueur[j].etape >= nb_etapes) {
              cout << "-> PERDU !" << endl;
              ++(joueur[i].points);
              --pouvant_jouer;
            }
          }
        }
      }
    }

    // le joueur qui a posé le mot peut à nouveau jouer si
    // il n'a pas été éliminé auparavant
    if (joueur[i].etape < nb_etapes)
      ++(pouvant_jouer);

  }

  // resultats :
  cout << endl
       << "La partie est finie." << endl
       << "Résultats : " << endl;
  for (unsigned int j(0); j < nb_joueurs; ++j) {
    cout << "Joueur " << joueur[j].nom << " (" << j+1  << ") ";
    if (joueur[j].etape < nb_etapes) {
      cout << "encore en vie ! et avec "
           << joueur[j].points << " point";
      if (joueur[j].points > 1) cout << 's';
      cout << '.';
    } else {
      cout << "pendu... (points : " << joueur[j].points << ")";
    }
    cout << endl;
  }

  return 0;
}
