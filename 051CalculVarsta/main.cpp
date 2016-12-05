#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    // Calcul varsta
    cout<<"Introduceti varsta dvs. in ani: ";
    int varsta;
    cin>>varsta;

    int anulnasterii(2016 - varsta);

    cout<<"Anul nasterii este: "<<anulnasterii<<endl;


    return 0;
}
