#include <iostream>
using namespace std;
int largest(int,int,int);
int largest(int a,int b,int c)
{
    int n,max;
    n=(a>b)?a:b;
    max=(n>c)?n:c;
    return(max);
}

int main()
{
    cout<<"largest is";
   cout<<largest(45,7,80);

   return 0;
}
