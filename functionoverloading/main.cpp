#include <iostream>
#include<string>
using namespace std;
void print(int);
void print(float);
void print(double);
void print(string);


int main()
{
    cout << "Hello world!" << endl;
    print(10);
    print("hey");
    print(12.444f);       //print(12.444) prints Double :12.444
    print(34.676459);
    return 0;
}

void print(int x)
{
    cout<<"\n Integer :"<<x;
}

void print(float x)
{
    cout<<"\n Float :"<<x;
}

void print(double x)
{
    cout<<"\n Double :"<<x;
}

void print(string x)
{
    cout<<"\n String :"<<x;
}
