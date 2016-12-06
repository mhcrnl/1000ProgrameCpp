#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef char type_el;

typedef vector<type_el> Pile;

// Prototypes des fonctions
void empile(Pile& p, type_el e);
void depile(Pile& p);
type_el top(Pile p);
bool est_vide(Pile p);

// verification de parenthesage
bool check(string parentheses);

// --------------------------------------------------------------------
int main()
{
  string s;

  do {
    cout << "Entrez une expresssion parenthesee : ";
    getline(cin, s);
    if (!s.empty())
      cout << " -> " << (check(s) ? "OK" : "Erreur") << endl;
  } while (!s.empty());
  return 0;
}

// --------------------------------------------------------------------
void empile (Pile& p, type_el e)
{
  p.push_back(e);
}

// --------------------------------------------------------------------
void depile (Pile& p)
{
  if (!est_vide(p)) p.pop_back();
}

// --------------------------------------------------------------------
type_el top (Pile p)
{
  if (!est_vide(p))
    return p[p.size()-1];
  else // que faire ??  -> totalement arbitraire...
    return 0;
  // en "vrai" (cad plus tard, on leverait ici une exception)
}

// --------------------------------------------------------------------
bool est_vide(Pile p)
{
  return p.empty();
}

// --------------------------------------------------------------------
bool check(string s) {
  Pile p;
  for (unsigned int i(0); i < s.size(); ++i) {
    if ((s[i] == '(') || (s[i] == '['))
      empile(p,s[i]);
    else if (s[i] == ')') {
      if ((!est_vide(p)) && (top(p) == '('))
        depile(p);
      else
        return false;
    } else if (s[i] == ']') {
      if ((!est_vide(p)) && (top(p) == '['))
        depile(p);
      else
        return false;
    }
  }

  return est_vide(p);
}
