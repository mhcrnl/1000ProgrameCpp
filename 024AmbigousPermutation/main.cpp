/**
	Author:		Mihai Cornel	Romania			    mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23	    Code::Blocks 16.01	gcc
	Copyright:	@2016
	Problem:    https://www.codechef.com/problems/PERMUT2
*/

#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    int testCases;
    cin >> testCases;
    while(testCases != 0){
        testCases++;
        int arr[testCases],i;
        for(i=1; i<testCases; i++){
            cin >> arr[i];
        }

        for(i=1; i<testCases; i++){
            if(arr[arr[i]] != i) break;
        }

        if(i == testCases){
            cout << "ambiguous" << endl;
        } else {
            cout << "not ambiguous" << endl;
        }

        cin >> testCases;
    }
    return 0;
}
