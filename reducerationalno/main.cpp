#include <iostream>

using namespace std;

int main()
{
    int n,d;
    cout << "Enter numerator and denominator" << endl;
    cin>>n>>d;
    if(d!=0)
    {
    int i,min,ct=0;
    min=(n<d)?n:d;
    cout<<"\nmin:"<<min<<"\n";
    for(i=min;i>=1;i--)
    {
        ct++;
        cout<<"\nLoop is executed "<<ct<<" time\n";
        if(n%i==0 && d%i==0)
        {
            n=n/i;
            d=d/i;
            break;
        }
    }
    cout<<"\nReduced Rational No is "<<n<<"/"<<d<<endl;
    }
    else
    {
        cout<<"\nDenominator cant be zero!!!";
    }

    return 0;
}
