#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int a=3;
    int *p,*i;
    p=&a;
    *i=a;
    cout<<"a : "<<a<<endl;
    cout<<"a : "<<*p<<endl;
    cout<<"a : "<<*i<<endl;
    cout<<"address of a : "<<p<<endl;
    return 0;
}
