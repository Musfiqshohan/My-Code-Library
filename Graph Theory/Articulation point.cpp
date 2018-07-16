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

vector<int>adj[10009];
int discTime=0, low[10009], disc[10009];
bool isAp[10009];

void dfs_findAp(int src, int parent)
{
    low[src]= disc[src]= ++ discTime;

    int child=0;

    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];

        if(!disc[node])
        {
            child++;

            dfs_findAp(node, src);

            low[src]= min(low[src], low[node]);

            if(parent==-1 && child>1)    isAp[src]=true;
            if(parent!=-1 && low[node]>=disc[src])  isAp[src]=true;


        }
        else if( node!=parent)
        {
            low[src]= min(low[src], disc[node]);
        }


    }
}

int main()
{

    int n,m,u,v;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //dfs_findAp(0,-1);

    for(int i=0;i<n;i++)
    {
        if(disc[i]==0)
        {
            dfs_findAp(i,-1);
        }
    }


    for(int i=0;i<n;i++)
    {
       if(isAp[i]==true)
         printf("%d\n",i);
    }

}
