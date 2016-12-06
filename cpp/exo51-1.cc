#include <cmath>
#include <iostream>

using namespace std;

const double g(9.81);

class Balle
{
public:
    Balle(const double eps);
    Balle(const double eps, const double h);

    double hRebond() const;
    double vRebond() const;

    void rebondit(const unsigned int nrebonds = 1);
    void rebondit(const double haut, const unsigned int nrebonds);

private:
    void prochainRebond();

private:
    const double epsilon; // coefficient de rebond de la balle
    double h;             // maximum hauteur pour rebond courant
    double v;             // vitesse initiale rebond courant
};

int main()
{
    Balle tennis(0.75);
    /* 1ère question, on peut directement utiliser le modèle */
    tennis.rebondit(20.0, 4);
    cout << "Partant d'une hauteur de 20, une balle " << endl
         << "de tennis (eps=0.75) normalement constituée" << endl
         << "atteint une hauteur de " << tennis.hRebond()
         << " à son 4è rebond." << endl;

    cout << endl;

    Balle pingpong(0.9, 10.0);
    /* 2è question, notre modèle ne mémorisant pas en interne
       le nombre de rebonds effectué, il faut le faire pour lui */
    unsigned int rebonds(0);               // compteur de rebonds
    do
    {
        pingpong.rebondit();
        ++rebonds;
    } while (pingpong.vRebond() > 3.0);
    cout << "Ce n'est qu'au " << rebonds << "e rebonds" << endl
         << "qu'une balle de ping-pong (eps=0.9)" << endl
         << "lâchée d'une hauteur de 10," << endl
         << "rebondit avec une vitesse inférieur à 3..." << endl;
    return 0;
}

Balle::Balle(const double eps)
: epsilon(eps), h(0.0), v(0.0)
{ }

Balle::Balle(const double eps, const double h)
: epsilon(eps), h(h), v(0.0)
{ }

double Balle::hRebond() const { return h; }

double Balle::vRebond() const { return v; }

void Balle::rebondit(const unsigned int nrebonds)
{
    for (unsigned int i(0); i<nrebonds; ++i)
        prochainRebond();
}

void Balle::rebondit(const double haut,
                     const unsigned int nrebonds)
{
    h = haut;
    rebondit(nrebonds);
}

void Balle::prochainRebond()
{
    v = epsilon * sqrt(2*h*g);
    h = (v*v)/(2*g);
}
