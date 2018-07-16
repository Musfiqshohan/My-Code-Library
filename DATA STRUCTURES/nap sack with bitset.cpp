///https://agc020.contest.atcoder.jp/tasks/agc020_c?lang=en
///http://petr-mitrichev.blogspot.com/2018/01/
#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

int ara[2001];
bitset<2001*2001>bset;//[2];
int main()
{
    int n;
    scanf("%d",&n);

    int sum=0,mx=0;
    for(int i=1; i<=n; i++)
        scanf("%d",&ara[i]);


  //  sort(ara+1,ara+n+1);

    for(int i=1; i<=n; i++)
    {
        sum+=ara[i];
        mx=max(mx,ara[i]);
    }

    int avg=(sum+2-1)/2, last=mx*n;

    bset[0]=1;
    for(int i=1; i<=n; i++)
        bset= bset | (bset<<ara[i]);


    for(int i=avg; i<=last; i++)
    {
        if(bset[i]==1)
        {
            printf("%d\n",i);
            return 0;
        }
    }


    return 0;
}	
