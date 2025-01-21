#include <iostream>

using namespace std;
class father
{
protected:
    int age;
public:
    father()
    {
        age=0;
    }
    father(int x)
    {
        age=x;
    }
    virtual void iam()
    {
        cout<<"\n I am the Father,my age is "<<age<<endl;
    }
};

class son:public father
{
public:
    son()
    {
        age=0;
    }
    son(int y)
    {
        age=y;
    }
    void iam()
    {
        cout<<"\n I am the son, my age is "<<age<<endl;
    }
};

class daughter:public father
{
public:
    daughter()
    {
        age=0;
    }
    daughter(int z)
    {
        age=z;
    }
    void iam()
    {
        cout<<"\n I am the daughter, my age is "<<age<<endl;
    }
};
int main()
{
    father f(40);
    f.iam();
    son s(18);
    s.iam();
    daughter d(10);
    d.iam();

    father *p,F(30);
    p=&F;
    p->iam();
    son S(5);
    p=&S;
    p->iam();
    daughter D(3);
    p=&D;
    p->iam();

    return 0;
}
