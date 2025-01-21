#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a="asdgdsagds";
    string b="adfsds";
    int i=0;
    int l;
    l=(a.size()>b.size())?a.size():b.size();
    cout<<"large string size"<<l;
    while(i<l)
    {
    if(b[i]!=a[i])
    {
        cout<<"diff\n";
    }
    i++;
    }
    /*string s,r;
    cout<<"Enter string ";
    cin>>s;
    cout<<"\nString is "<<s;
    int l,m,n;
    l=s.size();
    cout<<"\noriginal string size "<<l;
    r[0]=s[0];
    cout<<"\nString index 0 is "<<s[0]<<r[0];
    for(m=1;m<l;m++)
    {
        for(n=m-1;n<=0;n--)
        {
            if(s[n]!=s[m])
                {
                    r[m]=s[m];
                }
        }
    }
    cout<<"\nCharacters in string are "<<r;
    cout<<"\nsize of r "<<r.size();
    */
    return 0;
}

