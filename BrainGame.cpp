#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<thread>
#include<Windows.h>

using namespace std;

char name[12];
int timer=0,Terminator_Flage=0,score=0;

void counter()
{
    for(;;){

    if(Terminator_Flage != 0){
        system("cls");
        break;
    }
    if(timer >34){
        Terminator_Flage =12;
        system("cls");
        break;
    }
    timer++;
    Sleep(500);
    }
}

void random_name_generator()
{
    for(int i=1;i<10;i++)
    {
        name[i] = 65 +rand()%26;
    }
    name[10] = '\0';
}

class box
{
public:
    char sign;
    box* left;
    box* right;
    box* up;
    box* down;
    box()
    {
        sign = '\0';
        left = 0;
        right = 0;
        up = 0;
        down = 0;
    }
};

box* head=0;
box* tempo;

void create(int a)
{

    box* temp;
    box* temp_1;
    box* temp_2;
    temp = new box();
    if(a==1){
    head = temp;
    temp->sign = name[a];
    }
    else if(a==2)
    {
        head->right = temp;
        temp->left = head;
        temp->sign = name[a];
    }
    else if(a==3)
    {
        temp_1=head->right;
        temp_1->right = temp;
        temp->left = temp_1;
        temp->sign = name[a];
    }
    else if(a==4)
    {
        head->down = temp;
        temp->up = head;
        temp->sign = name[a];
    }
    else if(a==5)
    {
        temp_1=head->right;
        temp_2=head->down;
        temp_2->right = temp;
        temp->left =temp_2;
        temp_1->down = temp;
        temp->up = temp_1;
        temp->sign = name[a];
    }
    else if(a==6)
    {
        temp_1=(head->right)->right;
        temp_2=(head->down)->right;
        temp_2->right = temp;
        temp->left =temp_2;
        temp_1->down = temp;
        temp->up = temp_1;
        temp->sign = name[a];
    }
    else if(a==7)
    {
        temp_1=head->down;
        temp_1->down = temp;
        temp->up = temp_1;
        temp->sign = name[a];
    }
    else if(a==8)
    {
        temp_1 = (head->down)->right;
        temp_2 = (head->down)->down;
        temp_2->right = temp;
        temp->left =temp_2;
        temp_1->down = temp;
        temp->up = temp_1;
        temp->sign = name[a];
    }
    else if(a==9)
    {
        temp_1 = ((head->down)->right)->right;
        temp_2 = ((head->down)->down)->right;
        temp_2->right = temp;
        temp->left =temp_2;
        temp_1->down = temp;
        temp->up = temp_1;
        temp->sign = name[a];
    }
}

void made()
{
    for(int i=1;i<10;i++)
    {
        create(i);
    }
}

void show()
{
    box* temp;
    box* temp_1=head;

    for(;;)
    {
        if(Terminator_Flage != 0)
        {
            system("cls");
             break;
        }

        system("cls");
        temp = head;
        temp_1 = head;
        cout<<"Time :"<<timer<<"\n\n";
        cout<<"Score :"<<score<<"\n\n";
        for(int i=0;i<3;i++)
        {
            for(;;)
            {
                if(temp==tempo)
                    cout<<"    "<<temp->sign<<"    ";
                else
                    cout<<"    *    ";
                if(temp->right==0)
                {
                    cout<<"\n\n";
                    break;
                }
                temp = temp->right;
            }
            if(temp_1->down == 0)
                break;
            temp_1 = temp_1->down;
            temp = temp_1;
        }
        Sleep(125);
    }
}

void scan()
{
    tempo = head;

    char choice[2];

    for(;;)
    {
        if(Terminator_Flage != 0){
            system("cls");
            break;
        }
        for(int i=0;i<2;i++)
        {
            choice[i] = getch();
            if(choice[0]==13)
                Terminator_Flage=12;
            if(choice[0] != -32)
            {
                choice[1]='\0';
                break;
            }
        }
        if(Terminator_Flage != 0){
            system("cls");
            break;
            }
        if(choice[1]==80)
        {
            if(tempo->down != 0)
                tempo= tempo->down;
            else
            {
                cout<<"You are in circumference\nPlease,look for another way\n";
                getch();
            }
        }
        else if(choice[1]==72)
        {
            if(tempo->up != 0)
                tempo= tempo->up;
            else
            {
                cout<<"You are in circumference\nPlease,look for another way\n";
                getch();
            }
        }
        else if(choice[1]==77)
        {
            if(tempo->right != 0)
                tempo= tempo->right;
            else
            {
                cout<<"You are in circumference\nPlease,look for another way\n";
                getch();
            }
        }
        else if(choice[1]==75)
        {
            if(tempo->left != 0)
                tempo= tempo->left;
            else
            {
                cout<<"You are in circumference\nPlease,look for another way\n";
                getch();
            }
        }
        //Sleep(500);
    }

}

int main()
{
    int x,y;
    int m,c,d;
    char input_char;
    srand(time(0));
    random_name_generator();
    made();

    for(;;){
    thread t(show);
    thread p(scan);
    thread s(counter);

    t.join();
    p.join();
    s.join();
    system("cls");
    x= 1+ rand()%3;
    y= 1+ rand()%3;

    cout<<"What was ("<<x<<","<<y<<")th Character :";
    cin>>input_char;
    m=(x-1)*3;
    m+=y;
    if(input_char == name[m]){
        cout<<"Welldone....!\n";
        getch();
        c=35 - timer;
        timer = 0;
        Terminator_Flage = 0;
        random_name_generator();
        d=c/35;
        c=d*100;
        score+=5;
        score+=c;
    }
    else{
         cout<<"Game Over....!\n\n\n\n";
         cout<<"Your Total Score :"<<score<<endl;
         getch();
         break;
    }
    }
    //cout<<((((head->right)->down)->right)->down)->sign<<endl;

    return 0;
}
