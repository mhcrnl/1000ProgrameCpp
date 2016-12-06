#include <iostream> 
using namespace std;

main()
{ 
    cout << "     Tables de multiplication" << endl;
    for (int i(2); i <= 10; ++i) { 
        cout << endl << " Table de " << i << " :" << endl; 
        for (int j(0); j <= 10; ++j) { 
            cout << "    " << i << " * " << j << " = " << i*j << endl; 
        }
    } 
}
