#include <iostream>
using namespace std;

// --- structure de donnees pour representer les rationnels
struct Rationnel {
  int p;
  unsigned int q;
};

void affiche(const Rationnel& r);
Rationnel addition(const Rationnel& r1, const Rationnel& r2);
Rationnel soustraction(const Rationnel& r1, const Rationnel& r2);
Rationnel multiplication(const Rationnel& r1, const Rationnel& r2);
Rationnel division(const Rationnel& r1, const Rationnel& r2);
void reduction(Rationnel& r);
unsigned int pgcd(unsigned int a, unsigned int b);

// fonction en extra pour faciliter l'ecriture du main()
// pas du tout necessaires pour le corrige
void afficheNL(const Rationnel& r) { affiche(r); cout << endl; }
void afficheADD(const Rationnel& r1, const Rationnel& r2)
{
  affiche(r1); cout << " + "; affiche(r2); cout << " = ";
  afficheNL(addition(r1, r2));
}
void afficheSOUS(const Rationnel& r1, const Rationnel& r2)
{
  affiche(r1); cout << " - "; affiche(r2); cout << " = ";
  afficheNL(soustraction(r1, r2));
}
void afficheMULT(const Rationnel& r1, const Rationnel& r2)
{
  affiche(r1); cout << " * "; affiche(r2); cout << " = ";
  afficheNL(multiplication(r1, r2));
}
void afficheDIV(const Rationnel& r1, const Rationnel& r2)
{
  affiche(r1); cout << " / ("; affiche(r2); cout << ") = ";
  afficheNL(division(r1, r2));
}

int main()
{
  Rationnel r1 = { 1, 2 }, r2 = {-3, 5 }, r3 = { 2, 1 };

  afficheNL(r1);
  afficheNL(r2);
  afficheNL(r3);

  afficheADD(r1, r2);
  afficheADD(r3, r2);
  afficheADD(r3, r3);

  afficheSOUS(r1, r2);
  afficheSOUS(r3, r2);
  afficheSOUS(r2, r2);

  afficheMULT(r1, r2);
  afficheMULT(r3, r2);
  afficheMULT(r2, r2);

  afficheDIV(r1, r2);
  afficheDIV(r3, r2);
  afficheDIV(r2, r2);

  return 0;
}

/* ================================================================= */
void affiche(const Rationnel& r)
{
  cout << r.p;
  if (r.q != 1) cout << "/" << r.q;
}

/* ================================================================= */
unsigned int pgcd(unsigned int a, unsigned int b)
{
  int x(a), y(b), r;
  while (y != 0) {
    r = x%y;
    x = y;
    y = r;
  }
  return x;
}

/* ================================================================= */
void reduction(Rationnel& r)
{
  unsigned int s;
  if (r.p < 0)
    s = pgcd(-r.p, r.q);
  else
    s = pgcd(r.p, r.q);
  if (s != 1) {
    r.p /= s;
    r.q /= s;
  }
}

/* ================================================================= */
Rationnel addition(const Rationnel& r1, const Rationnel& r2)
{
  Rationnel rez = { r1.p*r2.q + r2.p*r1.q,
                    r1.q*r2.q };
  reduction(rez);
  return rez;
}

/* ================================================================= */
Rationnel soustraction(const Rationnel& r1, const Rationnel& r2)
{
  Rationnel rez = { r1.p*r2.q - r2.p*r1.q,
                    r1.q*r2.q };
  reduction(rez);
  return rez;
}

/* ================================================================= */
Rationnel multiplication(const Rationnel& r1, const Rationnel& r2)
{
  Rationnel rez = { r1.p*r2.p, r1.q*r2.q };
  reduction(rez);
  return rez;
}

/* ================================================================= */
Rationnel division(const Rationnel& r1, const Rationnel& r2)
{
  Rationnel rez;
  if (r2.p < 0) {
    rez.p = (-r1.p) * r2.q;
    rez.q = (-r2.p) * r1.q;
  } else if (r2.p > 0) {
    rez.p = r1.p * r2.q;
    rez.q = r2.p * r1.q;
  } else {
    // il faudrait normalement lancer une exception ici
    cout <<"Erreur: division par zero." << endl;
    rez.p = 0; rez.q = 1; // arbitraire
  }
  reduction(rez);
  return rez;
}
