#include <iostream>
#include<string>

using namespace std;

int mini(int d[], int sset[], int v)
{
    //cout<<"\nFunc mini called - ";
    int min = 9999, minindex = -1;
    for (int i=0; i<v; i++)
    {
        if(d[i] < min && sset[i] != 1)
        {
            min = d[i];
            minindex = i;
        }
    }
    //cout<<"returning "<<minindex<<endl;

    return(minindex);
}

int main()
{

    int v=5;
    int g[v][v] =  {{0, 0, 6, 3, 0},
                    {3, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0},
                    {0, 1, 1, 0, 0},
                    {0, 4, 0, 2, 0}};

    int s ;
    cout<<"Enter source\n";
    cin>>s;
    int dis[v]; //distance of vertex x from source
    int sset[v]; //if shortest distance from vertex to source is computed
    string par[v];  //to store shortest path from source

    dis[s] = 0;
    sset[s] = 1;
    par[s] = '\0';
    for(int i=0; i<v; i++)
    {
        if(i != s)
        {
            sset[i] = 0;
            if(g[s][i] != 0)
            {
                dis[i] = g[s][i];   //direct path
                par[i] = to_string(s);
            }
            else
            {
                dis[i] = 999;   //no direct path
            }
        }
    }


    for(int i=0; i<v; i++)
    {
        if(sset[i] != 1)
        {
            int act = mini(dis,sset,v);
            sset[act] = 1;
            for(int j=0; j<v; j++)
            {
                if(sset[j] != 1 && g[act][j] !=0 && dis[j] >= dis[act] + g[act][j]) {
                    dis[j] = dis[act] + g[act][j];
                    par[j] = par[act] + to_string(act);

                }
            }

        }

    }

    cout<<"\nThe shortest distances of vertices from source "<<s+1<<": \n";

    for (int i=0; i<v ; i++)
    {
        cout<<"\nShortest Distance of vertex "<<i+1<<" from source vertex "<<s+1<<":  "<<dis[i];
        //cout<<"  sset:"<<sset[i]
        cout<<"\t\tPath: ";
        for(int j=0; j< par[i].length(); j++)
        {
            cout<<par[i][j]<<"-";
        }
        cout<<endl;

    }
    return 0;
}
