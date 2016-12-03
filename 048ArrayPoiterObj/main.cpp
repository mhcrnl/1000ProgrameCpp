#include <iostream>

using namespace std;

class Array{
    int *valori;
    int dimensiune;
public:
    Array(int dim){
        dimensiune = dim;
        valori = new int[dimensiune];
        cout<<"Array are "<<dimensiune<<" de elemente."<<endl;
    }
    ~Array(void){
        delete[] valori;
        cout<<"Array are "<<dimensiune<<" de elemente a fost sters."<<endl;
    }
    int Get(int ix){
        return valori[ix];
    }
    void Put(int ix, int val){
        valori[ix] = val;
    }
};
int main()
{
    cout << "Hello world!" << endl;

    Array *arr = new Array(2);

    for(int i(0); i<2; i++){
        arr->Put(i,i+100);
    }
    for(int i(0); i<2;i++){
        cout<<"#"<<i+1<<":"<<arr->Get(i)<<endl;
    }

    delete arr;

    return 0;
}
