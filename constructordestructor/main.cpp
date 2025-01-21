#include <iostream>

using namespace std;

class Number
{
    int n;
public:
    Number();
    Number(int);
    Number(Number&);
    ~Number();
    void put();
};

Number::Number()
{
    n=0;
    cout<<"\nDefault Constructor";
}

Number::Number(int n)
{
    this->n=n;
    cout<<"\nParameterised Constructor";
}

Number::Number(Number& v)
{
    n=v.n;
    cout<<"\nCopy Constructor";
}

Number::~Number()
{
    cout<<"\nDestructor";
}

void Number::put()
{
    cout<<"\nNumber is "<<n;
}

int main()
{
    cout << "Hello world!" << endl;
    Number n1,n2(4),n3(n2),n5=n3;
    Number n4= n1;
    Number n6;
    n6=n2;
    n1.put();
        n2.put();
            n3.put();
            n4.put();
            n5.put();
            n6.put();
    return 0;
}
