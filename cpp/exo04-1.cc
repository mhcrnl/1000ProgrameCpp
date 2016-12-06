#include <iostream>
using namespace std;

main() {
  cout << "Entrez un reel : " ;  // demande un nombre a l'utilisateur
  double x ;                     // declaration de la variable x
  cin >> x ;                     // enregistre la reponse dans x

  if ( (x >= -1.0) && (x < 1.0) ) {
      cout << "x appartient a I" << endl;
  } else {
      cout << "x n'appartient pas a I" << endl;
  }
}
