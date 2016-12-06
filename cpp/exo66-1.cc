#include <iostream>  // pour cout
#include <algorithm> // pour copy
#include <set>
#include <string>
#include <iterator>  // pour ostream_iterator
using namespace std;

int main()
{
  set<char> unensemble;

  unensemble.insert('a');
  unensemble.insert('b');
  unensemble.insert('c');

  cout << "mon ensemble contient :" << endl;
  for (set<char>::iterator i(unensemble.begin());
       i != unensemble.end(); ++i) {
    cout << "    " << *i << endl;
  }

  string s;

  // pour utiliser copy, il est imperatif que la chaine ait
  // la place necessaire, donc ici au moins 3 caracteres.
  // En pratique on n'utilisera donc pas copy pour CREER un
  // nouveau container, mais bien pour COPIER des valeurs;
  s = "xxx";

  copy(unensemble.begin(), unensemble.end(), s.begin());

  cout << s << endl;

  // affichage
  cout << "mon ensemble = ";
  copy(unensemble.begin(), unensemble.end(),
       ostream_iterator<char>(cout, ", "));
  cout << endl;

  return 0;
}
