#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin>>n;
    int a[n];
    cout<<"Enter the list with "<<n<<" numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cout<<"How many largest numbers do you need?"<<endl;
    cin>>m;
    int max[m];

    for(int i=0;i<m;i++)
    {
        max[i]=0;
    }
    cout<<"\nThe max array before processing is :\n";
    for(int i=0;i<m;i++)
    {
        cout<<max[i]<<"\t";
    }

    int count=0;

    for(int i=0;i<n;i++)
    {


        if(a[i]>=max[m-1])
        {
            for(int j=m-1;j>0;j--)
            {
                max[j]=max[j-1];
                count++;

            }
            max[0]=a[i];
        }
        count++;
    }

    cout<<"\nFirst "<<m<<" largest nos in the given list are :\n";
    for(int i=0;i<m;i++)
    {
        cout<<max[i]<<"\t";
    }
    cout<<"\nNo of Iterations : "<<count;
    return 0;
}
