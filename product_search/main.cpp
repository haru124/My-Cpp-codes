#include <iostream>
#include<string>

using namespace std;

int main()
{
    string products[8]={"shirt","pant","shoe","jeans","slipper","kurti","tshirt","dupatta"};
    cout<<"Enter product to be searched ";
    string x;
    cin>>x;
    int n=8,found=0,i;
    for (i=0; i<n; i++)
    {
        if(products[i]==x)
        {
            found=1;
            cout<<"\nWe have the product you are looking for, here are the links to buy "<<x<<endl;
            break;
        }

    }

    if (found==0)
    {
            cout<<"\nSorry we dont have what you are looking for, we will try to include "<<x<<" to our stocks soon\n";
    }

    return 0;
}
