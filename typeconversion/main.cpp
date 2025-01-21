#include <iostream>
#include<string.h>
using namespace std;

class strings
{
    char *p;
    int l;
public:
    strings(char *);
    void dis();
};

strings::strings(char *a)
{
    l=strlen(a);
    cout<<"\n length is  "<<l;
    p=new char[l];
    strcpy(p,a);
}

void strings::dis()
{
    cout<<"\n Your string is : "<<p;
}

int main()
{
    char *s="MIT";
    char *r="ECE";
    cout<<"\n s and r are \n"<<s<<"\t"<<r<<endl;

    strings s1=s,s2=strings(r);
    s1.dis();

    s2.dis();
    return 0;
}
