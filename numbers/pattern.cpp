#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"\nEnter n ";
    cin>>n;


    int j;
    for(int i=1;i<=n;i++)
    {
        j=1;
        for(j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }


    cout<<"\nSecond Pattern\n";
    for(int i=1;i<=n;i++)
    {
        int l=1,k,x,s;
        x=2*(n-1);
        s=x-(2*(i-1));
        for(int o=1;o<=s;o++)
        {
            cout<<" ";
        }
        for(l=1;l<=i;l++)
        {
            cout<<l<<" ";
        }
        for(k=i-1;k>=1;k--)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }

}
