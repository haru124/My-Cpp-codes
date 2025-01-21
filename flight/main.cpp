#include <iostream>

using namespace std;
class flight
{
    int fno;
    float d;
    float f;
public:
    void feed();
    void show();
    void calcfuel();

};

void flight::feed()
{
    cout<<"\n enter fno dis ";
    cin>>fno>>d;
}

void flight::show()
{
    cout<<"\n Flight no and distance is ";
    cout<<fno<<endl<<d;
    cout<<"\n fuel needed "<<f;
}

void flight::calcfuel()
{
    if(d<=1000)
    {
        f=500;
    }
   else if(d>1000&&d<=2000)
    {
        f=1100;
    }
    else
        f=2200;


}


int main()
{
    flight f1;
    f1.feed();
    f1.calcfuel();
    f1.show();

}
