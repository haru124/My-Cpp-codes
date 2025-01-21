#include <iostream>
#include<string.h>

using namespace std;

class clothes{
char gender;
void showSelectedGender(){
cout<<"Selected gender is "<<gender<<endl;
}

protected:
    string material;
    void showSelectedMaterial(){
    cout<<"Selected material is "<<material<<endl;
    }


public:
    void getMaterial(){
    cout<<"Enter material of cloth"<<endl;
    cin>>material;
    showSelectedMaterial();
    }
    void getGender(){
    cout<<"Select gender : F/M"<< endl;
    cin>>gender;
    showSelectedGender();
    }

};

class womenApparel: public clothes{
string category;
public:
    void getCategory(){
    cout<<"Enter category of women's apparel"<<endl;
    cin>>category;
    }
};

class childrenApparel: private clothes{
string category;
public:
    void getCategory(){
    cout<<"Enter category of children's apparel"<<endl;
    cin>>category;
    }
};

class menApparel: protected clothes{
string category;
public:
    void getCategory(){
    cout<<"Enter category of men's apparel"<<endl;
    cin>>category;
    getMaterial();
    }

};


int main()
{
    clothes C;
    C.getGender();
    C.getMaterial();
    //C.showSelectedGender();  //error: 'void clothes::showSelectedGender()' is private
    //C.showSelectedMaterial();  // error: 'void clothes::showSelectedMaterial()' is protected
    womenApparel W;
    W.getMaterial();
    W.getCategory();
    menApparel M;
    //M.getMaterial(); //error: 'clothes' is not an accessible base of 'menApparel'|
    M.getCategory();

    return 0;
}
