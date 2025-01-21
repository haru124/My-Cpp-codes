#include <iostream>`

using namespace std;

class complex
{
    int r,i;
public:
    void get();
    void show();
    friend complex operator +(complex,complex);
};

void complex::get()
{
    cout<<"\n Enter real and imaginary part\n";
    cin>>r>>i;
}

void complex:: show()
{
    cout<<"\n Complex no is  "<<r<<"+"<<i<<"i\n";
}

complex operator +(complex c1,complex c2)
{
    complex C;
    C.r=c1.r+c2.r;
    C.i=c1.i+c2.i;
    return(C);
}


int main()
{
    complex c1,c2,c3;
    cout<<"Enter 2 complex no.s u want to add\n";
    c1.get();
    c2.get();
    cout<<"\n c1 : ";
    c1.show();
    cout<<"\n c2 : ";
    c2.show();
    c3=c1+c2;
    cout<<"\n c3 : ";
    c3.show();

    return 0;

}
