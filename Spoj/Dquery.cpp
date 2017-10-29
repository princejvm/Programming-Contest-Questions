/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> http://www.spoj.com/problems/DQUERY/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
struct val{
int l;
int r;
int i;
}q[200005];
int a[30004];
int sq;
int cl,cr;
int mp[1000006];
int ans[200005];
bool comp(val a,val b)
{
    if(a.l/sq!=b.l/sq)
        return a.l/sq<b.l/sq;
    else
        return a.r<b.r;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sq=sqrt(n);
    int qu;
    scanf("%d",&qu);
    int l,r;
    for(int i=1;i<=qu;i++)
    {
        scanf("%d %d",&l,&r);
        q[i].l=l;
        q[i].r=r;
        q[i].i=i;
    }
    sort(q+1,q+qu+1,comp);
    cl=q[1].l,cr=cl-1;
    int cnt=0;
    //cout<<"*";
    for(int i=1;i<=qu;i++)
    {
        while(cl<q[i].l)
        {
            mp[a[cl]]--;
            if(mp[a[cl]]==0)
                cnt--;
            cl++;
        }
        while(cl>q[i].l)
        {
            cl--;
            mp[a[cl]]++;
            if(mp[a[cl]]==1)
                cnt++;
        }
        while(cr<q[i].r)
        {
            cr++;
            mp[a[cr]]++;
            if(mp[a[cr]]==1)
                cnt++;
        }
        while(cr>q[i].r)
        {
            mp[a[cr]]--;
            if(mp[a[cr]]==0)
                cnt--;
            cr--;
        }
        ans[q[i].i]=cnt;
    }
    for(int i=1;i<=qu;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
