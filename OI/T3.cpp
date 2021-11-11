#include<windows.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
    system("git add .");
    char arg[90]="git commit -m \"";
    for(int i=1;i<argc;i++)
    {
        strcat(arg,argv[i]);
        char a[]=" ";
        strcat(arg,a);
    }
    char a[]="\"";
    strcat(arg,a);
    system(arg);
    return 0;
}