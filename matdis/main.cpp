#include <iostream>

using namespace std;


int getmatrix(int c,int r=2)
{
    int i,j;
    int a[r][c];

    cout<<"\n Enter elements of matrix row by row";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }

    cout <<"\n Your matrix is \n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return(a[r][c]);
}


int main()

{
    cout<<"\n Enter matrix 1";
    getmatrix(3,3);
    cout<<"\n Enter matrix 2";

    getmatrix(2);

    return 0;
}

