#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct QCM {
  string question;
  vector<string> reponses;
  unsigned int solution;
};

typedef vector<QCM> Examen;

void affiche(const QCM& question);
int demander_nombre(int min, int max);
unsigned int poser_question(const QCM& question);
Examen creer_examen();

// --------------------------------------------------------------------
int main()
{
  unsigned int note(0);
  Examen exam(creer_examen());

  for (unsigned int i(0); i < exam.size(); ++i)
    if (poser_question(exam[i]) == exam[i].solution)
      ++note;

  cout << "Vous avez trouve " << note << " bonne";
  if (note > 1) cout << 's';
  cout << " reponse";
  if (note > 1) cout << 's';
  cout << " sur " << exam.size() << "." << endl;

  return 0;
}

// --------------------------------------------------------------------
void affiche(const QCM& q)
{
  cout << q.question << " ?" << endl;
  for (unsigned int i(0); i < q.reponses.size(); ++i) {
    cout << "    " << i+1 << "- " << q.reponses[i] << endl;
  }
}

// --------------------------------------------------------------------
int demander_nombre(int a, int b)
{
  /* echange les arguments s'ils n'ont pas ete donnes dans *
   * le bon sens.                                          */
  if (a > b) { int tmp(b); b=a; a=tmp; }

  int res;

  do {
    cout << "Entrez un nombre entier compris entre "
         << a << " et " << b <<" : ";
    cin >> res;
  } while ((res < a) || (res > b));

  return res;
}

// --------------------------------------------------------------------
unsigned int poser_question(const QCM& q)
{
  affiche(q);
  return (unsigned) demander_nombre(1,q.reponses.size());
}

// --------------------------------------------------------------------
Examen creer_examen()
{
  QCM q;
  Examen retour;

  q.question = "Combien de dents possede un elephant adulte";
  q.reponses.clear();
  q.reponses.push_back("32");
  q.reponses.push_back("12");
  q.reponses.push_back("beaucoup");
  q.reponses.push_back("48");
  q.reponses.push_back("4");
  q.solution=2;
  retour.push_back(q);

  q.question = "Laquelle des expressions suivantes est un prototype "
               "de fonction";
  q.reponses.clear();
  q.reponses.push_back("int f(0);");
  q.reponses.push_back("int f(int 0);");
  q.reponses.push_back("int f(int i);");
  q.reponses.push_back("int f(i);");
  q.solution=3;
  retour.push_back(q);

  q.question = "Qui pose des questions stupides";
  q.reponses.clear();
  q.reponses.push_back("le prof. de math");
  q.reponses.push_back("mon copain/ma copine");
  q.reponses.push_back("les auteurs de ce livre");
  q.reponses.push_back("moi");
  q.reponses.push_back("le prof. d'info");
  q.reponses.push_back("personne, il n'y a pas de question stupide");
  q.reponses.push_back("les sondages");
  q.solution=6;
  retour.push_back(q);

  return retour;
}
