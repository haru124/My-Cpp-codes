#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string s;
    string a="abcdefghijklmnopqrstuvwxyz";
    char r[26];
    cout<<"Alphabet string\n"<<a;
    cout<<"\nEnter input string ";
    cin>>s;
    cout<<"\nString is "<<s;
    int l=s.size();
    cout<<"\nInput string length is "<<l<<endl;
    int m,n,ct=0,o=0;
    for(m=0;m<a.size();m++)
    {
        for(n=0;n<l;n++)
        {
            if(s[n]==a[m])
            {
                ++ct;
            }
        }
        if(ct!=0)
        {
        r[o]=a[m];
        o++;
        cout<<a[m]<<" is repeated "<<ct<<" times\n";
        ct=0;
        }
    }
    r[strlen(r)]='/0';
    cout<<"\nReduced string is "<<r;
    cout<<"\nReduced string length is "<<strlen(r);

    return 0;
}
