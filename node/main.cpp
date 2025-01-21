#include <iostream>

using namespace std;

int main()
{
    int *a,*p;
    a= new int;
    cout<<"\n Enter data ";
    cin>>*a;
    p=a;
    cout<<"a = "<<*p<<"\t"<<*a;
    cout<<"\n ptr = "<<p;
    cout<<"\n ptr = "<<a;
    int **pp,**ap;
    pp=&p;
    ap=&a;
    cout <<"\n address of ptrs a and p are "<<pp<<"\t"<<ap;
    return 0;
}
