#include <vector>
#include <iostream>

using namespace std;

const unsigned int LARGEUR(8);
const unsigned int HAUTEUR(8);

const char WALL('W');
const char FREE(' ');
const char EXIT('E');
const char VIEW('+');

typedef char Labyrinthe[HAUTEUR][LARGEUR];

void nettoieLabyrinthe(Labyrinthe labyrinthe);
void dessineLabyrinthe(const Labyrinthe, unsigned int i, unsigned int j);

bool chercheSortie(Labyrinthe labyrinthe, unsigned int i, unsigned int j);

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

  cout << "1er test, labyrinthe 'mendes'" << endl;
  dessineLabyrinthe(mendes, 1,1);

  cout << "Sortie ";
  if (!chercheSortie(mendes, 1,1)) cout << "in";
  cout << "atteignable"
       << " [réponse attendue: atteignable]" << endl;

  // examinons les parties explorées
  dessineLabyrinthe(mendes, 1,1);

  // puis réinitialisation de l'état du labyrinthe
  nettoieLabyrinthe(mendes);

  cout << endl << "2e test, labyrinthe 'mendes'" << endl;
  dessineLabyrinthe(mendes, 1,6);
  cout << "Sortie ";
  if (!chercheSortie(mendes, 1,6)) cout << "in";
  cout << "atteignable"
       << " [réponse attendue: inatteignable]" << endl;
  nettoieLabyrinthe(mendes);

  cout << endl << "3e test, labyrinthe 'cnossos'" << endl;
  dessineLabyrinthe(cnossos, 2,2);
  cout << "Sortie ";
  if (!chercheSortie(cnossos, 2,2)) cout << "in";
  cout << "atteignable"
       << " [réponse attendue: atteignable]" << endl;
  nettoieLabyrinthe(cnossos);
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

  for (unsigned int ii(0); ii<HAUTEUR; ++ii)
  {
    cout << "\t|"; // cadre extérieur droit
    for (unsigned int jj(0); jj<LARGEUR; ++jj)
    {
      if ((i == ii) && (j == jj)) cout << 'o'; // la position courante
      else cout << labyrinthe[ii][jj];
    }
    cout << '|' << endl; // cadre extérieur gauche
  }

  // ----------- affichage du cadre inférieur
  cout << "\t+";
  for (unsigned int j(0); j<LARGEUR; ++j) {cout << "-";}
  cout << "+" << endl;
  // ----------------------------------------
}

bool chercheSortie(Labyrinthe labyrinthe, unsigned int i, unsigned int j)
{
  // Pour suivre 'pas à pas' la progression de l'algorithme,
  // décommenter la ligne suivante cout << endl;
  // afficheLabyrinthe(labyrinthe, i,j);

  // le test suivant n'est pas obligatoire... juste au cas où l'on
  // se tromperait de coordonnées dans la fonction appelante.
  if (labyrinthe[i][j] == WALL)
  {
    cerr << endl << "Erreur! on part dans un mur!" << endl;
    exit(1);
  }

  if (labyrinthe[i][j] == EXIT) return true;   // sortie trouvée
  if (labyrinthe[i][j] == VIEW) return false;  // déjà exploré

  labyrinthe[i][j] = VIEW;  // la position actuelle est 'explorée'

  if ((i+1<HAUTEUR) && (labyrinthe[i+1][j] != WALL)
      && (chercheSortie(labyrinthe, i+1,j))) return true;

  if ((i>0)         && (labyrinthe[i-1][j] != WALL)
      && (chercheSortie(labyrinthe, i-1,j))) return true;

  if ((j+1<LARGEUR) && (labyrinthe[i][j+1] != WALL)
      && (chercheSortie(labyrinthe, i,j+1))) return true;

  if ((j>0)         && (labyrinthe[i][j-1] != WALL)
      && (chercheSortie(labyrinthe, i,j-1))) return true;

  return false;
}
