#include <iostream>
#include <cmath>
using namespace std;

const double g(9.81); // la constante de gravité terrestre

main()
{
  // Declarations -----------------------------------------
  double h_fin;        // maximum de hauteur
  double eps;          // coefficient de rebond de la balle
  double h0, h1;       // hauteurs avant et après le rebond
  double v0, v1;       // vitesses avant et apres le rebond

  // Saisie des valeurs, avec test de validité ------------
  do {
    cout << "Coefficient de rebond (0 <= coeff < 1) : ";
    cin >> eps;
  } while ( (eps < 0.0) || (eps >= 1.0) );
  do {
    cout << "Hauteur initiale      (h0 >= 0)        : ";
    cin >> h0;
  } while ( h0 < 0.0 );
  do {
    cout << "Hauteur finale        (0 < h_fin < h0) : ";
    cin >> h_fin;
  } while (h_fin <= 0.0 || h_fin >= h0);

  double rebonds(0);
  // Boucle de calcul -------------------------------------
  do {
    ++rebonds;                 // une iteration par rebond
    v0 = sqrt(2.0 * g * h0);   // vitesse avant rebond
    v1 = eps * v0;             // vitesse apres le rebond
    h1 =(v1 * v1) / (2.0 * g); // hauteur après rebond
    h0 = h1;   // qui devient nouvelle haut. avant rebond suivant
  } while (h0 > h_fin);

  // Affichage du resultat --------------------------------

  cout << "La balle rebondit " << rebonds
       << " fois avant que la hauteur de rebond (" << h0
       << ") soit inférieure à la limite de " << h_fin << endl;
}
