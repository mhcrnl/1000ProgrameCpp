#include <iostream>
using namespace std;

main()
{
    double S0;
    double r;
    double ir;

    do {
        cout << "Somme pretee (S0 > 0) : ";
        cin >> S0;
    } while (S0 <= 0.0);

    do {
        cout << "Montant fixe rembourse chaque mois (r > 0) : ";
        cin >> r;
    } while (r <= 0.0);

    do {
        cout << "Taux d'interet en % (0 < tx < 100) : ";
        cin >> ir;
    } while ( (ir <= 0.0) || (ir >= 100.0) );
    ir /= 100.00;

    double cumul(0.0);
    double S(S0);
    int nbr(0);   // nombre de remboursements
    while (S > 0.0) {
        ++nbr;
        cumul += ir * S;
        S -= r;
    }
    cout << "Somme des interets encaisses : " << cumul
         << "  (sur " << nbr << " mois)." << endl;
}
