#include <iostream>

using namespace std;

class vector;
class matrix
{
    int a[2][2];
public:
    void get();
    void print();
    friend void multiply(matrix,vector);
};

class vector
{
    int b[2][1];
public:
    void get();
    void print();
    friend void multiply(matrix,vector);
};


void matrix::get()
{
    cout<<"\n Enter the matrix row by row\n";
    cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
}

void matrix::print()
{
    cout<<"\n The matrix given is : \n";
    cout<<a[0][0]<<"\t"<<a[0][1]<<"\n"<<a[1][0]<<"\t"<<a[1][1];
}

void vector::get()
{
    cout<<"\n Enter the vector matrix row by row\n";
    cin>>b[0][0]>>b[1][0];
}

void vector::print()
{
    cout<<"\n The vector matrix given is : \n";
    cout<<b[0][0]<<"\n"<<b[1][0];
}

void multiply(matrix m,vector v)
{
    int s[2][1];
    s[0][0]=(m.a[0][0]*v.b[0][0]) + (m.a[0][1]*v.b[1][0]);
    s[1][0]=(m.a[1][0]*v.b[0][0]) + (m.a[1][1]*v.b[1][0]);
    cout<<"\n After Multiplication : \n";
    cout<<s[0][0]<<"\n"<<s[1][0];
}

int main()
{
    matrix m1;
    vector v1;
    m1.get();
    v1.get();
    m1.print();
    v1.print();
    multiply(m1,v1);
    return 0;
}
