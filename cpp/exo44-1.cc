#include <iostream>
using namespace std;

void echange(int &a, int &b)
{
  int copie(a);
  a=b;
  b=copie;
}

void tri_shell(int tab[], unsigned int taille) {
  for (unsigned int k(taille/2); k >= 1; k /= 2)
    for (unsigned int i(k+1); i <= taille; ++i) {
      int j(i-k);
      while (j > 0) {
        if (tab[j-1] > tab[j+k-1]) {
          echange(tab[j-1], tab[j+k-1]);
          j -= k;
        } else {
          j = 0;
        }
      }
    }
}

int main()
{
  const unsigned int taille(12);
  int a_trier[taille] = {4, 5, 2, 6 , 4, 2, 1, 8, -1, 4, 6, -1 };

  for (unsigned int i(0); i < taille; ++i) cout << a_trier[i] << endl;
  tri_shell(a_trier, taille);
  cout << "---------------------" << endl;
  for (unsigned int i(0); i < taille; ++i) cout << a_trier[i] << endl;

  return 0;
}
