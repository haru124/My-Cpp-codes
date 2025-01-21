#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    char c[5]="abcd";
    char b[10];
    cout<<"c is "<<c<<endl;
    cout << "c length " <<strlen(c)<< endl;
    cout<<c[0]<<"\t"<<c[1]<<"\t"<<c[2]<<"\t"<<c[3]<<"\t"<<c[4]<<"\t";
    strcpy(b,c);
    cout<<"\nb is "<<b<<endl;
    cout << "b length " <<strlen(b)<< endl;
    return 0;
}
