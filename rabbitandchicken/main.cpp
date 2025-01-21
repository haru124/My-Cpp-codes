#include <iostream>

using namespace std;

int main()
{
    int h,l;
    cout<<"Enter head and leg count"<<endl;
    cin>>h>>l;

    int x,y,a;
    int flag=0;

    a=(4*h)-l;
    y=a/2;
    x=h-y;
    if((x+y)==h && ((4*x)+(2*y))==l && x%1==0 && y%1==0)
        {
            cout<<"Chickens = "<<y<<endl;
            cout<<"Rabbits = "<<x<<endl;
            flag=1;
        }

    if(flag!=1)
    {
        cout<<"\nThe number of chickens and rabbits cannot be found\n";
    }

    return 0;
}
