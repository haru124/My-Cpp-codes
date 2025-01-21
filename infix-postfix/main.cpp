#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


class Stack
{
    public:
	char *stk;
	int maxsize;
	int top;
	Stack()
	{
	    maxsize=0;
		top=-1;
		stk = NULL;
	}
	Stack(int size)
	{
	    maxsize=size;
	    stk = new char[maxsize];
		top=-1;
	}
	~Stack()
	{
	    delete[] stk;
	}
	void push(char);
	char pop();
	char getTop();
	void display();
	bool isEmpty() {
        return(top == -1);
    }
    bool isFull() {
        return(top == maxsize - 1);
    }
};
char Stack::getTop()
{
    if(!isEmpty())
    {
        return(stk[top]);
    }
    else
        cout<<"\nStack empty";
}
void Stack::display()
{
    cout<<"\nStack: ";

    for(int i=0; i<=top; i++)
    {
        cout<<stk[i]<<" ";
    }
}
void Stack::push(char x)
{
    if(!isFull()){
	stk[++top]=x;
    }
    else
        cout<<"\nStack Full";

}
char Stack::pop()
{
    if(!isEmpty())
    {
	return(stk[top--]);
    }
    else
        cout<<"\nStack Empty";
}

bool isOperator(char c)
{
    return(c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}

bool isOperand(char ch)
{
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

//FUNCTION TO ASSIGN PRECEDENCE FOR OPERATORS
int precedence(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/'|| c == '%')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infixtoPostfix(string s)
{
    int len = s.length();
    string postfix;
    Stack op(len);   // p -postfix stack ; op - operator stack
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            cout<<"\n'(' encountered, pushing to stack";
            op.push(s[i]);
            op.display();
        }
        else if(isOperand(s[i]))
        {
            cout<<"\nOperand encountered, adding to postfix";
            postfix += s[i];
            cout<<"\nPostfix: "<<postfix;
        }
        else if (s[i] == ')')
        {
            cout<<"\n')' encountered, popping stack till '('";
            while (/*!op.isEmpty() && */op.getTop() != '('){
                postfix += op.pop();
                op.display();
                cout<<"\nAdding popped operators to postfix string";
                cout<<"\nPostfix: "<<postfix;
            }
            op.pop();
            op.display();
        }
        else if(isOperator(s[i]))
        {
            int flag =0;
            while(precedence(op.getTop()) >= precedence(s[i]))
            {
                flag = 1;
                cout<<"\nOperator with lower precedence encountered, popping high precedence operators from stack and adding them to postfix string";
                postfix += op.pop();
                op.display();

                cout<<"\nPostfix: "<<postfix;
            }
            if(flag==0)
            cout<<"\nOperator encountered, pushing to stack";
            else
                cout<<"\nOperator with lower precedence pushed to stack";
            op.push(s[i]);
            op.display();

        }
        else
        {
            cerr<<"\nInvalid character in Infix expression "<<s[i];
            exit(1);
        }
        i++;
    }

    while(!op.isEmpty() && op.getTop() != '(')  //to push the remaining operators from op to postfix stack
    {
        postfix += op.pop();
        cout<<"\nPostfix: "<<postfix;
    }
    while(!op.isEmpty()){
    op.pop();    // the last (
    op.display();
    }

    cout<<"\n\n\nPostfix Expression:  "<<postfix<<endl;

}

//Driver program to test above functions
int main()
{

    char infix[50];
	cout<<"\nEnter a infix expression: ";
    cin>>infix;
	infixtoPostfix(infix);
}
