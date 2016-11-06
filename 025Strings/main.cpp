/**
	Author:		Mihai Cornel	Romania			    mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23	    Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:    https://education.cppinstitute.org/course_datas/display/71/369#
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world! String operator+ concatenare" << endl;
    string Bed = "Hyde", Good = "Jekyll";
    cout << Bed + "&"+ Good<<endl;
    cout << Good + "&"+ Bed<<endl;

    cout << "Nu se pot concatena literals ambii fiind de tip."<<endl;
    string String;
    //String = "a" + "b";//Eroare de compilare
    String = "A" + String;
    String = String + "b";
    cout<< String<<endl;

    cout<<"Utilizarea operatorului de concatenera += "<<endl;
    string Intrebare = "A fi sau ";
    Intrebare += "a nu fi?";
    cout<<Intrebare<<endl;

    cout<<"Inserarea de la tastatura a stringurilor cu cin(doar primul cuvant):"<<endl;
    string InsertStr, eliberareLinie;
    cin>>InsertStr;
    getline(cin, eliberareLinie);// elibereaza linia de cuvinte
    cout<<InsertStr<<endl;

    cout<<"Inserarea de la tastatura a unei intregi linii cu getline(cin, string):"<<endl;
    string oLinie;
    getline(cin, oLinie);
    cout<<oLinie<<endl;

    cout<<"Compararea a doua stringuri cu operatorul == :"<<endl;
    string cheie = "abracadabra";
    string pass;
    cout<<"Introduce-ti parola(abracadabra): ";
    getline(cin, pass);
    if(cheie == pass){
        cout<<"Acesul permis."<<endl;
    } else {
        cout<<"Parola incorecta!"<<endl;
    }

    cout<< "Compararea stringurilor cu operatorii < > >= <= != Introduce-ti doua texte:"<<endl;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    if(str1 == str2){
        cout<<"\""<<str1<<"\""<< " == "<<"\""<<str2<<"\""<<endl;
    } else if(str1>str2) {
        cout<<"\""<<str1<<"\""<<" > "<<"\""<<str2<<"\""<<endl;
    } else {
        cout<<"\""<<str1<<"\""<<" < "<<"\""<<str2<<"\""<<endl;
    }

    cout<<"Utilizarea metodei compare() pt compararea string-urilor.Introduce-ti parola:"<<endl;
    string parola= "abcd";
    string password;
    getline(cin, password);
    if(parola.compare(password) == 0){
        cout<<"Accesul permis, parola corecta."<<endl;
    } else {
        cout<<"Accesul respins, parola incorecta."<<endl;
    }

    cout<<"Compararea stringurilor cu metode OOP. Introduce-ti doua texte: ";
    string txt1, txt2;
    getline(cin, txt1);
    getline(cin, txt2);
    if(txt1.compare(txt2) == 0){
        cout<<"\""<<txt1<<"\""<<" == "<<"\""<<txt2<<"\""<<endl;
    } else if(txt1.compare(txt2) > 0){
        cout<<"\""<<txt1<<"\""<<" > "<<"\""<<txt2<<"\""<<endl;
    } else {
        cout<<"\""<<txt1<<"\""<<" < "<<"\""<<txt2<<"\""<<endl;
    }

    return 0;
}
