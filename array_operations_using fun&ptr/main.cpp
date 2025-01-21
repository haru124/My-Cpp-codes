#include <iostream>

using namespace std;


void print(int *p, int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void insert(int *p, int& n, int ele, int pos)
{
    for(int i=n;i>=pos;i--)

    {
        p[i]=p[i-1];
    }
    p[pos-1]=ele;
    n+=1;
}
void del(int *p,int &n,int ele)
{
int flag =0;
for(int pos=0;pos<n;pos++)
{
    if(p[pos]==ele)
    {
        for(int i=pos;i<n;i++)
        {
            p[i]=p[i+1];
        }
        p[n-1]='\0';
        flag =1;
        n-=1;
        break;
    }
}
if(flag==0)
{
    cout<<"Element to be deleted " <<ele<<" not found"<<endl;
}
}

void search(int* p, int n, int ele)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]==ele)
        {
            cout<<"\nElement "<<ele<<" found at position "<<i+1<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"\nElement "<<ele<<" not found in array "<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the array elements ";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int len = sizeof(a) / sizeof(int);
    cout<<"Length of array:"<<len<<endl;
    print(a,len);
    insert(a,len,10,3);
    cout<<"Length of array:"<<len<<endl;
    print(a,len);
    del(a,len,3);
    cout<<"Length of array:"<<len<<endl;
    print(a,len);
    search(a,len,10);
    return 0;
}
