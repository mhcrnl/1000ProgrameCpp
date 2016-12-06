#include <iostream>
#include <string>
using namespace std;

class Document {
public:
  Document(int, string, string);
  virtual ~Document();
  void afficher() const;

private:
  int taille;
  string nom;
  string extension;
};

Document::Document(int taille, string nom, string extension)
  :taille(taille), nom(nom), extension(extension)
{
  cout << "creation d'un document" << endl;
}

Document::~Document()
{
 cout << "destruction d'un document" << endl;
}

void Document::afficher() const
{
  cout << "Je suis le fichier " << nom << "." << extension<< endl;
  cout << "ma taille est de : " << taille << "Kb" << endl;
}

class Programme {
public:
  Programme(string, string, string);
  virtual ~Programme();
  void afficher() const;
private:
  string langage;
  string auteur;
  string descriptif;
};

Programme::Programme(string langage, string auteur, string descriptif)
  :langage(langage), auteur(auteur), descriptif(descriptif)
{
  cout << "creation d'un programme" << endl;
}

Programme::~Programme()
{
 cout << "destruction d'un programme" << endl;
}

void Programme::afficher() const
{
  cout << "Je suis ecrit en : " << langage << endl;
  cout << "mon auteur est   : " << auteur<<  endl;
  cout << "Je fait du : " << descriptif << endl;
}

class FichierCPP: public Programme, public Document{
public:
  FichierCPP(int, string, string, string, string, string);
  ~FichierCPP();
  void afficher () const;
};

FichierCPP::FichierCPP(int taille, string nom, string extension,
                       string langage, string auteur, 
                       string descriptif)
  : Programme(langage, auteur, descriptif), 
    Document(taille, nom, extension)
{
  cout << "construction d'un fichier C++" << endl;
}

FichierCPP::~FichierCPP()
{
  cout << "destruction d'un fichier C++" << endl;
}

void FichierCPP::afficher() const
{
 
  this->Document::afficher();
  this->Programme::afficher();
 
}

int main ()
{
  FichierCPP f(1600, "numeric", "cc", "C++", "C.Hacker", 
               "calcul numerique");
  f.afficher();
  return 0;
}
