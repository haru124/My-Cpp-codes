#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "\nEnter 1 for coffee\n      2 for tea\n      3 for boost" << endl;
    cin>>x;
    switch(x)
    {
    case 1:
    {
        cout<<"\nEnjoy ur coffee!";
        break;
    }
    case 2:
        cout<<"\nEnjoy ur tea!";
        break;
    case 3:
        cout<<"\nEnjoy ur boost!";
        break;
    default:
        cout<<"\nSorry, we serve only coffee, tea and boost. We will try to add on more to the menu soon!";
        break;
    }

    return 0;
}
