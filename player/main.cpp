#include <iostream>

using namespace std;

class player
{
protected:
   string name;
   string nat;
public:
    player();
    player(string,string);
    virtual void print();
};

player::player()
{
    name="zzz";
    nat="yyy";
}

player::player(string n,string nt)
{
    name=n;
    nat=nt;
}

void player::print()
{
    cout<<"\n Player name : "<<name<<"\n Nationality : "<<nat;
}
class event:public player
{
   string etype;
   string ename;
public:
    event();
    event(string,string,string,string);
    void print();
};

event::event()
{
    etype="xxx";
    ename="aaa";
}
event::event(string a,string b,string c,string d):player(a,b)
{
    etype=c;
    ename=d;
}
void event::print()
{
    player::print();
    cout<<"\n Event type : "<<etype<<"\n Event name : "<<ename;
}


class personal:public player
{
    int age;
    char sex;
public:
    personal();
    personal(string,string,int,char);
    void print();
};

personal::personal()
{
    age=0;
    sex='X';
}

personal::personal(string a,string b,int l,char s):player(a,b)
{
    age=l;
    sex=s;
}
void personal::print()
{
    player::print();
    cout<<"\n Age : "<<age<<"\n Sex : ";
    if(sex=='M')
        cout<<"Male";
    if(sex=='F')
        cout<<"Female";
}


int main()
{
    player *P;
    cout<<"\n Enter 1 for event details\n2 for individual details";
    int o;
    cin>>o;
    if(o==1)
    {
        event E("Lily","Indian","Team","Hockey");
        P=&E;
        P->print();
    }
    else if(o==2)
    {
        personal p("Lily","Indian",20,'F');
        P=&p;
        P->print();
    }
    else{cout<<"\n Enter valid choice";}

}
