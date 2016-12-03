#include <iostream>

using namespace std;

class Class{
public:
    Class(){
        cout<<"Obiectul este creat."<<endl;
    }
    ~Class(){
        cout<<"Obiectul este distrus."<<endl;
    }
    void Afiseaza(void){
        cout<<"Valoare= "<< ++valoare<<endl;
    }
    int valoare;
};

int main()
{
    cout << "Hello world!" << endl;

    Class *ptrClass;
    ptrClass = new Class();

    ptrClass->valoare = 23;
    ptrClass->Afiseaza();

    delete ptrClass;

    return 0;
}
