#include<iostream>
using namespace std;
#define MAXSIZE 7
class QUEUE
{
	int queue[MAXSIZE];
	int front;
	int rear;
	public:
	QUEUE()
	{
		front=-1;
		rear=-1;
	}
	void enque(int);
	void deque();
	void display();
	int isEmpty();
	int isFull();

};
int QUEUE::isEmpty()
{
    if(front==-1 || front>rear)
        return(1);
    else
    return(0);
}
int QUEUE::isFull()
{
    if(rear>=MAXSIZE-1)
    {
        return (1);
    }
    else
    return(0);
}
void QUEUE::enque(int data)
{
	if(rear>=MAXSIZE-1)
		cout<<"Queue Overflow";
	else if(front==-1 && rear==-1)//if first data inserted in queue
	{
		front=front+1;
		rear=rear+1;
		queue[rear]=data;
	}
	else
	{
		rear=rear+1;
		queue[rear]=data;
	}
}
void  QUEUE::deque()
{
	if(front==-1)
		cout<<"\nQueue empty";
	else if(front<=rear)
	{
		//cout<<"\nDeleted data:"<<queue[front];
		front=front+1;
		display();
	}
	else
		return;
}
void QUEUE::display()
{
	if(front==-1 && rear==-1)
		cout<<"\nQueue empty";
    else if(front>rear)
        cout<<"\nQueue empty";
	else
	{
		int i;
        cout<<"\n";
		for(i=front;i<=rear;i++){
			cout<<queue[i]<<" ";
		}
		if(front ==0 && rear>=MAXSIZE-1)
        {
        cout<<"\nQueue full1";
        }
	}

}

int main()
{
	QUEUE q;
	int n,data;
	cin>>n;
	int check = q.isEmpty();
	if(check==1)
	{
	    cout<<"Queue empty";
	}
	while(!q.isFull())
	{
	 cin>>data;
	 q.enque(data);
	}
	q.display();

	while(q.isEmpty()!=1)
	{
	 q.deque();
	}
}
