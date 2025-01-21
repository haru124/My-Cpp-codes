#include <iostream>
#include <cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int kthsmallest(int arr[], int k) {
    int min=999, pos = -1, prevmin=0;
    //cout<<"\nK = "<<k;
    for (int i=0; i<k; i++)
    {
        min =999;
        for(int j=0; j<4 ; j++)
        {
            if(arr[j] < min && arr[j] > prevmin)
            {
                min = arr[j];
                pos = j;
            }
        }
        prevmin = min;
    }

    return pos;
}
int main() {
    string nums[4];
    for(int i=0; i<4; i++)
    {
        cin>>nums[i];
    }
    /*for(int i=0; i<4; i++)
    {
        cout<<nums[i]<<"   ";
    }*/
    int n;
    cin>>n;
    int q[n][2];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++){
        cin>>q[i][j];
        }
    }

    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++){
        cout<<q[i][j]<<"   ";
        }
        cout<<endl;
    }*/

    for(int k=0; k<n; k++)
    {
        int temp[4];
        for(int i=0; i<4; i++)
        {
            int e = pow(10,q[k][1]);
            temp[i] = stoi(nums[i]) % e;
        }
        /*for(int i=0; i<4; i++)
        {
            cout<<temp[i]<<"  ";
        }
        cout<<endl;*/
        int res = kthsmallest(temp, q[k][0]);

        cout<<res<<" ";
    }

    return 0;
}
