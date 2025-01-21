#include <iostream>

using namespace std;

class rational
{
    int n,d;
public:
    rational();
    rational(int,int);
    rational(rational&);
    void get();
    void print();
    rational reduce(rational);
    rational add(rational,rational);
    rational sub(rational,rational);
    rational multiply(rational,rational);
    rational divide(rational,rational);
};

rational::rational()
{
    n=1;d=1;
    cout<<"\ndefault\n";

}

rational::rational(int nu,int de)
{


    cout<<"\n parameterised \n";
    cout<<"\n given no. is "<<nu<<"/"<<de;
    int i,max;
    max=(nu>de)?nu:de;
    cout<<"\nmax:"<<max<<"\n";
    for(i=max;i>=1;i--)
    {
        if(nu%i==0 && de%i==0)
        {
            nu=nu/i;
            de=de/i;

        }
    }
    n=nu;d=de;
    cout<<"\n Simplified fraction is\t"<<n<<"/"<<d;

}

rational::rational(rational& r)
{
    n=r.n;
    d=r.d;
    cout<<"\n Copy\n";

}

void rational::get()
{
    cout<<"\n Enter numerator and denominator\n";
    cin>>n>>d;
    cout<<"\n The given rational no is\n"<<n<<"/"<<d;
}

void rational::print()
{
    cout<<"\n The fraction is  "<<n<<"/"<<d<<endl;
}

rational rational::reduce(rational r)
{
    int i,max;
    max=(r.n>r.d)?r.n:r.d;
    for(i=max;i>=1;i--)
    {
        if(r.n%i==0&&r.d%i==0)
        {
            r.n=r.n/i;r.d=r.d/i;
        }
    }
    cout<<"\n Simplified fraction is\t"<<r.n<<"/"<<r.d;
    return(r);
}

rational rational::add(rational r1,rational r2)
{
    rational a;
    a.n=(r1.n*r2.d)+(r2.n*r1.d);
    a.d=r1.d*r2.d;
    a=a.reduce(a);
    return(a);
}

rational rational::sub(rational r1,rational r2)
{
    rational s;
    s.n=(r1.n*r2.d)-(r2.n*r1.d);
    s.d=r1.d*r2.d;
    s=s.reduce(s);
    return(s);
}

rational rational::divide(rational r1,rational r2)
{
    rational dv;
    dv.n=r1.n*r2.d;
    dv.d=r1.d*r2.n;
    dv=dv.reduce(dv);
    return(dv);
}

rational rational::multiply(rational r1,rational r2)
{
    rational m;
    m.n=r1.n*r2.n;
    m.d=r1.d*r2.d;
    m=m.reduce(m);
    return(m);
}

int main()
{
    rational r1,r2(3,4),r3(15,12),r4(r3),r5,r6;

    cout<<"\n r1 is";
    r1.print();
    cout<<"\n r2 is";
    r2.print();
    cout<<"\n r3 is";
    r3.print();
    cout<<"\n r4 is";
    r4.print();
    r5.get();
    r5=r5.reduce(r5);
    cout<<"\n r5 is";
    r5.print();

    r6=r2;
    cout<<"\n r6 is";
    r6.print();

    rational ra,rs,rm,rd;
    ra=ra.add(r2,r3);
    cout<<"\n Addition is:\n";
    ra.print();
    rs=rs.sub(r3,r4);
    cout<<"\n Subtraction is:\n";
    rs.print();
    rm=rm.multiply(r5,r6);
    cout<<"\n Multiplication is:\n";
    rm.print();
    rd=rd.divide(r5,r6);
    cout<<"\n Division is:\n";
    rd.print();
    return 0;
}


