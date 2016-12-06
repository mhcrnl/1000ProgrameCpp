#include <iostream>

using namespace std;

class X{
protected:
    int v;
};

//Y() este private nu este permis accesul din afara clasei
class Y : protected X{
    Y():v(0) {}
};

int main()
{
    cout << "Hello world!" << endl;

    Y *y = new Y();
    cout <<y->v;
    delete y;

    return 0;
}
