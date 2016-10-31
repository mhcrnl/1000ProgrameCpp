#include <iostream>
#include <iomanip>
using namespace std;

double atm(int x, double y){
    if(x+0.50<y && x%5==0) y=y-x-0.50;
    return y;
}

int main()
{
    //cout << "Hello world!" << endl;
    int x;
    float y;
    cin>>x>>y;
    cout<<setprecision(2)<<fixed<<atm(x,y)<<endl;
    return 0;
}
