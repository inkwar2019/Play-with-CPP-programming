#include<iostream>
#include<ctype.h>
#include<conio.h>
using namespace std;

int main()
{
    char ch[2];
    for(;;)
    {
        for(int i=0;i<2;i++){
                ch[i]=getch();
            cout<<i+1<<"."<<int(ch[i])<<endl;
        }
    }

    return 0;
}
