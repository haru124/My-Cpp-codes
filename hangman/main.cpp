#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int tries = 7;
    char word[]="strawberry";
    char guessedletters[26];
    /*cout << "Hello player1 ! Enter the word to be guessed" << endl;
    cin>>word;
    */
    cout<<"Hey player! It's your turn to guess. You have 7 tries";
    char guess;
    char guessed[20];
    for(int i=0;i<strlen(word);i++)
    guessed[i] = '_';
    guessed[strlen(word)]='\0';
    cout<<"\nWord to be guessed is ";
    for(int i=0; i<strlen(guessed); i++)
        cout<<guessed[i]<<" ";
    int n=0;


    while(tries!=0)
    {
        int flag=1;
        for(int i=0; i<strlen(guessed); i++ )
            {
                if(guessed[i]!=word[i])
                    flag=0;
            }
        if(flag==1)
            {
                cout<<"\nYOU WIN :)\nThe word is "<<word<<endl;
                break;
            }
        int count=0;

        cout<<"\nEnter your guess ";
        cin>>guess;
        for(int i=0; i<strlen(guessedletters); i++)
        {
           if(guessedletters[i]==guess)
           {
               count++;
           }
        }
        if(count!=0)
           {
            cout<<"You already guessed that letter! You have "<<tries<<" tries left. Try a different letter\n";
           }
        else
        {

                guessedletters[n]=guess;
                n++;
                int ct=0;
                for(int i=0; i<strlen(word); i++)
                {
                    if(word[i]==guess)
                    {
                        guessed[i]=guess;
                        ct++;
                    }
                }
                if(ct==0)
                {
                    tries-=1;
                    cout<<"Wrong Guess :( You have "<<tries<<" tries left\n";
                }
                else
                {
                    cout<<"Right guess! You have "<<tries<<" tries left\n";
                    cout<<"Guessed word is ";
                    for(int i=0; i<strlen(guessed); i++)
                       cout<<guessed[i]<<" ";
                    cout<<"\n\n";
                }

        }


    }

    if(tries==0)
    {
        cout<<"\nGame over :( \nBetter luck next time\nThe word is "<<word<<endl;
    }
    return 0;
}
