#include<iostream>
#include<string>
#include<thread>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>


using namespace std;


string first_player,second_player;
char ch1='X',ch2='W',s[3][3];
int m=0,n=0,flage=1,k[9],kp=0,l[9],lp=0,finish=0;

void show()
{
    if(flage==1)
        cout<<"Player_1 : \n";
    else
        cout<<"Player_2 : \n";
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(i==(m*4)+2 && j==(n*13)+6){
                cout<<'V';
                continue;
            }
            int flage33;
            flage33=0;
            for(int f=0;f<lp;f++)
            {
                if(i==(k[f]*4)+2 && j==(l[f]*13)+6)
                {
                    cout<<s[k[f]][l[f]];
                    flage33=1;
                    break;
                }
            }
            if(flage33==1)
                continue;
            if(j==13 || j==26)
                cout<<char(179);
            else if(i==4 || i==8)
                cout<<char(196);
            else
                cout<<' ';
        }
        cout<<'\n';
    }
}

void input()
{
    cout<<"Enter 1st player nickname :";
    cin>>first_player;
    system("cls");
    cout<<"Enter 2nd player nickname :";
    cin>>second_player;
}

void control()
{
    char ch[2];
    int a,b;
    a=m;
    b=n;

    for(int i=0;i<2;i++)
    {
        ch[i]=getch();
        if(ch[0] != -32)
        {
            ch[1]='\0';
            break;
        }
    }
    if(ch[1]==77)
    {
        if(n<2)
        {
            n++;
        }
        else
        {
            if(m<2)
                m++;
            else
                m=0;
            n=0;
        }
    }
    else if(ch[1]==75)
    {
        if(n>0)
        {
            n--;
        }
        else
        {
            if(m>0)
                m--;
            else
                m=2;
            n=2;
        }
    }
    else if(ch[1]==72)
    {
        if(m>0)
        {
            m--;
        }
        else
        {
            if(n>0)
                n--;
            else
                n=2;
            m=2;
        }
    }
    else if(ch[1]==80)
    {
        if(m<2)
        {
            m++;
        }
        else
        {
            if(n<2)
                n++;
            else
                n=0;
            m=0;
        }
    }
    if(ch[0]==13)
    {
        if(lp<9){
        k[kp]=m;
        l[lp]=n;
        kp++;
        lp++;
        }
        if(flage==1)
        {
            s[m][n]=ch1;
            flage=2;
        }
        else
        {
            s[m][n]=ch2;
            flage=1;
        }
    }

    if(s[m][n]==ch1 || s[m][n]==ch2)
    {
        m=a;
        n=b;
    }


}

void run()
{
    for(;;)
    {
        if(finish != 0)
            break;
        system("cls");
        show();
        control();
    }
}

void took(int k,int& s,int& t)
{
    if(k==3){
            s=0;t=0;
        }
        else if(k==2){
            s=0;t=2;
        }
        else if(k==1)
        {
            s=2;t=0;
        }
}

char control_2()
{
    int cheak=0,cheak2=0,cheak3=0,cheak4=0;
    int result,x=0,y=0;
    char ch;
    for(int i=3;i>0;i--)
    {
        result=0;
        for(int j=0;j<i;j++)
        {
            if(cheak2==0){
            if(cheak==0)
            {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    y++;
                }
                if(result==3)
                    return ch;
                result=0;
            }
            else if(cheak==1)
            {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    x++;
                }
                if(result==3)
                    return ch;
                result=0;
            }
            else if(cheak==2)
            {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    x++;
                    y++;
                }
                if(result==3)
                    return ch;
                result=0;
            }
            cheak++;
            }
            else if(cheak2==1)
            {
                if(cheak3==0)
                {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    x++;
                    y--;
                }
                if(result==3)
                    return ch;
                result=0;
                }
                else if(cheak3==1)
                {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    x++;
                }
                if(result==3)
                    return ch;
                result=0;
                }
                cheak3++;
            }
            else if(cheak2==2)
            {
                took(i,x,y);
                for(int k=0;k<3;k++)
                {
                    if(k==0)
                        ch=s[x][y];
                    if(s[x][y]==ch)
                        result++;
                    x--;
                }
                if(result==3)
                    return ch;
                result=0;
            }

        }
        cheak2++;
    }
    return 'A';
}

void system()
{
    char pop;
    for(;;)
    {
        pop=control_2();
        if(pop=='A')
          continue;
        else
        {
            system("cls");
            if(pop==ch1)
                cout<<first_player<<" Win........\n";
            if(pop==ch2)
            {
                cout<<second_player<<" Win........\n";
            }
            finish=12;
            break;
        }
    }
}


int main()
{
    thread c(run);
    thread d(run);

    c.join();
    d.join();

    return 0;
}
