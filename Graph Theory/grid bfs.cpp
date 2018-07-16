#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int R,C;
struct par
{
    int r,c;
};

int dirr[4]= { 0, 0, 1, -1 };
int dirc[4]= { 1, -1,0,  0 };

int dis[21][21], vis[21][21];
char ara[21][21];
vector<par>vec;

void clearr()
{
    vec.clear();
    ms(dis,0);
    ms(vis,0);
}


void bfs(par src)
{
    queue<par>q;
    q.push(src);

    dis[src.r][src.c]=0;
    vis[src.r][src.c]=1;


    while(!q.empty())
    {
        par t= q.front();
        q.pop();

        int r=t.r;
        int c=t.c;

        for(int i=0; i<4; i++)
        {
            int  r1=r+dirr[i];
            int  c1=c+dirc[i];

            if(r1>=1 && r1<=R && c1>=1 && c1<=C && ara[r1][c1] !='#' &&  ara[r1][c1]!='m' && vis[r1][c1]==0) // && visf[r1][c1][num]==0
            {
                vis[r1][c1]=1;

                dis[r1][c1]=dis[r][c]+1;
                q.push({r1,c1});


            }
        }


    }


}



int main()
{
    int tt=0,test;
    cin>>test;
    getchar();
    while(tt<test)
    {

        scanf("%d %d",&R,&C);
        getchar();

        int cnt=0;
        par t;

        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                scanf("%c",&ara[i][j]);
                if(ara[i][j]=='a' || ara[i][j]=='b'  || ara[i][j]=='c')
                {
                    vec.push_back({i,j});

                }
                if(ara[i][j]=='h')
                    t= {i,j};
            }
            getchar();
        }



        int mx=0;

        for(int i=0; i<3; i++)
        {
            ms(vis,0);
            bfs( vec[i] );


            mx= max(mx, dis[ t.r ][ t.c ] );
        }

        printf("Case %d: %d\n",++tt, mx);


        clearr();

    }

    return 0;
}
