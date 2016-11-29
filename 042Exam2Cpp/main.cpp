#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
             struct sct {
        int t[2];
    };

    struct str {
        sct t[2];
    };


            str t[2] = { {0, 2, 4, 6}, {1, 3, 5, 7} };
            cout << t[1].t[0].t[1] << t[0].t[1].t[0];
    return 0;
}
