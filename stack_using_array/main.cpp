#include<iostream>
using namespace std;
#define MAXSIZE 5
class STACK
{
	int stack[MAXSIZE];
	int top;
	public:
	STACK()
	{
		top=-1;
	}
	void push(int);
	void pop();
	void display();
	int getTop();
	int isEmpty();
	int isFull();
	int currSize();
};
/*void STACK::push(int data)
{
	if(top>=MAXSIZE-1)
		cout<<"\nStack full";
	else
	{
		top=top+1;
		stack[top]=data;
	}
}
void  STACK::pop()
{
	if(top<0)
		cout<<"\nStack empty";
	else
	{
		cout<<"\nDeleted Item:"<<stack[top];
		top=top-1;
	}
}*/
void STACK::display()
{
	if(top==-1)
		cout<<"\nStack empty";
	else
	{
		for(int i=0;i<top;i++)
		{
			cout<<stack[i]<<" ";
		}
                cout<<endl;
	}
}
int STACK::getTop()
{
	if(top<0)
		return(-1);
	else
		return(stack[top]);
}
int STACK::isEmpty()
{
	if(top<0)
		return(1);
	else
		return(0);
}
int STACK::isFull()
{
	if(top==MAXSIZE-1)
		return(1);
	else
		return(0);
}
int STACK::currSize()
{
	return(top+1);
}
void STACK::push(int data)
{
	if(!isFull())
	{
		top=top+1;
		stack[top]=data;
	}
	else
		cout<<"\nStack full";
}
void  STACK::pop()
{
	if(!isEmpty())
	{
		cout<<"\nDeleted Item:"<<stack[top];
		top=top-1;
	}
	else
		cout<<"\nStack empty";
}
int main()
{
	STACK s;
	char c;
	int x,check,csize;
	do
	{
		cout<<"\n1.PUSH";
		cout<<"\n2.POP";
		cout<<"\n3.Display";
		cout<<"\n4.getTop most element";
		cout<<"\n5.Is stack empty?";
		cout<<"\n6.Is stack Full";
		cout<<"\n7.Current size of stack";
		int ch;
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\nEnter the data to be inserted:";
				int data;
				cin>>data;
				s.push(data);
				break;
			case 2:s.pop();
				break;
			case 3:cout<<"\nStack elements are:\n";
				s.display();
				break;
			case 4:x=s.getTop();
				if(x<0)
					cout<<"\nList empty";
				else
					cout<<"\nTop most element is "<<x;
				break;
			case 5:check=s.isEmpty();
				if(check==1)
					cout<<"\nList Empty";
				else
					cout<<"\nNo list is not empty";
				break;
			case 6: check=s.isFull();
				if(check==1)
					cout<<"\nList Full";
				else
					cout<<"\nNo list is not Full";
				break;
			case 7:csize=s.currSize();
				cout<<"\nCurrent size="<<csize;
				break;
			default:cout<<"\nWrong choice";
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>c;
	}while(c=='y');
}

