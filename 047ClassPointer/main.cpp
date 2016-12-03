#include <iostream>

using namespace std;

class Class{
public:
    Class(){
        cout<<"Obiectul creat cu constructorul#1"<<endl;
    }
    Class(int val){
        cout<<"Obiectul creat cu constructorul#2"<<endl;
        valoare = val;
    }
    ~Class(){
        cout<<"Destructorul apelat"<<valoare<<endl;
    }
    void Afiseaza(){
        cout<<"Valoare= "<<++valoare<<endl;
    }
    int valoare;
};

int main()
{
    cout << "Hello world!" << endl;

    Class *obj1;
    Class *obj2;

    obj1 = new Class();
    obj2 = new Class(56);

    obj1->valoare =1;
    obj1->Afiseaza();
    obj2->Afiseaza();

    delete obj1;
    delete obj2;

    return 0;
}
