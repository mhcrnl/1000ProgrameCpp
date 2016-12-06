#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* La classe Livre */

class Livre {
public:
  Livre(string, string, int, bool);
  virtual ~Livre() {}
  virtual double calculer_prix() const ;
  virtual void afficher() const ;
    
protected:
  string titre;
  string auteur;
  int nbPages;
  bool  bestseller;
};

// constructeur

Livre::Livre(string titre, string auteur,
             int nbPages, bool bestseller)
  : titre(titre), auteur(auteur), nbPages(nbPages),
    bestseller(bestseller)
{}

// calcul du prix d'un livre
double Livre::calculer_prix() const
{
  double p(nbPages* 0.3);
  if (bestseller)
    return (p + 50.0);
  else return p;
}

// affichage des caracteristiques d'un livre
void Livre::afficher() const
{
  cout << "titre : " << titre <<endl;
  cout << "auteur : " << auteur <<endl;
  cout << "nombre de pages : " << nbPages <<endl;
  cout << "bestseller : " ;
  if (bestseller) cout << "oui";
  else            cout << "non";
  cout << endl;
  cout << "prix : " << this->calculer_prix() << endl;
}

/* la sous-classe Roman*/

class Roman: public Livre {
public:
  Roman(string, string, int, bool, bool);
  virtual ~Roman() {}
  virtual void afficher() const ;
  
protected:
  bool biographie;

};

Roman::Roman(string titre, string auteur,
             int nbPages, bool bestseller, bool biographie)
  : Livre(titre, auteur, nbPages, bestseller), biographie(biographie)
  
{}

void Roman::afficher() const
{
  Livre::afficher();
  if (biographie)
    cout << "Ce roman est une biographie" << endl;
  else
    cout << "Ce roman n'est pas une biographie" << endl;
}

/* les romans policiers */

class Policier : public Roman {
public:
  Policier(string, string, int, bool, bool);
  virtual ~Policier() {}
  virtual double calculer_prix() const ;
 
};

Policier::Policier(string titre, string auteur,
                   int nbPages, bool bestseller, bool biographie)
  : Roman(titre, auteur, nbPages, bestseller, biographie)
{}

double Policier::calculer_prix() const
{
  double p (Livre::calculer_prix() - 10.0);
  if (p <= 0.0) p = 1.0;
  return p;
}

/* la sous-classe BeauLivre */

class BeauLivre : public Livre {
public:
  BeauLivre(string, string, int, bool);
  virtual ~BeauLivre() {}
  virtual double calculer_prix() const ;
};

BeauLivre::BeauLivre(string titre, string auteur,
                     int nbPages, bool bestseller)
  : Livre(titre, auteur, nbPages, bestseller)
{}

double BeauLivre::calculer_prix() const
{
  return (Livre::calculer_prix() + 30.0);
}

/* la classe Librairie */

class Librairie : private vector <Livre*> {
public:
  void ajouter_livre(Livre* livre) { push_back(livre); }
  void vider_stock();
  void afficher() const;
};

void Librairie::afficher() const
{
  for (unsigned int i(0); i < size(); ++i){
    (*this)[i]->afficher();
    cout << endl;
  }
}

void Librairie::vider_stock()
{
  for (unsigned int i(0); i < size(); ++i) {
    delete (*this)[i];
  }
  clear();
}
      
int main()
{
  Librairie l;

  l.ajouter_livre(new Policier("Le chien des Baskerville", "A.C.Doyle",
                               221, false, false));
  l.ajouter_livre(new Policier("Le Parrain ", "A.Cuso",
                               367, true, false));
  l.ajouter_livre(new Roman("Le baron perche", "I. Calvino",
                            283, false, false));
  l.ajouter_livre(new Roman ("Memoires de Geronimo", "S.M. Barrett",
                             173, false, true));
  l.ajouter_livre(new BeauLivre ("Fleuves d'Europe", "C. Osborne",
                                 150, false));

  l.afficher();
  l.vider_stock();

  return 0;
}
