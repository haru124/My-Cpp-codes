#include <iostream>

using namespace std;

class student
{
    string n;
    float t;
public:
    void get();
    void print();
    void checkpass(float , float pm=50);
};

void student::get()
{
    cout<<"\n Enter name and total marks";
    cin>>n>>t;

}

void student::print()
{
    cout<<" \nStudent name : "<<n;
    cout<<"\n Total marks : "<<t;
}

void student::checkpass(float t,float pm)
{
    if(t>=pm)
        cout<<"\n Pass ";
    else
        cout<<"\n Fail ";
}
int main()
{
    student a,b;
    a.get();
    a.print();
    a.checkpass(a.t);
    b.get();
    b.print();
    b.checkpass(b.t,pm=60);
    return 0;
}
