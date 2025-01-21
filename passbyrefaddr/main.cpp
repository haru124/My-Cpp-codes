#include <iostream>

using namespace std;
void swap(int*,int*);
int main()
{
    int a, b;
    cout<<"\n Enter a and b ";
    cin>>a>>b;
    cout<<"\n a and b are "<<a<<"\t"<<b;
    swap(&a,&b);
    return 0;
}
void swap(int*a,int*b)
{
    cout<<*a<<"\t"<<*b<<endl;
       cout<<a<<"\t"<<b<<endl;
    int t;
    t=*a;
    *a=*b;
    *b=t;
    cout<<"After swap a and b are "<<*a<<"\t"<<*b<<endl;
    cout<<a<<"\t"<<b<<endl;
}
