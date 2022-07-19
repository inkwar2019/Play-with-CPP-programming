#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>


using namespace std;

void game();
void help();
int main()
{
    int c;
    srand(time(0));
    for(;;){
        cout<<"1.Play Game\n2.Help\n3.Exit\nEnter your opinion :";
        cin>>c;
        system("cls");
        switch(c)
        {
            case 1:game();break;
            case 2:help();break;
            case 3:break;
            default:continue;
        }
    }
    return 0;
}

void game()
{
    int x,n,a=1,b=100,i,exit,m,p,counter;
    char ch;
    for(i=10;;i+=5){
        n=1+rand()%b;
        exit=0;
        counter=0;
        cout<<"\n";
        for(;;){
            cout<<"Interval "<<a<<" to "<<b<<endl<<"You have find within "<<i<<" search\n";
            cout<<"You searched :"<<counter<<endl;
            cout<<"Enter choice :";
            cin>>x;
            counter++;
            if(x==n){
                system("cls");
                cout<<"You Win......................\n";
                cout<<"your number is matched.\n";
                cout<<"\n\n\n\npress Enter for Next game......\nPress space for Menu.\n";
                ch= getch();
                if(ch==13){
                    system("cls");
                    exit=0;
                    break;
                }
                else if(ch==32){
                    system("cls");
                    exit=1;
                    break;
                }
            }
            if(x<n){
                system("cls");
                cout<<"Your number is less.\n";
            }
            else if(x>n){
                system("cls");
                cout<<"Your number is more.\n";
            }

            if(counter>i-1){
                system("cls");
                cout<<"You loss......................\n";
                cout<<"\v\v\vpress Enter for try......\nPress space for Menu.\n";
                ch= getch();
                if(ch==13){
                    system("cls");
                    exit=0;
                    n=1+rand()%b;
                    counter=0;
                }
                else if(ch==32){
                    system("cls");
                    exit=1;
                    break;
                }
                system("cls");
            }
        }
        if(exit==1)
            break;
    b+=100;
    }
}

void help()
{
    cout<<"Computer take automatically a number\nyou have to find it by binary scharch\n";
    getch();
}

