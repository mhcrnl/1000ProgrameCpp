#include <iostream>

using namespace std;

class Class {
public:
    Class(){cout<<"constructorul a fost apelat"<<endl;}
    ~Class(){cout<<"Destructorul a fost apelat"<<endl;}
    void Hello(void){cout<<"Obiectul spune SALUT!"<<endl;}

};

void DoCalculation(int i){
    if(i==0){
        throw string ("fatal1");
    }
    Class object;
    if(i ==1){
        throw string ("fatal2");
    }
    object.Hello();
    if(i ==2){
        throw string ("fatal3");
    }

}

int main()
{
    cout << "Hello world!" << endl;
    for(int i(0); i<3; i++){
        try{
            cout<<"_______"<<endl;
            DoCalculation(i);
        } catch(string &exec){
            cout<<exec<<endl;
        }
    }
    return 0;
}
