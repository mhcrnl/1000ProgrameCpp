/**
    Author:        Mihai Cornel    Romania            mhcrnl@gmail.com
    System:        Ubuntu 16.04    Code::Blocks 13.12    gcc 5.4.0
                    Fedora 23    Code::Blocks 16.01    gcc 5.3.1
    Copyright:    @2016
    Problem:    cel mai mare numar cu do...while
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!Cel mai mare numar do...while" << endl;
    int numar;
    int maxim = -100000;
    int counter=0;

    // insert #include <fstream>
    ofstream fila("fila.txt", ios::app);

    if(fila.is_open()){
            fila << "Numere introduse: ";
        } else {
            cout << "Fila nu a fost deschisa!";
        }

    do
    {
        cout<< "Introduceti un numar(-1 pt inchidere): ";
        cin >> numar;
        if(numar != -1) counter++;
        if (numar > maxim)
            maxim = numar;

        if(fila.is_open()){
            fila << numar << " ";
        } else {
            cout << "Fila nu a fost deschisa!";
        }

    } while (numar != -1);

    if(counter){
        cout<< "Numarul cel mai mare este: "<<maxim<<endl;
    } else {
        cout << "Nu a-ti introdus niciun numar!"<<endl;
    }

    if(fila.is_open()){
            fila << "Cel mai mare numar este: " << maxim<<endl;
            fila.close();
        } else {
            cout << "Fila nu a fost deschisa!";
        }

    //citeste liniili din fila inc <fstream> <string>
    string line;
    ifstream file("fila.txt");
        if(file.is_open()){
            while(getline(file, line)){
                cout<<line<<"\n";
            }
            file.close();
        } else {
            cout<<"Fila nu a putut fi deschisa!\n";
        }

    return 0;
}
