#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cout<<"\n Enter n ";
    cin>>n;
    int a[n];
    cout<<"\n Enter elements ";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"\nArray : ";
    for(i=0;i<n;i++)
    cout<<a[i]<<"  ";
    //left greater
    //right lesser
    //d diff btw l and r
    int d[n];
    for(i=0;i<n;i++)
    {
        int l=0,r=0;
        for(j=0;j<i-1;j++)   //no of elements greater than the taken element to its left
        {
            if(a[j]>a[i])
                l++;
        }
        for(j=i+1;j<n;j++)    //no of elements lesser than the taken element to its right
        {
            if(a[j]<a[i])
                r++;
        }
        d[i]=l-r;
    }
    int m=d[0];
    int index;

    for(i=1;i<n;i++)
    {
            if(d[i]>m)
            {
            m=d[i];
            index=i;
    }
    }

    cout << "\nmax diff " << m;
    cout<<"\nmax diff occurs at index "<<index+1;
    return 0;
}
