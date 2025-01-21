#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    char s[10], t[]="hello";
    s[0]=t[0];
    cout<<"\nString s is "<<s;
    cout <<"\nLength of string s is " <<strlen(s) << endl;
    s[1]=t[3];
    cout<<"\nString s is "<<s;
    cout <<"\nLength of string s is " <<strlen(s) << endl;
    return 0;
}
