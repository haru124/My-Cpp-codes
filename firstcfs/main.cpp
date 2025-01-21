#include <iostream>
#include<string>
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


    process()
    {
        x = "\0";
        at = 0;
        bt = 0;
        pt = 0;
        tat = 0;
        wt = 0;
        ct = 0;
    }
    process(string s, int a, int b, int c)
    {
        x = s;
        at = a;
        bt = b;
        pt = c;
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
  cout<<"\nInside swap";
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

/*(void pc:: arrange(int *a)
{

}
*/
void fcfs(process *p, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(p[j].at < p[i].at)
            {
            cout<<"\n arrival times :"<<p[j].at<<p[i].at<<endl;
            cout<<"\nBefore Swap:";
            p[i].print();
            p[j].print();
            swap(p[j],p[i]);
            cout<<"\nAfter Swap:";
            p[i].print();
            p[j].print();
            }

        }

    }
}

void calc(process *P, int n)
{
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
        P[i].ct = P[i].bt + P[i].at;
        P[i].wt = 0;
        P[i].tat = P[i].ct - P[i].at;
        }
        else
        {
        P[i].ct = P[i-1].ct + P[i].bt;
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
    cout<<"\n\nUsing FCFS:\n";
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
    int n;
    cout<<"\nEnter the number of processes to be scheduled ";
    cin>>n;
    process P[n];
    for(int i=0; i<n; i++)
    {
        P[i].get();
    }
    print(P,n);
    fcfs(P,n);
    calc(P,n);

    print(P,n);


    return 0;
}
