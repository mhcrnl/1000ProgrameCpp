#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int x;
    double y;
    cin>>x>>y;
    if(x+0.50<y && x%5==0) y=y-x-0.50;
    cout<<setprecision(2)<<fixed<<y<<endl;

    return 0;
}
