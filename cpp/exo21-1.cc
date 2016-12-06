#include <iostream>
using namespace std;

const unsigned int DIM(10);

// --------------------------------------------------------------------
bool remplitGrille(bool grille[DIM][DIM],
                   unsigned int ligne, unsigned int colonne,
                   char direction, unsigned int longueur)
{
  int dx, dy;

  switch (direction) {
  case 'N': dx = -1; dy =  0; break;
  case 'S': dx =  1; dy =  0; break;
  case 'E': dx =  0; dy =  1; break;
  case 'O': dx =  0; dy = -1; break;
  }

  unsigned int i(ligne);     // les coordonnee de la case...
  unsigned int j(colonne);   // ...a modifier
  unsigned int l;            // la longueur modifiee

  bool possible(true); // est-ce possible de mettre tout l'element ?

  // avant de modifier la grille, il faut verifier si c'est possible de
  // mettre tout l'objet
  for (// initialisation 
       l = 0;

       /* condition de continuation. Vu que i et j sont des "unsigned" *
        * pas besoin de tester ici les condition (i >= 0) et (j >= 0), *
        * lesquelles sont forcément vraies                             */
       (possible) && (i < DIM) && (j < DIM) && (l < longueur);

       // increments
       ++l, i += dx, j += dy) {

    if (grille[i][j])// c'est-a-dire la grille est deja occupee
      possible = false;  // on ne peut donc pas mettre l'objet voulu
  }

  /* Si l == longueur c'est qu'on a pu tout placer.
   * Il se pourrait en effet qu'on soit sorti de la boucle ci-dessus
   * parce que i >= DIM ou j >= DIM... ...ce qui n'a pas modifie'
   * "possible" jusqu'ici.
   */
  possible = possible && (l == longueur);

  if (possible)
    // on met effectivement l'objet, plus besoin de test ici
    for (l = 0, i = ligne, j = colonne; l < longueur;
         ++l, i += dx, j += dy)
      grille[i][j] = true;

  return possible;
}

// --------------------------------------------------------------------
void initGrille(bool grille[DIM][DIM])
{
  unsigned int i, j;
  for (i = 0; i < DIM; ++i)
    for (j = 0; j < DIM; ++j)
      grille[i][j] = false;
}

// --------------------------------------------------------------------
void ajouterElements(bool grille[DIM][DIM])
{
  int x, y;
  char dir;
  unsigned int l;

  do {
    cout << "Entrez coord. x : ";
    cin >> x;

    if (x >= 0) {
      cout << "Entrez coord. y : ";
      cin >> y;

      if (y >= 0) {

        do {
          cout << "Entrez direction (N,S,E,O) : ";
          cin >> dir;
        } while ((dir != 'N') && (dir != 'S') &&
                 (dir != 'E') && (dir != 'O'));

        cout << "Entrez taille : ";
        cin >> l;

        cout << "Placement en (" << x << "," << y << ") direction "
             << dir << " longueur " << l << " -> ";

        if (remplitGrille(grille, x, y, dir, l))
          cout << "succes";
        else
          cout << "ECHEC";
        cout << endl;

      }
    }
  } while ((x >= 0) && (y >= 0));
}

// --------------------------------------------------------------------
void afficheGrille(bool grille[DIM][DIM])
{
  unsigned int i, j;
  for (i = 0; i < DIM; ++i) {
    for (j = 0; j < DIM; ++j) {
      if (grille[i][j])
        cout << "#";
      else
        cout << ".";
    }
    cout << endl;
  }
}

// --------------------------------------------------------------------
int main()
{
  bool grille[DIM][DIM];

  initGrille(grille);
  ajouterElements(grille);
  afficheGrille(grille);

  return 0;
}
