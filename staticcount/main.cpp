#include <iostream>
using namespace std;

class students
{
    int rno;
    string n;
    static int ct;
public:
    void get();
    void show();
    static void showcount();

};

int students::ct;

void students::get()
{
    cout<<"\n Enter name and roll no of student\n";
    cin>>n>>rno;

}

void students::show()
{
    ct++;
    cout<<"\n Student "<<ct<<":";
    cout<<"\n Name : "<<n;
    cout<<"\n Roll no : "<<rno;
}
 void students::showcount()
{
    cout<<"\n Count of students is "<<ct;

}


int main()
{
    cout << "Hello world!" << endl;
    students s1,s2,s3,s4,s5;
    s1.get();
    s2.get();
    s3.get();
    s1.show();
    s2.show();
    s3.show();
    students::showcount();
    return 0;
}
