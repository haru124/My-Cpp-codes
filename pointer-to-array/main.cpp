#include <iostream>

using namespace std;

int main()
{
    int a[]={1,8,3,4,5,6,7};
    int *p = a;

    cout << "Printing a " <<a<< endl;
    cout << "Printing &a " <<&a<< endl;
    cout << "Printing *a " <<*a<< endl;
    cout << "Printing *a+1 " <<*a+1<< endl;
    cout << "Printing *(a+1) " <<*(a+1)<< endl;
    cout << "Printing &*(a+1) " <<&*(a+1)<< endl;
    cout << "Printing &a+1 " <<&a+1<< endl;
    //cout << "Printing &(a+1) " <<&(a+1)<< endl;
    cout << "Printing p " <<p<< endl;
    cout << "Printing &p " <<&p<< endl;
    cout << "Printing *p " <<*p<< endl;
    cout << "Printing *p+1 " <<*p+1<< endl;
    cout << "Printing *(p+1) " <<*(p+1)<< endl;
    cout << "Printing &*(p+1) " <<&*(p+1)<< endl;
    cout << "Printing p+1 " <<p+1<< endl;
    cout<< "Printing p[2] "<<p[2];


    return 0;
}
