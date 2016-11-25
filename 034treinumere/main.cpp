#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!Cel mai mare din trei numere." << endl;

    int num1, num2, num3, maxim;
    cout << "Introduce-ti primul numar: ";
    cin >> num1;
    cout << "Introduce-ti al doilea numar: ";
    cin >> num2;
    cout << "Introduce-ti primul numar: ";
    cin >> num3;

    maxim = num1;
    if(num2 > maxim) maxim = num2;
    if(num3 > maxim) maxim = num3;

    char file[] = "celmaimare.txt";

    ofstream myfile(file, ios::app);
    if(myfile.is_open()){
        myfile << "Cel mai mare numar dintre: "<< num1<< " / "<<num2<<" / "<<num3<<" este: "<<maxim<<"\n";
        myfile.close();
    } else {
        cout<<"Fila nu a fost deschisa."<<endl;
    }

    string line;
    ifstream myfiler(file);
    if(myfiler.is_open()){
        while(getline(myfiler, line)){
           cout << line << endl;
        }
        myfiler.close();
    } else {
        cout << "Fila nu a putut fi deschisa."<<endl;
    }

    return 0;
}
