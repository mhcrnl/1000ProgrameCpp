#include <iostream>

using namespace std;

enum luni{IAN = 1, FEB, MAR, APR, MAI, IUN, IUL, AUG, SEP,OCT, NOE, DEC};

luni operator+ (luni luna, int nrLuna){
    return luni((int(luna)+nrLuna)%12);
}
/**
Supra incarcarea operatorului operator<< in functie de sine statatoare pt. definirea lunii
*/
ostream& operator<<(ostream &strm, luni luna){
    switch(int(luna)){
        case IAN:strm<<"Ianuarie"; break;
        case FEB:strm<<"Februarie"; break;
        case MAR:strm<<"Martie"; break;
        case APR:strm<<"Aprilie"; break;
        case MAI:strm<<"Mai"; break;
        case IUN:strm<<"Iunie"; break;
        case IUL:strm<<"Iulie"; break;
        case AUG:strm<<"August"; break;
        case SEP:strm<<"Septembrie"; break;
        case OCT:strm<<"Octombrie"; break;
        case NOE:strm<<"Noembrie"; break;
        case DEC:strm<<"Decembrie"; break;
        default: strm<< "Nu mai sunt luni in an!!!"; break;
    }
    return strm;
}

class Cheltuieli{
    /**
    Variabilele clasei in modul private
    */
    double upc;
    double intretinere;
    double electricitate;
    double teldigi;

    /** Functiile clasei declarate in modul public */
public:
    /** Constructorul clasei fara/cu parametrii */
    Cheltuieli();
    Cheltuieli(double upcFac, double intretinereFac, double electricitateFac, double teldigiFac);
    /** Seteaza valoarea facturii upc*/
    void setUpc(double upcFac);
    /** Returneaza valoarea facturii upc*/
    double getUpc(void);
    /** Seteaza valoarea facturii de intretinere*/
    void setIntretinere(double intretinereFac);
    /** Returneaza valoarea facturii de intretinere*/
    double getIntretinere(void);
    /** Seteaza valoarea facturii de electricitate */
    void setElectricitate(double electricitateFac);
    /** Returneaza valoarea facturii de electricitate */
    double getElectricitate(void);
    /** Seteaza valoarea facturii telefon digi*/
    void setTeldigi(double teldigi);
    /** Returneaza valoarea facturii telefon digi*/
    double getTeldigi(void);
    /** Cheltuieli totale calculate lunar*/
    double cheltuieliLunare(void);
};
/** Constructorul cu parametrii a fost definit */
Cheltuieli::Cheltuieli(double upcFac, double intretinereFac, double electricitateFac, double teldigiFac){
    cout<<"Constructorul cu parametrii a fost apelat"<<endl;
    upc = upcFac;
    intretinere = intretinereFac;
    electricitate = electricitateFac;
    teldigi = teldigiFac;
}

/** Constructorul default a fost definit*/
Cheltuieli::Cheltuieli(){
    cout<<"Constructorul default este apelat!"<<endl;
}

void Cheltuieli::setTeldigi(double teldigiFac){
    teldigi = teldigiFac;
}

double Cheltuieli::getTeldigi(void){
    return teldigi;
}

void Cheltuieli::setElectricitate(double electricitateFac){
    electricitate = electricitateFac;
}

double Cheltuieli::getElectricitate(void){
    return electricitate;
}

void Cheltuieli::setIntretinere(double intretinereFac){
    intretinere = intretinereFac;
}

double Cheltuieli::getIntretinere(void){
    return intretinere;
}

void Cheltuieli::setUpc(double upcFac){
    upc = upcFac;
}

double Cheltuieli::getUpc(){
    return upc;
}

double Cheltuieli::cheltuieliLunare(){
    return upc+intretinere+electricitate+teldigi;
}

int main()
{
    cout << "Hello world!" << endl;

    Cheltuieli cheltDec;
    Cheltuieli cheltIan(45.45, 34.56, 455.67, 8.76);
    //cheltDec.upc;
    /** Cheltuieli luna decembrie */
    cheltDec.setUpc(85.90);
    cheltDec.setIntretinere(123.45);
    cheltDec.setElectricitate(65.89);
    cheltDec.setTeldigi(8.95);

    /** Calcul si afisare cheltuieli luna decembrie */
    cout<<cheltDec.getUpc()+cheltDec.getIntretinere()+cheltDec.getElectricitate()+cheltDec.getTeldigi()<<endl;
    cout<<cheltIan.getUpc()+cheltIan.getIntretinere()+cheltIan.getElectricitate()+cheltIan.getTeldigi()<<endl;

    luni luna=static_cast<luni>(1);
    cout<<"Cheltuieli Totale: "<<luna+12<<" : "<<cheltDec.cheltuieliLunare()<<endl;
    return 0;
}
