/**
    Author:        Mihai Cornel    Romania            mhcrnl@gmail.com
    System:        Ubuntu 16.04    Code::Blocks 13.12    gcc 5.4.0
                   Fedora 23       Code::Blocks 16.01    gcc 5.3.1
    Copyright:     @2016
    Problem:       numere pare / impare
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!Numere pare impare" << endl;

    int numar;
    int par=0;
    int impar=0;

    ofstream fila("fila.txt", ios::app);


    cout << "introduce-ti primul numar: ";
    cin >> numar;

    if(fila.is_open()){
        fila << "Numere introduse: " << numar << " ";
    } else {
        cout << "Fila nu a fost deschisa!";
    }

    while (numar != 0){
        if (numar%2 == 1){
            impar++;
        } else {
            par++;
        }
        cout<<"Inroduce-ti urmatorul numar(0 pt inchidere): ";
        cin >> numar;
        if(fila.is_open()){
            fila << numar << " ";
        } else {
            cout << "Fila nu a fost deschisa!";
        }
    }
    if(fila.is_open()){
        fila << "Numere pare: " << par << " Numere impare: "<< impar<<endl;
    } else {
        cout << "Fila nu a fost deschisa!";
    }

    fila.close();

    cout<< "Numere pare: "<< par<<endl;
    cout<< "Numere impare: "<< impar<<endl;

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
