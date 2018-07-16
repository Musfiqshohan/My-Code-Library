#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(b,"w",stdout)
using namespace std;
vector<ll>adj[28];
string str;
ll val[28];
ll BFS()
{

    queue<ll>q;
    ll inq[28]= {}, dist[28]= {};
    ll cnt[28]= {};
    for(ll i=0; i<26; i++)
    {
        q.push(i);  //inq[i]=1
        dist[i]=1;
    }


    while(!q.empty())
    {
        ll src= q.front();
        q.pop();
        inq[src]=0;

        for(ll i=0; i<adj[src].size(); i++)
        {
            ll node= adj[src][i];

            if(dist[node]<dist[src]+1)
            {
                dist[node]=dist[src]+1;

                if(inq[node]==0)
                {
                    inq[node]=1;
                    q.push(node);
                    if(++cnt[node]>26)
                        return 0;
                }
            }

        }

    }


    for(ll i=0; i<26; i++) val[i]=dist[i];

    return 1;

}

ll dp[405][405], vis[405][405];

ll f(ll l, ll r)
{
    if(l==r)
    {

        return val[str[l]-'a'];
    }

    if(vis[l][r]==1) return dp[l][r];
    vis[l][r]=1;

    ll brac=0,test=0;
    ll ret=inf;

    for(ll i=l; i<=r; i++)
    {
        if(str[i]=='(') brac++;
        if(str[i]==')') brac--;

        if(brac==0 && str[i]=='+')
        {
            ret= min(ret, f(l,i-1) +  f(i+1,r));
            test++;
        }

        if(brac==0 && str[i]=='*')
        {
            ret= min( ret, f(l,i-1)* f(i+1,r) );
            test++;
        }

    }



    if(test==0)
    {
        ret=min(ret, f(l+1,r-1));
    }

    return dp[l][r]=ret;

}


int main()
{

//    in("input11724.txt");
//    out("output11724.txt");


    int test,t=0;
    cin>>test;

    while(t<test)
    {

        ms(vis,0);


        string ss;
        cin>>str;

        ll n;
        scanf("%lld",&n);

        for(ll i=0; i<n; i++)
        {
            cin>>ss;

            adj[ss[2]-'a'].push_back(ss[0]-'a');

        }

        printf("Case %d: ",++t);

        if(BFS()==0)
            printf("-1\n");
        else  printf("%lld\n",f(0,str.length()-1));

        for(int i=0; i<26; i++) adj[i].clear();


    }

    return 0;
}
