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
    int rt;
    //bool s;


    process()
    {
        x = "\0";
        at = 0;
        bt = 0;
        pt = 0;
        tat = 0;
        wt = 0;
        ct = 0;
        rt = bt;
        //s= false;
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
        //s= false;
        rt = bt;
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

  t2 = a.rt;
  a.rt = b.rt;
  b.rt = t2;

  t2 = a.ct;
  a.ct = b.ct;
  b.ct = t2;
}
int sortsrt(process *p, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n ;j++ )
        {
            if(p[j].rt < p[i].rt)
            {
            swap(p[j],p[i]);
            }
        }
    }
    int index;
    for(int i=0; i<n; i++)
    {
        if(p[i].rt!=0)
        {
            index = i;
            break;
        }
    }
    return(index);
}

bool issrt(process *p, int n, int index, int clock)
{
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(p[i].rt < p[index].rt && p[i].rt!=0 || p[index].rt==0)
            flag =1;
    }
    cout<<"\nIssrt :"<<flag<<", if Issrt = 1 then it is not srt\n";
    if (flag == 0 && p[index].at <= clock)
        return true;
    else
        return false;
}


void calc(process *P, int n)
{
    for(int i=0; i<n; i++)
    {
          P[i].tat = P[i].ct - P[i].at;
          P[i].wt = P[i].tat - P[i].bt;
    }

    float sTAT=0, sWT=0;
    for(int i=0; i<n; i++)

    {
        sTAT += P[i].tat;
        sWT+= P[i].wt;
    }
    cout<<"\n\nUsing SRTF:\n";
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
    process P[4]={process("p1",2,2,0),process("p2",1,1,0),process("p3",0,5,0),process("p4",3,3,0)};
    /*for(i=0; i<n; i++)
    {
        P[i].get();
    }
    */
    int n=sizeof(P)/sizeof(P[0]);
    print(P,n);
    int clk =0;
    sortsrt(P,n);
    cout<<"\nAfter sorting the processes in ascending order of their burst time:\n";
    print(P,n);
    int TBT=0;
    for(int j =0; j<n; j++)
    {
        TBT += P[j].bt;
    }
    cout<<"\nTotal burst time :"<<TBT<<"\n";
    int i=0; //index=0; //prev_clk=0;
    while(TBT != 0)
    {
        i = sortsrt(P,n);
        //clk =0;
        cout<<"\nindex with low remaining time:"<<i<<endl;
        while(!issrt(P,n,i,clk)){
            i++;
        }
        while(issrt(P,n,i,clk))
        {
            if(P[i].rt==0)
                break;
            else{
            clk++;
            //P[i].ct = prev_clk;
            P[i].ct += clk;
            P[i].rt -= 1;

            TBT--;
            cout<<"\nP[i] :"<<P[i].x<<"  rt :"<<P[i].rt<<endl;
            }

        }




        //prev_clk = clk;
    }


    calc(P,n);

    print(P,n);


    return 0;
}
