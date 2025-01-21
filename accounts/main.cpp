#include <iostream>

using namespace std;

class accounts
{
protected:
    float balance;
    int ano;
    string aname,aadd;
public:
    accounts();
    accounts(float,int,string,string);
    virtual void withdrawal()=0;
    virtual void deposit()=0;
    virtual void display()=0;

};

accounts::accounts()
{
    balance=0;
    ano=0;
    aname="---";
    aadd="xxx";
}
accounts::accounts(float b,int no,string n,string ad)
{
    balance=b;
    ano=no;
    aname=n;
    aadd=ad;
}

class savingsaccount:public accounts
{
    int irate;
public:
    savingsaccount();
    savingsaccount(float,int,string,string,int);
    void withdrawal();
    void deposit();
    void calcamount();
    void display();

};
savingsaccount::savingsaccount():accounts()
{
    irate=0;
}
savingsaccount::savingsaccount(float a,int b,string c,string d,int r):accounts(a,b,c,d)
{
    irate=r;
}

void savingsaccount::calcamount()
{
    balance=balance+((balance*irate)/100);
}

void savingsaccount::withdrawal()
{
    int w;
    cout<<"\n Enter amount";
    cin>>w;
    balance=balance-w;
    cout<<"\n Net Main Balance \tRs."<<balance;
}
void savingsaccount::deposit()
{
    int d;
    cout<<"\n Enter amount";
    cin>>d;
    balance=balance+d;
    cout<<"\n Net Main Balance \tRs."<<balance;
}
void savingsaccount::display()
{

    calcamount();
    cout<<"\n\nAccount holder name\t"<<aname<<"\nAccount no.\t"<<ano<<"\nAddress\t"
         <<aadd<<"\nRate of interest\t"<<irate<<"%"<<"\nMain Balance\tRs."<<balance;
}

class currentaccount:public accounts
{
    float odlimit;
public:
    currentaccount();
    currentaccount(float,int,string,string,float);
    void withdrawal();
    void deposit();
    void display();
};
currentaccount::currentaccount():accounts()
{
    odlimit=0;
}
currentaccount::currentaccount(float a,int b,string c,string d,float od):accounts(a,b,c,d)
{
    odlimit=od;

}
void currentaccount::withdrawal()
{
    int w;
    cout<<"\n Enter amount";
    cin>>w;
    balance=balance-w;
    cout<<"\n Net Main Balance \tRs."<<balance;
}
void currentaccount::deposit()
{
    int d;
    cout<<"\n Enter amount";
    cin>>d;
    balance=balance+d;
    cout<<"\n Net Main Balance \tRs."<<balance;
}
void currentaccount::display()
{
    cout<<"\n\nAccount holder name\t"<<aname<<"\nAccount no.\t"<<ano<<"\nAddress\t"
         <<aadd<<"\nBalance\tRs."<<balance<<"\nOverdraft limit\tRs."<<odlimit;

   balance=odlimit+balance;
   cout<<"\nMain balance\tRs."<<balance;
}


int main()
{
    accounts *A;
    char x;
    cout << "\n Enter s for savings account or\nc for current account" << endl;
    cin>>x;
    switch(x)
    {
        case 's':
        {

            savingsaccount S(10000,555,"Kanmani","Chennai",5);
            A=&S;
            A->display();
            int m;
            cout<<"\n Choose method 1.Withdrawal\n2.Deposit";
            cin>>m;
            if(m==1)
            {
                A->withdrawal();
            }
            else if(m==2)
            {
                A->deposit();
            }
            else{cout<<"\n choose valid option";}


            break;
        }

        case 'c':
        {
            currentaccount C(10000,555,"Kanmani","Chennai",100000);
            A=&C;
            A->display();
            int mt;
            cout<<"\n Choose method 1.Withdrawal\n2.Deposit";
            cin>>mt;
            if(mt==1)
            {
                A->withdrawal();
            }
            else if(mt==2)
            {
                A->deposit();
            }
            else{cout<<"\n choose valid option";}

            break;
        }
        default:
        cout<<"\n Select valid option";
        break;
    }
    return 0;
}
