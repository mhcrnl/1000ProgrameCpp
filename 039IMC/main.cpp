#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!Indicele masei corporale!" << endl;

    double greutate(98.76);
    double inaltime(1.85);
    double imc(greutate/(inaltime*inaltime));

    cout << "Greutatea: "<< greutate
            <<" kg si inaltimea: "<<inaltime
            <<" IMC: "<< imc << endl;
    return 0;
}
