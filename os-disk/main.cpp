#include<iostream>
using namespace std;

struct heap
{
    int *e;
    int c;
    int sz;
};

struct heap *h;

void heapify(int in)
{
    int max;
    int left = (2*in) +1;
    int right = (2*in) +2;
    max = in;
    if(left >= h->sz || left<0)
    {
        left = -1;
    }
    if(right >= h->sz || right<0)
    {
        right = -1;
    }
    if(left != -1 && left > h->e[in])
    {
        max = left;
    }
    if(right != -1 && right > h->e[in])
    {
        max = right;
    }

    if(max != in)
    {
        int tmp = h->e[max];
        h->e[max] = h->e[in];
        h->e[in] = tmp;
        heapify(max);
    }

}

void printhp()
{
    for(int i=0; i < h->sz; i++)
    {
        cout<<h->e[i]<<"  ";
    }
    cout<<endl;
}

void deletemax()
{
    int d = h->e[0];
    cout<<"\nDeleted Ele = "<<d;
    if(h->sz > 0)
    {
        h->e[0] = h->e[h->sz - 1];
        h->sz --;
        heapify(0);
    }
    else
        cout<<"\nHeap empty";
}

int main()
{
    int n,cap,d;
    cin>>n;

    h = new heap;
    h->e = new int[n];
    cin>>cap;
    h->c = cap;
    int i;
    for(i=0; i < n; i++)
    {
        cin>>d;
        h->e[i] = d;
    }
    h->sz = i;
    int ind = (i -2)/2;
    while(ind >=0)
    {
        heapify(ind);
        ind--;
    }
    printhp();
    return 0;
}
