/**
	Author:		Mihai Cornel	Romania			mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                	Fedora 23	Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:    https://www.codechef.com/problems/CIELRCPT
*/
#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int testCases, price, i,c, a, n;
    cin >> testCases;

    while(testCases--){
        c = 0;
        cin >> price;

        n = price%2048;
        //cout<<"n = "<<n<<endl;
        a =price/2048;
        //cout <<"a = "<< a <<endl;
        while(n){
            if((n%2)== 1) c++;
            n=n/2;
        }
        cout<<"\n"<<a+c<<endl;
    }
    return 0;
}
