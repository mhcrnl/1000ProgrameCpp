#include <iostream>
#include <iomanip>
using namespace std;

class Atm{
public:
    int x;
    float y;
    float atmfun(int x, float y){
        if(x+0.50<y && x%5==0) y =y-x-0.50;
        return y;
    }
};
int main()
{
    //cout << "Hello world!" << endl;
    Atm atm;
    cin>>atm.x>>atm.y;
    cout<<setprecision(2)<<fixed<<atm.atmfun(atm.x, atm.y)<<endl;
    return 0;
}
