#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ----------------------------------------------------------------------
class Employe {
public:
  Employe(string prenom, string nom, unsigned int age,
                   string date)
    : nom(nom), prenom(prenom), age(age), date(date) {}
  virtual ~Employe() {}
  virtual double calculer_salaire() const = 0;
  virtual string get_nom() const { return prenom + ' ' + nom; }
protected:
  string nom;
  string prenom;
  unsigned int age;
  string date;
};

// ----------------------------------------------------------------------
class Commercial: public Employe {
public:
  Commercial(string prenom, string nom, unsigned int age, string date,
             double chiffre_affaire)
    : Employe(prenom, nom, age, date), chiffre_affaire(chiffre_affaire)
  {}
  ~Commercial() {}
protected:
  double  chiffre_affaire;
};

// ----------------------------------------------------------------------
class Vendeur: public Commercial {
public:
  Vendeur(string prenom, string nom, unsigned int age,
          string date, double chiffre_affaire)
    : Commercial(prenom, nom, age, date, chiffre_affaire)
  {}
  ~Vendeur() {}
  string get_nom() const;
  double calculer_salaire() const;
};

double Vendeur::calculer_salaire() const {
  return (0.2 * chiffre_affaire) + 400;
}

string Vendeur::get_nom() const {
  return "Le vendeur " + Employe::get_nom();
}

// ----------------------------------------------------------------------
class Representant: public Commercial {
public:
  Representant(string prenom, string nom, unsigned int age,
               string date, double chiffre_affaire)
    : Commercial(prenom, nom, age, date, chiffre_affaire)
  {}
  ~Representant() {}
  string get_nom() const;
  double calculer_salaire() const;
};

double Representant::calculer_salaire() const {
  return (0.2 * chiffre_affaire) + 800;
}

string Representant::get_nom() const {
  return "Le representant " + Employe::get_nom();
}

// ----------------------------------------------------------------------
class Technicien: public Employe {
public:
  Technicien(string prenom, string nom, unsigned int age, string date,
             unsigned int unites)
    : Employe(prenom, nom, age, date), unites(unites)
  {}
  ~Technicien() {}
  string get_nom() const;
  double calculer_salaire() const;
protected:
  unsigned int unites;
};

double Technicien::calculer_salaire() const {
   return 5.0 * unites;
}

string Technicien::get_nom() const {
  return "Le technicien " + Employe::get_nom();
}

// ----------------------------------------------------------------------
class Manutentionnaire: public Employe {
public:
  Manutentionnaire(string prenom, string nom, unsigned int age,
                   string date, unsigned int heures) 
    : Employe(prenom, nom, age, date), heures(heures)
  {}
  ~Manutentionnaire() {}
  string get_nom() const;
  double calculer_salaire() const;
protected:
  unsigned int heures;
};

double Manutentionnaire::calculer_salaire() const {
  return 65.0 * heures;
}

string Manutentionnaire::get_nom() const {
  return "Le manut. " + Employe::get_nom();
}

// ----------------------------------------------------------------------
class ARisque {
public:
  ARisque(double prime = 100) : prime(prime) {}
  virtual ~ARisque() {}
protected:
  double prime;
};

// ----------------------------------------------------------------------
class TechnARisque: public Technicien, public ARisque {
public:
  TechnARisque(string prenom, string nom, unsigned int age,
               string date, unsigned int unites, double prime)
    : Technicien(prenom, nom, age, date, unites), ARisque(prime)
  {}
  double calculer_salaire() const;
};

double TechnARisque::calculer_salaire() const {
   return Technicien::calculer_salaire() + prime;
}

// ----------------------------------------------------------------------
class ManutARisque: public Manutentionnaire, public ARisque {
public:
  ManutARisque(string prenom, string nom, unsigned int age,
               string date, unsigned int heures, double prime)
    : Manutentionnaire(prenom, nom, age, date, heures), ARisque(prime)
  {}
  double calculer_salaire() const;
};

double ManutARisque::calculer_salaire() const {
  return Manutentionnaire::calculer_salaire() + prime;
}

// ----------------------------------------------------------------------
class Personnel {
public:
  void ajouter_employe(Employe* newbie) {
    staff.push_back(newbie); }
  void licencie();
  void afficher_salaires() const;
  double salaire_moyen() const;
protected:
  vector<Employe*> staff;
};

void Personnel::licencie() {
  for (unsigned int i(0); i < staff.size(); ++i) {
    delete staff[i];
  }
  staff.clear();
}

double Personnel::salaire_moyen() const {
  double somme(0.0);
  for (unsigned int i(0); i < staff.size(); ++i) {
    somme += staff[i]->calculer_salaire();
  }
  return somme / staff.size();
}

void Personnel::afficher_salaires() const {
  for (unsigned int i(0); i < staff.size(); ++i) {
    cout << staff[i]->get_nom() << " gagne "
         << staff[i]->calculer_salaire() << " francs."
         << endl;
  }
}

// ----------------------------------------------------------------------
int main()
{
  Personnel p;
  p.ajouter_employe(new Vendeur("Pierre", "Business", 45,
                                "1995", 30000));
  p.ajouter_employe(new Representant("Leon", "Vendtout", 25,
                                     "2001", 20000));
  p.ajouter_employe(new Technicien("Yves", "Bosseur", 28,
                                   "1998", 1000));
  p.ajouter_employe(new Manutentionnaire("Jeanne", "Stocketout", 32,
                                         "1998", 45));
  p.ajouter_employe(new TechnARisque("Jean", "Flippe", 28,
                                     "2000", 1000, 200));
  p.ajouter_employe(new ManutARisque("Al", "Abordage", 30,
                                     "2001", 45, 120));

  p.afficher_salaires();
  cout << "Le salaire moyen dans l'entreprise est de "  
       << p.salaire_moyen() << " francs." << endl;

  // liberation memoire
  p.licencie();

  return 0;
}
