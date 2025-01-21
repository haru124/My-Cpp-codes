#include <iostream>

using namespace std;

class link
{
public:
    int data;
    link *add;
    link get();
    void print();
};

link link::get()
{
    link l;
    cout<<"\n Enter data";
    cin>>l.data;
    l.add=&l;
    return(l);
}

void link::print()
{
    cout<<"\n Data :  "<<data;
    cout<<"\n Address :  "<<add;
}
int main()
{
    link L;
    L.get();
    L.print();
}
