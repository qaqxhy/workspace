#include<iostream>
using namespace std;
int main()
{
    int count=0;
    for(int i=0;i<=6;i++)
    {
        for(int j=i+1;j<=7;j++)
        {
            for(int k=j+1;k<=8;k++)
            {
                for(int l=k+1;l<=9;l++) count++;
            }
        }
    }
}