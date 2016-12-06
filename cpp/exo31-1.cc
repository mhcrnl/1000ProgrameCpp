#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// nombre maximum de demandes en cas d'erreur
const unsigned short int NB_DEMANDES(3);

struct QCM {
  string question;
  vector<string> reponses;
  unsigned int solution;
};

typedef vector<QCM> Examen;

void affiche(const QCM& question);
int demander_nombre(int min, int max);
unsigned int poser_question(const QCM& question);
Examen creer_examen(ifstream& fichier);
bool demander_fichier(ifstream& f,
                      unsigned short int max_demandes = NB_DEMANDES);
string& enlever_blancs(string& chaine);

// --------------------------------------------------------------------
int main()
{
  unsigned int note(0);
  ifstream fichier;

  if (! demander_fichier(fichier)) {
    cout << "=> j'abandonne !" << endl;
  } else {

    Examen exam(creer_examen(fichier));

    for (unsigned int i(0); i < exam.size(); ++i)
      if (poser_question(exam[i]) == exam[i].solution)
        ++note;

    cout << "Vous avez trouve " << note << " bonne";
    if (note > 1) cout << 's';
    cout << " reponse";
    if (note > 1) cout << 's';
    cout << " sur " << exam.size() << "." << endl;
  }
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
Examen creer_examen(ifstream& fichier)
{
  QCM q;
  Examen retour;
  bool erreur(false);       // une erreur de format s'est produite
  bool dansquestion(false); // en train de lire une question
  string line;              // ligne a lire

  do {
    getline(fichier, line); // lit une ligne

    if (line[0] != '#') {
      // si ce n'est pas un commentaire

      if ((line[0] != 'Q') || (line[1] != ':')) {
        // si la ligne ne commence pas par "Q:"

        if (! dansquestion) {
          // Si on n'a pas encore eu de question : qqchose ne va pas !
          cerr << "Mauvais format de fichier : pas de \"Q:\"" << endl;
          erreur = true;
        } else {
          // on a deja eu une question => c'est donc une ligne de
          // reponse => lecture d'une reponse a la question

          if ((line[0] == '-') && (line[1] == '>')) {
            // reponse correcte
            line.replace(0,2,""); // supprime le "->" initial
            if (q.solution != 0) {
              cerr << "Hmmm bizarre, j'avais deja une reponse correcte"
                   << " pour cette question !" << endl;
              cerr << "Q: " << q.question << endl;
            }
            if (enlever_blancs(line) == "") {
              cerr << "?? la reponse correcte indiquee est vide !"
                   << endl;
              erreur = true;
            } else {
              q.solution = q.reponses.size() + 1;
            }
          }

          // ajoute la reponse courante
          if (enlever_blancs(line) != "") q.reponses.push_back(line);
        }

      } else {
        // ligne de question : "Q: ..."
        if (dansquestion)
          retour.push_back(q); // ajoute la question precedente a
                               // l'examen

        line.replace(0,2,"");  // supprime le "Q:" initial
        if (enlever_blancs(line) == "") {
          cerr << "??? Question vide !!" << endl;
          erreur = true;
        } else {
          q.question = line;     // copie la question
          q.reponses.clear();    // remets a zero les reponses...
          q.solution = 0;        // ...et la solution
          dansquestion = true;   // on a une question
        }
      }
    }
  } while (!fichier.eof() && !erreur);

  // Ne pas oublier la derniere question si elle existe
  if (! erreur && dansquestion) retour.push_back(q);

  return retour;
}

/* ====================================================================
 * Fonction demander_fichier
 * --------------------------------------------------------------------
 * In: Un ifstream (par reference) a ouvrir et le nombre maximum de
 *     demande (par defaut NB_DEMANDES).
 * Out:  Ouvert ou non ?
 * What: Demande a l'utilisateur (au plus max fois) un nom de fichier
 *       et essaye de l'ouvrir
 * ================================================================= */
bool demander_fichier(ifstream& f, unsigned short int max)
{
  string nom;
  unsigned short int nb(0);

  do {
    f.clear(); ++nb;

    // demande le nom du fichier
    do {
      cin.clear();
      cout << "Nom du fichier a lire : ";
      cin >> nom;
    } while (cin.fail());

    // essaye d'ouvrir le fichier
    f.open(nom.c_str());

    // est-ce que ca a marche ?
    if (f.fail()) {
      cout << "-> ERREUR, je ne peux pas lire le fichier "
           << nom << endl;
    } else {
      cout << "-> OK, fichier " << nom << " ouvert pour lecture."
           << endl;
    }
  } while (f.fail() && (nb < max));

  return !f.fail();
}

// --------------------------------------------------------------------
string& enlever_blancs(string& chaine)
{ // Supprime les blancs initiaux et finaux d'une chaine

  unsigned int i;
  for (i = 0; (i < chaine.size()) && (chaine[i] == ' '); ++i);
  if (i > 0) chaine.replace(0,i,"");

  for (i = chaine.size()-1; (i >= 0) && (chaine[i] == ' '); --i);
  if (i < chaine.size()-1) chaine.replace(i+1,chaine.size(),"");

  return chaine;
}
