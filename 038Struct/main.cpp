/**
    Author:        Mihai Cornel    Romania            mhcrnl@gmail.com
    System:        Ubuntu 16.04    Code::Blocks 13.12    gcc 5.4.0
                   Fedora 23       Code::Blocks 16.01    gcc 5.3.1
    Copyright:  @2016
    Problem:    https://www.codechef.com/problems/PERMUT2
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

 typedef struct
{
    string titlu;
    string autor;
    string subiect;
    int id;
} CARTE;


int main()
{
    cout << "Hello world!Structura Carte aplicatie" << endl;

    CARTE carte1, carte2;

    // insert #include <fstream>
    ofstream fila("fila.txt", ios::app);





    carte1.titlu = "Totul despre C++";
    carte1.autor = "George Albert";
    carte1.subiect = "Preda pe intelesul tuturor C++";
    carte1.id = 001;

    carte2.titlu = " C++ pe intelesul tuturor";
    carte2.autor = "Bijorn George Albert";
    carte2.subiect = "Preda pe intelesul tuturor C++";
    carte2.id = 002;

    if(fila.is_open()){
            fila << "CARTE" << carte1.autor<<carte1.titlu<< carte1.subiect<<carte1.id;
        } else {
            cout << "Fila nu a fost deschisa!";
    }
    fila.close();

    cout<< carte1.autor<<" "<<carte1.titlu <<endl;
    cout<< carte1.id << " "<<carte1.subiect << endl;

    cout<< carte2.autor<<" "<<carte2.titlu <<endl;
    cout<< carte2.id << " "<<carte2.subiect << endl;

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
