///This a implementation of 2d segment tree. I am trying to solve a problem ,so if i learn this by myself ,it may or may not
///help me in any contest :p  but implementation by myself is also like solving a problem.
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define INF 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int T[2*250009],ara[505][505];

struct point
{
    int r,c;
};

void build(int nd, point b, point e)
{
    if(b.r==e.r && b.c==e.c)
    {
        T[nd]=ara[b.r][b.c];
        return;
    }

    int ch1,ch2,ch3,ch4;
    ch1=nd*4+1;
    ch2=nd*4+2;
    ch3=nd*4+3;
    ch4=nd*4+4;

    point mid1b,mid1e,mid2b, mid2e,mid3b,mid3e, mid4b, mid4e;
    mid1b=b;
    mid1e= {(b.r+e.r)/2, (b.c+e.c)/2};


    mid2b= {b.r,  min((b.c+e.c)/2 +1,e.c) };
    mid2e= {(b.r+e.r)/2, e.c};

    mid3b= {min((b.r+e.r)/2 +1,e.r) , b.c};
    mid3e= {e.r,(b.c+e.c)/2 };

    mid4b= {min((b.r+e.r)/2 +1,e.r), min((b.c+e.c)/2+1,e.c)};
    mid4e=e;


    build(ch1, mid1b, mid1e);
    build(ch2, mid2b, mid2e);
    build(ch3, mid3b, mid3e);
    build(ch4, mid4b, mid4e);

    int r1=max(T[ch1],T[ch2]);
    int r2=max(T[ch3],T[ch4]);

    T[nd]=max(r1,r2);
}


bool check_outside(point b, point e, point st, point en)
{
    if(e.r<st.r || b.r>en.r) return true;   /// up or down of my square

    if(e.c<st.c || b.c>en.c) return true;   /// left or right of my square

    return false;

}

bool check_inside(point b, point e, point st, point en)
{
    if(b.r>=st.r && b.c>=st.c && e.r<=en.r && e.c<=en.c) return true;  ///Inside my square

    return false;
}

int query(int nd, point b, point e, point st, point en)
{

    if(check_outside(b,e,st,en)==true) return 0;

    if(check_inside(b,e,st,en)==true)
    {
         return T[nd];
    }


    int ch1,ch2,ch3,ch4;
    ch1=nd*4+1;
    ch2=nd*4+2;
    ch3=nd*4+3;
    ch4=nd*4+4;

    point mid1b,mid1e,mid2b, mid2e,mid3b,mid3e, mid4b, mid4e;
    mid1b=b;
    mid1e= {(b.r+e.r)/2, (b.c+e.c)/2};


    mid2b= {b.r,  min((b.c+e.c)/2 +1,e.c) };
    mid2e= {(b.r+e.r)/2, e.c};

    mid3b= {min((b.r+e.r)/2 +1,e.r) , b.c};
    mid3e= {e.r,(b.c+e.c)/2 };

    mid4b= {min((b.r+e.r)/2 +1,e.r), min((b.c+e.c)/2+1,e.c)};
    mid4e=e;


    int t1,t2,t3,t4;
    t1=t2=t3=t4=0;


    t1=query(ch1, mid1b, mid1e, st,en);
    t2=query(ch2, mid2b, mid2e, st,en);
    t3=query(ch3, mid3b, mid3e, st,en);
    t4=query(ch4, mid4b, mid4e, st,en);


    int r1=max(t1,t2);
    int r2=max(t3,t4);

    return max(r1,r2);

}



int main()
{

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        printf("Case %d:\n",++tt);
        int n,q;
        scanf("%d %d",&n,&q);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&ara[i][j]);
            }
        }

        build(0, {0,0}, {n-1,n-1});

        while(q--)
        {
            int I,J,S;
            scanf("%d %d %d",&I,&J,&S);
            I--,J--;
            printf("%d\n",query(0, {0,0}, {n-1,n-1}, {I,J}, {I+S-1,J+S-1} ));

        }

        ms(T,0);
        ms(ara,0);
    }

    return 0;
}

