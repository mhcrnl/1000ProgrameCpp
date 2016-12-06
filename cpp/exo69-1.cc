#include <string>
#include <iostream>
#include <sstream>
using namespace std;

const char FLAG('#');

struct Erreur {
  string message;
  string decode;
  string suite;
};

string compresse(const string& data, char flag);
string decompresse(const string& rledata, char flag) throw(Erreur);

string toStr(int data)  
{ 
    /*
     * conversion d'entier sous forme de string
     *
     * Exemple:
     *     int i = 4;
     *     string s = toStr(i);
     */
    ostringstream os;
    os << data;
    return os.str();
}

int fromStr(const string& str)
{
    /*
     * conversion de string vers entier
     *
     * Exemple:
     *     string s = "41";
     *     int i = fromStr(s);
     */
    int extracted(0);
    istringstream is(str);
    is >> extracted;
    return extracted;
}
 
int fromStr(char c)
{
    /*
     * conversion de char vers entier
     *
     * Exemple:
     *     char c = '4';
     *     int i = fromStr(c);
     */
  if ((c >= '0') && (c <= '9'))
    return c - '0';
  else
    return 0;
}

int main()
{
    string dta;
    cout << "Entrez les donnees a comprimer : ";
    getline(cin,dta);
    string rle(compresse(dta, FLAG));
    cout << "Forme compressee:   " << rle << endl
         << "[ratio = " << rle.size()*100.0/dta.size() << "%]" << endl;
    string dcp(decompresse(rle, FLAG));
    if (dcp != dta)
        cout << "Erreur - donnees corrompues:" << endl
             << dcp << endl;
    else cout << "decompression ok!" << endl;
    // teste la decompression
    cout << "Entrez les donnees a decompresser : ";
    getline(cin,dta);
    try {
      dcp = decompresse(dta, FLAG);
      cout << "decompresse : " << dcp << endl;
    }
    catch (Erreur& erreur) {
      cout << "Erreur de decompression : " << erreur.message
           << endl;
      cout << "decode a ce stade : " << erreur.decode << endl;
      cout << "non decode        : " << erreur.suite << endl;
    }
}

string compresse(const string& data, char flag)
{
    char c;             // le caractere a encoder
    int  l;             // le nombre de repetitions
    unsigned int p = 0; // position dans la chaine a encoder
    string out;         // resultat de l'encodage
    
    while (p < data.size()) {
      l = 1;
      if ((c = data[p]) == flag) {
        // sequence speciale: flag 0
        p++;
        out += c;
        out += toStr(0);
      } 
      else {
        while ((p++ < data.size()) && (l < 9) && (data[p] == c)) l++;
        if (l >= 3) {
          out += c;
          out += flag;
          out += toStr(l);
        } 
        else while (--l > 0) out += c;
      }
    }
    return out;
}

string decompresse(const string& rledata, char flag) throw(Erreur)
{
    char c;         // caractere extrait
    int  l;         // nombre de repetitions a produire
    unsigned int p; // position dans la chaine a decompresser
    string out;     // chaine decompressee

    for (p = 0; p < rledata.size(); p++) {
      c = rledata[p];
      if ((p+1 < rledata.size()) && (rledata[p+1] == flag)) {
        // flag en p+1 detecte ?
        p += 2;
        if (p >= rledata.size()) {
          // erreur : on devrait avoir qqchode derriere le FLAG
          Erreur err;
          err.message ="flag ";
          err.message += flag;
          err.message += " sans rien derriere";
          err.decode = out + c;
          err.suite = flag + rledata.substr(p);
          throw err;
        } else if ((rledata[p] >= '0') && (rledata[p] <= '9')) { 
          l = fromStr(rledata[p]); // on recupere l
          if (l >= 1)
            while (--l > 0) out += c; // decompression des l x c
          else {
            // l=0 -> le flag etait dans les donnees
            out += c;
            out += flag;
          }
        } else {
          // erreur : ce qui suit le FLAG n'est pas correct
          Erreur err;
          err.message = "caractere ";
          err.message += rledata[p];
          err.message += " incorrect apres le flag ";
          err.message += flag;
          err.decode = out + c;
          err.suite = flag + rledata.substr(p);
          throw err;
        }
      } else {
        // caractere seul
        out += c;
        if (c == flag) p++; // saute le 0 dans le cas d'un flag au
                            // debut ("#0")
      }
    }
    return out;
}
