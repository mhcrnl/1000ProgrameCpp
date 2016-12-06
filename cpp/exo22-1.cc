#include <iostream>
using namespace std;

struct Complexe {
  double x;
  double y;
};

// Solution simple
void affiche(Complexe z) 
{
  cout << "(" << z.x << "," << z.y << ")";

  // autre solution :  cout << z.x << "+" << z.y << "i";
}

// Solution plus complexe mais plus elegante
void affiche2(Complexe z)
{
  if ((z.x == 0.0) && (z.y == 0.0)) {
    cout << "0";
    return;
  }

  if (z.x != 0.0) {
    cout << z.x;
    if (z.y > 0.0)
      cout << "+";
    else if (z.y < 0.0) {
      cout << "-";
      z.y = -z.y; /* pas d'effet de bord car z est passe par valeur
                   * et non pas par reference */
    }
  }
  if (z.y != 0.0) {
    if ((z.x == 0.0) && (z.y == -1.0))
      cout << "-";
    else if (z.y != 1.0)
      cout << z.y;
    cout << "i";
  }
}

Complexe addition(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x + z2.x, z1.y + z2.y };
  return z;
}

Complexe soustraction(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x - z2.x, z1.y - z2.y };
  return z;
}

Complexe multiplication(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x * z2.x - z1.y * z2.y ,
                 z1.x * z2.y + z1.y * z2.x };
  return z;
}

Complexe division(Complexe z1, Complexe z2)
{
  const double r(z2.x*z2.x + z2.y*z2.y);
  Complexe z = { (z1.x * z2.x + z1.y * z2.y)/r ,
                 (z1.y * z2.x - z1.x * z2.y)/r };
  return z;
}

int main()
{
  Complexe un = { 1.0, 0.0 };
  Complexe i  = { 0.0, 1.0 };
  Complexe j;

  j = addition(un, i);

  affiche(un); cout << " + "; affiche(i); cout << " = ";
  affiche(j); cout << endl;

  Complexe z;

  z = multiplication(i,i);
  affiche(i); cout << " * "; affiche(i); cout << " = ";
  affiche(z); cout << endl;

  z = multiplication(j,j);
  affiche(j); cout << " * "; affiche(j); cout << " = ";
  affiche(z); cout << endl;

  Complexe z2;
  z2 = division(z,i);
  affiche(z); cout << " / "; affiche(i); cout << " = ";
  affiche(z2); cout << endl;

  z.x = 2.0; z.y = -3.0;
  z2 = division(z,j);
  affiche(z); cout << " / "; affiche(j); cout << " = ";
  affiche(z2); cout << endl;
  
  return 0;
}
