#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

class list
{
    node *head;
    public:
        list();
        void createlist();
        void displaylist();
        void insertfront();
        void insertback();
        void insertafter();
        void deletefront();
        void deleteback();
        void deletenode();
        void search();
        void update();
        ~list();
};
list::list()
{
    cout<<"\nconstructor\n";
    head=NULL;
}

void list::createlist()
{
  char choice;
  node *newnode,*nn;
  newnode=new node;
  cout<<"\n Enter data";
  cin>>newnode->data;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  while(1)
  {
      cout<<"Do u want to add more nodes? y/n ?";
      cin>>choice;
      if(choice=='n')
        break;
      else
      {
          nn=new node;
          cout<<"\n Enter data";
          cin>>nn->data;
          nn->next=NULL;
          newnode->next=nn;
          newnode=nn;
      }
  }
  displaylist();
}

void list::displaylist()
{
    node *t;
    t=head;
    cout<<"\n LIST is\n";
    while(t!=NULL)
    {

        cout<<t->data<<endl;
        t=t->next;
    }
}

void list::insertfront()
{
    node *nn=new node;
    cout<<"\n Enter data of node to be inserted at front";
    cin>>nn->data;
    if(head==NULL)
    {
        head=nn;
        nn->next=NULL;
    }
    else
    {
        nn->next=head;
        head=nn;
    }
    cout<<"\nAfter insertion";
    displaylist();
}

void list::insertback()
{
    node *nn=new node;
    cout<<"\n Enter data of node to be inserted at back";
    cin>>nn->data;
    if(head==NULL)
    {
        head=nn;
        nn->next=NULL;
    }
    node *t;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=nn;
    nn->next=NULL;
    cout<<"\nAfter insertion";
    displaylist();
}

void list::insertafter()
{
    int n,i;
    cout<<"\n Enter position after which u want to insert a node";
    cin>>n;
    node *nn=new node;
    cout<<"\nEnter data";
    cin>>nn->data;
    node *t;
    t=head;
    for(i=1;i<n;i++)
    {
        t=t->next;
    }
    nn->next=t->next;
    t->next=nn;
    cout<<"\nAfter insertion";
    displaylist();
}

void list::deletefront()
{
    node *t;
    if(head!=NULL)
    {
        t=head;
        head=head->next;
        delete t;
    }
    cout<<"\nAfter deletion";
    displaylist();
}

void list::deleteback()
{
    node *t1,*t2;
    if(head!=NULL)
    {
        t1=head;
        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        t2->next=NULL;
        delete t1;
    }
    cout<<"\nAfter deletion";
    displaylist();
}

void list::deletenode()
{
    int n,i;
    cout<<"\nEnter node number which u want to delete";
    cin>>n;
    node *t1,*t2;
    t1=head;
    if(t1==NULL)
        cout<<"\nList Empty";
    else if(n==1)
    {
        head=head->next;
        delete t1;
    }
    else
    {
        for(i=1;i<n;i++)
        {
            t2=t1;
            t1=t1->next;
        }
        t2->next=t1->next;
        delete t1;
    }
    cout<<"\nAfter deletion";
     displaylist();
}

void list::search()
{
    int d,pos,flag=0;
    cout<<"\nEnter element to be searched";
    cin>>d;
    node *t;
    t=head;
    pos=1;
    if(t==NULL)
    {
        cout<<"\nList Empty";
    }
    while(t!=NULL)
    {
        if(t->data==d)
        {
            flag=1;
            break;
        }
        else
            pos+=1;
         t=t->next;
    }
    if(flag==1)
    {
        cout<<"\nElement found in position "<<pos<<endl;
    }
    else
    {
        cout<<"\nElement not found";
    }
    displaylist();
}

void list::update()
{
    int n,d;
    cout<<"\nEnter node number whose data u want to update";
    cin>>n;
    cout<<"\nEnter new data";
    cin>>d;
    node *t;
    t=head;
    int i,flag;
    i=1;
    while(t!=NULL)
        {
            if(i==n)
            {
                t->data=d;
                cout<<"\nData Updated Successfully at position "<<n;
                flag=1;
                break;
            }
            i+=1;
            t=t->next;
        }
if(flag!=1)
{
    cout<<"U have entered a no greater than no. of nodes present";
}
 displaylist();
}


list::~list()
{
    node *t;

    while(head!=NULL)
    {
        t=head;
        head=head->next;
        delete t;
    }
    cout<<"\n List destructed\n";
}
int main()
{
    cout << "Hello user!" << endl;
    list L;
    L.createlist();
    char c;
    do
    {
    cout<<"\nAvailable operations:";
    cout<<"\n1.Insert in front"<<"\n2.Insert in back"<<"\n3.Insert After"
           <<"\n4.Delete front"<<"\n5.Delete back"<<"\n6.Delete Node"
           <<"\n7.Search the list"<<"\n8.Update node\n";
    int ch;
    cout<<"\nEnter ur choice of operation";
    cin>>ch;
    switch(ch)
    {
    case 1:
        L.insertfront();
        break;
    case 2:
        L.insertback();
        break;
    case 3:
        L.insertafter();
        break;
    case 4:
        L.deletefront();
        break;
    case 5:
        L.deleteback();
        break;
    case 6:
        L.deletenode();
        break;
    case 7:
        L.search();
        break;
    case 8:
        L.update();
        break;
    default:
        cout<<"\nPlease select a valid operation";
        break;
    }
    cout<<"Do you want to do more operations? y/n?";
    cin>>c;
    }
    while(c=='y');
    return 0;
}
