#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int cont=0;
    int numar;
    int largest;

    cout <<"Introduce-ti 10 numere: "<< endl;
    while(cont<10){
        cout<<"Numarul:"<<cont+1<<endl;
        cin >> numar;
        if(numar>largest){
            largest=numar;
        } else if(numar<0){
            cout<<"Eroare! Intoduce-ti un numar pozitiv"<<endl;
        }
        cont++;
    }
    cout<<"Cel mai mare numar este:" << largest<<endl;
    return 0;
}
