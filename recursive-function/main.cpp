#include <iostream>

using namespace std;

void fun1(int n)
{
    if(n==0)
        return;

    fun1(n/2);
    cout<<n%2<<endl;
}

void fun2(int n)
{
    if(n<=0)
        return;

    cout<<n<<endl;
    fun2(n*2);
    cout<<n<<endl;
}
int main()
{
    cout << "Hello world!" << endl;
    fun1(9);
    //fun2(5);
    return 0;
}
