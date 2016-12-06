#include <iostream>
using namespace std;

int demander_nombre();

int main()
{
  int num;
  num = demander_nombre();
  cout << "Le nombre est : " << num << endl;
  return 0;
}

int demander_nombre()
{
  int res;
  cout << "Entrez un nombre entier : ";
  cin >> res;
  return res;
}
