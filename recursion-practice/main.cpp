#include <iostream>

using namespace std;

int fact(int *f,int n)
//factorial fnc using memorization
{
    if(n==0)
    {
        return 1;
    }
    f[n] = n * fact(f, n-1);
    return f[n];
}
int power(int x, int n)
{
    if (n==1)
        return x;

    return x*power(x, n-1);
}

int improvedPower(int x, int n)
{
    if (n==1)
        return x;

    if (n%2 == 0)
        return improvedPower(x,n/2) * improvedPower(x,n/2);
    else
        return x*improvedPower(x,n/2) * improvedPower(x,n/2);
}
int fibo(int *fib, int n)
{
    if (n==0)
    {
        fib[n] = 0;
        return 0;
    }
    if (n==1)
    {
        fib[n] = 1;
        return 1;
    }

    fib[n] = fibo(fib, n-1) + fibo(fib, n-2);

    return fib[n];

}
int main()
{
    cout << "Enter n__";
    int n;
    cin>>n;
    int f[n];
    cout<<"Factorial: "<<fact(f,n);
    int x;
    cout<<"\nEnter x__ ";
    cin>>x;
    cout<<"Power: "<<power(x,n);
    cout<<"\nUsing Improved solution, Power: "<<improvedPower(x,n);
    int fib[n];
    fibo(fib, n);
    cout<<"\nFibonacci series: ";
    for(int i=0; i<n; i++)
        {
           cout<<fib[i]<<"   ";
        }
    return 0;
}
