#include <iostream>

using namespace std;

int main()
{
int n;
char ch;
cout<<"\n enter n";
cin>>n;
if(n>=0 && n<=35)
{
if(n<=9)
cout<<"\n n is  "<<n;
else
{

ch=char(n+87);
cout<<"\n char is  "<<ch;
}
}
else {cout<<"\n Invalid";}
}

