#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world! Cel mai mare numar!" << endl;

    int numar;
    cout << "Introduce-ti primul numar: ";
    cin >> numar;
    int maxim = numar;

    while(numar != -1){
        if(numar > maxim) maxim = numar;
        cout<< "introduce-ti urmatorul numar(sau -1 pt. inchidere program): ";
        cin >> numar;
    }

    cout << "Cel mai mare numar este: "<<maxim<<endl;

    return 0;
}
