#include <iostream>
#include <string.h>
using namespace std;

void numofdeletions(char s[])
{
    cout<<endl<<strlen(s)<<endl;
    int n=0, k=1;
    bool repeat;
    char distinct[100]="";
    distinct[0]=s[0];
    cout<<distinct;
    cout<<endl<<strlen(distinct);
    for (int i=1; i<strlen(s); i++)
    {

        for(int j=0; j<strlen(distinct); j++)
        {
             if(s[i]==distinct[j])
             {
                repeat=true;
             }
        }
        if (repeat!=true)
        {
            distinct[k]=s[i];
            k++;
            cout<<endl<<strlen(distinct);
        }
        repeat=false;

    }

    cout<<"\nString with distinct characters is "<<distinct<<endl;
    cout<<strlen(s);
    cout<<endl<<strlen(distinct);
    n= strlen(s)- strlen(distinct);
    cout<<"\nNo of deletions needed to make the characters in the string distinct = "<<n;
}

int main()
{
    char s[100];
    cout<<"\nEnter string\n";
    cin>>s;
    numofdeletions(s);
    return 0;
}
