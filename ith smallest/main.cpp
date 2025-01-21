#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];
    // traversing the array to find
    // smallest element.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "smallest element is: " << smallest << endl;

    int second_smallest = a[0];

    // traversing the array to find second smallest element
    for(int j=1; j<n ; j++)
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < second_smallest && arr[i] > smallest)
        {
            second_smallest = arr[i];
        }
    }
    cout << "second smallest element is: " << second_smallest << endl;
    return 0;
}
