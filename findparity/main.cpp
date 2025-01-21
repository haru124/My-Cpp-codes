#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    string p;
    cin>>p;
    int m=0, par;
    for (int i=0; i<p.length(); i++)
    {
        if(p[i] == '1')
        {
            m++;
        }
    }
    if (m%2 == 0)
    {
        par = 0;
    }
    else
        par =1;
    cout << "Hello world! parity bit = " <<par<< endl;
    return 0;
}
