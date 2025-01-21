#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int tries = 10;
    srand(time(0));
    string wordlist[20]={"coal","soap","easy","dumb","play","yolk","ring","rose","gaze","born","nest","arch","clap","turn","poem","song","bird","lion","king","trap"};
    string word=wordlist[rand()%20];
    string guess;
    cout << "Hello player! Let's play a game of tom and jerry\nHow to play?\n";
    cout<<"1. This is a four letter word game where no repetition of letters is allowed"<< endl;
    cout<<"2. You have to guess the four letter word thought by the computer"<< endl;
    cout<<"3. Tom means the letter in the word you guessed matches to that in computer word and it is in the same position as that in the computer word"<< endl;
    cout<<"4. Jerry means the letter in the word you guessed matches to that in computer word but it is in a different position to that in the computer word"<< endl;
    cout<<"5. You have 10 chances to guess the computer word\nLet's Start! ;)\n";
    while(tries!=0)
    {
        int tom=0,jerry=0;
        cout<<"\nEnter your guess ";
        cin>>guess;
        if(word.compare(guess)==0)
        {
            system("Color F2");
            cout<<"\nYOU WIN :)\nThe word is "<<word<<endl;

            break;
        }
        else
        {
            for(int i=0; i<4; i++)
            {
                if(guess[i]==word[i])
                    tom++;
                else
                {
                    for(int j=0; j<4; j++)
                    {
                        if(guess[i]==word[j])
                            jerry++;
                    }
                }
            }

            cout<<tom<<" tom\n"<<jerry<<" jerry"<<endl;
            tries-=1;
            cout<<"\nYou have "<<tries<<" tries left\n";
        }
    }


    if(tries==0)
    {
        system("Color F4");
        cout<<"\nGame over :( \nBetter luck next time\nThe word is "<<word<<endl;
    }

    return 0;
}
