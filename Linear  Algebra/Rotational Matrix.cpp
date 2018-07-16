///https://www.codechef.com/FEB18/problems/BROCLK
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
#define mod 1000000007
using namespace std;

struct elem
{
    i64 r, i;

    elem operator *(elem &n)
    {
        elem res;
        res.r=(r*n.r)%mod;

        if(i==n.i)
        {
            res.r=(res.r*i)%mod;
            res.i=1;
        }
        else
            res.i=(i*n.i)%mod;

        return res;
    }

    elem operator +(elem &n)
    {
        elem res;
        res.r=((r+n.r)+mod)%mod;
        res.i=n.i;
        return res;
    }
};

struct matrix
{
    elem v[5][5];
    i64 row, col; // number of row and column
} identity;


void pri64_mat(matrix mat)
{
    for(i64 i=0; i<2; i++)
    {
        for(i64 j=0; j<2; j++)
            printf("%lld,%lld  ",mat.v[i][j].r,mat.v[i][j].i);
        puts("");
    }
}


matrix multiply(matrix a, matrix b)
{
    matrix r;

    r.row=a.row;
    r.col=b.col;

    for(i64 i=0; i<r.row; i++)
    {
        for(i64 j=0; j<r.col; j++)
        {
            elem tot= {0,0}, t;
            for(i64 k=0; k<b.row; k++)
            {
                t=a.v[i][k]*b.v[k][j];
                tot=tot+t;
            }

            r.v[i][j]=tot;
        }
    }


    return r;

}



matrix power(matrix mat, i64 p)
{
    if(p==1)
        return mat;

    if(p%2==0)
    {
        matrix ret= power(mat,p/2);
        return multiply(ret,ret);
    }

    return multiply(mat, power(mat,p-1));

}

i64 pow1(i64 x,i64 n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        i64 ret=pow1(x,n/2);
        return  (ret*ret)%mod;
    }
    return (x*pow1(x,n-1))%mod;
}




int main()
{
  //  identity.v[0][0]=identity.v[0][1]=identity.v[1][0]=identity.v[1][1]= {1,1};

    int tt;
    cin>>tt;

    while(tt--)
    {
        i64 L,d,t;
        cin>>L>>d>>t;

        i64 a=(d* pow1(L,mod-2))%mod;

        //  cout<<a<<" "<<a*a<<endl;
        matrix mat;

        elem a00,a01,a10,a11;
        a00= { a,1};
        a01= {-1+mod,((1-(a*a)%mod)+mod)%mod};
        a10= { 1, ((1-(a*a)%mod)+mod)%mod};
        a11= { a,1};

        // cout<<"-->"<<(((2*a*a)%mod-1)*L)%mod<<endl;

        mat.row=mat.col=2;
        mat.v[0][0]=a00;
        mat.v[0][1]=a01;
        mat.v[1][0]=a10;
        mat.v[1][1]=a11;

        mat= power(mat,t);
        // pri64_mat(mat);

        i64 res= (mat.v[0][0].r*L)%mod;

        cout<<res<<endl;

    }


}


