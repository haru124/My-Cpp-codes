#include <iostream>

using namespace std;
//class name cannot be distance
class dis
{
    int f;
    int i;
public:
    void get();
    void put();
    void sum(dis,dis);
    dis sum(dis);
};

 void dis::get()
    {
        cout<<"\n enter feet and inch\n";
        cin>>f>>i;
    }
void dis::put()
    {
        cout<<"feet : "<<f<<"\t inch : "<<i<<endl;
    }
dis dis::sum(dis x)
{
    dis d;
    d.i=i+x.i;
    d.f=f+x.f;
    if(d.i>=12)
    {
        d.f=d.f+(d.i/12);
        d.i=d.i%12;
    }
    return(d);
}

void dis::sum(dis x,dis y)
{
    i=x.i+y.i;
    f=x.f+y.f;
    if(i>=12)
    {
        f=f+(i/12);
        i=i%12;
    }
}

int main()
{
    dis d1,d2,d3,d4;
    d1.get();
    d2.get();
    d1.put();
    d2.put();
    d3 = d2.sum(d1);
    d3.put();
    d4.sum(d1,d2);
    d4.put();

    return 0;
}

