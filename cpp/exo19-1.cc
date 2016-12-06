#include <string>
#include <iostream>
using namespace std;

bool nextToken(const string& str, int& from, int& len);
bool issep (char c); // teste si le caractère est un separateur

int main()
{
  string phrase;

  cout << "Entrez une chaine : ";
  getline(cin,  phrase);

  cout << "Les mots de \"" << phrase << "\" sont :" << endl;
  int debut(0);
  int longueur(0);
  while (nextToken(phrase, debut, longueur)) {
    cout << "'" << phrase.substr(debut, longueur) << "'" << endl;
    debut += longueur;
  }
  return 0;
}

// Ecrire une fonction presente l'avantage de pouvoir redefinir
// facilement la notion de separateur (et eventuellement d'en definit
// plusieurs)
bool issep (char c) {
  return (c == ' ');
}

// Il y a de multiples façons d'ecrire cette fonction.
// Celle-ci est relativement élégante.
bool nextToken(const string& str, int& from, int& len)
{
  const int taille(str.size());

  // saute tous les separateurs à partir de from
  while ((from < taille) && issep(str[from])) ++from;

  // avance jusqu'au prochain separateur ou la fin de str
  len = 0;
  for (int i(from); ((i < taille) && !issep(str[i])); ++len, ++i);

  return (len != 0);
}

