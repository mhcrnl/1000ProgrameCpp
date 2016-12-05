#include <iostream>
#include <array>
using namespace std;

enum Couleur { vide, rouge, jaune };

typedef array<array<Couleur, 7>, 6> Grille;

// ======================================================================
void initialise(Grille& grille)
{
  for(auto &ligne : grille) {
    for(auto &kase : ligne) { // "case" est un mot réservé du C++ !
      kase = vide;
    }
  }
}

// ======================================================================
void affiche_simple(const Grille& grille)
{
  for(auto ligne : grille) {
    for(auto kase : ligne) {
      if (kase == vide) {
	cout << ' ';
      } else if (kase == rouge) {
	cout << 'O';
      } else {
	cout << 'X';
      }
    }
    cout << endl;
  }
}

// ======================================================================
void affiche(const Grille& grille)
{
  cout << endl;

  for(auto ligne : grille) {
    cout << " |";
    for(auto kase : ligne) {
      if (kase == vide) {
	cout << ' ';
      } else if (kase == rouge) {
	cout << 'O';
      } else {
	cout << 'X';
      }
      cout << '|';
    }
    cout << endl;
  }

  cout << '=';
  for(size_t i(1); i <= grille[0].size(); ++i) {
    cout << '=' << i;
  }
  cout << "==";

  cout << endl << endl;
}

// ======================================================================
bool joue(Grille& grille, size_t colonne, Couleur couleur)
{
  // Si le numero de colonne n'est pas valide, le coup n'est pas valide :
  if (colonne >= grille[0].size()) {
    return false;
  }

  /* On parcourt la colonne en partant du bas jusqu'a trouver une case
   * vide, ou jusqu'au haut de la colonne si la colonne est pleine :
   */
  size_t ligne(grille.size() - 1);
  bool pleine(false);
  while ((not pleine) and (grille[ligne][colonne] != vide)) {
    if (ligne == 0) {
      pleine = true;
    } else {
      --ligne;
    }
  }

  /* Si on n'est pas arrive' jusqu'en haut de la colonne, on remplit la
   * case vide trouvee,
   * sinon c'est que la colonne est pleine et le coup n'est pas valide :
   */
  if (not pleine) {
    grille[ligne][colonne] = couleur;
    return true;
  } else {
    return false;
  }
}

// ======================================================================
bool joue_v2(Grille& grille, size_t colonne, Couleur couleur)
{
  // Si le numero de colonne n'est pas valide, le coup n'est pas valide :
  if (colonne >= grille[0].size()) {
    return false;
  }
  
  /* On parcourt la colonne en partant du bas jusqu'a trouver une case
   * vide.
   *
   * Si le test (ligne < grille.size()) devient faux, c'est qu'on a
   * soustrait 1 a ligne quand elle valait 0, ce qui arrive quand la
   * colonne est pleine :
   */
  size_t ligne(grille.size() - 1);
  while ((ligne < grille.size()) and (grille[ligne][colonne] != vide)) {
    --ligne;
  }

  /* Si ligne < grille.size() on a trouve une case vide et on la
   * remplit, 
   * sinon c'est que la colonne est pleine et le coup n'est pas valide :
   */
  if (ligne < grille.size()) {
    grille[ligne][colonne] = couleur;
    return true;
  } else {
    return false;
  }
}

// ======================================================================
bool joue_v3(Grille& grille, size_t colonne, Couleur couleur)
{
  // Si le numero de colonne n'est pas valide, le coup n'est pas valide :
  if (colonne >= grille[0].size()) {
    return false;
  }

  // Si la colonne est pleine, le coup n'est pas valide :
  if (grille[0][colonne] != vide) {
    return false;
  }

  /* On parcourt la colonne en partant du bas jusqu'a trouver une case
   * vide :
   */
  size_t ligne(grille.size() - 1);
  while (grille[ligne][colonne] != vide) {
    --ligne;
  }

  // On remplit la case vide trouvee :
  grille[ligne][colonne] = couleur;
  return true;
}

