#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string s;
    cout<<"\n Enter string \n";
    cin>>s;
    cout<<"\n String is "<<s;
    int x;
    x=s.size();                        //or x=s.length();
    cout<<"\n String size is "<<x;
    char c[s.length()+1];              //or char c[s.size()];
    int z;
    z=strlen(c);
    cout<<"\n Char array size after declaration is "<<z;
    //strcpy(c,s.c_str());
    //s.copy(c,s.size()+1);
    copy(s.begin(),s.end(),c);
    c[s.length()]='\0';
    cout<<"\n Char array is "<<c;
    int v;
    v=strlen(c);
    cout<<"\n Char array size after string copy is "<<v;
    c[s.length()-1]='\0';
    int y;
    y=strlen(c);
    cout<<"\n Char array is "<<c;
    cout<<"\n Char array size is "<<y;
    return(0);
}
