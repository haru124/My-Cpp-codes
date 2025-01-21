#include <iostream>

using namespace std;

class Number
{
    int n;
public:
    Number();
    Number(int);
    Number(Number&);
    void put();
};

Number::Number()
{
    n=0;
}

Number::Number(int n)
{
    this->n=n;
}

Number::Number(Number& v)
{
    n=v.n;
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
    n1.put();
        n2.put();
            n3.put();
            n4.put();
            n5.put();
    return 0;
}
