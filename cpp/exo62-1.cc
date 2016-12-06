#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ====================================================================
enum Couleur { vide = 0, rouge, jaune };

// ====================================================================
class Jeu {
public:
  Jeu(unsigned int taille = 8);

  bool jouer(unsigned int, Couleur);
  Couleur gagnant() const;
  bool fini(Couleur&) const;
  unsigned int get_taille() const { return grille.size(); }
  ostream& affiche(ostream& out) const;

protected:
  vector< vector< Couleur > > grille;

private:
  unsigned int compte(Couleur, unsigned int, unsigned int,
                      int, int) const;
};

// ------------------------------------------------------------
Jeu::Jeu(unsigned int taille)
  : grille(taille, vector<Couleur>(taille, vide))
{}

// ------------------------------------------------------------
bool Jeu::jouer(unsigned int i, Couleur c) {
  if (c == vide) return false;
  if (i >= get_taille()) return false;
  unsigned int j(0);
  while ((j < get_taille()) && (grille[i][j] != vide)) ++j;
  if (j >= get_taille()) return false;
  grille[i][j] = c;
  return true;
}

// ------------------------------------------------------------
Couleur Jeu::gagnant() const {
  Couleur vainqueur(vide);
  for (unsigned int i(0); i < get_taille(); ++i) {
    for (unsigned int j(0); j < get_taille(); ++j) {
      if (grille[i][j] != vide) {
        vainqueur = grille[i][j];
        // teste dans les 5 directions possibles (+ (0,0) qui ne fait
        // rien)
        for (int di(0); di <= 1; ++di)
          for (int dj(-1); dj <= 1; ++dj)
            if (compte(vainqueur, i, j, di, dj) >= 4) return vainqueur;
      }
    }
  }
  return vide;
}

// ------------------------------------------------------------
unsigned int Jeu::compte(Couleur couleur,
                         unsigned int i, unsigned int j,
                         int di, int dj) const
{
  unsigned int n(1);
  if ((di != 0) || (dj != 0)) {
    for(i += di, j += dj;
        (i < get_taille()) && (j < get_taille()) && (grille[i][j] == couleur);
        i += di, j += dj)
      ++n;
  }
  return n;
}

// ------------------------------------------------------------
bool Jeu::fini(Couleur& resultat) const {
  resultat = gagnant();
  if (resultat == vide) {
    // est-ce plein ?
    for (unsigned int i(0); i < get_taille(); ++i) {
      for (unsigned int j(0); j < get_taille(); ++j) {
        if (grille[i][j] == vide)
          return false;
      }
    }
  }
  return true;
}

// ------------------------------------------------------------
ostream& operator<<(ostream& out, const Jeu& jeu) {
  return jeu.affiche(out);
}
ostream& Jeu::affiche(ostream& out) const {
  for (unsigned int j(get_taille()); j >= 1; --j) {
    for (unsigned int i(0); i < get_taille(); ++i) {
      switch (grille[i][j-1]) {
      case vide:  out << ' '; break;
      case rouge: out << '#'; break;
      case jaune: out << 'O'; break;
      }
    }
    out << endl;
  }
  for (unsigned int i(0); i < get_taille(); ++i) out << '-';
  out << endl;
  for (unsigned int i(1); i <= get_taille(); ++i) out << i;
  out << endl;
  return out;
}

// ====================================================================
class Joueur {
public:
  Joueur(string nom, Couleur couleur = rouge)
    : nom(nom), couleur(couleur) {}
  virtual ~Joueur() {}
  virtual void jouer(Jeu&) const = 0;
  string get_nom() const { return nom; }
  Couleur get_couleur() const { return couleur; }

protected:
  string nom;
  Couleur couleur;
};

// ====================================================================
class Partie {
public:
  Partie(Joueur const*, Joueur const*);
  void lancer();
  void vider();
protected:
  Joueur const* joueur[2];
  Jeu jeu;
};

// ------------------------------------------------------------
Partie::Partie(Joueur const* j1, Joueur const* j2) {
  joueur[0] = j1;
  joueur[1] = j2;
}

// ------------------------------------------------------------
void Partie::lancer() {

  unsigned int tour(0);
  Couleur vainqueur;
  do {
    joueur[tour]->jouer(jeu);
    tour = 1 - tour; // joueur suivant: 0 ->  1   1 -> 0
  } while (!jeu.fini(vainqueur));

  cout << "La partie est finie." << endl;
  cout << jeu << endl;
  if (vainqueur == joueur[0]->get_couleur()) {
    cout << "Le vainqueur est " << joueur[0]->get_nom() << endl;
  } else if (vainqueur == joueur[1]->get_couleur()) {
    cout << "Le vainqueur est " << joueur[1]->get_nom() << endl;
  } else {
    cout << "Match nul." << endl;
  }
}

// ------------------------------------------------------------
void Partie::vider() {
  delete joueur[0];
  delete joueur[1];
}

// ====================================================================
class Humain : public Joueur {
public:
  Humain(Couleur couleur = rouge) : Joueur("quidam", couleur) {
    cout << "Entrez votre nom : " << flush;
    cin >> nom;
  }
  void jouer(Jeu&) const;
};

// ------------------------------------------------------------
void Humain::jouer(Jeu& jeu) const {
  cout << jeu << endl;

  unsigned int lu;
  bool valide;
  do {
    cout << "Joueur " << nom << ", entrez un numéro de colonne" << endl
         << "  (entre 1 et " << jeu.get_taille() << ") : ";
    cin >> lu; // on pourrait faire ici la validation de la lecture
    --lu; // remet entre 0 et taille-1 (indice à la C++)
    valide = jeu.jouer(lu, couleur);
    if (!valide) cout << "-> Coup NON valide." << endl;
  } while (!valide);
}

// ====================================================================
class Ordi : public Joueur {
public:
  Ordi(Couleur couleur = jaune) : Joueur("Le programme", couleur) {}
  void jouer(Jeu&) const;
};

// ------------------------------------------------------------
void Ordi::jouer(Jeu& jeu) const {
  for (unsigned int i(0); i < jeu.get_taille(); ++i) {
    if (jeu.jouer(i, couleur)) {
      cout << nom << " a joué en " << i+1 << endl;
      return;
    }
  }
}

// ====================================================================
int main()
{
  Partie p(new Ordi(rouge), new Humain(jaune));
  p.lancer();
  p.vider();
  return 0;
}
