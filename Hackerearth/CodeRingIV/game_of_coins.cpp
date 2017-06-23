/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/problem/algorithm/game-of-coins-264/
//Author-->Prince Kumar 
//Handle-->princejvm
//BEST SUBMISSION ON HACKEREARTH IN C++14

#include<bits/stdc++.h>
using namespace std;
int LP[10000007];
vector<int>prime;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,p;
        cin>>n>>k>>p;
        if(n%2!=0)
        {
            if(p==1&&k!=1)
            {cout<<"BRAN"<<"\n";continue;}
            if(p==1&&k==1)
            {cout<<"ARYA"<<"\n";continue;}
            int c=0;
            for(int i=2;i<=sqrt(k);i++)
            {
                int l=k/i; 
                if((k%i==0)&&(i>=p||l>=p))
                {
                    c=1;
                    break;
                }
            }
            if(c>0)
            cout<<"BRAN"<<"\n";
            else cout<<"ARYA"<<"\n";
 
        }
        else cout<<"ARYA"<<"\n";
    }
    return 0;
}
