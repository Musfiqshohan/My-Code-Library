#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
int b_size;
struct query
{
    int i,l,r;
} Q[200009];


ll answer[200009], sum=0;
int cntAra[1000009],  ara[200009];
bool cmp(query a, query b)
{
    if(a.l/b_size != b.l/b_size)
        return a.l/b_size < b.l/b_size;
    return a.r<b.r;
}

inline void Add(int pos)
{
    ll num= ara[pos];

    sum-= cntAra[num]*(cntAra[num] * num);
    cntAra[num]++;
    sum+= cntAra[num]*(cntAra[num] * num);

}

inline void Remove(int pos)
{
    ll num= ara[pos];
    sum-= cntAra[num]*(cntAra[num] * num);
    cntAra[num]--;
    sum+= cntAra[num]*(cntAra[num] * num);

}


int main()
{
    int  n,t;
    scanf("%d %d",&n,&t);

    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);

    b_size= sqrt(n);

    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&Q[i].l, &Q[i].r);
        Q[i].i=i;
    }

    sort(Q,Q+t,cmp);

    int curL=0, curR=-1;

    for(int i=0; i<t; i++)
    {
        int L= Q[i].l-1, R= Q[i].r-1;

        while(curR<R)
        {
            curR++;
            Add(curR);
        }

        while(curR>R)
        {
            Remove(curR);
            curR--;
        }


        while(curL<L)
        {
            Remove(curL);
            curL++;
        }

        while(curL>L)
        {
            curL--;
            Add(curL);
        }


        answer[Q[i].i]=sum;
    }

    for(int i=0; i<t; i++)
        printf("%lld\n",answer[i]);



    return 0;
}

