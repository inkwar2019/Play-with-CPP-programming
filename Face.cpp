#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,n=0;
    string ss;
    for(;;){
    ss="   ";
    ss+=char(220);
    ss+=char(219);
    ss+=char(219);
    ss+=char(219);
    ss+=char(219);
    ss+=char(220);
    ss+="\n";
    ss+="  ";
    ss+=char(219);
    ss+=" o  o ";
    ss+=char(219);
    ss+="\n";
    ss+="  ";
    ss+=char(219);
    ss+=char(220);
    if(n==0)
        ss+=" \\\/ ";
    else if(n==1)
        ss+=" -- ";
    else if(n==2)
        ss+=" ~~ ";
    else if(n==3)
        ss+=" ^^ ";
    else if(n==4)
        ss+=" () ";
    else if(n==5)
        ss+=" == ";
    ss+=char(220);
    ss+=char(219);
    ss+="\n";
    ss+="  ";
    ss+=char(220);
    ss+=char(220);
    ss+=char(219);
    ss+=char(219);
    ss+=char(219);
    ss+=char(219);
    ss+=char(220);
    ss+=char(220);
    ss+="\n";
    ss+=char(220);
    ss+=char(219);
    ss+="        ";
    ss+=char(219);
    ss+=char(220);
    ss+="\n";
    ss+=char(219);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(220);
    ss+=char(219);
    ss+="\n";

    system("cls");
    cout<<ss<<endl;
    if(n<5)
        n++;
    else
        n=0;

    for(int i=0;i<pow(10,7);i++){
        i=i;
    }
    }

    return 0;
}
