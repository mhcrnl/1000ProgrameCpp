#include <algorithm> // pour sort()
#include <iterator>  // pour ostream_iterator
#include <ctime>     // pour time()
#include <cstdlib>   // pour rand
#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Chars; // un tableau de caract�res

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

int main()
{
    const unsigned int TAILLE(10);
    int entiers[TAILLE];
    double reels[TAILLE];
    Date dates[TAILLE];
    Chars caracteres;

    srand(time(0)); // initialisation de la graine du g�n�rateur

    for (unsigned int i(0); i < TAILLE; ++i) {
        entiers[i] = (rand() % 199) - 99;
        reels[i] = rand() * (1.0 / RAND_MAX);
        dates[i].set(1+(rand()%31),
                     1+(rand()%12),
                     1900+(rand()%150));
        caracteres.push_back(char(65 + (rand() % 26)));
    }

    cout << "Table d'entiers avant le tri:" << endl;
    copy(entiers, &(entiers[TAILLE]),
             ostream_iterator<int>(cout, "\n"));
    cout << "Table de r�els avant le tri:" << endl;
    copy(reels, &(reels[TAILLE]),
             ostream_iterator<double>(cout, "\n"));
    cout << "Table de dates avant le tri:" << endl;
    copy(dates, &(dates[TAILLE]),
             ostream_iterator<Date>(cout, "\n"));
    cout << "Table de caract�res avant le tri:" << endl;
    copy(caracteres.begin(), caracteres.end(),
             ostream_iterator<char>(cout, "\n"));

    sort(entiers, &(entiers[TAILLE]));
    sort(reels, &(reels[TAILLE]));
    sort(dates, &(dates[TAILLE]));
    sort(caracteres.begin(), caracteres.end());

    cout << "les entiers tri�s:" << endl;
    copy(entiers, &(entiers[TAILLE]),
             ostream_iterator<int>(cout, "\n"));
    cout << "les r�els tri�s:" << endl;
    copy(reels, &(reels[TAILLE]),
             ostream_iterator<double>(cout, "\n"));
    cout << "les dates tri�s:" << endl;
    copy(dates, &(dates[TAILLE]),
             ostream_iterator<Date>(cout, "\n"));
    cout << "les caract�res tri�s:" << endl;
    copy(caracteres.begin(), caracteres.end(),
             ostream_iterator<char>(cout, "\n"));

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
    return ( ! ((*this < d) || (d < *this)) );
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
