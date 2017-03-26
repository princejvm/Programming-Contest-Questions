/*life never ends so believe in god and just code*/

//Author-->Prince Kumar 
//Handle on codechef-->princejvm
//Handle on codeforces-->prince593
#include<bits/stdc++.h>
using namespace std;
vector <int> a[200000];
vector<int> e;
int v[200000];
int n,m;
void dfs(int i)
{
    v[i]=1;
    e.push_back(i);
    for(int j=0;j<a[i].size();j++)
    {
        if(v[a[i][j]]==0)
            dfs(a[i][j]);
    }
    return;
}
int main()
{

    scanf("%d %d",&n,&m);
    int u,l;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&l);
        a[u].push_back(l);
        a[l].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0){
            dfs(i);
            int j;
            for( j=0;j<e.size();j++)
            {

                if((a[e[j]].size())!=(e.size()-1))
                    break;
            }
            if(j!=e.size())
            {
                printf("NO");
                return 0;
            }
        e.clear();}
    }
    printf("YES");
    return 0;
}
