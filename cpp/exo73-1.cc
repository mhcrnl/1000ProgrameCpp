#include <iostream>
#include <vector>
#include <cstdlib> // pour la fonction abs(int)
using namespace std;

class Position {
public:
  Position(unsigned char li, unsigned char co) : x(li), y(co)
     { check(x); check(y); }
  void affiche() const;
  unsigned char ligne()   const { return x; }
  unsigned char colonne() const { return y; }
protected:
  unsigned char x;
  unsigned char y;
private:
  void check(unsigned char&);
};

void Position::check(unsigned char& pos) {
  if (pos < 1) pos = 1;
  else if (pos > 8) pos = 8;
}

void Position::affiche() const {
  cout << (char) ('a' + x-1) << (int) y;
}

// -------------------------------------------------------------------
enum Couleur { Blanc, Noir };

// -------------------------------------------------------------------
class Piece {
public: 
  bool deplace(const Position&);
  virtual void affiche() const { affiche_type(); p.affiche(); }
  Piece(Position p, Couleur c) : p(p), c(c) {}
protected:
  Position p;
  Couleur c;
  virtual void affiche_type() const = 0;
  virtual bool deplacement_possible(const Position&) const = 0;
};

bool Piece::deplace(const Position& new_p) {
  if (deplacement_possible(new_p)) {
    affiche_type();
    cout << " déplacé de "; p.affiche(); cout << " à ";
    new_p.affiche(); cout << endl;
    p = new_p;
    return true;
  } else {
    return false;
  }
}

// -------------------------------------------------------------------
class Cheval : public Piece {
public:
  Cheval(Position p, Couleur c) : Piece(p,c) {}
private:
  void affiche_type() const { cout << 'C'; }
  bool deplacement_possible(const Position& new_p) const {
    return (abs(p.ligne() - new_p.ligne()) 
            * abs(p.colonne() - new_p.colonne()) == 2);
  }
};

// -------------------------------------------------------------------
class Tour : public Piece {
public:
  Tour(Position p, Couleur c) : Piece(p,c) {}
private:
  void affiche_type() const { cout << 'T'; }
  bool deplacement_possible(const Position& new_p) const {
    return (((p.ligne() == new_p.ligne()) && (p.colonne() != new_p.colonne())) ||
            ((p.ligne() != new_p.ligne()) && (p.colonne() == new_p.colonne())) );
  }
};

// -------------------------------------------------------------------
class Jeu : public vector<Piece*>
{
public:
  Jeu();
  void affiche() const;
  virtual ~Jeu();
};

Jeu::Jeu() {
  push_back(new Cheval(Position(5,6), Noir ));
  push_back(new Cheval(Position(1,2), Blanc));
  push_back(new Tour(Position(7,6), Noir));
  push_back(new Tour(Position(3,2), Blanc));
}

Jeu::~Jeu() {
  for (unsigned int i(0); i < size(); ++i) { delete (*this)[i]; }
}

void Jeu::affiche() const {
  for (unsigned int i(0); i < size(); ++i) { 
    (*this)[i]->affiche(); 
    cout << endl;
  }
}

// ===================================================================
int main()
{
  Jeu mon_jeu;

  mon_jeu.affiche();
  mon_jeu[1]->deplace(Position(6, 4));
  mon_jeu[0]->deplace(Position(6, 4));
  mon_jeu[3]->deplace(Position(7, 1));
  mon_jeu[2]->deplace(Position(7, 1));
  cout << "----------" << endl;
  mon_jeu.affiche();

  return 0;
}
