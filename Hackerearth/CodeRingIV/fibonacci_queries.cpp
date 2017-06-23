/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/problem/algorithm/fibonacci-query/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
int tree[500000];
int a[100005];
#define MOD 1000000007
long long int a1,b1,c1,d1;
int gcd(int a,int b);
int ans(int st,int en,int node,int l,int r);
void make(int st,int en,int node);
void fast_fib(long long int n,long long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a1 = ans[0];             /* F(n) */
    b1 = ans[1];             /* F(n+1) */
    c1 = 2*b1 - a1;
    if(c1 < 0)
        c1 += MOD;
    c1 = (a1 * c1) % MOD;      /* F(2n) */
    d1 = (a1*a1 + b1*b1) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c1;
        ans[1] = d1;
    }
    else
    {
        ans[0] = d1;
        ans[1] = c1+d1;
    }
}
 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void make(int st,int en,int node)
{
    if(st==en)
    {
        tree[node]=a[st];
        return;
    }
    int mid=st+(en-st)/2;
    make(st,mid,2*node);
    make(mid+1,en,2*node+1);
    tree[node]=gcd(tree[2*node],tree[2*node+1]);
}
int ans(int st,int en,int node,int l,int r)
{
    if(r<st||l>en)
        return 0;
    if(l<=st&&en<=r)
        return tree[node];
    int mid=st+(en-st)/2;
    return(gcd(ans(st,mid,2*node,l,r),ans(mid+1,en,2*node+1,l,r)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    make(1,n,1);
    int l1,r1,l2,r2;
    for(int i=0;i<q;i++)
    {
        cin>>l1>>r1>>l2>>r2;
        int val=gcd(ans(1,n,1,l1,r1),ans(1,n,1,l2,r2));
        long long int ans1[2]={0};
        fast_fib(val,ans1);
        printf("%lld\n",ans1[0]%MOD);
    }
    return 0;
}
