#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;

int get()
{
    int x;
    srand(time(NULL));
    x=1+rand()%8;
    return x;
}

int main()
{
    int a=1,b=3,c=5,d=2,e=4,f,g,h,i,j,k,l,m;
    srand(time(NULL));

    for(;;){
    system("cls");
    for(i=0;i<10;i++){
        for(j=0;j<40;j++){
             if((i>a && j==0)||(i>b && j==2)||(i>c && j==4)||(i>d && j==6)||(i>e && j==8)||(i>f && j==10)||(i>g && j==12)||(i>h && j==14)||(i>k && j==16)||(i>l && j==18)||(i>m && j==20))
                cout<<char(219);
             else
                cout<<" ";
        }
        cout<<"\n";
    }
    a=1+rand()%8;
    b=1+rand()%8;
    c=1+rand()%8;
    d=1+rand()%8;
    e=1+rand()%8;
    f=1+rand()%8;
    g=1+rand()%8;
    h=1+rand()%8;
    k=1+rand()%8;
    l=1+rand()%8;
    m=1+rand()%8;


    for(int q=0;q<pow(7,9);q++)
        int l=0;
    }
    return 0;
}
