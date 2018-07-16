
int matchR[55],Graph[55][55];
bool vis[55];
struct person
{
    int h,a,d;
} mp[55], fp[55];


bool bpm(int u, int m)  // for each node,  match with m elements in 2nd set
{
    for(int v=1;v<=m;v++)
    {
        if(Graph[u][v]==1 && vis[v]==false)
        {
            vis[v]=true;

            if(matchR[v]<0 || bpm(matchR[v],m))
            {
                matchR[v]=u;
                return true;
            }

        }
    }

    return false;
}


int maxBPM(int n, int m)  // n= number in 1st set,  m is # in another set
{
    memset(matchR, -1, sizeof matchR);

    int result=0;
    for(int u=1;u<=n;u++)
    {
        memset(vis,0,sizeof vis);

        if(bpm(u,m))
            result++;
    }

    return result;
}
