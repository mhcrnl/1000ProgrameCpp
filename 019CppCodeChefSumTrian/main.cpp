/**
    Author: Mihai Cornel Romania mhcrnl@gmail.com
    Problem: https://www.codechef.com/problems/SUMTRIAN
*/
#include <iostream>

using namespace std;

void sumTriangle(){
    int testCases;
    cin >> testCases;
    while(testCases--){
       int rows;
       cin >> rows;
       int biArr[rows][rows];   //numerele din sir
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
    sumTriangle();
    return 0;
}
