#include <iostream>
#include <cmath>
using namespace std;

double f1(double x) { return x*x;             }
double f2(double x) { return sqrt(exp(x));    }
double f3(double x) { return log(1.0+sin(x)); }

typedef double (* Fonction)(double);

double demander_nombre()
{
  double res;
  cout << "Entrez un nombre réel : ";
  cin >> res;
  return res;
}

Fonction demander_fonction()
{
  int rep;
  Fonction choisie;
  do {
    cout << "De quelle fonction voulez-vous calculer "
         << "l'intégrale [1-5] ? ";
    cin >> rep;
  } while ((rep < 1) || (rep > 5));

    switch (rep) {
    case 1: choisie = f1 ; break ;
    case 2: choisie = f2 ; break ;
    case 3: choisie = f3 ; break ;
    case 4: choisie = sin ; break ;
    case 5: choisie = exp ; break ;
    }

  return choisie;
}

double integre(Fonction f, double a, double b)
{
  double res;
  res =  41.0 * ( f(a) + f(b) )
      + 216.0 * ( f((5*a+b)/6.0) + f((5*b+a)/6.0) )
      +  27.0 * ( f((2*a+b)/3.0) + f((2*b+a)/3.0) )
      + 272.0 * f((a+b)/2.0) ;
  res *= (b-a)/840.0;
  return res;
}

int main()
{
  double a(demander_nombre());
  double b(demander_nombre());

  Fonction choix(demander_fonction());

  cout.precision(12);
  cout << "Intégrale entre " << a
       << " et " << b << " :" << endl;
  cout << integre(choix, a, b) << endl;
  return 0;
}
