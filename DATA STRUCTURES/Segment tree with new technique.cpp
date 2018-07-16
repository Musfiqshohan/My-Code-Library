#include<bits/stdc++.h>
///http://codeforces.com/problemset/problem/914/D

/// here instead of query and decide which child to go,, first go to that range then use the lc, rc val to decide
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

const int MAXN=500009;
int n,foundIdx,foundVal;
int tree[MAXN*4], ara[MAXN];


void init(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]=ara[beg];
        return ;
    }


    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    init(left,beg,mid);
    init(right,mid+1,endd);

    tree[node]=__gcd(tree[left], tree[right]);
}



void  update(int node, int beg, int endd, int x, int val)
{
    if(beg==x &&endd==x)
    {
        tree[node]=val;
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    if(x<=mid) update(left, beg, mid, x, val);
    else update(right, mid+1, endd, x, val);

    tree[node]=__gcd(tree[left],tree[right]);
}


int query2(int node, int beg, int endd, int i, int j)
{
    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j)
    {
        return tree[node];
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    int t1=query2(left, beg, mid, i,j);
    int t2=query2(right, mid+1,endd,i,j);

    return __gcd(t1,t2);

}




void  query(int node, int beg, int endd, int i, int j, int flag, int x)
{


    if(beg>j || endd<i ) return ;


    if(beg>=i && endd<=j)
    {

        if(tree[node]%x==0)
            return ;

        if(foundIdx!=-1) return;
        flag=1;
    }

    if(beg==endd)
    {
        foundIdx=beg;
        foundVal=tree[node];
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    int t1,t2;
    if(flag==0)
    {
        query(left,beg,mid,i,j,flag,x);
        query(right,mid+1,endd,i,j,flag,x);
    }
    else
    {
        int lg=tree[left];
        int rg=tree[right];

        if(lg%x!=0)
            query(left,beg, mid, i,j,flag,x);
        else query(right,mid+1,endd,i,j,flag,x);
    }

}


int main()
{
    int l,r,x,q,cs,y;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);

    init(1,0,n-1);


    scanf("%d",&q);

    while(q--)
    {


        scanf("%d",&cs);

        if(cs==1)
        {
            scanf("%d %d %d",&l,&r,&x);

            foundIdx=-1;
            query(1,0,n-1,l-1,r-1,0,x);

            if(foundIdx==-1)
                printf("YES\n");
            else
            {

                update(1,0,n-1,foundIdx,x);
                int res=query2(1,0,n-1,l-1,r-1);


                if(res%x==0)
                    printf("YES\n");
                else
                    printf("NO\n");
                update(1,0,n-1,foundIdx,foundVal);
            }


        }
        else
        {
            scanf("%d %d",&x,&y);
            update(1,0,n-1,x-1,y);
        }

    }

    return 0;
}

