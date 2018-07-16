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

set<pii>bridge;
vector<int>adj[100009];
int low[100009],disc[100009],par[100009],vis[100009], times;
void dfs1(int src)
{
    disc[src]=low[src]=++times;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0 && node!= par[src])
        {
            par[node]=src;
            vis[node]=1;

            dfs1(node);

            low[src]= min(low[src], low[node]);

            if(low[node]> disc[src])
            {
                bridge.insert({ min(src,node), max(src,node) });
                // prllf("%d -> %d\n",src, node);
            }
        }
        else if(node!= par[src])
        {
            low[src]= min(low[src], disc[node]);
        }
    }
}
int main()
{

}
