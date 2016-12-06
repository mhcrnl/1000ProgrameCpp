#include <iostream>
#include <vector>
using namespace std;

typedef int Degre;

class Polynome {
public:
  // constructeurs
  Polynome(double coef = 0.0, unsigned int degre = 0);

  // methodes publiques
  Degre degre() const { return p.size()-1; }
  void affiche_coef(ostream& out, Degre deg, bool signe = true) const;
  double top() const { return p[degre()]; }
  double get_coef(unsigned int n) const { return p[n]; }
  void divise(Polynome const& denominateur, Polynome& quotien, Polynome& reste) const;

  // operateurs internes
  Polynome& operator=(const Polynome&);
  Polynome& operator+=(const Polynome&);
  Polynome& operator-=(const Polynome&);
  Polynome& operator*=(const Polynome&);
  Polynome& operator/=(const Polynome&);
  Polynome operator+(const Polynome&) const;
  Polynome operator-(const Polynome&) const;
  Polynome operator*(const Polynome&) const;
  Polynome operator/(const Polynome&) const;
  Polynome operator%(const Polynome&) const;
  bool operator==(const Polynome&) const;
  bool operator!=(const Polynome&) const;

private:
  // attributs prives
  vector<double> p;

  // méthodes privees
  void simplifie();
  void met_coef(double const c, Degre const d);
};

// ==============================================================
// definition des methodes

// --------------------------------------------------------------
Polynome::Polynome(double coef, unsigned int deg)
 : p(deg+1, 0.0) // garantit que le degre de p est deg
{
  p[deg] = coef; // change la valeur du coef de plus haut degre
}

// --------------------------------------------------------------
Polynome Polynome::operator*(const Polynome& q) const {
  Polynome r(0.0);

  // Prepare la place pour le polynome resultat 
  // (de degre degre()+q.degre()).
  // Notez que r = 0, donc il contient deja un monome 
  // (0.0 de degre 0), et donc il suffit d'aller jusqu'au degre 1 
  // (et non 0) pour avoir le bon nombre de coefficients.
  for (Degre i(degre() + q.degre()); i >= 1; --i)
    r.p.push_back(0.0);

  // fait le calcul
  for (Degre i(0); i <= degre(); ++i)
    for (Degre j(0); j <= q.degre(); ++j)
      r.p[i+j] += p[i] * q.p[j];

  // retourne le resultat
  return r;
}

// --------------------------------------------------------------
Polynome& Polynome::operator*=(const Polynome& q) {
  return (*this = *this * q);
}

// --------------------------------------------------------------
Polynome& Polynome::operator=(const Polynome& q) {
  if (&q != this) { p = q.p; }
  return *this;
}

// --------------------------------------------------------------
void Polynome::affiche_coef(ostream& out, Degre deg, bool signe) const
{
  if (p[deg] != 0) {
    if (signe && (p[deg] > 0.0))  out << "+";
    out << p[deg];
    if (deg > 1)
      out << "*X^" << deg;
    else if (deg == 1) out << "*X";
  }
}

// --------------------------------------------------------------
Polynome& Polynome::operator+=(const Polynome& q) {
  // garantit que le degre de p (resultat) est au moins le degre de b
  while (degre() < q.degre()) p.push_back(0);

  for (Degre i(0); i <= q.degre(); ++i) p[i] += q.p[i];

  return *this;
}

// --------------------------------------------------------------
Polynome& Polynome::operator-=(const Polynome& q)
{
  // garantit que le degre de p (resultat) est au moins le degre de b
  while (degre() < q.degre()) p.push_back(0);

  for (Degre i(0); i <= q.degre(); ++i) p[i] -= q.p[i];

  // garantit la bonne forme du polynome
  simplifie();

  return *this;
}

// --------------------------------------------------------------
bool Polynome::operator==(const Polynome& q) const {
  return p == q.p;
}

// --------------------------------------------------------------
bool Polynome::operator!=(const Polynome& q) const {
  return p != q.p;
}

