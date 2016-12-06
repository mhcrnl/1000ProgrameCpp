#include <iostream>
using namespace std;

const unsigned int N(4); // la taille de la tour de depart

// un disque sera represente simplement par sa taille (rayon)
typedef unsigned int Disque; 
// 0 signifiant pas de disque
const Disque PAS_DE_DISQUE(0);

typedef Disque Pilier[N]; // un pilier est une pile d'au plus N disques
typedef Pilier Jeu[3]; // le jeu est constitue de 3 piliers

// les fonctions
void affiche(char c, unsigned int n = 1);
void affiche(Disque d);
void affiche(Jeu jeu);;
void init(Jeu& jeu); /* Note: le passage par reference est ici
                      * facultatif vu que Jeu est un tableau.  Mais je
                      * prefere marquer clairement par ce passage par
                      * reference que l'argument jeu est modifie par
                      * cette fonction */

unsigned int sommet(Pilier p);
void deplace(Pilier& origine, Pilier& destination); // meme remarque
unsigned int autre(unsigned int p1, unsigned int p2);
void hanoi(unsigned int n, unsigned int origine,
           unsigned int destination, Jeu jeu);

// --------------------------------------------------------------------
int main()
{
  Jeu monjeu;

  init(monjeu);
  affiche(monjeu);
  hanoi(N, 0, 2, monjeu);

  return 0;
}

// --------------------------------------------------------------------
void init(Jeu& jeu)
{
  for (unsigned int i(0); i < N; ++i) {
    jeu[0][i] = i+1;
    jeu[1][i] = PAS_DE_DISQUE;
    jeu[2][i] = PAS_DE_DISQUE;
  }
}

// --------------------------------------------------------------------
void affiche(char c, unsigned int n)
{
  for (unsigned int i(0); i < n; ++i) cout << c;
}

// --------------------------------------------------------------------
void affiche(Disque d)
{
  if (d == PAS_DE_DISQUE) {
    affiche(' ', N-1);
    cout << '|';
    affiche(' ', N);
  }
  else {
    affiche(' ', N-d);
    affiche('-', 2*d-1);
    affiche(' ', N-d+1);
  }
}

// --------------------------------------------------------------------
void affiche(Jeu jeu)
{
  for (unsigned int i(0); i < N; ++i) {
    affiche(jeu[0][i]);
    affiche(jeu[1][i]);
    affiche(jeu[2][i]);
    cout << endl;
  }
  // le socle
  affiche('#', 6*N-1); // 3*(2*N-1)+2 = 6*N-1
  cout << endl << endl;
}

// --------------------------------------------------------------------
unsigned int sommet(Pilier p)
{
  unsigned int top;
  for (top = 0; (top < N) && (p[top] == PAS_DE_DISQUE); ++top);
  return top;
}

// --------------------------------------------------------------------
void deplace(Pilier& origine, Pilier& destination)
{
  unsigned int top1(sommet(origine));
  if (top1 < N) { // si la tour d'origine existe bien

    unsigned int top2(sommet(destination));
    if ((top2 < N) && (destination[top2] < origine[top1])) {
      /* on essaye de mettre un disque plus gros (origine[top1])
       * sur un disque plus petit (destination[top2]) : ce n'est pas 
       * un deplacement autorise !
       */
      cerr << "ERREUR : on ne peut pas deplacer une disque de taille "
           << origine[top1] << " sur un disque de taille "
           << destination[top2] << " !" << endl;
      return;
    }

    // effectue le mouvement
    destination[top2-1] = origine[top1];
    origine[top1] = PAS_DE_DISQUE;
  }
}

// --------------------------------------------------------------------
unsigned int autre(unsigned int p1, unsigned int p2)
{
  return 3 - p1 -p2;
}

// --------------------------------------------------------------------
void hanoi(unsigned int n, unsigned int origine,
           unsigned int destination, Jeu jeu)
{
  if (n != 0) {
    unsigned int auxiliaire(autre(origine, destination));
    hanoi(n-1, origine, auxiliaire, jeu);
    deplace(jeu[origine], jeu[destination]);
    affiche(jeu);
    hanoi(n-1, auxiliaire, destination, jeu);
  }
}
