/***********************************************************************
    Author:     Mihai Cornel    mhcrnl@gmail.com
    Date:       30.10.2016
    Software:   Example
************************************************************************/

#ifndef CLASFILE_H_INCLUDED
#define CLASFILE_H_INCLUDED

#include <iostream>

using namespace std;

class FirstClass {
    int octal = 0123;
public:
    /*
    Afiseaza un string care este pasat functiei cout
    */
    void afiseazaSalut(void);
    int afiseazaOctal(int octal);
    int afiseazaHexidecimal(int hexi);
    /*
    Viteza luminii
    */
    void afiseazaSpeedOfLight(void);
    /*
    Aduna doua numere int
    */
    int adunare(int num1, int num2);
    /*
    Scaderea a doua numere int
    */
    int scadere (int num1, int num2);
    /*
    Modulo calc num1%num2 return % remainder
    */
    int modulo(int num1, int num2);
};

#endif // CLASFILE_H_INCLUDED
