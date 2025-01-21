#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char word[20]="donkey";
    char guessed[20];
    cout<<"\nEnter word\n";
    cin>>guessed;
    int flag=0;
    for(int i=0; i<strlen(guessed); i++ )
        {
            if(guessed[i]==word[i])
                flag=1;
            else
                flag=0;
        }
        if(flag==1)
        {
            cout<<"\nYou win :) The word is "<<word<<endl;
        }
        else
        {
            cout<<"\nYou lose :( ";
        }
    return 0;
}
