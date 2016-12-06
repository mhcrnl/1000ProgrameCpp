#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
 bool test1(true);
bool test2(false);
bool test3(true);

if (test1 or test2) {
  cout << "La" << " ";
} else {
  cout << "Si" << " ";
}

test1 = not test3;

if ((not test1 and test2) or test3) {
  if (test1 and test3) {
    cout << "La" << " ";
  } else {
    cout << "Si" << " ";
  }

  if (test3) {
    cout << "Si" << " ";
  } else {
    cout << "La" << " ";
  }
}
}
