#include <iostream>

using namespace std;
//prgm explicit =operatoroverloading

class number
{
    int n;
public:
    void get();
    void show();
    void operator=(number);
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

void number::operator=(number N)
{
    n=N.n;
}

int main()
{
    cout << "Hello world!" << endl;
    number a,b;
    a.get();
    a.show();
    b.operator=(a);
    b.show();
    return 0;
}
