     #include <iostream>

    using namespace std;

    class N {
    public:
        float x;
        N() { x = 0.0; }
        N(float a) { x = a; }
        N(N &n) { x = n.x; }
    };

    N &operator=(N &y,float f) { return *new N(f); }

    int main() {
        N a;
        a = 2.0;
        cout << a.x;
        return 0;
    }
