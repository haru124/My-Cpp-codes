#include<iostream>
using namespace std;

struct heap
{
    int *e;
    int c;
    int sz;
};

struct heap *h;
void inserthp(int in)
{
    if(in ==0)
        return;
    int par = (in-1)/2;
    if(h->e[par] < h->e[in])
    {
        int tmp = h->e[in];
        h->e[in] = h->e[par];
        h->e[par] = tmp;
        inserthp(par);
    }
}

void insert(int d)
{
    if (h->sz < h->c)
    {
        h->e[h->sz] = d;
        inserthp(h->sz);
        h->sz++;
    }
}
void printhp()
{
    for (int i = 0; i < h->sz; i++)
    {
        cout << h->e[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int n, cap, d;
    cin >> n;

    h = new heap;
    h->e = new int[n];

    h->c = n;
    h ->sz = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        //h->sz = i+1;
        insert(d);
    }
    printhp();
    return 0;
}
