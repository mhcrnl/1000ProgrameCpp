#include <iostream>
using namespace std;

void echange(int& a, int& b)
{
  int copie(a);
  a=b;
  b=copie;
}

int main()
{
  int i(10);
  int j(55);

  cout << "Avant : i=" << i << " et j=" << j << endl;
  echange(i,j);
  cout << "Apres : i=" << i << " et j=" << j << endl;
  return 0;
}
