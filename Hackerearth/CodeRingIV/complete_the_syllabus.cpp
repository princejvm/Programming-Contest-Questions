/*Any fool can write code that a computer can understand. Good programmers write code that humans can understand.*/
//Que link-> https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/complete-the-syllabus/
//Author-->Prince Kumar 
//Handle-->princejvm
#include<bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    char a[][10]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int b[10];
        for(int i=0;i<7;i++) cin>>b[i];
        int c=0,d=0;
        for(int i=0;i<7;i++) if(b[i]>0) c+=b[i],d=i;
        int p=k%c;
        if(p==0) {printf("%s\n",a[d]);continue;}
        for(int i=0;i<7;i++)
        {
            p-=b[i];
            if(p<=0)
            {
                d=i;
                break;
            }
        }
        cout<<a[d]<<"\n";
    }
    return 0;
}
