#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

vector<int>adj[30009];
const int maxL=18;  ///log2(2*1e5)
int Level[30009], par[30009][maxL+5];
void dfs(int src, int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            Level[node]=Level[src]+1;
            par[node][0]=src;
            dfs(node,src);
        }
    }
}


void precomputeSparse(int N)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=0; u<N; u++)
        {
            if(par[u][i-1]!=-1)
                {par[u][i]= par[ par[u][i-1] ][i-1];

               // printf("u=%d %dth= par=%d\n",u,i,par[u][i]);
                }
        }
    }
}


int getLca(int u, int v)
{

    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;
        if(dif>=d)
        {
            dif-=d;
            u=par[u][i];
        }
    }

    if(u==v)
        return u;


    for(int i=maxL; i>=0; i--)
    {
      //  printf("i=%d %d->%d , %d->%d\n",i,u,par[u][i],v,par[v][i]);
        if(par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    }

     return par[u][0];
}

int main()
{
    int n,u,v;
    scanf("%d",&n);

    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ms(par,-1);
    dfs(0,-1);   /// 1 no step


    precomputeSparse(n); /// 2 no step


    while(1){
    cin>>u>>v;
    cout<<getLca(u,v)<<endl;  /// 3 no step
    }




    return 0;
}

