/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/problem/algorithm/problem-2-52/description/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
int a[505];
int b[505];
int dp[505][505];
int fun(int i,int j)
{
    if(i<0||j<0)
        return 0;
    if(a[i]>b[j])
        dp[i][j]=2+fun(i-1,j-1);
    if(a[i]==b[j])
        {dp[i][j]=max(1+fun(i-1,j-1),fun(i,j-1));
        }
    if(a[i]<b[j])
        dp[i][j]=fun(i,j-1);
    return dp[i][j];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        int ans=fun(n-1,n-1);
      printf("%d\n",ans);
    }
    return 0;
}
