#include <iostream>

using namespace std;

void isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        cout<<"\nis op";
    else
        cout<<"\nis not op";
}

void swap(int *m,int *n)
{
    int t;
    t=*m;
    *m=*n;
    *n=t;
    cout<<"\n After swap a and b are ";
    cout<<*m<<"\t"<<*n;

}

void add(int &p,int &q)
{
    int sum;
    sum=p+q;
    cout<<"\n a and b are "<<p<<"\t"<<q;
    cout<<"\n sum is "<<sum;
    int &total=sum;
    cout<<"\n Total="<<total<<endl;

}

void print(int l,int m)
{
    cout<<"\n a="<<l<<"  b="<<m;
}



int main()
{
    cout << "Hello world!" << endl;
    int a,b;
    cout<<"\n Enter a,b  ";
    cin>>a>>b;
    print(a,b);
    swap(&a,&b);
    cout<<"\n a and b now "<<a<< "\t" << b;
    add(a,b);

    char c;
    cin>>c;
    isoperator(c);


    cout<<endl;
    return 0;
}
