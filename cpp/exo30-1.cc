#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// ===== CONSTANTES =====

// nombre maximum de demandes en cas d'erreur
const unsigned short int NB_DEMANDES(3);

// bornes sur les caract�res � prendre en compte
const char start(' ');
const char stop('z');

/* taille maximum d'une Statistique : au plus 256 car il n'y a pas plus  *
 * que 256 char.                                                         *
 * On aurait aussi pu mettre "stop-start+1", mais faire attention dans   *
 * le cas g�n�ral si stop est inf�rieur � start (par exemple stop < 0) ! */
const unsigned short int TAILLE(256);

// ===== DEFINITIONS DE TYPES ======

typedef unsigned long int Statistique[TAILLE];

// ===== FONCTIONS ======
bool demander_fichier(ifstream& f,
                      unsigned short int max_demandes = NB_DEMANDES);

void initialise_statistique(Statistique& a_initialiser);

unsigned long int collecte_statistique(Statistique& a_remplir,
                                       ifstream& fichier_a_lire);

void affiche(const Statistique a_afficher, unsigned long int total = 0,
             unsigned short int taille = TAILLE);

// --------------------------------------------------------------------
int main()
{
  ifstream f;
  if (! demander_fichier(f)) {
    cout << "=> j'abandonne !" << endl;
  } else {
    Statistique stat;
    initialise_statistique(stat);
    affiche(stat, collecte_statistique(stat, f), stop-start+1);
    f.close();
  }

  return 0;
}

/* ===================================================================
 * Fonction demander_fichier
 * -------------------------------------------------------------------
 * In: Un ifstream (par r�f�rence) � ouvrir et le nombre maximum de
 *     demandes (par defaut NB_DEMANDES).
 * Out:  Ouvert ou non ?
 * What: Demande � l'utilisateur (au plus max fois) un nom de fichier
 *       et essaye de l'ouvrir.
 * ================================================================= */
bool demander_fichier(ifstream& f, unsigned short int max)
{
  string nom;
  unsigned short int nb(0);

  do {
    f.clear(); ++nb;

    // demande le nom du fichier
    do {
      cin.clear();
      cout << "Nom du fichier a lire : ";
      cin >> nom;
    } while (cin.fail());

    // essaye d'ouvrir le fichier
    f.open(nom.c_str());

    // est-ce que �a a march� ?
    if (f.fail()) {
      cout << "-> ERREUR, je ne peux pas lire le fichier "
           << nom << endl;
    } else {
      cout << "-> OK, fichier " << nom << " ouvert pour lecture."
           << endl;
    }
  } while (f.fail() && (nb < max));

  return !f.fail();
}

/* ===================================================================
 * Fonction initialiser_statistique
 * -------------------------------------------------------------------
 * In:   Une Statistique (par r�f�rence) � initialiser.
 * What: Initialiser tous les �l�ments d'une Statistique � z�ro.
 * ================================================================= */
void initialise_statistique(Statistique& stat)
{
  for (int i(0); i < TAILLE; ++i) {
    stat[i] = 0;
  }
}

/* ===================================================================
 * Fonction collecte_statistique
 * -------------------------------------------------------------------
 * In:   Une Statistique (par r�f�rence) � remplir et le fichier � lire
 * Out:  Le nombre d'�l�ments compt�s dans la Statistique.
 * What: Lit tous les caract�res dans le fichier et compte dans la
 *       Statistique combien de fois chaque caract�re apparait dans le
 *       fichier.
 * ================================================================= */
unsigned long int collecte_statistique(Statistique& stat, ifstream& f)
{
  char c;  // le caract�re lu
  unsigned long int nb(0); // le nombre d'�l�ments compt�s

  while (f.get(c)) {
    if ((c >= start) && (c <= stop)) {
      ++(stat[c-start]);
      ++nb;
    }
  }

  return nb;
}

/* ===================================================================
 * Fonction affiche
 * -------------------------------------------------------------------
 * In: La Statistique � afficher, le nombre par rapport auquel on
 *     affiche les pourcentages (si 0 recalcule ce nombre comme la
 *     somme des �l�ments) et la taille du tableau.
 * What: Affiche tous les �l�ments d'une Statistique (valeurs absolue
 *       et relative).
 * ================================================================= */
void affiche(const Statistique stat, unsigned long int nb,
             unsigned short int taille)
{
  if (nb == 0) {
    for (unsigned short int i(0); i < taille; ++i)
      nb += stat[i];
  }

  const double total(nb);

  cout << "STATISTIQUES :" << endl << setprecision(3);
  for (unsigned short int i(0); i < taille; ++i) {
    if (stat[i] != 0) {
      cout << char(i+start) << " : " << setw(11) << stat[i] << " - "
           << setw(5) << 100.0 * stat[i] / total << "%" << endl;
    }
  }
}
