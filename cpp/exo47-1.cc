#include <iostream>
using namespace std;

// --------------------------------------------------------------------
class Point3D
{
public:
  bool compare(const Point3D& autre) const;
  void affiche() const;

  double x, y, z;
};

// --------------------------------------------------------------------
bool Point3D::compare(const Point3D& autre) const
{
  return (autre.x == x) && (autre.y == y) && (autre.z == z);
}

// --------------------------------------------------------------------
void Point3D::affiche() const
{
  cout << '(' << x << ", " << y << ", " << z << ')' << endl;
}

// ====================================================================
int main() {
  Point3D point1;
  Point3D point2;
  Point3D point3;

  point1.x = 1.0; point1.y = 2.0; point1.z = -0.1;
  point2.x = 2.6; point2.y = 3.5; point2.z =  4.1;
  point3 = point1;

  cout << "Point 1 :";
  point1.affiche();

  cout << "Point 2 :";
  point2.affiche();

  cout << "Le point 1 est ";
  if (point1.compare(point2)) {
    cout << "identique au";
  } else {
    cout << "différent du";
  }
  cout << " point 2." << endl;

  cout << "Le point 1 est ";
  if (point1.compare(point3)) {
    cout << "identique au";
  } else {
    cout << "différent du";
  }
  cout << " point 3." << endl;

  return 0;
}
