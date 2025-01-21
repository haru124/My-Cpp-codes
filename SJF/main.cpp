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
    int s;     // to flag if a process is already scheduled
    process()
    {
        x = "\0";
        at = 0;
        bt = 0;
        pt = 0;
        tat = 0;
        wt = 0;
        ct = 0;
        s=0;
    }
    process(string p, int a, int b, int c, int q)
    {
        x = p;
        at = a;
        bt = b;
        pt = c;
        s = q;
    }
    process(process& k)
    {
        x = k.x;
        at = k.at;
        bt = k.bt;
        pt = k.pt;
        //ct = k.ct;
        //tat = k.tat;
        //wt = k.wt;
        s = k.s;
    }

    void print();
    void get();
    void swap(process, process);
};

void process:: print()
{
        cout<<"\n"<<x<<"\t\t"<<at<<"\t\t"<<bt<<"\t\t"<<pt<<"\t\t"<<ct<<"\t\t"<<tat<<"\t\t"<<wt;
}

void process::get()
{
    cout<<"\nEnter Process name, Arrival time, Burst time and Priority\n";
    cin>>x;
    cin>>at;
    cin>>bt;
    cin>>pt;
}

void process::swap(process a, process b)
{
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

int main()
{
    process P[20], S[20];
    int n,clk=0;
    cout<<"\nEnter the number of processes to be scheduled ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        P[i].get();
    }
    cout<<"\nProcess"<<"\t  ArrivalTime"<<"\t  BurstTime"<<"\t   Priority"<<"\tCompletionTime"<<"\t\tTAT"<<"\t\tWT\n";
    for(int i=0; i<n; i++)
    {
        P[i].print();
    }
    float avgtat;
    float avgwt;

    for(int i=0; i<n-1; i++)   // Sort the input process array in ascending order of burst time- short job first
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(P[j].bt < P[i].bt)
            {
                swap(P[j],P[i]);
            }
        }
    }

    for(int j=0; j<n; j++)    // for each process in P if it has not been scheduled yet and has arrived
    {
        for(int i=0; i<n; i++){
        if(P[i].s==0 && P[i].at<=clk)
        {
            P[i].s = 1;
            S[j] = P[i];        // copy constructor
            clk+=P[i].bt;
            break;
        }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
        S[i].ct = S[i].bt + S[i].at;
        S[i].wt = 0;
        S[i].tat = S[i].ct - S[i].at;
        }
        else
        {
        S[i].ct = S[i-1].ct + S[i].bt;
        S[i].tat = S[i].ct - S[i].at;
        S[i].wt = S[i].tat - S[i].bt;
        }
    }
    cout<<"\n\n\nSolution: SJF order(non preemptive)\n";
    cout<<"\nProcess"<<"\t  ArrivalTime"<<"\t  BurstTime"<<"\t   Priority"<<"\tCompletionTime"<<"\t\tTAT"<<"\t\tWT\n";
    for(int i=0; i<n; i++)
    {
        S[i].print();
    }
    cout<<endl;
    int sumtat=0,sumwt=0;
    for(int i=0; i<=n; i++)
    {
        sumtat+=S[i].tat;
        sumwt+=S[i].wt;
    }
    avgtat = sumtat/n;
    avgwt = sumwt/n;

    cout<<"\nAverage TAT : "<<avgtat;
    cout<<"\nAverage WT : "<<avgwt;

    return 0;
}
