#include <iostream>

using namespace std;

class number
{
    int n;
public:
    void get();
    void show();
    friend number operator +(number,number);
};

void number::get()
{
    cout<<"\n Enter no.\n";
    cin>>n;
}

void number::show()
{
    cout<<"\n no. is  "<<n;
}

number operator+(number n1,number n2)
{
    number N;
    N.n=n1.n+n2.n;
    cout<<"\n sum is "<<N.n;
    return(N);


}
int main()
{
    cout << "Hello world!" << endl;
    number n1,n2,n3;
    n1.get();
    n2.get();
    n1.show();
    n2.show();
    n3=n1+n2;
    n3.show();
    return 0;
}
