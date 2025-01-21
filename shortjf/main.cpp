#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class process
{
    public:
    string x;
    int at;
    int bt;
    int pt;
    int tat;
    int wt;
    int ct;
    bool s;


    process()
    {
        x = "\0";
        at = 0;
        bt = 0;
        pt = 0;
        tat = 0;
        wt = 0;
        ct = 0;
        s= false;
    }
    process(string st, int a, int b, int c)
    {
        x = st;
        at = a;
        bt = b;
        pt = c;
        tat = 0;
        wt = 0;
        ct = 0;
        s= false;
    }

    void print()
    {
        cout<<"\n"<<x<<"\t"<<at<<"\t"<<bt<<"\t"<<pt<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt;
    }
    void get();
    //void swap(process,process);
};
void process::get()
{
    cout<<"\nEnter Process name, Arrival time, Burst time and Priority\n";
    cin>>x;
    cin>>at;
    cin>>bt;
    cin>>pt;
}
void swap(process &a, process &b)
{
  //cout<<"\nInside swap";
  string t1;
  int t2;
  t1 = a.x;
  a.x = b.x;
  b.x = t1;

  t2 = a.at;
  a.at = b.at;
  b.at = t2;

  t2 = a.bt;
  a.bt = b.bt;
  b.bt = t2;

  t2 = a.pt;
  a.pt = b.pt;
  b.pt = t2;
}
void sjf(process *p, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(p[j].bt < p[i].bt)
            {
            swap(p[j],p[i]);
            }

        }

    }
}

void calc(process *P, int n)
{
    for(int i=0; i<n; i++)
    {
        if(i==0){
          P[i].wt = 0;
          //P[i].ct = P[i].bt + P[i].at;
          P[i].tat = P[i].ct - P[i].at;
        }
        else{
          //P[i].ct = P[i-1].ct + P[i].bt;
          P[i].tat = P[i].ct - P[i].at;
          P[i].wt = P[i].tat - P[i].bt;
        }
    }

    float sTAT=0, sWT=0;
    for(int i=0; i<n; i++)

    {
        sTAT += P[i].tat;
        sWT+= P[i].wt;
    }
    cout<<"\n\nUsing SJF:\n";
    cout<<"\nAverage TAT : "<<sTAT/n;
    cout<<"\nAverage WT : "<<sWT/n;
}

void print(process *p, int n)
{
    cout<<"\nPrcs"<<"\tA.Time"<<"\tB.Time"<<"\tPrty"<<"\tC.Time"<<"\tTAT"<<"\tWT\n";
    for(int i=0; i<n; i++)
    {
        p[i].print();
    }
}

int main()
{
    //int n,i;
    //cout<<"\nEnter the number of processes to be scheduled ";
    //cin>>n;
    process P[4]={process("p1",4,3,0),process("p2",2,1,0),process("p3",1,2,0),process("p4",3,4,0)};
    /*for(i=0; i<n; i++)
    {
        P[i].get();
    }
    */
    int n=sizeof(P)/sizeof(P[0]);
    print(P,n);
    sjf(P,n);
    cout<<"\nAfter sorting the processes in ascending order of their burst time:\n";
    print(P,n);
    process s[n];
    int clk =0,lowest_at=100,j=0;
    while(j!=n){
    int flag=0;
    for(int i=0; i<n; i++)
    {
        if(P[i].s == false && P[i].at < lowest_at)
            lowest_at = P[i].at;
        if(P[i].s == false && P[i].at <= clk)
        {
            P[i].s = true;
            s[j] = P[i];
            if(j==0)
               s[j].ct = s[j].bt + s[j].at;
            else
               s[j].ct = s[j-1].ct + s[j].bt;
            clk = s[j].ct;
            //clk += P[i].bt;
            cout<<"\nClock = "<<clk<<endl;
            j++;
            flag =1;
            break;
        }
    }
    if(flag==0){
    clk += lowest_at;
    cout<<"\n clock incremented-flag0. Clock = "<<clk<<endl;
    }
}
    calc(s,n);

    print(s,n);


    return 0;
}
