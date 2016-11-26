#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world! Cel mai mare numar!" << endl;

    ofstream myfile("celmaimare.txt", ios::app);


    int numar;
    cout << "Introduce-ti primul numar: ";
    cin >> numar;
    int maxim = numar;

    myfile << "Numere introduse: "<<numar<<" ";

    while(numar != -1){
        if(numar > maxim) maxim = numar;
        cout<< "introduce-ti urmatorul numar(sau -1 pt. inchidere program): ";
        cin >> numar;
        if(myfile.is_open()){
            myfile << numar <<" ";
        } else {
            cout << "Fila nu a fost deschisa!\n";
        }
    }
    myfile<< "MAXIMUL ESTE: "<<maxim<<"\n";
    myfile.close();

    string line;
    ifstream file("celmaimare.txt");
    if(file.is_open()){
        while(getline(file, line)){
            cout<<line<<"\n";
        }
        file.close();
    } else {
        cout<<"Fila nu a putut fi deschisa!\n";
    }


    cout << "Cel mai mare numar este: "<<maxim<<endl;

    return 0;
}
