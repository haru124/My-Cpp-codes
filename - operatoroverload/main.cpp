#include <iostream>

using namespace std;

class number
{
    int n;
public:
    void get();
    void show();
    friend int operator <(number,number);
};

void number::get()
{
    cout<<"\n Enter no.\n";
    cin>>n;
}


void number::show()
{
    cout<<"\n No is  "<<n<<endl;
}


int operator <(number n1,number n2)
{
    return((n1.n<n2.n)?n1.n:n2.n);
}


int main()
{
    number N,M;
    int min;
    N.get();
    cout<<"number N:\n";
    N.show();
    M.get();
    cout<<"\n number M: \n";
    M.show();
    min=N<M;
    cout<<"\n Minimum is  "<<min;

    return 0;
}
