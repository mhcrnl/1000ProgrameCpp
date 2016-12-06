#include <iostream>
using namespace std;

void echange(int& a, int& b)
{
  int copie(a);
  a=b;
  b=copie;
}

void echange(double& a, double& b)
{
  double copie(a);
  a=b;
  b=copie;
}

void echange(char& a, char& b)
{
  char copie(a);
  a=b;
  b=copie;
}

int main()
{
    int    i(10),      j(55);
    char   a('B'),     b('a');
    double x(3.14159), y(1.414);

    cout << "Avant : i=" << i << " et j=" << j << endl;
    echange(i,j);
    cout << "Apres : i=" << i << " et j=" << j << endl << endl;

    cout << "Avant : a=" << a << " et b=" << b << endl;
    echange(a,b);
    cout << "Apres : a=" << a << " et b=" << b << endl << endl;

    cout << "Avant : x=" << x << " et y=" << y << endl;
    echange(x,y);
    cout << "Apres : x=" << x << " et y=" << y << endl;
    return 0;
}
