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
    int variabila;
};

int main()
{
    cout << "Hello world!Exemplu cu clase" << endl;
    Class *classPtr;
    classPtr = new Class();
    classPtr->variabila=0;//deoarece este pointer accesul la variabila se face cu ->

    cout<< classPtr->variabila <<endl;
    cout<< ++ classPtr->variabila <<endl;
    cout<< ++ (classPtr->variabila) <<endl;

    cout<< ++(*classPtr).variabila<<endl;

    delete classPtr;

    return 0;
}
