#include <iostream>
#include <cmath> // pour sqrt et acos
using namespace std;

// ## Repris d'un exercice précédant. Le mieux serait d'utiliser
// ## ici la compilation séparée !
// --------------------------------------------------------------------
class Point3D
{
public:
  // constructeur par défaut
  Point3D() : x(0.0), y(0.0), z(0.0) {}
  // constructeur par 3 coordonnees
  Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

  // ex compare()
  bool operator==(const Point3D& autre) const;

  // methode d'acces en lecture
  double get_x() const { return x; }
  double get_y() const { return y; }
  double get_z() const { return z; }

protected:
  double x, y, z;
};

// --------------------------------------------------------------------
bool Point3D::operator==(const Point3D& autre) const
{
  return (autre.x == x) && (autre.y == y) && (autre.z == z);
}

// --------------------------------------------------------------------
ostream& operator<<(ostream& flot, const Point3D& p)
{
  flot << '(' << p.get_x() << ", " << p.get_y() << ", " << p.get_z() << ')';
  return flot; // à ne pas oublier !
}

// ## NOUVELLE CLASSE
// --------------------------------------------------------------------
class Vecteur : public Point3D
{
public:        
  Vecteur() : Point3D() {}
  Vecteur(double x, double y, double z) : Point3D(x, y, z) {}

  // opérateurs
  Vecteur& operator+=(const Vecteur& autre)
  { x += autre.x; y += autre.y; z += autre.z; return *this; }
  Vecteur operator+(const Vecteur& autre) const
  { return Vecteur(*this) += autre; }

  Vecteur& operator-=(const Vecteur& autre)
  { x -= autre.x; y -= autre.y; z -= autre.z; return *this; }
  Vecteur operator-(const Vecteur& autre) const
  { return Vecteur(*this) -= autre; }

  // l'opposé
  Vecteur operator-() const
  { return Vecteur(-x, -y, -z); }

  Vecteur& operator*=(double scal)
  { x *= scal; y *= scal; z *= scal; return *this; }
  Vecteur operator*(double scal) const
  { return Vecteur(*this) *= scal; }

  double operator*(const Vecteur& autre) const
  { return x * autre.x  +  y * autre.y  +  z * autre.z; }

  // pas demandé mais pour donné pour information :
  // le produit vectoriel
  Vecteur operator^(const Vecteur& autre) const
  { return Vecteur(y*autre.z - z*autre.y, 
                   z*autre.x - x*autre.z, 
                   x*autre.y - y*autre.x); }

  double norme() const { return sqrt(x*x + y*y + z*z); }

  double angle(const Vecteur& autre) const
  { return acos((*this * autre) / (norme() * autre.norme())); }
};

// --------------------------------------------------------------------
Vecteur operator*(double x, const Vecteur& v) { return v * x; }

// ## NOUVELLE CLASSE
// --------------------------------------------------------------------
class VecteurUnitaire : public Vecteur
{
public:        
  /* constructeur par défaut : choix d'une valeur arbitraire,       *
   * ici : le premier vecteur de base.                              */
  VecteurUnitaire() : Vecteur(1.0, 0.0, 0.0) {}

  // constructeur général : effectue la normalisation si nécessaire.
  VecteurUnitaire(double x, double y, double z) : Vecteur(x, y, z) 
  { normalise(); }

  // copie d'un vecteur en un vecteur unitaire.
  // construit le vecteur unitaire colinaire et de meme sens
  // que le vecteur à copier
  VecteurUnitaire(const Vecteur& a_copier) : Vecteur(a_copier) 
  { normalise(); }

  // redéfinition des opérateurs d'affectation
  VecteurUnitaire& operator+=(const Vecteur& autre) { 
    Vecteur::operator+=(autre); normalise(); return *this; 
  }
  VecteurUnitaire& operator-=(const Vecteur& autre) { 
    Vecteur::operator-=(autre); normalise(); return *this; 
  }
  VecteurUnitaire& operator*=(double x) { 
    Vecteur::operator*=(x);     normalise(); return *this; 
  }

  // méthodes masquantes, qui sont plus efficaces
  double angle(const VecteurUnitaire& autre) const
  { return acos(*this * autre); }
  double norme() const { return 1.0; }

private:
  // nouvelle méthode normalisant le vecteur
  // cette méthode est privée car c'est de la
  // "cuisine interne" qui ne regarde personne d'autre
  void normalise() {
    const double n(Vecteur::norme());

    if (n == 0.0) {
      /* si l'on veut normaliser le vecteur nul en tant que   *
       * vecteur unitaire (!!), on met à la place la valeur   * 
       * par defaut choisie pour les vecteurs unitaires (en   *
       * utilisant le constructeur par défaut).               */
      *this = VecteurUnitaire();
    }

    else if (n != 1.0) { // ce test pourrait être rendu plus robuste
                         // par : abs(n-1.0) < precision
                         // avec une "precision" à definir, voire passée
                         // en paramètre.
      x /= n; y /= n; z /= n;
    }
  }
};

// ====================================================================
int main()
{
  VecteurUnitaire v1(1.0, 2.0, -0.1);
  VecteurUnitaire v2(2.6, 3.5, 4.1);

  cout << "Vecteur V1 : " << v1 << endl;
  cout << "Vecteur V2 : " << v2 << endl;
  cout << "norme de V1 : " << v1.Vecteur::norme() << endl;
  cout << "norme de V2 : " << v2.Vecteur::norme() << endl;
  // Note : nous appelons ici la méthode norme de Vecteur
  // a des fins de *VERIFICATION* (pour lesquelles appeler la méthode
  // norme optimisée ne nous apprendrait rien ici !)

  cout << "V1 + V2       : " << v1 + v2  << endl;
  VecteurUnitaire v3(v1 + v2);
  cout << "V3 = V1 + V2  : " << v3  << endl;

  cout << "norme de V1+V2 : " << (v1 + v2).norme() << endl;
  cout << "norme de V3    : " << v3.Vecteur::norme() << endl;

  v3 = Vecteur(1,2,3);
  cout << "V3 = (1,2,3) : " << v3  << endl;
  cout << "norme de V3    : " << v3.Vecteur::norme() << endl;

  v3 += v1;
  cout << "V3 += V1 : " << v3  << endl;
  cout << "norme de V3    : " << v3.Vecteur::norme() << endl;

  cout << "angle de V1 et V2 : " << v1.angle(v2) << endl;

  return 0;
}
