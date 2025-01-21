#include <iostream>
#include <string.h>
#include<string>
#include<stack>
using namespace std;

class CustomStack
{
    stack<char> s;
    stack<char> lastdel;
    stack<string> commands;

public:

    void delet(int val)
    {
        while(val >0)
        {
            lastdel.push(s.top());
            s.pop();
            val--;
        }
    }
    void get_char(int index)
    {
         stack<char> tempStack;
    // Pop the top index-1 elements and push them into the temporary stack
        int ind = s.size()-index;
        for (int i = 0; i <= ind; i++)
        {
            tempStack.push(s.top());
            s.pop();
        }
    // Get the element from the top of temp stack
        char Element = tempStack.top();
        while(!tempStack.empty())
        {
            s.push(tempStack.top());
            tempStack.pop();
        }
        cout<<Element<<endl;
    }
    void undo()
    {
        commands.pop();
        string lastcom = commands.top();
        cout<<"\nLast command: "<<lastcom<<endl;

        switch(lastcom[0])
            {
            case '1':
                {
                    cout<<"\nDeleting Inserted elemnets";
                    delet(lastcom.length()-2);
                    break;
                }
            case '2':
                {
                    cout<<"\nInserting deleted elements";
                    int t = lastcom[2]-'0';
                    while(t > 0)
                    {
                        s.push(lastdel.top());
                        lastdel.pop();
                        t--;
                    }
                    break;
                }
            default:
                break;
            }
    }

    void get_commands()
    {
        string in;
        cout<<"Enter Input seq of commands -- ";
        getline(cin,in);
        string temp;

        for(int i=0; i< in.length(); )
        {
            while(i< in.length() && in[i] != ',')
            {
                temp += in[i];
                i++;
            }
            cout<<"\nCommand = "<<temp;
            commands.push(temp);
            char com = temp[0];
            switch(com)
            {
            case '1':
                {
                    for(int i=2; i< temp.length(); i++)
                    {
                        s.push(temp[i]);
                    }
                    break;
                }
            case '2':
                {
                    delet(temp[2] - '0');
                    break;
                }
            case '3':
                {
                    get_char(temp[2] - '0');
                    break;
                }
            case '4':
                {
                    undo();
                    break;
                }
            default:
                cout<<"\nInput Error\n";
                break;
            }
            temp.erase();
            i++;
        }
        cout<<"\nNo of commands "<<commands.size();
    }

};

int main() {
    CustomStack C;
    C.get_commands();

    return 0;
}
