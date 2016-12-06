#include <iostream>
#include <cmath> // pour M_PI
using namespace std;

class Forme { 
public:
  virtual void description() const {
    cout << "Ceci est une forme." << endl;
  }
  virtual double aire() const = 0;
};

class Cercle : public Forme { 
public:
  Cercle(double x = 0.0) : rayon(x) {}
  void description() const {
    cout << "Ceci est un cercle." << endl;
  }
  double aire() const { return M_PI * rayon * rayon; }
private:
  double rayon;
};

class Triangle : public Forme { 
public:
  Triangle(double h = 0.0, double b = 0.0) : base(b), hauteur(h) {}
  void description() const {
    cout << "Ceci est un triangle." << endl;
  }
  double aire() const { return 0.5 * base * hauteur; }
private:
  double base; double hauteur;
};

void affichageDesc(const Forme& f) {
  f.description(); 
  cout << " son aire est " << f.aire() << endl;
}

int main()
{
  Cercle c(5);                    
  affichageDesc(c);
  Triangle t(10, 2);
  affichageDesc(t);
  return 0;
}
