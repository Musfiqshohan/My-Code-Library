///Rotating around A then around B, is not same as rotating around B then around A
#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 100000000000000000
#define mod 1000000007
#define i64 long long
using namespace std;

struct info
{
    int Px,Py,ang;
} ara[100009];


struct matrix
{
    int row,col;
    i64 v[3][3];
} I, T[4*100009];

int COS[5]= {1,0,-1,0,1};  ///-2
int SIN[5]= {0,1,0,-1,0};


void print(i64 a[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%lld ",a[i][j]);
        puts("");
    }
    puts("");
}

matrix make(info a)    ///-1
{
    matrix r;
    r.col=r.row=3;

    int ct=COS[a.ang/90];   ///-3
    int st=SIN[a.ang/90];

    r.v[0][0]=ct,  r.v[0][1]=-st,  r.v[0][2]=(1-ct)*a.Px+ st*a.Py;
    r.v[1][0]=st,  r.v[1][1]=ct,  r.v[1][2]=(1-ct)*a.Py- st*a.Px;
    r.v[2][0]=0,  r.v[2][1]=0,  r.v[2][2]=1;

    return r;
}


matrix multiply(matrix a, matrix b)   ///0
{
    matrix r;
    assert(a.col==b.row);
    r.row=a.row, r.col=b.col;
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            i64 sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];
                sum= (sum+mod)%mod;
            }
            r.v[i][j]=sum;
        }
    }
    return r;
}

void build(int nd, int l, int r)   ///1
{
    if(l==r)
    {  // printf("l= %d  nd=%d\n",l,nd);
        T[nd]=make(ara[l]);
        return ;
    }

    int mid=(l+r)/2;
    int lc=nd*2;
    int rc=nd*2+1;

    build(lc,l,mid);
    build(rc,mid+1,r);

    T[nd]=multiply(T[rc],T[lc]);  ///reversed

}

void update(int nd, int l, int r, int idx, info val)  ///2
{

    if(l==r)
    {
        T[nd]=make(val);
        return ;
    }

    int mid=(l+r)/2;
    int lc=nd*2;
    int rc=nd*2+1;

    if(idx<=mid)
        update(lc, l,mid, idx, val);
    else update(rc,mid+1,r,idx,val);

    T[nd]=multiply(T[rc],T[lc]);   ///reversed
}


matrix query(int nd, int l, int r, int  beg, int en)    ///3
{
    if(r<beg || l>en) return I;

    if(l>=beg && r<=en)
        return T[nd];

    int mid=(l+r)/2;
    int lc=nd*2;
    int rc=nd*2+1;

    matrix t1=query(lc,l,mid, beg,en);
    matrix t2=query(rc,mid+1,r,beg,en);

    return multiply(t2,t1);     ///reversed
}




int main()
{

    I.row=3,I.col=3;

    for(int i=0; i<3; i++) I.v[i][i]=1;


    int n,x,y,ang,u,b,l,r,cs;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&x,&y,&ang);
        ara[i]= {x,y,ang};
    }

    build(1,0,n-1);


//    print(T[2].v);

    int q;
    cin>>q;

    while(q--)
    {
        cin>>cs;

        if(cs==1)
        {
            cin>>x>>y>>l>>r;
            matrix ret=query(1,0,n-1,l-1,r-1);

           // print(ret.v);
            matrix p;
            p.row=3, p.col=1;
            p.v[0][0]=x,  p.v[1][0]=y,  p.v[2][0]=1;

            ret=multiply(ret,p);

            cout<<ret.v[0][0]<<" "<<ret.v[1][0]<<endl;

        }
        else
        {
            cin>>u>>x>>y>>b;
            update(1,0,n-1, u-1, {x,y,b});

        }
    }



    return 0;
}

