#include <iostream>

using namespace std;

class publication
{
    protected:
    string title;
    float price;
    public:
    void take();
};

class book:public publication
{
    int pagect;
public:
    void get();
    void display();

};

class tape:public publication
{
    int ptime;
public:
    void get();
    void display();
};

void publication::take()
{
    cout<<"\n Enter title and price\n ";
    cin>>title>>price;
}

void book::get()
{
    cout<<"\n Book \n";
    take();
    cout<<"\n Enter page count\n";
    cin>>pagect;
}

void tape::get()
{
     cout<<"\n Tape \n ";
     take();
    cout<<"\n Enter playing time in minutes\n";
    cin>>ptime;
}

void book::display()
{
    cout<<"\n\n Book Title : "<<title<<"\n Price : "<<price
    <<"\n No of pages : "<<pagect<<" pages\n\n";
}

void tape::display()
{
    cout<<"\n\n Tape Title : "<<title<<"\n Price : "<<price
    <<"\n Playing time in minutes : "<<ptime<<" minutes \n\n";
}

int main()
{
    cout << "Hello!" << endl;
    book b;
    b.get();
    b.display();
    tape t;
    t.get();
    t.display();
    return 0;
}
