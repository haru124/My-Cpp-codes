#include <iostream>

using namespace std;
void print(int x)
{
    cout<<"\nInteger is "<<x;
}

void print(float y)
{
    cout<<"\nFloat is "<<y;
}

void print(double y)
{
    cout<<"\nDouble is "<<y;
}

void print(string r)
{
    cout<<"\nString is "<<r;
}

int add(int a,int b)
{
    print(a);
    print(b);
    return(a+b);
}

float add(float a,float b)
{
    print(a);
    print(b);
    return(a+b);
}

double add(double a,double b)
{
    print(a);
    print(b);
    return(a+b);
}


string add(string a,string b)
{
    print(a);
    print(b);
    return(a+b);
}

int main()
{
    print(10);
    print(8.01);
    int i=add(3,5);
    float f=add(8.8,7.5);
    double d=add(0.988,2.05);
    string s=add("Hello ","World");
    print(i);
    print(f);
    print(s);

    print(d);
}
