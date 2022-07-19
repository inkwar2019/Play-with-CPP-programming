#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<thread>
using namespace std;

int score=0,type=0,timed=0,flage=0;

void timer()
{
    for(;;){
    Sleep(1000);
    //system("cls");
    //cout<<timed<<endl;
    timed++;

    if(timed==10)
    {
        flage==12;
        break;
    }
    }
}

void controler()
{
    char ch[10],ck,ph[10];
    int i,j,total;
    for(;;)
    {

        total=0;

        i=1+rand()%9;
        for(j=0;j<i;j++)
        {
            ch[j]=97+rand()%26;
        }
        ch[j]='\0';
        for(;;)
        {
            system("cls");
            cout<<score<<endl;
            cout<<timed<<endl;
            cout<<"                      "<<ch<<endl;
            cout<<"\n\n\n\n\n\n\n"<<ph<<endl<<"--------------------|             |------------------------\n";
            cout<<"                     ";
            ck=getch();

            if(ck==ch[total])
            {
                ph[total]=ck;
                ph[total+1]='\0';
                total++;
            }
            else{
                score--;
                if(score<0){
                    flage=12;
                    break;
                }
            }
            if(total==strlen(ch))
                break;

        }
        ph[0]='\0';
        timed=0;
        if(flage==0)
           score++;
        else
        {
            break;
        }
    }
}

int main()
{
    srand(time(0));
    thread t(controler);
    thread p(timer);
    //t.join();
    p.join();



    return 0;
}
