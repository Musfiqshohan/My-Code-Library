#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int Graph[104][104], rGraph[104][104],parent[105];
int n;

bool bfs(int s, int t)
{
    bool vis[104];
    memset(vis,0,sizeof vis);

    queue<int>q;
    q.push(s);
    vis[s]=true;
    parent[s]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=1; v<=n; v++)
        {

            if(vis[v]==false  && rGraph[u][v]>0)
            {
                // printf("%d -> %d\n",u,v);
                q.push(v);
                parent[v]=u;
                vis[v]=true;
            }
        }
    }



    return (vis[t] == true);

}

int fordFulkerson(int s, int t)
{
    int u,v;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            rGraph[i][j]=Graph[i][j];
    int max_flow=0;

    while(bfs(s,t))
    {
        int path_flow=INT_MAX;

        for(v=t ; v!=s ; v=parent[v])
        {
            u= parent[v];
            path_flow= min(path_flow,rGraph[u][v]);
        }

        for(v=t; v!=s ; v=parent[v])
        {
            u=parent[v];
            rGraph[u][v]-= path_flow;
            rGraph[v][u]+= path_flow;
        }

        // cout<<path_flow<<endl;

        max_flow+=path_flow;
    }



    return max_flow;



}


int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int s,t,c,u,v,w;

        scanf("%d",&n);
        scanf("%d %d %d",&s,&t,&c);

        for(int i=0; i<c; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            Graph[u][v]+=w;
            Graph[v][u]+=w;
        }


        printf("Case %d: %d\n",++tt,fordFulkerson(s,t));

        memset(Graph,0,sizeof Graph);
        memset(rGraph,0,sizeof rGraph);
        memset(parent,0,sizeof parent);

    }
    return 0;
}