// --------------------------------------------------------------
void Polynome::simplifie()
{
  while ((!p.empty()) && (top() == 0.0)) p.pop_back();
  if (p.empty()) p.push_back(0.0);
}

// --------------------------------------------------------------
void Polynome::met_coef(const double c, const Degre d)
{
  // garantit que le degré de p est au moins d
  while (degre() < d) p.push_back(0);
  p[d] = c;
}

// --------------------------------------------------------------
void Polynome::divise(const Polynome& denominateur,
                      Polynome& quotien, Polynome& reste) const
{
  quotien = 0;
  reste = *this;
  for (Degre dq(reste.degre() - denominateur.degre());
       (dq >= 0) // il est important ici que dq soit signe
         && (reste != 0);
       dq = reste.degre() - denominateur.degre()) {
    quotien.met_coef(reste.top() / denominateur.top(), dq);
    reste -= Polynome(quotien.p[dq], dq) * denominateur;
  }
}

// --------------------------------------------------------------
Polynome Polynome::operator/(const Polynome& q) const {
  Polynome r,s;
  divise(q,r,s);
  return r;
}

// --------------------------------------------------------------
Polynome Polynome::operator%(const Polynome& q) const {
  Polynome r,s;
  divise(q,r,s);
  return s;
}

// --------------------------------------------------------------
Polynome& Polynome::operator/=(const Polynome& q) {
  return *this = *this / q;
}

// --------------------------------------------------------------
Polynome Polynome::operator+(const Polynome& q) const {
  return (Polynome(*this) += q);
}

// --------------------------------------------------------------
Polynome Polynome::operator-(const Polynome& q) const {
  return (Polynome(*this) -= q);
}

// ==============================================================
// operateurs externes

// --------------------------------------------------------------
ostream& operator<<(ostream& sortie, const Polynome& polynome)
{
  // plus haut degre : pas de signe + devant
  Degre i(polynome.degre());
  polynome.affiche_coef(sortie, i, false);

  // degre de N a 0 : +a*X^i
  for (--i; i >= 0; --i) polynome.affiche_coef(sortie, i);

  // degre 0 : afficher quand meme le 0 si rien d'autre
  if ((polynome.degre() == 0) && (polynome.get_coef(0) == 0.0))
    sortie.operator<<(0);

  return sortie;
}

// --------------------------------------------------------------
Polynome operator*(double x, Polynome const & p)
{
  return Polynome(x, 0) * p;
}

// ==============================================================
void affiche_res(const Polynome& p, const Polynome& q,
		 const Polynome& r, const Polynome& s)
{
  cout << "La division de " << p << " par " << q << endl;
  cout << "  a pour quotien " << r << endl;
  cout << "  et pour reste " << s << endl;
}

// ==============================================================
int main() {
  const Polynome X( 1.0, 1);
  const Polynome X2(1.0, 2);
  const Polynome X3(1.0, 3);
  const Polynome X4(1.0, 4);
  const Polynome X5(1.0, 5);

  Polynome p(3.2, 4);
  cout << "p=" << p << endl;

  Polynome q(1.1, 2), r;

  r = p * q;
  cout << p << " * " << q << " = " << r << endl;

  p = 5*X3 + 4*X2 - 2*X + 3;
  q = -2*X2 + 2*X + 1;
  Polynome s;

  p.divise(q, r, s);
  affiche_res(p,q,r,s);

  // -----------------------------------------------------------
  q = p;
  p.divise(q, r, s);
  affiche_res(p,q,r,s);

  // -----------------------------------------------------------
  q = 3;
  p.divise(q, r, s);
  affiche_res(p,q,r,s);

  // -----------------------------------------------------------
  q = 6*X4 + 5*X3 + 4*X2 - 2*X + 3;

  p.divise(q, r, s);
  affiche_res(p,q,r,s);

  // -----------------------------------------------------------
  q = Polynome(3,5);

  p.divise(q, r, s);
  affiche_res(p,q,r,s);

  return 0;
}
