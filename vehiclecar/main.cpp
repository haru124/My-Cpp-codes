#include <iostream>

using namespace std;
class vehicle
{
protected:
    string name;
    int mno;
    float mp;
    public:
    vehicle();
    vehicle(string,int,float);
    void display();
};

vehicle::vehicle()
{
    name="NULL";
    mno=0;
    mp=000;
}

vehicle::vehicle(string n,int mn,float p)
{
    name=n;
    mno=mn;
    mp=p;
}

void vehicle::display()
{
    cout<<"\n Model Name : "<<name<<"\n Model no. : "<<mno
    <<"\n Model price : Rs."<<mp;
}

class car:public vehicle
{
    int dr;
public:
    car();
    car(string,int,float,int);
    float discount();
    void display();
};

car::car():vehicle()
{
    dr=0;
}

car:: car(string w,int x,float y,int z):vehicle(w,x,y)
{
    dr=z;
}

float car::discount()
{
    float t;
    t=mp-((dr*mp)/100);
    return(t);
}

void car:: display()
{
    cout<<"\n CAR ";
    vehicle::display();
    cout<<"\n Discount : "<<dr<<"%"<<"\n Net price : "<<discount();
}

int main()
{
    car A,B("Audi",555,5000000,5);

    A.display();

    B.display();
}
