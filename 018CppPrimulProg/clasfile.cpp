
#include "clasfile.h"

void FirstClass::afiseazaSalut(void){
    cout<< "Salut din clasa FirstClass"<<endl;
}

int FirstClass::afiseazaOctal(int octal){
    int ret = 0;
    cout << "int: "<<octal<<endl;
    return ret;
}

int FirstClass::afiseazaHexidecimal(int hexi){
    int ret =0;
    cout<<"HexizecimalToInt: "<< hexi<<endl;
    return ret;
}

void FirstClass::afiseazaSpeedOfLight(void){
    float speed_of_light = 3e-8;
    cout<<"Viteza luminii este: "<<speed_of_light<<endl;
}

int FirstClass::adunare(int num1, int num2){
    int rezultat;
    rezultat = num1 + num2;
    return rezultat;
}

int FirstClass::scadere (int num1, int num2){
    int res;
    res = num1-num2;
    return res;
}

int FirstClass::modulo(int num1, int num2){
    int remainder;
    remainder = num1 % num2;
    return remainder;
}
