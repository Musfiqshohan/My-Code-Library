///using pbds  each operation in logn and this is using structure for any number of keys

#include<bits/stdc++.h>

///These are for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
#define MP(x,y) make_pair(x,y)


using namespace std;
using namespace __gnu_pbds;


struct info
{
    int solved,penalty,efficiency;
};

typedef pair<info,int>PI;
//
typedef tree<PI,null_type, less<PI>, rb_tree_tag,
tree_order_statistics_node_update> set_t;
//
const int mx=1e5+10;
int ps[mx],pp[mx],pe[mx];
//
inline bool operator<(const info& lhs, const info& rhs)
{
    if(lhs.solved==rhs.solved)
    {
        if(lhs.penalty==rhs.penalty)
            return lhs.efficiency>rhs.efficiency;
        return lhs.penalty<rhs.penalty;
    }
    return lhs.solved>rhs.solved;
}

int main()
{
    set_t s;

    int n,m,t,p,e;

    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        info a;
        a= {0,0,0};
        s.insert(MP(a,i+1));
    }

    rep(i,m)
    {
        cin>>t>>p>>e;
        info a;
        a= {ps[t],pp[t], pe[t]};
        s.erase(MP(a,t));


        ps[t]++;
        pp[t]+=p;
        pe[t]+=e;


        a= {ps[t],pp[t], pe[t]};
        s.insert(MP(a,t));


        a= {ps[1],pp[1],pe[1]};
        cout<<s.order_of_key(MP(a,1))+1<<endl;

    }

//    set_t ::iterator it;
//    for(it=s.begin(); it!=s.end();it++)
//    {
//        info a= it->first;
//        int per=it->second;
//        cout<<a.solved<<" "<<a.penalty<<" "<<a.efficiency<<" "<<per<<endl;
//    }


    return 0;
}

