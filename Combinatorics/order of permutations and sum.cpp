///https://www.quora.com/How-do-you-do-addition-with-factorials

#include<bits/stdc++.h>
using namespace std;

int ara1[200009],ara2[200009], tree[4*200009], sum[200009];

void build(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]=1;
        return ;
    }
    int mid= (beg+endd)/2;
    int left= node*2;
    int right= node*2 +1;
    build(left, beg, mid);
    build(right, mid+1, endd);
    tree[node]= tree[left]+ tree[right];
}

int query1(int node, int beg, int endd, int x, int y)
{
    if(beg>y || endd<x) return 0;
    if(beg>=x && endd<=y)
        return tree[node];


    int mid= (beg+endd)/2;
    int left= node*2;
    int right= node*2 +1;

    int t1=query1(left, beg, mid, x,y);
    int t2=query1(right, mid+1, endd, x,y);
    return t1+t2;
}

int query2(int node, int beg, int endd, int x)
{
    if(beg==endd && x==tree[node])
    {
        tree[node]=0;
        return beg;

    }
    int mid= (beg+endd)/2;
    int left= node*2;
    int right= node*2 +1;

    int t;
    if(x>tree[left])
        t= query2(right, mid+1, endd, x-tree[left]);
    else t= query2(left, beg, mid, x);

    tree[node]=tree[left]+tree[right];

    return t;

}

void update(int node, int beg, int endd, int x)
{
    if(beg==endd && beg==x)
    {
        tree[node]=0;
        return;
    }
    int mid= (beg+endd)/2;
    int left= node*2;
    int right= node*2 +1;

    if(x<=mid)
        update(left, beg, mid, x);
    else update(right, mid+1, endd, x);

    tree[node]= tree[left]+tree[right];

}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&ara1[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&ara2[i]);

    build(1, 0, n-1);

    for(int i=0; i<n; i++)
    {
        int ret= query1(1, 0, n-1, 0, ara1[i])-1;
        update(1,0,n-1, ara1[i]);
        sum[i]+=ret;
    }

    build(1,0,n-1);

    for(int i=0; i<n; i++)
    {
        int ret= query1(1, 0, n-1, 0, ara2[i])-1;
        update(1,0,n-1, ara2[i]);
        sum[i]+=ret;
    }

    for(int i=n-1; i>0; i--)
    {
        int yy= n-i;
        int div= sum[i]/(yy);
        sum[i]%=yy;

        sum[i-1]+=div;
    }

    sum[0]= sum[0]%(n);


    build(1,0,n-1);
    vector<int>vec;
    for(int i=0; i<n; i++)
    {
        int ret= query2(1,0,n-1,sum[i]+1);

        vec.push_back(ret);
    }


    for(int i=0;i<vec.size();i++)
        printf("%d ",vec[i]);

    puts("");



    return 0;
}

