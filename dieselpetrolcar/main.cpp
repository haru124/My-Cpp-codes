#include <iostream>

using namespace std;

int main()
{
    int i,j;
    int N;
    cout<<"Enter no of canvas (columns) ";
    cin>>N;
    char c[3][N];
    cout<<"\nEnter the characters pixel art\nOnly '#','*','.' allowed"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<N;j++)
        {
        cin>>c[i][j];
        }
        cout<<endl;
    }
  cout<<"/nPixel Art"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<N;j++)
        {
        cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

 int o=(N+1)/4;
 cout<<o<<" Characters are depicted by ur pixel art"<<endl;
 char t[o];
 int x=0;
 for(i=0;i<o;i++)
 {
 if(c[0][x]=='.')
    t[i]='A';

 else if(c[1][x]=='.' && c[1][x+2]=='.')
    t[i]='I';

 else if(c[0][x+1]=='.' && c[1][x+1]=='.')
    t[i]='U';

 else if(c[1][x+1]=='.')
    t[i]='O';

 else if(c[1][x+2]=='.')
    t[i]='E';

 else
    cout<<"\nChar is not defined";

x=x+4;
 }


cout<<"\nCharacters in Pixel Art are ";
for(i=0;i<o;i++)
 {
     cout<<t[i]<<" | ";
 }



    return 0;
}
