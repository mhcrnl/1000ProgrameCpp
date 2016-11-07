      #include <iostream>
    using namespace std;

    namespace S {
    int A = 1;
    }

    namespace S {
    int B = A + 2 ;
    }

    int main(void) {
        S::A = S::A + 1;
        { using namespace S;
           ++B;
        }
        cout << S::B << S::A;
        return 0;
    }
