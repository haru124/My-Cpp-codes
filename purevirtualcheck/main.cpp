#include <iostream>

using namespace std;
class base
{
protected:
    int i;
public:
    virtual void show()
    {
        cout<<"\nBase class show";
    }
    virtual void print()=0;
};

class child:public base
{
    int x;
public:
    void show()
    {
        cout<<"\nChild class show";
    }
    void print()
    {
        cout<<"\nprint ";
    }
};

int main()
{
    cout << "Hello world!" << endl;
    child C;
    base *b;


    b=&C;
    b->show();
    b->base::show();
    b->print();
    return 0;
}
