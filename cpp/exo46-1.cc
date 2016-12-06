#include <iostream>
#include <cmath>    // pour M_PI et sqrt()

using namespace std;

class Cercle {
public:
    double surface() const { return M_PI * rayon * rayon; }
    bool estInterieur(double x, double y) const {
        return (((x - this->x) * (x - this->x)  +
                 (y - this->y) * (y - this->y))
                <= rayon * rayon);
    }
    void getCentre(double& x, double& y) const {
        x = this->x;
        y = this->y;
    }
    void setCentre(double x, double y) {
       this->x = x;
       this->y = y;
    }
    double getRayon() const { return rayon; }
    void setRayon(double r) {
       if (r < 0.0) r = 0.0;
       rayon = r;
    }
private:
    double rayon;
    double x;  // abscisse du centre
    double y;  // ordonnee du centre
};

int main () {
    Cercle c1, c2;

    c1.setCentre(1.0, 2.0);
    c1.setRayon(sqrt(5.0)); // passe par (0, 0)
    c2.setCentre(-2.0, 1.0);
    c2.setRayon(2.25);  // 2.25 > sqrt(5) => inclus le point (0, 0)

    cout << "Surface de C1 : " << c1.surface() << endl;
    cout << "Surface de C2 : " << c2.surface() << endl;

    cout << "position du point (0, 0) : ";
    if (c1.estInterieur(0.0, 0.0)) cout << "dans";
    else                           cout << "hors de";
    cout << " C1 et ";
    if (c2.estInterieur(0.0, 0.0)) cout << "dans";
    else                           cout << "hors de";
    cout << " C2." << endl;

    return 0;
}
