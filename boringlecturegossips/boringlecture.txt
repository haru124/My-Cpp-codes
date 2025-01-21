#include <iostream>

using namespace std;

/*int calc(int a[m][n], int m, int n)
{
    int s=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j+1]==1 || a[i+1][j]==1 || a[i][j-1]==1 || a[i-1][j]==1)
                s++;
        }
    }
    return(s);
}*/
int main()
{
    int m,n;
    cout << "Enter dimensions of 2d array" << endl;
    cin>>m>>n;
    int a[m][n];
    int i,j;
    cout << "\nEnter elements of 2d array only 0 or 1" << endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout << "\nArray diaplaying attendees in a class" << endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    int s=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                if(j==n)
                {
                   if (a[i][j-1]==1 || a[i-1][j]==1 || a[i+1][j]==1)
                     s++;
                }
                if(j==0)
                {
                   if(a[i][j+1]==1 || a[i+1][j]==1 || a[i-1][j]==1)
                     s++;
                }
                if(j!=0 && j!=n)
                {
                   if(a[i][j+1]==1 || a[i+1][j]==1 || a[i][j-1]==1 || a[i-1][j]==1)
                     s++;
                }

            }
        }
    }
    cout<<"\nNo. of attendees with neighbors : "<<s;
    return 0;
}
