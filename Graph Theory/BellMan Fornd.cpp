#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


vector<pii>vec;
int n;
int dis[209],busy[209],inCycle[209];
int calc(int a, int b)
{
    int c= b-a;

    return c*c*c;
}

void Bellman_ford(int src)
{
    for(int i=1;i<=n;i++)
        dis[i]=inf;

    dis[src]=0;

    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            pii tp= vec[j];

            int u=tp.first;
            int v=tp.second;
            int w= calc(busy[u],busy[v]);

            if(dis[u]!=inf && dis[u]+ w <dis[v])
            {
               // printf("u=%d v=%d w=%d\n",u,v,w);
                dis[v]= dis[u]+w;
            }


        }

    }


    bool flag=false;

    for(int i=0;i<vec.size();i++)
    {
            pii tp= vec[i];
            int u=tp.first;
            int v=tp.second;
            int w= calc(busy[u],busy[v]);

            if( dis[u]!=inf &&  dis[u]+ w <dis[v])
            {
               // printf("Fuck\n");
               inCycle[v]=1;
               inCycle[u]=1;

                break;
            }

    }


    return ;

}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test){

    printf("Case %d:\n",++tt);

    int m,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&busy[i]);

    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        vec.push_back({u,v});
    }

    Bellman_ford(1);

    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        scanf("%d",&v);

       // printf(" v=%d dis[v]=%d\n",v,dis[v]);

        if(inCycle[v]==1 || dis[v]<3 || dis[v]==inf)
            printf("?\n");

        else
            printf("%d\n",dis[v]);

    }

    vec.clear();
    ms(inCycle,0);
    ms(dis,0);



    }


    return 0;
}
