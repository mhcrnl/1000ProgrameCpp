#include <iostream>

using namespace std;


float div(float a, float b){
    if(b==0) throw string("Impartirea la 0!!!");
    return a/b;
}

int main()
{
    cout << "Hello world! Exception!" << endl;

    float a, b;

    while(cin>>a){
        try{
            cin>>b;
            cout<<div(a,b)<<endl;
        } catch(string &problem)
        {
            cout<<"Uite ce ai facut"<<endl;
            cout<<problem<<endl;
        }
    }
    return 0;
}
