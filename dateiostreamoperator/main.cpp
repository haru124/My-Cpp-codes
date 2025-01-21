#include <iostream>

using namespace std;

class date
{
    int d,m,y;
public:
    friend istream& operator>>(istream&,date&);
    friend ostream& operator<<(ostream&,date&);
};

istream& operator>>(istream& in,date& D)
{
    cout<<"\n Enter date month year";
    in>>D.d>>D.m>>D.y;
    return(in);
}

ostream& operator<<(ostream& out,date& D)
{
    cout<<"\n Date is  ";
    cout<<D.d<<"/"<<D.m<<"/"<<D.y<<endl;
    return(out);
}

int main()
{
  date d1;
  cin>>d1;
  cout<<d1;
}
