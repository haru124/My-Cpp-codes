#include <iostream>

using namespace std;
class matrix
{

    int r,c;
    int a[r][c];
public:
    void getmatrix(int,int);
    void display();
};


void matrix::getmatrix(int r,int c)
{
    int i,j;

    cout<<"\n Enter elements of matrix row by row";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
}

void matrix::display()
{
    int i,j;
    cout <<"\n Your matrix is \n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}



int main()

{
    matrix m1,m2;
    m1.getmatrix(3,3);
    m1.display();
    m2.getmatrix(2,2);
    m2.display();
    return 0;
}
