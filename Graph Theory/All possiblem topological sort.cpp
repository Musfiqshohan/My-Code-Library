#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>adj[1009];
stack<int>stk;
ll total=1;
ll dp[1009][1009], vis[1009];
ll mod=1000000007;

void clearr(int n)
{
    total=1;
    ms(vis,0);
    for(int i=1;i<=n;i++) adj[i].clear();

}

ll nCr(int n, int r)
{
    if(r==0 || n==r) return 1;
    if(r==1) return n;

    if(dp[n][r]!=-1) return dp[n][r];

    return dp[n][r]= (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

ll f1(int n, int k)
{
    return nCr(n+k, k);
}

void dfs1(int src)
{

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            dfs1(node);
        }

    }

    stk.push(src);

}


int dfs2(int src)
{
    int tot_nodes=0;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        int decend=0;

        if(vis[node]==0)
        {
            vis[node]=1;
            decend= dfs2(node);

            if(tot_nodes!=0)
            total= (total * f1(tot_nodes,decend))%mod;
        }

        tot_nodes+= decend;

    }

    tot_nodes++;

    return tot_nodes;

}


int main()
{

    in("1382 - The QueueI.txt");
    out("1382 - The QueueO.txt");


    ms(dp,-1);
    for(int i=1;i<=1006;i++)
    {
        for(int j=1;j<=1006;j++)
            dp[i][j]= nCr(i,j);
    }



    int tt=0,test;
    cin>>test;

    while(tt<test) {

    int n,u,v;
    scanf("%d",&n);

    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
    }


    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;

            dfs1(i);
        }
    }

    ms(vis,0);
    while(!stk.empty())
    {
        int src= stk.top();

        int tot_nodes=0;

        if(vis[src]==0)
        {

            int decend= dfs2(src);

            if(tot_nodes!=0)
            total= (total * f1(tot_nodes,decend))%mod;
            tot_nodes+= decend;

        }

        stk.pop();

    }

    printf("Case %d: %lld\n",++tt, total);

    clearr(n);

    }

    return 0;
}
