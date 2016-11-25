
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world! Cel mai mare număr." << endl;
    int num1, num2, mare;
    cout << "Introduceti primul numar pentru comparatie: ";
    cin >> num1;
    cout << "Introduce-ti al doilea numar: ";
    cin >> num2;

    mare = num1;
    if(mare<num2) mare = num2;

    ofstream file;
    file.open("celmaimarenumar.txt", ios::app);
    file << "Cel mai mare numar dintre: "<<num1<<" si "<<num2<<" este "<<mare <<".\n";
    file.close();

    string line;
    ifstream rFile("celmaimarenumar.txt");
    if(rFile.is_open()){
        while(getline(rFile, line)){
            cout << line <<"\n";
        }
        rFile.close();
    } else {
        cout <<"Fila nu a putut fi deschisa."<<endl;
    }

    return 0;
}
