/**
	Author:	Mihai Cornel	Romania		mhcrnl@gmail.com
	System:	Ubuntu 16.04	Code::Blocks 13.01	gcc
            Fedora 23	    Code::Blocks 16.12	gcc
	Problem: https://www.codechef.com/problems/SUMTRIAN  - with class
*/
#include <iostream>

using namespace std;

class SumTriangle{
public:
    void sunTriangle(void);
};

void SumTriangle::sunTriangle(){
    int testCases;
    cin >> testCases;
    while(testCases--){
        int rows;
        cin >> rows;
        int biArr[rows][rows];
        for(int i=0; i<rows; i++){
            for(int j=0; j<=i; j++){
                cin >> biArr[i][j];
            }
        }
        for(int i=rows-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                biArr[i][j] += max(biArr[i+1][j], biArr[i+1][j+1]);
            }
        }
        cout << biArr[0][0] << endl;
    }
    return;
}

int main()
{
    //cout << "Hello world!" << endl;
    SumTriangle tri;
    tri.sunTriangle();
    return 0;
}
