#include <iostream>

using namespace std;

int** getmatrix(int c,int r=3)
{
    int i,j;
    static int **a[5][5];
    cout<<"\nEnter matrix elements ";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>**a[i][j];
        }
    }

    cout<<"\nMatrix is  ";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<**a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return(a[r][c]);
}


int main()
{
    int **m=getmatrix(2);
    return 0;
}
