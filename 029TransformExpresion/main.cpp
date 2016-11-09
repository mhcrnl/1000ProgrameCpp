/**
	Author:		Mihai Cornel	Romania			mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23   	Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:    in: (a+(b*c))               out: abc*+
                    ((a+b)*(z+x))                ab+zx+*
                    ((a+t)*((b+(a+c))^(c+d)))    at+bac++cd+^*
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    for(int i=0; i<testCases; i++){
        char in[300];
        stack<char> out;
        cin >> in;
        char *p = in;
        while(*p){
            switch(*p){
                case '(': out.push(*p); p++; break;
                case ')': cout << out.top(); out.pop();out.pop(); p++; break;
                case '-':
                case '+':
                case '/':
                case '*':
                case '^': out.push(*p); p++; break;
                default : cout << *p; p++; break;
            }
        }
        while(!out.empty()){
            cout << out.top(); out.pop();
        }
        cout << endl;
    }

    return 0;
}
