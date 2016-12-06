#include <iostream>
#include <cmath>
using namespace std;

main()
{
    int n;               // le nombre a tester
    bool premier(true);  // resultat du test de primalite
    int diviseur(1);

    // Saisie du nombre a tester
    do {
        cout << "Entrez un nombre entier > 1 : ";
        cin >> n;
    } while (n <= 1);

    if (n % 2 == 0) {
        // le nombre est pair
        if (n != 2) {
            premier  = false;
            diviseur = 2;
        }
    } else {
        const double borne_max(sqrt(n));
        for (int i(3); (premier) && (i <= borne_max); i += 2) {
            if (n % i == 0) {
                premier  = false;
                diviseur = i;
            }
        }
    }

    cout << n ;

    if (premier) {
        cout << " est premier" << endl;
    } else {
        cout << " n'est pas premier, car il est divisible par "
             << diviseur << endl;
    }
}
