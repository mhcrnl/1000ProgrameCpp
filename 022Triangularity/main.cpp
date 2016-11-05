/**
	Author:	    Mihai Cornel	Romania		        mhcrnl@gmail.com
	System:	    Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23	    Code::Blocks 16.01	gcc
	Copyright:	@2016
	Problem:    using new and delete array int **
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int rows=5, cols =5;
    int **arr;
    arr = new int *[rows];
    for(int r=0; r<rows; r++){
        arr[r] = new int[r+1];
        for(int c=0; c<=r; c++)
            arr[r][c]=(r+1)*10+c+1;
    }

    for(int r =0; r<rows; r++){
        for(int c=0; c<=r; c++)
            cout << arr[r][c]<< " ";
        cout << endl;
    }

    for(int r=0; r<rows; r++)
        delete[] arr[r];
    delete[] arr;

    return 0;
}
