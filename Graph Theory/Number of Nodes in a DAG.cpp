///https://www.hackerrank.com/contests/accel-hack/challenges/acyclic-graph
#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

const int MAXN=5*10009;
vector<int>adj[MAXN];
int keeps[MAXN],vis[MAXN];


bitset<5*10009>bset[50009];

void dfs(int src)
{
    vis[src]=1;

    for(int i=0;i<adj[src].size();i++)
    {
        int nd=adj[src][i];
        if(vis[nd]==0)
        {
            dfs(nd);
            bset[src]|=bset[nd];
        }
        else bset[src]|=bset[nd];
    }

    bset[src][src]=1;
}

int main()
{
    int n,m,res=0,u,v;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++)
    {

        dfs(i);
        int ret=bset[i].count();
        if(ret*2>=n) res++;
    }

   printf("%d\n",res);

    return 0;
}

/*
5 5
1 2
1 5
2 3
5 3
3 4

7 7
1 2
1 3
2 4
3 5
4 6
5 6
6 7*/
