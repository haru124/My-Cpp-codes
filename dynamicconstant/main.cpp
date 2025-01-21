#include <iostream>

using namespace std;

int main()
{
    int *p;
    cout << "Hello world!" << endl;
    p= new int;
    cout<<"\n Enter no ";
    cin>>*p;
    cout<<"\nNo is "<<*p;
    int *a;
    a= new int[*p];
    cout<<"\nEnter array\n";
    for(int i=0;i<*p;i++)
    {
       cin>>*(a+i);
    }

    cout<<"\nArray is\n";
    for(int i=0;i<*p;i++)
    {
       cout<<*(a+i)<<"  ";
    }
    return 0;
}
