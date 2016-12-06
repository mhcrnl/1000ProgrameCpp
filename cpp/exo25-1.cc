#include <iostream>
#include <cmath>
using namespace std;

// --------------------------------------------------------------------
struct Complexe {
  double x;
  double y;
};

struct Solutions {
  Complexe z1;
  Complexe z2;
};

// --------------------------------------------------------------------
void affiche(Complexe z);

Complexe addition      (Complexe z1, Complexe z2);
Complexe soustraction  (Complexe z1, Complexe z2);
Complexe multiplication(Complexe z1, Complexe z2);
Complexe division      (Complexe z1, Complexe z2);
Complexe sqrt          (Complexe z);

Solutions resoudre_second_degre(Complexe b, Complexe c);

// --------------------------------------------------------------------
int main()
{
  Complexe b  = { 3.0, -2.0 };
  Complexe c  = { -5.0, 1.0 };
  Solutions s;
  
  s = resoudre_second_degre(b, c);
  cout << "Avec b="; affiche(b); cout << " et c="; affiche(c); 
  cout << " on a :" << endl;
  cout << "  z1="; affiche(s.z1); cout << endl;
  cout << "  z2="; affiche(s.z2); cout << endl;

  return 0;
}

// --------------------------------------------------------------------
void affiche(Complexe z)
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

// --------------------------------------------------------------------
Complexe addition(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x + z2.x, z1.y + z2.y };
  return z;
}

// --------------------------------------------------------------------
Complexe soustraction(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x - z2.x, z1.y - z2.y };
  return z;
}

// --------------------------------------------------------------------
Complexe multiplication(Complexe z1, Complexe z2)
{
  Complexe z = { z1.x * z2.x - z1.y * z2.y ,
                 z1.x * z2.y + z1.y * z2.x };
  return z;
}

// --------------------------------------------------------------------
Complexe division(Complexe z1, Complexe z2)
{
  const double r(z2.x*z2.x + z2.y*z2.y);
  Complexe z = { (z1.x * z2.x + z1.y * z2.y)/r ,
                 (z1.y * z2.x - z1.x * z2.y)/r };
  return z;
}

// --------------------------------------------------------------------
Complexe sqrt(Complexe z)
{
  const double r(sqrt(z.x * z.x + z.y * z.y));
  Complexe retour;

  retour.x = sqrt((r + z.x) / 2.0);
  if (z.y >= 0.0)
    retour.y = sqrt((r - z.x) / 2.0);
  else
    retour.y = - sqrt((r - z.x) / 2.0);

  return retour;
}

// --------------------------------------------------------------------
Solutions resoudre_second_degre(Complexe b, Complexe c)
{
  Solutions reponse;

  Complexe deux   = { 2.0, 0.0 };
  Complexe quatre = { 4.0, 0.0 };

  Complexe sdelta(sqrt(soustraction(multiplication(b, b),
                                    multiplication(quatre, c))));

  // calcule -b
  b.x = -b.x; b.y = -b.y;

  reponse.z1 = division( soustraction(b, sdelta) , deux);
  reponse.z2 = division( addition    (b, sdelta) , deux);

  return reponse;
}
