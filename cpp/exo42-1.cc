#include <cmath>
#include <iostream>
using namespace std;

const double epsilon(1e-6);

double f(double x)     { return (x-1.0)*(x-1.5)*(x-2.0); }
double df(double x)    { return (f(x+epsilon)-f(x))/epsilon; }
double itere(double x) { return x - f(x) / df(x); }

int main()
{
  double x, x2;
  cout << "Point de départ ? ";
  cin >> x;

  do {
    x2 = x;
    cout << " au point " << x2 << " : "<< endl;
    cout << "    f(x)  = " << f(x2) << endl;
    cout << "    f'(x) = " << df(x2) << endl;
    x = itere(x2);
    cout << "    nouveau point = " << x << endl;
  } while (abs(x-x2) > epsilon);

  cout << "Solution : " << x << endl;

  return 0;
}
