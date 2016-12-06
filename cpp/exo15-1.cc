#include <cmath>
#include <iostream>
using namespace std;

double f(double x);
double integre(double a, double b);
double demander_nombre();

int main()
{
  double a(demander_nombre());
  double b(demander_nombre());

  // precision de l'affichage a 12 chiffres significatifs
  cout.precision(12);

  cout << "Integrale de f(x) entre " << a
       << " et " << b << " :" << endl;
  cout << integre(a,b) << endl;
  return 0;
}

double f(double x) { return x*x; }
// double f(double x) { return x*x*x; }
// double f(double x) { return 1.0/x; }
//double f(double x) { return sin(x); }

double integre(double a, double b)
{
  double res;
  res =  41.0 * ( f(a) + f(b) )
      + 216.0 * ( f((5*a+b)/6.0) + f((5*b+a)/6.0) )
      +  27.0 * ( f((2*a+b)/3.0) + f((2*b+a)/3.0) )
      + 272.0 * f((a+b)/2.0) ;
  res *= (b-a)/840.0;
  return res;
}

double demander_nombre()
{
  double res;
  cout << "Entrez un nombre reel : ";
  cin >> res;
  return res;
}
