#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
#define p 3.14524638
int main()
{
    int a=67,x=10;
    char ch='s';
    cout<<"\n char = "<<ch;
    cout<<"\n ascii of char = "<<(int)ch;
    cout<<"\n a = "<<a;
    ch=(char)a;
    cout<<"\n a = "<<(char)a<<ch;
    cout<<"\n x^3 = "<<pow(x,3);
    cout<<"\n double is "<<setprecision(6)<<p;
    cout << "\nHello world!\nThis is Maya\nI'm a witch" << endl;
    return 0;
}
