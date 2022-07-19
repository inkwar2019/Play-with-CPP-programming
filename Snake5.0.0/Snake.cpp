#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<thread>
#include<string>
#include<string.h>

using namespace std;
int score;
class point{
public:
    int x,y;
    point(){x=2;y=2;}
    point(int a,int b){x=a;y=b;}
    void put_x(int a){x=a;}
    void put_y(int a){y=a;}
    int get_x(){return x;}
    int get_y(){return y;}
    void sw(int a){cout<<a<<"("<<x<<","<<y<<")\n";}
    void moveto(point &p){x=p.get_x();y=get_y();}
    void hmoveto(int);
    void rnd(){x=2+rand()%10;y=2+rand()%38;}
    void inc_x(){x++;}
    void dec_x(){x--;}
    void inc_y(){y++;}
    void dec_y(){y--;}
};
int sozib=1;

point head(7,8),shoulder(7,7);
point body(7,6),body_1(7,5),body_2(7,4),body_3(7,3);
point tail(7,2),eat(3,3),denger(5,5),denger_1(9,9),denger_2(3,38);

/**void point::hmoveto(int a){
    if(a==1)
        y++;
    else if(a==2)
        x--;
    else if(a==3)
        y--;
    else if(a==4)
        x++;
}*/

void change();
int check();
void scan();
void show();
void system_run();
int control();

void go()
{
    if(sozib==1)
        head.inc_x();
    else if(sozib==2)
            head.inc_y();
    else if(sozib==3)
        head.dec_x();
    else if(sozib==4)
        head.dec_y();

}
/**
void run()
{
    for(;;)
    {
        go();
        check();
        system("cls");
        show();
        Sleep(500);
    }
}
void system_run()
{
    for(;;){
    scan();
    control();
    }
}
*/
int main()///Main function is here .............
{
    thread t(show);
    thread p(scan);
    t.join();
    p.join();

    //t.join();
    return 0;
}

void show()///Show Function is here.................
{
    int speed=125;
    for(;;){
         change();
         go();
        int n=control();
        if(n==10)
            break;
        system("cls");
        for(int i=0;i<13;i++){
            for(int j=0;j<41;j++){
                if(i==0 && j==0)
                    cout<<"Score :"<<score;
                if(eat.get_x()==i && eat.get_y()==j){
                    cout<<"*";
                    continue;
                }
                if((denger.get_x()==i && denger.get_y()==j)||(denger_1.get_x()==i && denger_1.get_y()==j)||(denger_2.get_x()==i && denger_2.get_y()==j)){
                    cout<<'X';
                    continue;
                }
                if((i==head.get_x() && j==head.get_y())){
                    cout<<'O';
                    continue;
                }
                if((i==body.get_x() && j==body.get_y())||(i==body_1.get_x() && j==body_1.get_y())||(i==shoulder.get_x() && j==shoulder.get_y())){
                    cout<<'#';
                    continue;
                }
                if((i==body_2.get_x() && j==body_2.get_y())||(i==body_3.get_x() && j==body_3.get_y())||(i==tail.get_x() && j==tail.get_y())){
                    cout<<'#';
                    continue;
                }
                else
                    cout<<" ";
            }
            cout<<"\n";
        }
    Sleep(speed);
    }

}


int control()
{
    srand(time(0));
        int i;
        if(check()==1){
            system("cls");
            cout<<"You Fail.......\nYour score is "<<score<<endl;
            return 10;
        }
        if(head.get_x()==eat.get_x() && head.get_y()==eat.get_y()){
            eat.rnd();
            denger.rnd();
            denger_1.rnd();
            denger_2.rnd();
            score++;
        }
        if(((head.get_x()==denger.get_x()) && head.get_y()==denger.get_y())||((head.get_x()==denger_1.get_x()) && head.get_y()==denger_1.get_y())||((head.get_x()==denger_2.get_x()) && head.get_y()==denger_2.get_y()))
        {
            system("cls");
            cout<<"You Fail.......\nYour score is "<<score<<endl;
            return 10;
        }
}

void scan()///Scan Function is here.................
{
    for(;;){

    char ss[3];
    for(int i=0;i<2;i++){
            ss[i]=getch();
            if(ss[0]!=-32)
                break;
        }
        ss[2]='\0';
    if(ss[1]==char(72)){
        sozib=3;
        if(head.get_x()-1==shoulder.get_x())
            return;
    }
    else if(ss[1]==char(80)){
        sozib=1;
        if(head.get_x()+1==shoulder.get_x())
            return;
    }
    else if(ss[1]==char(75)){
        sozib=4;
        if(head.get_y()-1==shoulder.get_y())
            return;
    }
    else if(ss[1]==char(77)){
        sozib=2;
        if(head.get_y()+1==shoulder.get_y())
            return;
    }
    int n=control();
        if(n==10)
            break;
    }
}


void change()///Change Function is here..................
{
    tail.x=body_3.x;
    tail.y=body_3.y;
    body_3.x=body_2.x;
    body_3.y=body_2.y;
    body_2.x=body_1.x;
    body_2.y=body_1.y;
    body_1.x=body.x;
    body_1.y=body.y;
    body.x=shoulder.x;
    body.y=shoulder.y;
    shoulder.x=head.x;
    shoulder.y=head.y;
}

int check()///Check Function is here .....................
{
    int n=5;
    if(head.get_x()<2 || head.get_y()<2){
        if(head.get_x()<2)
            head.put_x(12);
        else
            head.put_y(40);
    }
    else if(head.get_x()>12 || head.get_y()>40){
        if(head.get_x()>12)
            head.put_x(2);
        else
            head.put_y(2);
    }
    if((head.get_x()==body.get_x() && head.get_y()==body.get_y())||(head.get_x()==body_1.get_x() && head.get_y()==body_1.get_y()))
            return 1;
    if((head.get_x()==body_2.get_x() && head.get_y()==body_2.get_y())||(head.get_x()==body_3.get_x() && head.get_y()==body_3.get_y())||(head.get_x()==tail.get_x() && head.get_y()==tail.get_y()))
        return 1;
    else
        return 0;
}
