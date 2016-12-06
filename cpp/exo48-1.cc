#include <iostream>
using namespace std;

// un bout de papier... pour ce tour de magie
class Papier {       
public: // public : tout le monde peut lire le papier

  // Ces 2 attributs sp�cifiquement, car d'une fa�on ou d'une autre
  // le spectateur rend intelligible l'information contenue sur le papier.
  // Nous n'avons pas ici pouss� la mod�lisation au point d'inclure la
  // fa�on dont le spectateur "code" l'information sur le papier ni la
  // fa�on dont l'assistant la d�code.
  unsigned int age;
  unsigned int argent;
};

// --------------------------------------
class Assistant { 
public:
  void lire(const Papier* papier);
  void calculer();
  unsigned int annoncer();

private:
  const Papier* papier; // un acc�s au papier lu
  unsigned int cerveau; // son cerveau lui sert � reternir le resultat 
                        // des calculs qu'il effectue  
};


// --------------------------------------
class Spectateur { 
public:
  void arriver();  // lorsqu'il entre dans la salle (avant 
                   //     il n'"existe" pas pour nous)

  void ecrire();   // �crit sur le papier
  Papier* montrer();  // montre le papier

private:
  // ses sp�cificit�s
  unsigned int age;
  unsigned int argent;

  // dans cette version nous faisons l'hypoth�se que
  // c'est le spectateur qui a un papier.
  // Dans d'autres mod�lisations, ce papier pourrait aussi bien
  // appartenir au magicien, � l'assistant ou m�me "�tre dans la
  // salle" (i.e. variable du main)
  Papier paquet_cigarettes;
};


// --------------------------------------
class Magicien { 
public:
  void tourDeMagie(Assistant& asst, Spectateur& spect);
  // pour faire son tour, le magicien a besoin d'au moins
  // un spectateur et d'un assistant

private: // partie priv�e ici car seul le magicien sait ce qu'il doit
         // faire dans son tour
  void calculer(unsigned int resultat_recu);
  void annoncer();

  unsigned int age_devine;
  unsigned int argent_devine;
};

// ======================================================================
int main() 
{
  // L'histoire g�n�rale :
  Spectateur thorin;    // Il �tait une fois un spectateur...
  thorin.arriver();     // ...qui venait voir un spectacle (!!)...

  Magicien gandalf;                   // ...o� un magicien...
  Assistant bilbo;                    // ...et son assistant...
  gandalf.tourDeMagie(bilbo, thorin); // ...lui firent un tour fantastique.

  return 0;
}         

// ----------------------------------------------------------------------
void Assistant::lire(const Papier* papier)
{
  cout << "[Assistant] (je lis le papier)" << endl;
  this->papier = papier;
}

void Assistant::calculer()
{
  cout << "[Assistant] (je calcule mentalement)" << endl;
  cerveau = papier->age * 2;
  cerveau += 5;
  cerveau *= 50;
  cerveau += papier->argent;
  cerveau -= 365;
}

unsigned int Assistant::annoncer()
{
  cout << "[Assistant] J'annonce : " << cerveau << " !" << endl;
  return cerveau;
}

// ----------------------------------------------------------------------
void Spectateur::arriver()
{
  cout << "[Spectateur] (j'entre en sc�ne)" << endl;
  cout << "Quel �ge ai-je ? "; 
  cin >> age;
  do {
    cout << "Combien d'argent ai-je en poche (<100) ? "; 
    cin >> argent;
  } while (argent >= 100);
  cout << "[Spectateur] (je suis l�)" << endl;
}

void Spectateur::ecrire()
{
  cout << "[Spectateur] (j'�cris le papier)" << endl;
  paquet_cigarettes.age    = age;
  paquet_cigarettes.argent = argent;
}

Papier* Spectateur::montrer()
{
  cout << "[Spectateur] (je montre le papier)" << endl;
  return &paquet_cigarettes;
}

// ----------------------------------------------------------------------
void Magicien::tourDeMagie(Assistant& fidele, Spectateur& quidam)
{
  cout << "[Magicien] un petit tour de magie..." << endl;
  // le magicien donne ses instructions :
  quidam.ecrire();
  fidele.lire(quidam.montrer());
  fidele.calculer();
  calculer(fidele.annoncer());
  annoncer();
}

void Magicien::calculer(unsigned int resultat_recu) {
  resultat_recu += 115;
  age_devine    = resultat_recu / 100;
  argent_devine = resultat_recu % 100;
}

void Magicien::annoncer() {
  cout << "[Magicien] " << endl
       << "  - hum... je vois que vous �tes ag� de " << age_devine << " ans" << endl
       << "    et que vous avez " << argent_devine << " euros en poche !" << endl;
}
