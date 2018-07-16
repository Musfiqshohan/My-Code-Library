#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

struct node
{
    int u,v,w;

    bool operator < (const node &p) const
    {
        return w<p.w;
    }

};
vector<node>vec;
vector<int>adj[2009],edge[2009];
int ara[2009][2009],dis[2009][2009];
int par[2009], vis[2009];
int n;
bool check()
{
    for(int i=1; i<=n; i++)
    {

        if(ara[i][i]!=0) return false;

        for(int j=i+1; j<=n; j++)
        {
            if(ara[i][j]!= ara[j][i])
                return false;

            if(ara[i][j]==0)
                return false;
        }
    }

    return true;

}

int findd(int r)
{
    return par[r]= (par[r]==r)? r:findd(par[r]);
}


void mst()
{
    sort(vec.begin(),vec.end());

    for(int i=1; i<=n; i++)
        par[i]=i;

    for(int i=0; i<vec.size(); i++)
    {
        int u= findd(vec[i].u);
        int v= findd(vec[i].v);

        if(u!=v)
        {
            par[u]=v;

            int u1= vec[i].u;
            int v1=vec[i].v;
            int w1=vec[i].w;

            adj[u1].push_back(v1);
            edge[u1].push_back(w1);

            adj[v1].push_back(u1);
            edge[v1].push_back(w1);

        }

    }


}

void dfs(int src, int ith)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        int ege= edge[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            dis[ith][node]=dis[ith][src]+ege;

            dfs(node,ith);
        }
    }

}

int main()
{

    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            scanf("%d",&ara[i][j]);

    }


    if(check()==false) {printf("NO\n"); return 0; }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            vec.push_back({ min(i,j), max(i,j), ara[i][j]});

        }
    }


    mst();


    for(int i=1; i<=n; i++)   /// Here is the main tree.
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            printf("%d %d %d\n",i,adj[i][j], edge[i][j]);
        }
    }

    puts("-------");

    for(int i=1; i<=n; i++)     /// N=2009 so , n^2 loop is for determining all pair shortest paths since its a tree
    {
        ms(vis,0);
        vis[i]=1;
        dfs(i,i);
    }


    for(int i=1; i<=n; i++)     /// checking if the given matrix is correct
    {
        for(int j=1; j<=n; j++)
        {
            //printf("%d ",dis[i][j]);
            if(ara[i][j]!=dis[i][j])
            {
                printf("NO\n");
                return 0;
            }
        }
        //puts("");
    }

    printf("YES\n");

    return 0;


}

