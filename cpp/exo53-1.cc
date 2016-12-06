#include <cmath>
#include <iostream>

using namespace std;

class Complexe {
public:
    Complexe(const double re = 0.0, const double im = 0.0);
    Complexe(const Complexe&);
    ~Complexe();

    double reel() const;
    double imag() const;

    Complexe& operator=(const Complexe&);
    Complexe& operator+=(const Complexe&);
    Complexe& operator-=(const Complexe&);
    Complexe& operator*=(const Complexe&);
    Complexe& operator/=(const Complexe&);

    bool operator==(const Complexe&) const;

    Complexe operator+(const Complexe&) const;
    Complexe operator-(const Complexe&) const;
    Complexe operator*(const Complexe&) const;
    Complexe operator/(const Complexe&) const;

private:
    double& reel();
    double& imag();

    double* re;
    double* im;
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
    if (zero == defaut) cout << " oui" << endl;
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

Complexe::Complexe(const double re, const double im)
: re(new double(re)), im(new double(im))
{ }

Complexe::Complexe(const Complexe& c)
: re(new double(c.reel())), im(new double(c.imag()))
{ }

Complexe::~Complexe()
{
    delete re;
    delete im;
}

double Complexe::reel() const { return *re; }

double Complexe::imag() const { return *im; }

double& Complexe::reel() { return *re; }

double& Complexe::imag() { return *im; }

Complexe& Complexe::operator=(const Complexe& c)
{
        if (&c != this)
        {
            reel() = c.reel();
            imag() = c.imag();
        }
    return *this;
}

Complexe& Complexe::operator+=(const Complexe& c)
{
    reel() += c.reel();
    imag() += c.imag();
    return *this;
}

Complexe& Complexe::operator-=(const Complexe& c)
{
    reel() -= c.reel();
    imag() -= c.imag();
    return *this;
}

Complexe& Complexe::operator*=(const Complexe& c)
{
    const Complexe oldme(*this);
    reel() = oldme.reel() * c.reel() - oldme.imag() * c.imag();
    imag() = oldme.reel() * c.imag() + oldme.imag() * c.reel();
    return *this;
}

Complexe& Complexe::operator/=(const Complexe& c)
{
    const Complexe oldme(*this);
    const double r(c.reel()*c.reel() + c.imag()*c.imag());
    reel() = (oldme.reel()*c.reel() + oldme.imag()*c.imag())/r;
    imag() = (oldme.imag()*c.reel() - oldme.reel()*c.imag())/r;
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
ostream& operator<<(ostream& o, const Complexe& c)
{
    o << '(' << c.reel() << ',' << c.imag() << ')';
    return o;
}
*/

// version plus sophistiquée
ostream& operator<<(ostream& o, const Complexe& c)
{
    o << '(';
    if (c == Complexe(0.0,0.0)) o << "0";
    else {
        if ( (c.reel() != 0.0) ||
             ( (c.imag()!=1.0) && (c.imag()!=-1.0) ) )
        {
            o << c.reel();
            if (c.imag() != 0.0) o << ',';
        }
        if (c.imag() != 0.0)
        {
            if (c.imag() == -1.0) o << "-i";
            else if (c.imag() == 1.0) o << "+i";
            else if (c.imag() > 0.0) o << "+" << c.imag();
            else o << c.imag();
        }
    }
    o << ')';
    return o;
}

Complexe operator+(const double x, const Complexe& c)
{
    return (Complexe(x,0.0) + c);
}

Complexe operator-(const double x, const Complexe& c)
{
    return (Complexe(x,0.0) - c);
}

Complexe operator*(const double x, const Complexe& c)
{
    return (Complexe(x,0.0) * c);
}

Complexe operator/(const double x, const Complexe& c)
{
    return (Complexe(x,0.0) / c);
}
