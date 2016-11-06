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

void printInfo(string &s){
    cout<<"Lungime            = "<< s.length()<<endl;
    cout<<"Capacitate         = "<< s.capacity()<<endl;
    cout<<"Dimensiunea maxima = "<< s.max_size()<<endl;
    cout<<"__________________"<<endl;
}

void PrintInfo(string &s){
    cout<<"Continut = \""<<s<<"\"";
    cout<<"Capacitate = "<<s.capacity()<<endl;
    cout<<"--------------------------------"<<endl;
}

void afisare(string &s){
    cout<<"Continut = \""<<s<<"\"";
    cout<<" Capacitate = "<<s.capacity()<<endl;
    cout<<"Este gol?: "<<(s.empty()?"yes":"no")<<endl;
    cout<<"--------------------------------"<<endl;
}

int main()
{
    cout << "Hello world! SUB-string"  << endl;
    string str1, str2;
    str1 = "ABCDEF";
    str2 = str1.substr(1,1)+str1.substr(4) +str1.substr();//B+EF +ABCDEF
    cout<< str2 <<endl;

    //lungimea unui string
    string str3 = "12345";

    int pos=1;
    cout<<str3.substr(pos).substr(pos).substr(pos).size()<<endl;

    string str4 = "ABC";
    cout<< str4.compare(1,1,"BC") + str4.compare(2,1,str4,2,2) <<endl;

    //gasirea unui string intr0un alt string
    string greeting = "My name is Bond, James Bond";
    string we_need_him = "James";
    if(greeting.find(we_need_him) != string::npos){
        cout << "OMG! He's here!"<<endl;
    } else {
        cout<< "It'not him."<<endl;
    }
    int comma = greeting.find(',');
    if(comma != string::npos) cout<<"Curious.He used a comma."<<endl;

    string theString = "Salut!";
    printInfo(theString);
    for(int i=0;  i<10; i++){
        theString += theString;
        printInfo(theString);
    }

    string TheString = "Continut";
    PrintInfo(TheString);
    TheString.reserve(100);
    PrintInfo(TheString);
    TheString.reserve(0);
    PrintInfo(TheString);

    string continut = "Stringul meu.";
    afisare(continut);
    continut.resize(50, '?');
    afisare(continut);
    continut.resize(4);
    afisare(continut);
    continut.clear();
    afisare(continut);

    string lit = "litere mici";
    for(int i=0; i<lit.length(); i++)
        lit[i] = lit[i]-'a'+'A';
    cout<<lit<<endl;

    return 0;
}
