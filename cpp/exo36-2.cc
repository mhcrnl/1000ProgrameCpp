#include <vector>
#include <iostream>

using namespace std;

const unsigned int LARGEUR(8);
const unsigned int HAUTEUR(8);

const char WALL('W');
const char FREE(' ');
const char EXIT('E');
const char VIEW('+');

struct Coord
{
  unsigned int i; // indice de ligne
  unsigned int j; // indice de colonne
};

typedef vector<Coord> Chemin;
typedef char Labyrinthe[HAUTEUR][LARGEUR];

void nettoieLabyrinthe(Labyrinthe labyrinthe);
void dessineLabyrinthe(const Labyrinthe, unsigned int i, unsigned int j);
void afficheChemin(const Chemin& chemin);
void dessineChemin(const Labyrinthe labyrinthe, const Chemin& chemin);

bool chercheCheminSortie(Labyrinthe labyrinthe, Chemin& chemin,
                         unsigned int i, unsigned int j);
bool test(Labyrinthe labyrinthe, Chemin& chemin, int i, int j);
bool chercheSortie(Labyrinthe labyrinthe, Chemin& chemin,
                   unsigned int i, unsigned int j);

int main()
{
  Labyrinthe mendes =
  {
    { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL },
    { WALL, FREE, FREE, FREE, WALL, FREE, FREE, WALL },
    { WALL, WALL, WALL, FREE, WALL, FREE, FREE, WALL },
    { EXIT, FREE, WALL, FREE, WALL, WALL, FREE, WALL },
    { WALL, FREE, FREE, FREE, FREE, FREE, WALL, WALL },
    { WALL, FREE, WALL, WALL, WALL, FREE, FREE, WALL },
    { WALL, FREE, WALL, FREE, FREE, FREE, FREE, WALL },
    { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
  };

  Labyrinthe cnossos =
  {
    { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE },
    { FREE, WALL, FREE, WALL, WALL, WALL, WALL, FREE },
    { WALL, WALL, FREE, FREE, FREE, FREE, FREE, FREE },
    { EXIT, WALL, WALL, WALL, WALL, FREE, WALL, FREE },
    { FREE, WALL, FREE, FREE, WALL, FREE, FREE, FREE },
    { FREE, WALL, WALL, FREE, FREE, FREE, WALL, FREE },
    { FREE, FREE, WALL, WALL, WALL, WALL, WALL, FREE },
    { WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE }
  };

  Chemin ariane;

  cout << "1er test, labyrinthe 'mendes'" << endl;
  dessineLabyrinthe(mendes, 1, 1);
  if (chercheCheminSortie(mendes, ariane, 1, 1)) {
    cout << "Sortie trouvée, le chemin est:" << endl;
    afficheChemin(ariane);
    cout << "Soit, dans le labyrinthe: " << endl;
    dessineChemin(mendes,ariane);
  } else {
    cout << "Pas de sortie." << endl;
  }

  cout << endl << "2e test, labyrinthe 'mendes'" << endl;
  dessineLabyrinthe(mendes, 1, 6);
  if (chercheCheminSortie(mendes, ariane, 1, 6)) {
    cout << "Sortie trouvée, le chemin est:" << endl;
    afficheChemin(ariane);
    cout << "Soit, dans le labyrinthe: " << endl;
    dessineChemin(mendes,ariane);
  } else {
    cout << "Pas de sortie." << endl;
  }

  cout << endl << "3e test, labyrinthe 'cnossos'" << endl;
  dessineLabyrinthe(cnossos, 2, 2);
  if (chercheCheminSortie(cnossos, ariane, 2, 2)) {
    cout << "Sortie trouvée, le chemin est:" << endl;
    afficheChemin(ariane);
    cout << "Soit, dans le labyrinthe: " << endl;
    dessineChemin(cnossos,ariane);
  } else {
    cout << "Pas de sortie." << endl;
  }
  return 0;
}

void nettoieLabyrinthe(Labyrinthe labyrinthe)
{
  for (unsigned int i(0); i<HAUTEUR; ++i)
    for (unsigned int j(0); j<LARGEUR; ++j)
      if (labyrinthe[i][j] == VIEW) labyrinthe[i][j] = FREE;
}

void dessineLabyrinthe(const Labyrinthe labyrinthe, unsigned int i, unsigned int j)
{
  // ----------- affichage du cadre supérieur
  cout << "\t+";
  for (unsigned int jj(0); jj<LARGEUR; ++jj) {cout << "-";}
  cout << "+" << endl;
  // ----------------------------------------

  for (unsigned int ii(0); ii<HAUTEUR; ++ii) {
    cout << "\t|"; // cadre extérieur droit
    for (unsigned int jj(0); jj<LARGEUR; ++jj) {
      if ((i == ii) && (j == jj))
        cout << 'o'; // la position courante
      else
        cout << labyrinthe[ii][jj];
    }
    cout << '|' << endl; // cadre extérieur gauche
  }

  // ----------- affichage du cadre inférieur
  cout << "\t+";
  for (unsigned int j(0); j < LARGEUR; ++j) {cout << "-";}
  cout << "+" << endl;
  // ----------------------------------------
}

void afficheChemin(const Chemin& chemin)
{
  for (unsigned int step(0); step < chemin.size(); ++step)
    cout << '(' << chemin[step].i << ',' << chemin[step].j << ')'
         << endl;
}

void dessineChemin(const Labyrinthe labyrinthe, const Chemin& chemin)
{
  // Le plus simple est encore de marquer le chemin
  // dans une copie du labyrinthe:

  Labyrinthe copie;

  // initialisation
  for (unsigned int i(0); i < HAUTEUR; ++i)
    for (unsigned int j(0); j < LARGEUR; ++j)
      copie[i][j] = labyrinthe[i][j];

  // marquage du chemin
  for (unsigned int step(0); step < chemin.size(); ++step)
    copie[chemin[step].i][chemin[step].j] = '*';

  dessineLabyrinthe(copie, chemin[0].i, chemin[0].j);
}

bool chercheCheminSortie(Labyrinthe labyrinthe, Chemin& chemin,
                         unsigned int i, unsigned int j)
{
  /*
     N'est pas récursive, pour permettre d'isoler le niveau 0 de
     récursion, et procéder aux initialisations et nettoyage des
     structures
  */

  // le test suivant n'est pas obligatoire... juste au cas où l'on
  // se tromperai de coordonnées dans la fonction appelante.
  if (labyrinthe[i][j] == WALL) {
    cerr << endl << "Erreur! on part dans un mur!" << endl;
    exit(1);
  }

  // on nettoye une structure éventuellement déjà utilisée
  chemin.clear();

  // on procède à la recherche récursive
  bool res(chercheSortie(labyrinthe, chemin, i, j));

  // on réinitialise le labyrinthe
  nettoieLabyrinthe(labyrinthe);

  // on inverse l'ordre du chemin pour le rendre logique
  for (unsigned int i(0); i<chemin.size()/2; ++i) {
    Coord tmp(chemin[i]);
    chemin[i] = chemin[chemin.size()-i-1];
    chemin[chemin.size()-i-1] = tmp;
  }

  return res;
}

bool test(Labyrinthe labyrinthe, Chemin& chemin, int i, int j)
{
  return ( (i>=0) && (i<HAUTEUR) &&
           (j>=0) && (j<LARGEUR) &&
           (labyrinthe[i][j] != VIEW) &&
           (labyrinthe[i][j] != WALL) &&
           chercheSortie(labyrinthe, chemin, i, j)
         );
}

bool chercheSortie(Labyrinthe labyrinthe, Chemin& chemin,
                   unsigned int i, unsigned int j)
{
  Coord position = {i,j};

  if (labyrinthe[i][j] == EXIT) {
    chemin.push_back(position); return true;
  }

  labyrinthe[i][j] = VIEW;

  if ( test(labyrinthe, chemin, i+1, j)) {chemin.push_back(position); return true;}
  if ( test(labyrinthe, chemin, i-1, j)) {chemin.push_back(position); return true;}
  if ( test(labyrinthe, chemin, i, j+1)) {chemin.push_back(position); return true;}
  if ( test(labyrinthe, chemin, i, j-1)) {chemin.push_back(position); return true;}

  return false;
}
