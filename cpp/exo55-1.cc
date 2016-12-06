#include <iostream>
#include <vector>
using namespace std;

// ======================================================================
// ==== Vehicules

class Vehicule {
public:
  Vehicule(string marque, unsigned int date, double prix)
  : marque(marque), date_achat(date), prix_achat(prix), 
    prix_courant(prix)
  {}

  void affiche(ostream& affichage) const;
  void calculePrix();

protected:
  string       marque       ;
  unsigned int date_achat   ;
  double       prix_achat   ;
  double       prix_courant ;
};


// --------------------------------------------------
void Vehicule::affiche(ostream& affichage) const {
  affichage << "marque : "         << marque
            << ", date d'achat : " << date_achat
            << ", prix d'achat : " << prix_achat
            << ", prix actuel : "  << prix_courant
            << endl;
}

// --------------------------------------------------
void Vehicule::calculePrix() {
  double decote((2005 - date_achat) * .01);
  prix_courant = max(0.0, (1.0 - decote) * prix_achat); 
}

// ======================================================================
// ==== Avions

enum Type_Avion { HELICES, REACTION };

class Avion : public Vehicule {
public:
  Avion(string marque, unsigned int date, double prix,
        Type_Avion moteur, unsigned int heures);
  void affiche(ostream&) const;
  void calculePrix();

protected:
  Type_Avion   moteur     ;
  unsigned int heures_vol ;
};

// --------------------------------------------------
Avion::Avion(string marque, unsigned int date, double prix,
             Type_Avion moteur, unsigned int heures)
  : Vehicule(marque, date, prix), moteur(moteur), heures_vol(heures)
{}

// --------------------------------------------------
void Avion::affiche(ostream& affichage) const {
  affichage << " ---- Avion a ";
  if (moteur == HELICES) affichage << "helices";
  else                   affichage << "reaction";
  affichage << " ----" << endl;
  Vehicule::affiche(affichage);
  affichage << heures_vol << " heures de vol." << endl;
}

// --------------------------------------------------
void Avion::calculePrix() {
  double decote;
  if (moteur == HELICES)
    decote = 0.1 * heures_vol / 100.0;
  else
    decote = 0.1 * heures_vol / 1000.0;

  prix_courant = max(0.0, (1.0 - decote) * prix_achat); 
}

// ======================================================================
// ==== Voitures

class Voiture : public Vehicule {
public:
  Voiture(string marque, unsigned int date, double prix,
          double cylindree, unsigned int portes, double cv, double km);
  void affiche(ostream&) const;
  void calculePrix();

protected:
  double cylindree       ;
  unsigned int nb_portes ;
  double puissance       ;
  double kilometrage     ;
};

// --------------------------------------------------
Voiture::Voiture(string marque, unsigned int date, double prix,
                 double cylindree, unsigned int portes, double cv,
                 double km) 
  : Vehicule(marque, date, prix),  cylindree(cylindree),
    nb_portes(portes), puissance(cv),  kilometrage(km)
{}

// --------------------------------------------------
void Voiture::affiche(ostream& affichage) const {
  affichage << " ---- Voiture ----" << endl;
  Vehicule::affiche(affichage);
  affichage << cylindree << " litres, "
            << nb_portes << " portes, "
            << puissance << " CV, "
            << kilometrage << " km." << endl;
}

// --------------------------------------------------
void Voiture::calculePrix() {
  double decote((2005 - date_achat) * .02); 
  decote += 0.05 * kilometrage / 10000.0; 
  if (marque == "Fiat" || marque == "Renault") 
    decote += 0.1; 
  else if (marque == "Ferrari" || marque == "Porsche") 
    decote -= 0.2; 

  prix_courant = max(0.0, (1.0 - decote) * prix_achat); 
}

// ======================================================================
// ==== main()
int main()
{
  vector<Voiture> garage;
  vector<Avion>   hangar;

  garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0,
                           12000));
  garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0,
                           81320));
  garage.push_back(Voiture("Fiat",    2001,   7327.30, 1.6, 3,  65.0, 
                           3000));

  hangar.push_back(Avion("Cessna",      1972, 1230673.90, HELICES,  
                         250));
  hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, REACTION,
                         1300));

  for (unsigned int i(0); i < garage.size(); ++i) {
    garage[i].calculePrix();
    garage[i].affiche(cout);
  }

  for (unsigned int i(0); i < hangar.size(); ++i) {
    hangar[i].calculePrix();
    hangar[i].affiche(cout);
  }

  return 0;
}
