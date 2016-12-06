#include <cmath>
#include <iostream>

using namespace std;

class Complexe {
public:
    Complexe(const double re = 0.0, const double im = 0.0)
    : re(re), im(im)
    {}

    double reel() const { return re; }
    double imag() const { return im; }

    bool operator==(const Complexe&) const;

    Complexe& operator+=(const Complexe&);
    Complexe& operator-=(const Complexe&);
    Complexe& operator*=(const Complexe&);
    Complexe& operator/=(const Complexe&);

    Complexe operator+(const Complexe&) const;
    Complexe operator-(const Complexe&) const;
    Complexe operator*(const Complexe&) const;
    Complexe operator/(const Complexe&) const;

private:
  void set_reel(double x) { re = x; }
  void set_imag(double y) { im = y; }

  double re;
  double im;
};

ostream& operator<<(ostream&, const Complexe&);

Complexe operator+(const double, const Complexe&);
Complexe operator-(const double, const Complexe&);
Complexe operator*(const double, const Complexe&);
Complexe operator/(const double, const Complexe&);

int main()
{
    Complexe defaut;
    Complexe zero(0.0, 0.0);
    Complexe un(1.0, 0.0);
    Complexe i(0.0, 1.0);
    Complexe j;

    cout << zero << " ==? " << defaut;
    if (zero == defaut) cout << " oui" << endl;
    else cout << " non" << endl;

    cout << zero << " ==? " << i;
    if (zero == i) cout << " oui" << endl;
    else cout << " non" << endl;

    j = un+i;
    cout << un << " + " << i << " = " << j << endl;

    Complexe trois(un);
    trois += un;
    trois += 1.0;
    cout << un << " + " << un << " + 1.0 = " << trois << endl;

    Complexe deux(trois);
    deux -= un;
    cout << trois << " - " << un << " = " << deux << endl;

    trois = 1.0 + deux;
    cout << "1.0 + " << deux << " = " << trois << endl;

    Complexe z(i*i);
    cout << i << " * " << i << " = " << z << endl;
    cout << z << " / " << i << " = " << z/i << " = ";
    cout << (z/=i) << endl;

    Complexe k(2.0,-3.0);
    z = k;
    z *= 2.0;
    z *= i;
    cout << k << " * 2.0 * " << i << " = " << z << endl;
    z = 2.0 * k * i / 1.0;
    cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;

    return 0;
}

Complexe& Complexe::operator+=(const Complexe& c)
{
    set_reel( reel() + c.reel() );
    set_imag( imag() + c.imag() );
    return *this;
}

Complexe& Complexe::operator-=(const Complexe& c)
{
    set_reel( reel() - c.reel() );
    set_imag( imag() - c.imag() );
    return *this;
}

Complexe& Complexe::operator*=(const Complexe& c)
{
    // attention ici, comme reel() va être modifié
    // par la première affectation, il faut préserver
    // la valeur d'origine pour le second calcul :
    const double anc_reel( reel() );

    set_reel( reel()   * c.reel() - imag() * c.imag() );
    set_imag( anc_reel * c.imag() + imag() * c.reel() );

    return *this;
}

Complexe& Complexe::operator/=(const Complexe& c)
{
    const double anc_reel( reel() );
    const double r(c.reel()*c.reel() + c.imag()*c.imag());
    set_reel(( reel() * c.reel() + imag()   * c.imag() ) / r);
    set_imag(( imag() * c.reel() - anc_reel * c.imag() ) / r);
    return *this;
}

bool Complexe::operator==(const Complexe& c) const
{
    return ((reel() == c.reel()) && (imag() == c.imag()));
}

Complexe Complexe::operator+(const Complexe& c) const
{
    return Complexe(*this) += c;
}

Complexe Complexe::operator-(const Complexe& c) const
{
    return Complexe(*this) -= c;
}

Complexe Complexe::operator*(const Complexe& c) const
{
    return Complexe(*this) *= c;
}

Complexe Complexe::operator/(const Complexe& c) const
{
    return Complexe(*this) /= c;
}

/* // version minimaliste
ostream& operator<<(ostream& out, const Complexe& c)
{
    out << '(' << c.reel() << ',' << c.imag() << ')';
    return out;
}
*/

// version plus sophistiquée
ostream& operator<<(ostream& out, const Complexe& c)
{
    out << '(';
    if (c == Complexe(0.0, 0.0)) out << "0";
    else {
        if ( (c.reel() != 0.0) ||
             ( (c.imag() != 1.0) && (c.imag() != -1.0) ) )
        {
            out << c.reel();
            if (c.imag() != 0.0) out << ',';
        }
        if (c.imag() != 0.0)
        {
            if (c.imag() == -1.0) out << "-i";
            else if (c.imag() == 1.0) out << "+i";
            else if (c.imag() > 0.0) out << "+" << c.imag();
            else out << c.imag();
        }
    }
    out << ')';
    return out;
}

// On utilise ici le plongement naturel des "double"
// dans "Complexe" offert par les constructeurs définis
// plus haut
Complexe operator+(const double x, const Complexe& c)
{
    return (Complexe(x) + c);
}

Complexe operator-(const double x, const Complexe& c)
{
    return (Complexe(x) - c);
}

Complexe operator*(const double x, const Complexe& c)
{
    return (Complexe(x) * c);
}

Complexe operator/(const double x, const Complexe& c)
{
    return (Complexe(x) / c);
}
