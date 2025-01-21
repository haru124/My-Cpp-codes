#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    string words[5]={"hello","idiot","beauty","ooty","apple"};
    string s;
    cout<<"\nEnter a string ";
    cin>>s;
    int flag=0,position;
    for(int i=0; i<5; i++)
    {
        if(words[i].compare(s)==0)
        {
            flag=1;
            position=i;
        }
    }
    if(flag==1)
    {
        cout<<"\nEntered string "<<s<<" is present in list at the position "<<position+1<<endl;
        int tom=0, jerry=0;
        string test=words[position];
        for(int i=0;i<s.length(); i++)
                {
                       if(s[i]==test[i])
                            tom++;
                       else
                       {
                           for(int j=0; j<test.length(); j++)
                           {
                               if(s[i]==test[j])
                                   jerry++;
                           }
                       }
                }

                cout<<tom<<" tom\n"<<jerry<<" jerry"<<endl;
    }
    else
        cout<<"\nString not present in the list";

    return 0;
}
