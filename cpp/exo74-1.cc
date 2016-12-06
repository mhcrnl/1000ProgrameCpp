#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef string Date;

// --------------------------------------------------------------------
class Ouvrage {
public :
  Ouvrage() : emprunte(false) {}
  virtual ~Ouvrage() {}
  void emprunt(string nom, Date d);
  void rendu();
  bool dispo() const { return !emprunte; }
  virtual void affiche() const;
protected :
  bool emprunte;
  string nom_emprunt;
  Date date_emprunt;
  virtual void info() const = 0;
};

void Ouvrage::affiche() const
{
  info();
  if (emprunte) {
    cout << "Emprunté le " << date_emprunt
         << " par " << nom_emprunt << endl;
  } else {
    cout << "Disponible." << endl;
  }
}

void Ouvrage::rendu() {
  nom_emprunt  = "";
  date_emprunt = Date(); // appel du constructeur par defaut
  emprunte = false;
}

void Ouvrage::emprunt(string nom, Date d) {
  nom_emprunt  = nom;
  date_emprunt = d; 
  emprunte = true;
}

// --------------------------------------------------------------------
class Periodique : public virtual Ouvrage
{
public:
  Periodique(string t, Date d, string e)
    : titre(t), date(d), editeur(e) {} 
  virtual ~Periodique() {}
protected:
  string titre;
  Date date;
  string editeur;
  void info() const;
};

void Periodique::info() const
{
  cout << "Journal :" << endl;
  cout << '\t' << titre << " de " << date << endl;
  cout << "\tpublié par " << editeur << endl;
}

// --------------------------------------------------------------------
class Livre : public virtual Ouvrage
{
public:
  Livre(string t, string auth, Date d, string e) 
    : titre(t), auteurs(auth), date(d), editeur(e) {}
  virtual ~Livre() {}
protected:
  string titre;
  string auteurs;
  Date date;
  string editeur;
  void info() const;
};

void Livre::info() const
{
  cout << "Livre :" << endl;
  cout << '\t' << titre << endl;
  cout << "\tpar " << auteurs << endl;
  cout << "\tpublié en " << date << " par " << editeur << endl;
}

// --------------------------------------------------------------------
class Video : public virtual Ouvrage
{
public:
  Video(string t, string auth, Date d, string e, unsigned int min) 
    : titre(t), auteurs(auth), date(d), editeur(e), minutes(min) {}
  virtual ~Video() {}
  void affiche();
protected:
  string titre;
  string auteurs;
  Date date;
  string editeur;
  unsigned int minutes;
  void info() const;
};

void Video::info() const
{
  cout << "Vidéo :" << endl;
  cout << '\t' << titre << endl;
  cout << "\tpar " << auteurs << endl;
  cout << "\tpubliée en " << date << " par " << editeur << endl;
  cout << "\tdurée : " << minutes << " minutes" << endl;
}

// --------------------------------------------------------------------
class OuvrageExterne : public virtual Ouvrage
{
public:
  OuvrageExterne(string nom, Date d, string where);
  virtual ~OuvrageExterne() {}
  void affiche() const;
protected:
  string origine;
};

OuvrageExterne::OuvrageExterne(string nom, Date d, string where) 
  : origine(where)
{
  emprunt(nom, d);
}

void OuvrageExterne::affiche() const
{
  Ouvrage::affiche();
  cout << "provenant de " << origine << endl;
}

// --------------------------------------------------------------------
class LivreExterne : public Livre, public OuvrageExterne
{
public:
  LivreExterne(string t, string auth, Date dp, string e, Date de, 
               string where, string nom)
    : Livre(t, auth, dp, e), OuvrageExterne(nom, de, where)
  {}
  virtual ~LivreExterne() {}
};

// --------------------------------------------------------------------
class Bibliotheque : public vector<Ouvrage*>
{
public:
  virtual ~Bibliotheque() {}
  unsigned int ajoute(Ouvrage*);
  void supprime(unsigned int);
  void affiche() const;
  void vider();
};

void Bibliotheque::vider()
{
  unsigned int i(size());
  while (i > 0) {
    --i;
    delete (*this)[i];
    pop_back();
  }
}

void Bibliotheque::affiche() const 
{
  for (unsigned int i(0); i < size(); ++i) {
    cout << i << "- ";
    (*this)[i]->affiche();
  }
}

unsigned int Bibliotheque::ajoute(Ouvrage* o)
{
  push_back(o);
  return (size()-1);
}

void Bibliotheque::supprime(unsigned int del)
  /* Note : si on connait bien la STL, on peut aussi le faire avec 
     les iterateurs et la methode erase().  */
{
  if (del < size()) {
    delete (*this)[del];
    const unsigned int end(size()-2);
    for (unsigned int i(del); i <= end; ++i)
        (*this)[i] = (*this)[i+1];
    pop_back();
  }
}

// ====================================================================
int main()
{
  Bibliotheque mabib;

  mabib.ajoute(new Livre("Programmation orientée objets en C++",
                         "Micheloud et Rieder", "2003", "PPUR"));

  mabib.ajoute(new Periodique("Computational Linguistics", 
                              "12/2003", "MIT Press"));

  unsigned int o1, o2;
  o1 = mabib.ajoute(new Video("Nanometers and Gigabucks", 
                              "G. E. Moore", "1996", 
                              "University Video Communications", 61));

  o2 = mabib.ajoute(new LivreExterne("Elements of Information Theory",
                                     "Cover and Thomas", "1991", 
                                     "Wiley", "25/02/2004",
                                     "ETHZ-BC", "C. Chatnonne"));

  mabib.affiche();
  cout << "==================================================" << endl;

  mabib[o1]->emprunt("J.-C. Chappelier", "05/07/2004");
  mabib.supprime(o2);

  mabib.affiche();

  mabib.vider();

  return 0;
}
