/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/problem/algorithm/sum-of-digits-8/description/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[18][180][4];
int dig[20];
int id,s;
void conv_dig(long long int no)
{
    int i=0;
    while(no>0)
    {
        dig[i++]=no%10;
        no/=10;
    }
    id=i;
}
int flag=1;
ll solve(int sum,int idx,int tight)
{
    if(idx==-1)
    {
        if(sum==s)
            {flag=0;return 1;}
        else
            return 0;
    }
    if(sum>s)
        return 0;
    if(dp[idx][sum][tight]!=-1&&tight!=1)
        return dp[idx][sum][tight];
    int k=tight?dig[idx]:9;
    ll ans=0;
    for(int i=0;i<=k;i++)
    {
        int nw_tht=(dig[idx]==i)?tight:0;
        ans+=solve(sum+i,idx-1,nw_tht);
    }
    if(!tight)
        dp[idx][sum][tight]=ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    long long int a,b;
    cin>>a>>b>>s;
    conv_dig(a-1);
    ll ans1=solve(0,id-1,1);
    memset(dp,-1,sizeof(dp));
    conv_dig(b);
    ll ans2=solve(0,id-1,1);
    cout<<ans2-ans1<<"\n";
    ll l=a,h=b,ans;
    while(l<=h)
    {
        ll mid=l+(h-l)/2;
        memset(dp,-1,sizeof(dp));
        conv_dig(mid);
        ll p=solve(0,id-1,1)-ans1;
        if(p>0)
        {
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}

