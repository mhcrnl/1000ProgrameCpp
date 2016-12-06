#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

typedef int type_el;

typedef vector<type_el> Pile;

// Structure de pile
bool est_vide(const Pile& p) { return p.empty(); }
void empile(Pile& p, type_el e) { p.push_back(e); }
void depile(Pile& p) { if (!est_vide(p)) p.pop_back(); }
type_el top(const Pile& p) 
{
    if (!est_vide(p)) return p[p.size()-1];
    return type_el(0);
}
//
int eval(string entree);

// --------------------------------------------------------------------
int main()
{
  string s;

  do {
    cout << "Entrez une expresssion a evaluer : ";
    getline(cin, s);
    if (!s.empty())
      cout << " -> resultat : " << eval(s) << endl;
  } while (!s.empty());
  return 0;
}

int eval(string s)
{
  Pile p;

  // recopie dans la pile
  for (unsigned int i(0); i < s.size(); ++i)
    if ((s[i] >= '0') && (s[i] <= '9')) {
      // On a lu un chiffre
      empile(p, int(s[i] - '0'));
    } else if ((s[i] == '+') || (s[i] == '-') ||
               (s[i] == '*') || (s[i] == '/')) {

      // recupere le second argument
      int y(top(p));
      depile(p);

      // recupere le premier argument
      int x(top(p));
      depile(p);

      // calcule et empile le resultat
      switch(s[i]) {
      case '+': empile(p, x + y); break;
      case '-': empile(p, x - y); break;
      case '*': empile(p, x * y); break;
      case '/': empile(p, x / y); break;
      }
    }

  return top(p);
}
