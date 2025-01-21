#include <iostream>

using namespace std;

class college
{
protected:
    string cname;
    string cadd;
public:
    college();
    college(string,string);
   void showcdetails();

};

college::college()
{
    cname="ABC college";
    cadd="XXX";
}

college::college(string a,string b)
{
    cname=a;
    cadd=b;
}

void college::showcdetails()
{
    cout<<"\nCollege name\t"<<cname<<"\nAddress\t"<<cadd<<endl<<endl;
}

class department:public college
{
protected:

    string deptname,hodname;
public:
    department();
    department(string,string,string,string);
    void showdeptdetails();
};

department::department():college()
{
    deptname="XYZ";
    hodname="Mr.K";
}

department::department(string c,string d,string e,string f):college(c,d)
{
    deptname=e;
    hodname=f;
}

void department::showdeptdetails()
{
    cout<<"\nDepartment name\t"<<deptname<<"\nHOD name\t"<<hodname;
    showcdetails();
}

class facultymem:public department
{
    string fname,fqual;
    int n;
public:
    facultymem();
    facultymem(string,string,string,string,string,string,int);
    void showfacdetails();

};

facultymem::facultymem():department()
{
    fname="KK";
    fqual="B.ed";
    n=0;
}

facultymem::facultymem(string u,string v,string w,string x,string y,string z,int no):department(u,v,w,x)
{
    fname=y;
    fqual=z;
    n=no;
}

void facultymem::showfacdetails()
{
    cout<<"\nFaculty name\t"<<fname<<"\nFaculty Qualification\t"<<fqual;
    cout<<"\nNo. of years of experience\t"<<n;
    showdeptdetails();
}


int main()
{
    cout << "Hello world!" << endl;
    facultymem F1,F2("MIT","Chennai","ECE","Mr.W","Ms.S","M.E. B.ed",3);
    F1.showfacdetails();
    F2.showfacdetails();
    return 0;
}
