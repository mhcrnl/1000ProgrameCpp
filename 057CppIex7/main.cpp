


    #include <iostream>
    #include <exception>
    #include <stdexcept>
    using namespace std;

    class Int {
    public:
        int v;
        Int(int a) : v(a) {}
    };

    void a() {
        throw Int(1);
    }

    void b() {
        try {
            a();
        } catch(Int &i) {
            throw Int(i.v + 1);
        }
    }

    void c() {
        try {
            b();
        } catch(...) {
            throw;
        }
    }

    int main(void) {
        try {
            c();
        } catch(Int &i) {
            cout << i.v;
        }
        return 0;
    }
