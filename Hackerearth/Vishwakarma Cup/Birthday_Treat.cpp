/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/challenge/college/vishwakarma-cup/algorithm/puppy-cakes/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s),r=0;
        for(int i=0;i<(n/2);i++)
        {
            if(s[i]!=s[n-i-1])
            {r=1;break;}
        }
        if(r==1)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