// ======================================================================
unsigned int compte(const Grille& grille,
		    size_t ligne_depart, size_t colonne_depart,
		    int dir_ligne, int dir_colonne)
{
  unsigned int compteur(0);
  
  size_t ligne(ligne_depart);
  size_t colonne(colonne_depart);

  /* On part de la case (ligne_depart, colonne_depart) et on parcourt
   * la grille dans la direction donnee par (dir_ligne, dir_colonne)
   * tant qu'on trouve des pions de la meme couleur que le pion de
   * depart.
   * On sait qu'on ne peut pas sortir de la grille.
   */
  while(grille[ligne][colonne] == grille[ligne_depart][colonne_depart]) {
    ++compteur;
    ligne   = ligne   + dir_ligne;
    colonne = colonne + dir_colonne;
  }

  return compteur;
}

// ======================================================================
bool est_ce_gagne(const Grille& grille, Couleur couleur_joueur)
{
  // On parcourt la grille

  for(size_t ligne(0); ligne < grille.size(); ++ligne) {
    for(size_t colonne(0); colonne < grille[ligne].size(); ++colonne) {
      Couleur couleur_case(grille[ligne][colonne]);

      /* Pour chaque case qui contient un pion de la bonne couleur,
       * on compte les pions de la meme couleur dans 4 directions :
       */
      if (couleur_case == couleur_joueur) {
	const size_t ligne_max(grille.size() - 4);
	const size_t colonne_max(grille[ligne].size() - 4);
	if (
	    // en diagonale, vers le haut et la droite :
	    (ligne >= 3 and colonne <= colonne_max and
             compte(grille, ligne, colonne, -1, +1) >= 4) or

	    // horizontalement, vers la droite :
	    (colonne <= colonne_max and
             compte(grille, ligne, colonne, 0, +1) >= 4) or

	    // en diagonale, vers le bas et la droite :
	    (ligne <= ligne_max and colonne <= colonne_max and
             compte(grille, ligne, colonne, +1, +1) >= 4) or

	    // verticalement, vers le bas :
	    (ligne <= ligne_max and
             compte(grille, ligne, colonne, +1, 0) >= 4)) {

	  /* Si le nombre de pions pour au moins une des directions
	   * est au moins 4, le joueur a gagne :
           */
	  return true;
	}
      }
    }
  }

  /* Si on a parcouru toute la grille sans trouver au moins 4 pions
   * alignes, le joueur n'a pas gagne, du moins pas encore :
   */
  return false;
}

// ======================================================================
void joue(Grille& grille, Couleur couleur_joueur)
{
  size_t colonne;
  bool valide;

  do {
    cin >> colonne;

    // les indices des tableaux commencent par 0 en C++:
    --colonne;

    valide = joue(grille, colonne, couleur_joueur);
    if (not valide) {
      cout << " > Ce coup n'est pas valide" << endl;
    }
  } while(not valide);
}


// ======================================================================
bool plein(const Grille& grille)
{
  // Si on trouve une case vide sur la premiere ligne, la grille n'est pas pleine :
  for(auto kase : grille[0]) {
    if (kase == vide) {
      return false;
    }
  }

  // Sinon, la grille est pleine :
  return true;
}

// ======================================================================
int main()
{
  Grille grille;

  initialise(grille);
  affiche(grille);

  Couleur couleur_joueur(jaune);
  bool gagne;

  do {
    cout << "Joueur ";
    if (couleur_joueur == jaune) {
      cout << 'X';
    } else {
      cout << 'O';
    }
    cout << ", entrez un numero de colonne :" << endl;

    joue(grille, couleur_joueur);

    affiche(grille);

    gagne = est_ce_gagne(grille, couleur_joueur);

    // On change la couleur pour la couleur de l'autre joueur:
    if (couleur_joueur == jaune) {
      couleur_joueur = rouge;
    } else {
      couleur_joueur = jaune;
    }

  } while(not gagne and not plein(grille));

  if (gagne) {
  // attention, on a change la couleur pour la couleur de l'autre joueur !
    cout << "Le joueur ";
    if (couleur_joueur == jaune) {
      cout << 'O';
    } else {
      cout << 'X';
    }
    cout << " a gagne' !" << endl;
  } else {
    cout << "Match nul !" << endl;
  }

  return 0;
}
