#include <iostream>
using namespace std;

double factorielle(int k);
double somme_partielle(double x, int N);
int demander_nombre(int a = 2, int b = 170);

int main()
{
  int N(demander_nombre());

  double x;
  cout.precision(16);
  do {
    cout << "entrez une valeur x pour le calcul de cos(x) : ";
    cin >> x;
    cout << "cos(x) ~ " << somme_partielle(x,N) << endl;
  } while (x != 0.0);
  return 0;        
}

double factorielle(int k)
{
  double fact(1.0);
  if (k == 0) return fact;       // 0! = 1
  else {
    for(int i(2); i <= k; ++i)
      fact *= i;                 // k! = 1*2*..*k
  }
  return fact;
}

double somme_partielle(double x, int N)
{
  double current_approx(0.0);// approximation courante
  double powerx(1.0);        // puissance de x (initialise à x^0=1)

  for(int i(0); i < N; ++i) {
    if (i%2 != 0)
      current_approx -= powerx / factorielle(i*2);
    else
      current_approx += powerx / factorielle(i*2);
    powerx *= x*x; // => x^0, x^2, x^4, x^6, ...x^2n
  }
  return current_approx;
}

int demander_nombre(int a, int b)
{
  int res;

  if (a > b) { res=b; b=a; a=res; }

  do {
    cout << "Entrez le degre d'approximation (entre "
         << a << " et " << b <<") : ";
    cin >> res;
  } while ((res < a) || (res > b));
  return res;
}
