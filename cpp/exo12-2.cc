#include <iostream>
using namespace std;

int demander_nombre(int min, int max);

int main()
{
  int num;
  num = demander_nombre(1, 100);
  cout << "Le nombre est : " << num << endl;
  return 0;
}

int demander_nombre(int a, int b)
{
  // echange a et b si ils ne sont pas dans le bon ordre
  // ceci est NECESSAIRE si on ne veut pas de boucle infinie
  // dans le cas ou on appelle la fonction avec a>b !!
  if (a > b) { int tmp(b); b=a; a=tmp; }

  int res;

  do {
    cout << "Entrez un nombre entier compris entre "
         << a << " et " << b <<" : ";
    cin >> res;
  } while ((res < a) || (res > b));
  return res;
}
