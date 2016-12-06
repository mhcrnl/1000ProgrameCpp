#include <iostream>
using namespace std;

void echange(int &a, int &b);
void affiche(int tab[], unsigned int taille);
void tri_bulles(int tab[], unsigned int taille);

int main()
{
  int tab[] = { 3, 5, 12, -1, 215, -2, 17, 8, 3, 5, 13, 18, 23, 5, 4, 3, 2, 1 };
  unsigned int taille(18);
  //int tab[] = { 3, 2, 1, 0, -1 };
  //unsigned int taille(5);

  cout << "A trier :" << endl;
  affiche(tab, taille);
  tri_bulles(tab, taille);
  cout << "Resultat :" << endl;
  affiche(tab, taille);

  return 0;
}

void echange(int &a, int &b)
{
  int copie(a);
  a=b;
  b=copie;
}

void affiche(int tab[], unsigned int taille)
{
  for (unsigned int i(0); i < taille; ++i)
    cout << tab[i] << ' ';
  cout << endl << "----===----" << endl;
}

void tri_bulles(int tab[], unsigned int taille)
{
  bool fin(true);
  do {
        fin = true;
    for (unsigned int i(1); i < taille; ++i) {
          if (tab[i] < tab[i-1]) {
        echange(tab[i], tab[i-1]);
        fin = false;
        // affiche(tab, taille);
      }
    }
  } while (!fin);
}
