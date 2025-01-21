#include <iostream>

using namespace std;

class dyncons
{
    int *p;
public:
    dyncons();
    dyncons(int);
    ~dyncons();
};

dyncons::dyncons()
{
    p=new int;
    cout<<"\n enter a value ";
    cin>>*p;
    cout<<"\n Value = "<<*p<<"\n Address = "<<p;
}

dyncons::dyncons(int n)
{
    p=new int[n];
    int i;
    cout<<"\n Enter values of array of size "<<n<<endl;
    for(i=0;i<n;i++)
    {

        cin>>*p;
        p++;
    }
    p=p-n;

    cout<<"\n elements of array are";
    for(i=0;i<n;i++)
    {
        cout<<*p;
        p++;
    }
}

dyncons::~dyncons()
{
    delete p;
}

int main()
{
    dyncons a,b(4);
       return 0;
}
