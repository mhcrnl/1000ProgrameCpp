/**
	Author:		Mihai Cornel	Romania			mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
			Fedora 23	Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:
*/
#include <stack>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void adaugaElementeInStack(){
    // create empty stack
    stack<int> myStack;
    // add elements in stack
    for(int i=0; i<=100; i++){
        // push elements in stack
        myStack.push(i);
    }
    // print elements
    cout<<"Elementele din stiva: ";
    while(!myStack.empty()){
        cout<<' '<<myStack.top();
        myStack.pop();

    }
    cout<<endl;
}

int main()
{
    cout << "Hello world! Stack example." << endl;

    adaugaElementeInStack();

    deque<int> mydeque(3, 100);
    vector<int> myvector(2,200);

    stack<int> first;
    stack<int> second(mydeque);
    stack<int, vector<int> > third;
    stack<int, vector<int> > fourth(myvector);

    cout <<"Dimensiunea primului stack: "<<first.size()<<'\n';
    cout <<"Dimensiunea al doi-lea stack: "<<second.size()<<'\n';
    cout <<"Dimensiunea al TREI-lea stack: "<<third.size()<<'\n';
    cout <<"Dimensiunea al patrulea-lea fourth: "<<fourth.size()<<'\n';

    return 0;
}
