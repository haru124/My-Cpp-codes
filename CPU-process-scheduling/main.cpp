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
    int rt;   //remaining time used for SRTF and Round Robin

    process()
    {
        x = "\0";
        at = 0;
        bt = 0;
        pt = 0;
        tat = 0;
        wt = 0;
        ct = 0;
        rt = 0;
    }
    process(string s, int a, int b, int c)
    {
        x = s;
        at = a;
        bt = b;
        pt = c;
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

class pc        //Gantt chart
{
    process P[25];
    int n;
    float avgtat;
    float avgwt;
    public:
    void get();
    void print();
    void fcfs();
    void sjf();
    void priority();
    void srtf();
    pc()
    {
        n=0;
        avgtat = 0;
        avgwt = 0;
        for(int i=0; i<n; i++)
        {
            P[i]=process("\0",0,0,0);
        }
    }

};



void pc:: get()
{
    cout<<"\nEnter the number of processes to be scheduled ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        P[i].get();
    }
}

void pc:: print()
{
    cout<<"\nProcess"<<"\t  ArrivalTime"<<"\t  BurstTime"<<"\t   Priority"<<"\tCompletionTime"<<"\t\tTAT"<<"\t\tWT\n";
    for(int i=0; i<n; i++)
    {
        P[i].print();
    }
}

void pc:: fcfs()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(P[j].at < P[i].at)
            {
                swap(P[j],P[i]);
            }
        }
    }

    for(int i=0; i<=n; i++)
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
    cout<<"\n\n\nSolution: FCFS order(non preemptive)\n";
    print();
    cout<<endl;
    int sumtat=0,sumwt=0;
    for(int i=0; i<=n; i++)
    {
        sumtat+=P[i].tat;
        sumwt+=P[i].wt;
    }
    avgtat = sumtat/n;
    avgwt = sumwt/n;

    cout<<"\nAverage TAT : "<<avgtat;
    cout<<"\nAverage WT : "<<avgwt;

}

void pc:: sjf()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(P[j].bt < P[i].bt)
            {
                swap(P[j],P[i]);
            }
        }
    }

    for(int i=0; i<=n; i++)
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
    cout<<"\n\n\nSolution: SJF order(non preemptive)\n";
    print();
    cout<<endl;
    int sumtat=0,sumwt=0;
    for(int i=0; i<=n; i++)
    {
        sumtat+=P[i].tat;
        sumwt+=P[i].wt;
    }
    avgtat = sumtat/n;
    avgwt = sumwt/n;

    cout<<"\nAverage TAT : "<<avgtat;
    cout<<"\nAverage WT : "<<avgwt;

}

void pc:: priority()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(P[j].pt < P[i].pt)
            {
                swap(P[j],P[i]);
            }
        }
    }

    for(int i=0; i<=n; i++)
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
    cout<<"\n\n\nSolution: Priority order(non preemptive)\n";
    print();
    cout<<endl;
    int sumtat=0,sumwt=0;
    for(int i=0; i<=n; i++)
    {
        sumtat+=P[i].tat;
        sumwt+=P[i].wt;
    }
    avgtat = sumtat/n;
    avgwt = sumwt/n;

    cout<<"\nAverage TAT : "<<avgtat;
    cout<<"\nAverage WT : "<<avgwt;

}


int main()
{
    pc X;
    X.get();
    X.print();
    X.fcfs();
    X.sjf();
    X.priority();

    return 0;
}
