#include <iostream>
using namespace std;

// ----------------------------------------------------------------------
class Animal {
public:
  Animal(string, string);
  ~Animal();
  void affiche() const;
protected:
  string nom;
  string continent;
};

void Animal::affiche() const {
   cout<<"Je suis un " << nom << " et je vis en " << continent << endl;
}

Animal::Animal(string nom, string continent)
  :nom(nom), continent(continent)
{
  cout<< "Nouvel animal protege"<< endl;
}

Animal::~Animal() {
  cout<< "Je ne suis plus protege"<< endl;
}

// --------------------------------------------------------------------
class EnDanger {
public:
  void affiche() const;
  EnDanger(unsigned int);
  ~EnDanger();
protected:
  unsigned int nombre;
};

void EnDanger::affiche() const {
    cout << "Il ne reste que " << nombre
         << " individus de mon espece sur Terre" << endl;
}

EnDanger::EnDanger(unsigned int nombre)
  : nombre(nombre) {
  cout << "Nouvel animal en danger" << endl;
}

EnDanger::~EnDanger() {
  cout<< "ouf! je ne suis plus en danger"<< endl;
}

// --------------------------------------------------------------------
class Gadget {
public:
  void affiche() const;
  void affiche_prix() const;
  Gadget(string, double);
  ~Gadget();
protected:
  string nom;
  double prix;
};

void Gadget::affiche() const {
  cout << "Mon nom est " << nom << endl;
}

void Gadget::affiche_prix() const {
  cout << "Achetez-moi pour " << prix
       << " francs et vous contribuerez a me sauver!" << endl;
}

Gadget::Gadget(string nom, double prix)
  : nom(nom), prix(prix) {
  cout<< "Nouveau gadget"<< endl;
}

Gadget::~Gadget() {
  cout<< "Je ne suis plus un gadget"<< endl;
}

// ----------------------------------------------------------------------
class Peluche : public Animal, public EnDanger, public Gadget {
public:
  void etiquette() const;
  Peluche(string, string, string, unsigned int, double);
  ~Peluche();
};

void Peluche::etiquette() const {
  cout << "Hello," << endl;
  Gadget::affiche();
  Animal::affiche();
  EnDanger::affiche();
  affiche_prix();
  cout<<endl;
}

Peluche::Peluche(string nom_animal, string nom_gadget,
                 string continent, unsigned int nombre,  double prix)
  : Animal(nom_animal, continent), EnDanger(nombre), 
    Gadget(nom_gadget, prix)
{ cout << "Nouvelle peluche" << endl; }

Peluche::~Peluche() {
  cout << "Je ne suis plus une peluche" << endl;
}

// ----------------------------------------------------------------------
int main()
{
  Peluche panda("Panda","Ming","Asie", 200, 20.0);
  Peluche serpent("Cobra","Ssss","Asie", 500, 10.0);
  Peluche toucan("Toucan","Bello","Amerique", 1000, 15.0);

  panda.etiquette();
  serpent.etiquette();
  toucan.etiquette();

  return 0;
}
