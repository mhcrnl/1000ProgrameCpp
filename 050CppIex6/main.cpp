

  #include <iostream>
    using namespace std;

    class A {
    friend void f();
    private:
        int field;
    public:
        int set(int x) { return field = ++x; }
        int get() { return ++field; }
    };

    void f(A &a) { a.field /= 2; }

    int main() {
        A a;
        a.set(2);
        f(a);
        cout << a.get();
        return 0;
    }
