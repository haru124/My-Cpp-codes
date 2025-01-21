#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int q[15];
    q[0] = 1;
    for(int i=1; i<15; i++)
    {
        q[i] = ((i+1)*q[i-1]) + q[i-1];
    }

    cout << "\nWeights: " << endl;
    char c='A';
    for(int i=0; i<15; i++)
    {
        cout<<c++<<" : "<<q[i]<<"\t";
        if (i!=0 && i%4==0)
            cout<<endl;
    }

    cout<<"\n\nEnter weight ";
    int w;
    cin>>w;
    c = 'A';

    cout<<char(c+5);

    string res="";
    //res+= 'a';
    //string res[10];
    int sum=0,wt = w;

    while(sum != wt)
    {
    for(int i= 10; i>=0; i--)
    {
        if(q[i]<=w)
        {
            res += char(c+i) ;
            sum+= q[i];
            w -= q[i];
        }
    }
    }
    sort(res.begin(), res.end());
    cout<<"\nResult : "<<res;

    return 0;
}
