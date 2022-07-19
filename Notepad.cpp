#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;


int main()
{
    ifstream file_in;
    ofstream name_file_open,number_file_open;
    char name[12];
    char ch;
    string comment;
    int n=0;
    for(int i=0;i<1;i++){
          cout<<"Enter file name :";
          cin>>name;
          strcat(name,".txt");

          name_file_open.open(name);

          for(;;)
          {
              if(n==2)
                break;
               ch=getch();
               if(ch==8){
                cout<<"\b";
               }
               if(ch==13){
                   n++;
                   cout<<"\n";
                   continue;
               }
               cout<<ch;
              n=0;
            name_file_open<<ch;
          }
     name_file_open.close();
    }



    return 0;
}
