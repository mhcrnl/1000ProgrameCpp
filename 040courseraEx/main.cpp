#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int a(8);
    cout<<"a = "<<a<<endl;

int b(a + 4);
cout << "b="<<b<<endl;

int c;

a *= b - 7;
cout <<a<<endl;

a += 1;
c = a - b;

cout << a << ", " << 2*b << ", " << c << endl;

    return 0;
}
