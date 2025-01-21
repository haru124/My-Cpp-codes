#include <iostream>

using namespace std;
class number
{
    int n;
public:
    void get();
    void print();
    friend number operator*(number,int);
};

void number::get()
{
    cout<<"\n enter n";
    cin>>n;

}

void number::print()
{
    cout<<"\n no is  "<<n;
}

number operator*(number N, int a)

{
    number x;
    x.n=N.n*a;
    return(x);

}

int main()
{
    number A,B;
    A.get();
    A.print();
    B=operator*(A,5);
    B.print();
    int m;
    number C;
    cout<<"\n Enter mul no..";
    cin>>m;
    C=A*m;
    C.print();
}
