#include <ctime>    // pour time()
#include <cstdlib>  // pour rand
#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Chars; // un tableau de caractères

class Date
{
public:
    void set(unsigned int, unsigned int, unsigned int);
    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    unsigned int get_jour()  const { return jour;  }
    unsigned int get_mois()  const { return mois;  }
    unsigned int get_annee() const { return annee; }
    
private:
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
};    

ostream& operator<<(ostream&, const Date&);

template<typename T>
void afficheTable(const T table, const unsigned int taille);

template<typename T, typename Item>
void trie(T table, unsigned int taille);

int main()
{
    const unsigned int TAILLE(10);
    int entiers[TAILLE];
    double reels[TAILLE];
    Date dates[TAILLE];
    Chars caracteres;

    srand(time(0)); // initialisation de la graine du générateur
    
    for (unsigned int i(0); i < TAILLE; ++i) {
        entiers[i] = (rand() % 199) - 99;
        reels[i] = rand() * (1.0 / RAND_MAX);
        dates[i].set(1+(rand()%31),
                     1+(rand()%12),
                     1900+(rand()%150));
        caracteres.push_back(char(65 + (rand() % 26)));
    }
    cout << "Table d'entiers avant le tri:" << endl;
    afficheTable(entiers, TAILLE);
    cout << "Table de réels avant le tri:" << endl;
    afficheTable(reels, TAILLE);
    cout << "Table de dates avant le tri:" << endl;
    afficheTable(dates, TAILLE);
    cout << "Table de caractères avant le tri:" << endl;
    afficheTable(caracteres, TAILLE);

    trie<int*,int>(entiers, TAILLE);
    trie<double*,double>(reels, TAILLE);
    trie<Date*,Date>(dates, TAILLE);
    trie<Chars&,char>(caracteres, TAILLE);

    cout << "les entiers triés:" << endl;
    afficheTable(entiers, TAILLE);
    cout << "les réels triés:" << endl;
    afficheTable(reels, TAILLE);
    cout << "les dates triés:" << endl;
    afficheTable(dates, TAILLE);
    cout << "les caractères triés:" << endl;
    afficheTable(caracteres, TAILLE);

    return 0;
}

void Date::set(unsigned int jour, unsigned int mois,
               unsigned int annee)
{
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
}

bool Date::operator==(const Date& d) const
{
    return (! ((*this < d) || (d < *this)) );
}

bool Date::operator<(const Date& d) const
{
    return
    ( (annee < d.annee) ||
      ( (annee == d.annee) && 
        ( (mois < d.mois) ||
          ( (mois == d.mois) && (jour < d.jour))
         )
       )
    );
}

bool Date::operator>(const Date& d) const
{
    return (d < *this);
}

ostream& operator<<(ostream& o, const Date& d)
{
    o << d.get_jour() << '/' << d.get_mois() << '/' << d.get_annee();
    return o;
}

template<typename T>
void afficheTable(const T table, const unsigned int taille)
{
    for (unsigned int i(0); i < taille; ++i) 
        cout << table[i] << endl;
}

template<typename T, typename Item>
void trie(T table, unsigned int taille)
{
    Item tmp;
    bool pasEnOrdre(false);

    do {
        pasEnOrdre = false;
        unsigned int i(0);
        for (unsigned int j(i+1); j<taille; ++i, ++j)
        {
            if (table[i] > table [j])
            {
                pasEnOrdre = true;
                tmp = table[i];
                table[i] = table[j];
                table[j] = tmp;
            }
        }
        --taille;
    } while (pasEnOrdre);
}
