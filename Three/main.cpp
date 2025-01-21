#include <iostream>

using namespace std;

class Three
{
   int n1,n2,n3;
   public:
       void get();
       void print();
       friend int max(Three);
};

void Three::get()
{
    cout<<"\n Enter 3 no.s\n";
    cin>>n1>>n2>>n3;
}

void Three::print()
{
    cout<<"\n Three no.s of this class are : ";
    cout<<n1<<"\t"<<n2<<"\t"<<n3;
}

int max(Three t)
{
    int x,m;
    x=(t.n1>t.n2)?t.n1:t.n2;
    m=(x>t.n3)?x:t.n3;
    cout<<"\nMax of ehe Three is ";
    cout<<m;
    return(m);
}
int main()
{
    cout << "Hello world!" << endl;
    Three t1;
    t1.get();
    t1.print();
    max(t1);
    return 0;
}
