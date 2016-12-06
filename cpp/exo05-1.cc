#include <iostream>
#include <cmath>
using namespace std;

main()
{
  double x;                           // declaration
  double resultat;
  cout << "Entrez un nombre reel : "; // message
  cin  >> x;                          // lecture de x

  // Expression 1
  cout << "Expression 1 : ";
  if (x == 0.0) {
      cout << "indefinie" << endl;
  }
  else {
      resultat = x / (1.0 - exp(x));
      cout << resultat << endl;
  }

  // Expression 2
  cout << "Expression 2 : ";
  if ((x <= 0.0) || (x == 1.0)) {
      cout << "indefinie" << endl;
  }
  else {
      resultat = x * log(x) * exp( 2.0 / (x-1.0) ) ;
      cout << resultat << endl;
  }

  // Expression 3
  cout << "Expression 3 : ";
  if ( (x > 0.0) && (x < 8.0) ) {
      cout << "indefinie" << endl;
  }
  else {
      resultat = ( -x - sqrt(x*x - 8.0*x) ) / (2.0-x) ;
      cout << resultat << endl;
  }

  // Expression 4
  cout << "Expression 4 : ";
  if  ((x <= 1.0 ) && (x >= 0.0)) {
      cout << "indefinie" << endl;
  } else {
      resultat = (sin(x) - x/20.0) * log(sqrt(x*x - 1.0/x));
      if (resultat < 0.0) {
	  cout << "indefinie" << endl;
      } else  {
          cout << sqrt(resultat) << endl;
      }
  }
}
