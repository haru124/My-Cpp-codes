#include <iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c[50];
    int i;
    cout<<"Enter char array "<<endl;
    cin>>c;
    cout<<"\n Char array is "<<c;

    for(i=0;i<strlen(c)/2;i++)
    {
        char temp=c[i];
        c[i]=c[strlen(c)-i-1];
        c[strlen(c)-i-1]=temp;
       // swap(c[i],c[strlen(c)-i-1]) ;
    }
    cout<<"\n Reversed Char array is "<<c;
    char b[50];
    for(i=0;i<strlen(c);i++)
    {
        b[i]=c[strlen(c)-i-1];
    }
    b[strlen(c)]='\0';
    cout<<"\n b Char array is "<<b;


    string s;
    cout<<"\nEnter string "<<endl;
    cin>>s;
    cout<<"\n String is "<<s;
    int l=s.size();
    int j;
    /*for(j=0;j<l/2;j++)
    {
        char temp=s[j];
        s[j]=s[l-j-1];
        s[l-j-1]=temp;
        swap(s[j],s[l-j-1]) ;
    }
    */
    reverse(s.begin(),s.end());

    cout<<"\n Reversed String is " <<s;

}
