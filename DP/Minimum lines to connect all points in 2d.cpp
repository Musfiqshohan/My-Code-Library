#include<bits/stdc++.h>
using namespace std;

int Set(int N, int pos)
{
    return N=N|(1<<pos);
}
int reset(int N, int pos)
{
    return N= N&~(1<<pos);
}
bool Check(int N, int pos)
{
    return (bool)(N&(1<<pos));
}

struct point
{
    int x, y;
} ara[17];
int Armask[17][17], dp[(1<<17)+5];
int n;

void clearr()
{
    memset(Armask,0,sizeof Armask);


}

double length(point a, point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)  + (a.y-b.y)*(a.y-b.y) );
}

void make_mask(int i, int j,point a, point b)
{
    int mask=0;
    double lenAB=length(a,b);

    //cout<<a.x<<","<<a.y<<" "<<b.x<<","<<b.y<<"="<<endl;

    for(int i=0; i<n; i++)
    {
        double l1= length(ara[i],a);
        double l2= length(ara[i],b);

        double a[3]= { lenAB, l1,l2 };
        sort(a,a+3);

        // printf("for %d th =%.2f %.2f = %.2f?\n",i, a[0],a[1],a[2]);
        if( fabs(a[0]+a[1] - a[2])<0.000000001 )
        {
            //printf("YES\n");
            mask=Set(mask,i);

        }
        //else printf("NO\n");


    }

    // printf("mask=%d\n",mask);
    Armask[i][j]=mask;

}


int f(int mask)
{



    if(mask==(1<<n)-1) return 0;

    int c=0;
    for(int i=0;i<n;i++)
        c+=!Check(mask,i);
    if(c<=2) return 1;


    if(dp[mask]!=-1) return dp[mask];


    int mn=100000000,ret=0;
    for(int i=0; i<n; i++)
    {
        if(Check(mask,i)) continue;

        for(int j=i+1; j<n; j++)
        {

            if( Check(mask,j)==0)
            {
                int temp= Armask[i][j];
                temp= temp|mask;
               // printf("%d and %d =mask->%d\n",i,j,temp);
                ret= 1+ f(temp);
                mn= min(ret,mn);
            }
        }
        break;
    }

    return dp[mask]=mn;

}
int main()
{
    int t=0,test;

    scanf("%d",&test);

    while(t<test)
    {
        //memset(Armask,-1,sizeof Armask);
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //if(i==j) continue;
                make_mask(i,j, {ara[i].x, ara[i].y }, {ara[j].x, ara[j].y});
                //printf("%d to %d = %d\n",i,j,Armask[i][j]);
            }
        }



        printf("Case %d: %d\n",++t,f(0));
        clearr();

    }


    return 0;
}



