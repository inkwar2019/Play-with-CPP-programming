#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>


using namespace std;

int main()
{
    string name;
    srand(time(0));
    char ch,ph,terminate;
    //ofstream output;
    ifstream input_1,input_2,input_3;
    int n,m;
    for(;;){

    name = " ";
    input_1.open("vowel.txt");
    input_2.open("first.txt");
    input_3.open("small.txt");

    n=1+rand()%21;
    for(int i=0;i<n;i++)
        input_2>>ch;
    name += ch;

    m=1+rand()%3;
    for(int j=0;j<m;j++){

    n=1+rand()%5;
    for(int i=0;i<n;i++)
        input_1>>ch;



    n=1+rand()%21;
    for(int i=0;i<n;i++)
        input_3>>ph;

    name +=ch;
    name += ph;
    }

    system("cls");
    cout<<"Name :";
    cout<<name<<endl;

    input_1.close();
    input_2.close();
    input_3.close();


    terminate = getch();
    if(terminate == '0')
        break;
    }
    return 0;
}
