#include <iostream>
#include<iomanip>
using namespace std;
#define pi 3.14
const double t=10;
int main()
{
    float x=65.35457,y,z;
    z=x*t;
    y=x*pi;
    char ch;
    int CH;
    ch=(char)x;
    CH=static_cast<int>(x);
    cout << ch << endl;
    cout << CH << endl;
    cout << setprecision(8)<<y << endl;
    cout << setprecision(8)<<z << endl;
    return 0;
}

