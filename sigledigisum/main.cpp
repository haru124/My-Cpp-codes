#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter n" << endl;
    cin>>n;
    int a[n];
    int i;

    cout << "\nEnter elements of array max 8 digits" << endl;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout << "\nArray" << endl;

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    for(i=0;i<n;i++)
    {
        cout<<"\nLength of a["<<i<<"] "<<sizeof(a[i])<<endl;
    }

    int max=0,m=0;
    int s[n];

    for(i=0;i<n;i++)
    {
        s[i]=0;
        int t=a[i];
        while(a[i]/10!=0)
        {
            s[i]=s[i]+(a[i]/10);
            a[i]=a[i]%10;
        }
        s[i]=s[i]+a[i];
        while(s[i]/10!=0)
        {
            s[i]=(s[i]/10)+(s[i]%10);
        }
         cout<<"\nsum"<<s[i]<<endl;
        if(m<=s[i])
        {
            m=s[i];
            max=t;
        }


    }

   cout<<max;
    return 0;
}
