#include <iostream>

#include "clasfile.h"

using namespace std;

int main()
{
    FirstClass primaclasa;
    primaclasa.afiseazaSalut();
    primaclasa.afiseazaOctal(0123);
    int hex = 0x123;
    primaclasa.afiseazaHexidecimal(hex);
    primaclasa.afiseazaSpeedOfLight();

    int res;
    res = primaclasa.adunare(90, 55);
    cout<< "Rezultatul adunarii: "<< res<<endl;

    int rescad;
    rescad = primaclasa.scadere(45, -20);
    cout<<"Rezultatul scaderii :"<< rescad <<endl;

    int rem;
    rem = primaclasa.modulo(341, 23);
    cout<<"Modulo: "<< rem <<endl;

    cout << "Primul program cpp!" << endl;
    return 0;
}
