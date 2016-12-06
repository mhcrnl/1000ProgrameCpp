#include <iostream>
using namespace std;

int demander_nombre(int min, int max);

int main() {
  int num;
  num = demander_nombre(1, 100);
  cout << "Le nombre est : " << num << endl;
  num = demander_nombre(100, 1);
  cout << "Le nombre est : " << num << endl;
  return 0;
}

int demander_nombre(int a, int b) {
  int res;
  do {
    cout << "Entrez un nombre entier ";
    if (a >= b)
      cout << "superieur ou egal a " << a;
    else
      cout << "compris entre " << a << " et " << b;
    cout << " : ";
    cin >> res;
  } while ((res < a) || ((a < b) && (res > b)));

  return res;
}
