#include <iostream>

using namespace std;
int sum(float f,double d)
{
    int sum;
    sum=f+d;
    return(sum);
}
int main()
{
    cout << "Hello world!" << endl;
    float f;
    double d;
    cout<<"\n enter f,d";
    cin>>f>>d;
    cout<<"\n F= "<<(float)f<<"\n D= "<<(double)d;
    cout<<sum(f,d);
    return 0;
}
