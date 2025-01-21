#include <iostream>

using namespace std;
class shape
{
protected:
    double x,y;
public:
    void getdata(float,float b=0);
    virtual void displayarea()=0;
};
void shape::getdata(float a,float b)
{
    x=a;
    y=b;
}
 class triangle:public shape
 {
 public:
    void displayarea()
    {
        cout<<"\n Area of triangle = "<<0.5*x*y;
    }
 };

 class rectangle:public shape
 {
 public:
    void displayarea()
    {
        cout<<"\n Area of rectangle = "<<x*y;
    }
 };

 class circle:public shape
 {
 public:
    void displayarea()
    {
        cout<<"\n Area of circle = "<<3.14*x*x;
    }
 };

int main()
{
    shape *S;
    triangle t;
    S=&t;
    S->getdata(2,3);
    S->displayarea();

    rectangle r;
    r.getdata(5,4);
    r.displayarea();

    circle c;
    S=&c;
    S->getdata(2);
    S->displayarea();
    return 0;
}
