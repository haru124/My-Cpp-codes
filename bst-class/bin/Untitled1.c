#include<stdio.h>

int bin(int n)
{
 int p=0, r=0;
 while(n!=0)
 {
     r+= pow(10,p) * (n%2);
     n = n/2;
     p++;
 }
 return r;
}
int main()
{
    int n = 10;
    int res= bin(10);
    printf("%d",res);
    return 0;
}
