#include <iostream>
#include <cmath> // pour sqrt et acos
using namespace std;

// ## Repris d'un exercice précédent. Le mieux serait d'utiliser
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

  // pas demandé mais donné pour information :
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

// ====================================================================
int main()
{
  Vecteur v1(1.0, 2.0, -0.1);
  Vecteur v2(2.6, 3.5, 4.1);

  cout << "Vecteur V1 : " << v1 << endl;
  cout << "Vecteur V2 : " << v2 << endl;

  cout << "V1 + V2  : " << v1 + v2  << endl;
  cout << "V1 - V2  : " << v1 - v2  << endl;
  cout << " -V1     : " << -v1      << endl;
  cout << "3.2 * V1 : " << 3.2 * v1 << endl;
  cout << "V1 * V2  : " << v1 * v2  << endl;

  cout << "norme de V1    : " << v1.norme() << endl;
  cout << "norme de V2    : " << v2.norme() << endl;
  cout << "norme de V1+V2 : " << (v1 + v2).norme() << endl;

  cout << "angle de V1 et V2 : " << v1.angle(v2) << endl;
  cout << "angle de V2 et V1 : " << v2.angle(v1) << endl;

  // pas demandé mais donné pour information :
  cout << "V1 ^ V2  : " << (v1^v2)  << endl;
  cout << "V2 ^ V1  : " << (v2^v1)  << endl;

  return 0;
}
