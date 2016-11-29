#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!Calcul indicele masei corporale." << endl;

    double greutate(98.50);
    double inaltime(1.85);

    cout << "Introduceti greutatea in kg(85.98): ";
    cin >> greutate;
    cout << "Introduceti inaltimea in metri(1.85): ";
    cin >> inaltime;
    double imc(greutate / (inaltime*inaltime));

    cout << "Greutatea: " << greutate
         << "\nInaltimea: " << inaltime
         << "\nIMC: "<< imc <<endl;

    return 0;
}
