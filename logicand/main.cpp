#include <iostream>

using namespace std;

int main()
{
    int a= 9 & 1;
    cout<<a<<endl;
   for(int x=10;x>=0;x--)
   {
       cout<<"x : "<<x<<"  ";
       int z=x&(x>>1);
       cout<<"z : "<<z<<"  ";
       if(z)
       cout<<"if cond z : "<<z<<endl;

   }
}
