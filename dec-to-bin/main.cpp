#include<iostream>
#include<math.h>
using namespace std;
int bin(int n)
{
 int p=0, r=0;
 while(n!=0)
 {
     r+= pow(10,p) * (n%2);
     //cout<<"n = "<<n<<"  r = "<<r<<"  power = "<<p<<endl;
     n = n/2;
     p++;
 }
 return r;
}

int bin_recursive(int n, int p = 0, int r = 0) {
    // Base case: when n becomes zero
    if (n == 0) {
        return r;
    }

    // Recursive case: calculate binary representation
    return bin_recursive(n / 2, p + 1, r + pow(10, p) * (n % 2));
}

int main()
{
    int n = 10;
    int res= bin(n);
    cout<<"Result from non recursive  = "<<res<<endl;
    int res2 = bin_recursive(n);
    cout<<"Result from recursive  = "<<res2<<endl;

    return 0;
}

