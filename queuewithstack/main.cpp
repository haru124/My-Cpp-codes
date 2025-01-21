#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Queue
{
    stack<int> eq;
    stack<int> dq;
public:
    void enque(int x)
    {
        eq.push(x);
    }
    void deque()
    {
        if(eq.empty())
        {
            cout<<"\nQueue Empty! cant be dequeued\n";
            return;
        }
        else
        {
            dq.push(eq.top());
            eq.pop();
        }
    }
    void print()
    {
        int frnt = eq.top();
        cout<<endl<<frnt<<endl;
    }
};


int main()
{
    Queue Q;
    string s;
    //cin>>s;
    getline(cin,s);
    int l = s.length();
    cout<<s<<endl;
    cout<<l<<endl;

    for(int i=0; i<l; )
    {
        if(s[i] == '1')
        {
            int en=0;
            i+=2;
            while (s[i] != ',')
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    en = (en*10) + (s[i] - '0');
                }
                i++;
            }
            cout<<"\nen = "<<en<<endl;
            Q.enque(en);
            i+=1;
        }
        else if(s[i] == '2')
        {
            Q.deque();
            i+=2;
        }
        else if(s[i] == '3')
        {
            Q.print();
            i+=2;
        }
        else
        {
            cerr<<"\nInvalid input code "<<s[i]<<"  Index: "<<i<<endl;
            exit(1);
        }
    }

    return 0;
}
