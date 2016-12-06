#include <iostream>
#include <vector>
using namespace std;

//----------------------------------------------------------------------
class Figure {
public:
  virtual void affiche()  const = 0;
  virtual Figure* copie() const = 0;
  virtual ~Figure(){}
};

//----------------------------------------------------------------------
class Cercle : public Figure {
public:
  Cercle(double x = 0.0) : rayon(x) {
    cout << "Construction d'un cercle de rayon " << rayon << endl;
  }

  Cercle(const Cercle& autre) : Figure(autre), rayon(autre.rayon) {
    cout << "Copie d'un cercle de rayon " << rayon << endl;
  }

  ~Cercle() { cout << "Destruction d'un cercle" << endl; }

  Figure* copie() const { return new Cercle(*this); }

  void affiche() const {
    cout << "Un cercle de rayon " << rayon << endl;
  }

private:
  double rayon;
};

//----------------------------------------------------------------------
class Triangle : public Figure {
public:
  Triangle(double b = 0.0, double h = 0.0) : base(b), hauteur(h) {
    cout << "Construction d'un triangle " << base << "x" << hauteur << endl;
  }

  Triangle(const Triangle& autre) 
    : Figure(autre), base(autre.base), hauteur(autre.hauteur) 
  {
    cout << "Copie d'un triangle " << base << "x" << hauteur << endl;
  }

  ~Triangle() { cout << "Destruction d'un triangle" << endl; }

  Figure* copie() const { return new Triangle(*this); }

  void affiche() const {
    cout << "Un triangle " << base << "x" << hauteur << endl;
  }

private:
  double base; double hauteur;
};

//----------------------------------------------------------------------
class Carre : public Figure {
public:
  Carre(double x = 0.0) : cote(x) {
    cout << "Construction d'un carré de coté " << cote << endl;
  }

  Carre(const Carre& autre) : Figure(autre), cote(autre.cote) {
    cout << "Copie d'un carré de coté " << cote << endl;
  }

  ~Carre() { cout << "Destruction d'un carré" << endl; }

  Figure* copie() const { return new Carre(*this); }

  void affiche() const {
    cout << "Un carré de coté " << cote << endl;
  }

private:
  double cote;
};

//----------------------------------------------------------------------
class Dessin : private vector<Figure*> {
public:
  Dessin() : vector<Figure*>() {}

  // constructeur de copie faisant une copie profonde
  Dessin(const Dessin& autre) : vector<Figure*>()
  { copie_profonde(autre); }

  ~Dessin() { 
    cout << "Destruction d'un dessin" << endl;
    libere();
  }

  // opérateur d'affectation faisant une copie profonde
  Dessin& operator=(const Dessin& autre) {
    if (this != &autre) { 
      libere();              // libere la mémoire actuellement utilisée
      clear();               // vide le vector
      copie_profonde(autre); // copie en faisant une nouvelle allocation
    }
    return *this;
  }

  void ajouteFigure(const Figure& fig) { push_back(fig.copie()); }

  void affiche() const { 
    cout << "Je contiens :" << endl;
    for (unsigned int i(0); i < size(); ++i) (*this)[i]->affiche();
  }

private:
  // méthode (privée) servant au constructeur de copie et à l'operator=
  void copie_profonde(const Dessin& autre) {
    for (unsigned int i(0); i < autre.size(); ++i) 
      push_back(autre[i]->copie());
  }
  // méthode (privée) servant au destructeur et à l'operator=
  void libere() {
    for (unsigned int i(0); i < size(); ++i) delete (*this)[i];
  }
};

//----------------------------------------------------------------------
void LocalementUnCercleDePlus(const Dessin& img) {
   Dessin tmp(img);            
   tmp.ajouteFigure(Cercle(1));
   cout << "Affichage de 'tmp': " << endl;
   tmp.affiche();          
}

//----------------------------------------------------------------------
int main() {
   Dessin dessin;         

   dessin.ajouteFigure(Triangle(3,4));               
   dessin.ajouteFigure(Carre(2));

   LocalementUnCercleDePlus(dessin);
   
   dessin.ajouteFigure(Triangle(6,1));
   dessin.ajouteFigure(Cercle(12));

   cout << endl << "Affichage du dessin : " << endl;
   dessin.affiche();  

   return 0;
}
