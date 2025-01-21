#include <iostream>
#include<string>
using namespace std;

int main()
{
    /*
    string s;
    cout<<"Enter input__";
    getline(cin,s);
    cout << "s.length() = " <<s.length()<< endl;
    int n = s[s.length()-1] - '0';
    int m;
    int i=1;

    while(s[i]!=' ')
    {
        i++;
    }
    i++;

    m = s[i] - '0';
    cout<<"m="<<m<<"  n="<<n<<endl;
    int a[m+n],b[n];
    int k=0,l=0;
    for (i=1; i<s.length(); i++)
    {
        while(s[i]!=']')
        {
        if(s[i]!=',')
        {
            a[k] = s[i] - '0';
            k++;
        }
        else()
            continue;
        }


    }

    */
    int a[]={2,6,8,999,999,999,999};
    int b[]={3,5,7,9};
    int n = sizeof(b)/sizeof(int);
    int m = sizeof(a)/sizeof(int);
    cout<<"m="<<m<<"  n="<<n<<endl;
    int k=m-n;
    for(int i=0,j=0; i<m,j<n;)
    {
        if(a[i]<=b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            a[k] = a[i];
            a[i] = b[j];
            k++;
            j++;
            i++;
        }
        cout<<"\nArray a: ";
        for(int i=0; i<m; i++)
        {
        cout<<a[i]<<"  ";
        }
    }

    cout<<"\n\nSorted a = ";
    for(int i=0; i<m; i++)
    {
        cout<<a[i]<<"  ";
    }

    //cout << "Hello world!" << endl;
    return 0;
}
