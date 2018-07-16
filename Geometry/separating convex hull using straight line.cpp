///http://www.spoj.com/problems/DOORSPEN/en/

/// separate two convex hulls using one straight line

#include<bits/stdc++.h>
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
using namespace std;
int d,p;
struct Points
{
    int x,y;
} p0;
vector<Points>pnts1,pnts2;


Points mp(int x,int y)
{
    Points ret;
    ret.x=x;
    ret.y=y;
    return ret;
}

int calc_dist(Points a, Points b)
{
    return (a.x-b.x)*(a.x-b.x)  + (b.x-b.y)*(b.x-b.y);
}

int orientation(Points a, Points b, Points c)
{
    int res= (c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x);

    if(res==0)
        return 0;

    if(res>0) return -1;
    else return +1;

}

bool comaprePoints(Points a, Points b)
{
    int ret=orientation(p0,a,b);

    if(ret==0)
        return calc_dist(p0,a)<calc_dist(p0,b);

    return (ret==-1)? true: false;
}
Points nextToTop(stack<Points> &stk)
{
    Points temp=stk.top();
    stk.pop();
    Points ret= stk.top();
    stk.push(temp);
    return ret;
}

bool isSeparatingAxis(Points a, Points b,vector<Points>&ara1,vector<Points>&ara2)
{

    int sign=orientation(a,b,ara2[0]);
    loop(i,ara2.size())
    {
        if(orientation(a,b,ara2[i])!=sign)
            return false;
    }

    loop(i, ara1.size())
    {
        if(orientation(a,b,ara1[i])==sign)
            return false;
    }


    return true;
}

bool Convexhull(vector<Points>&ara1, vector<Points>&ara2, int n)
{
    int miny=1e8,mni=0;

    loop(i,n)
    {
        if(ara1[i].y<miny || (ara1[i].y==miny && ara1[i].x<ara1[mni].x))
        {
            miny=ara1[i].y;
            mni=i;
        }
    }


    swap(ara1[0], ara1[mni]);
    p0=ara1[0];

    sort(ara1.begin()+1,ara1.end(), comaprePoints);

    vector<Points>vec;


    vec.push_back(p0);  ///remove co linear from p0
    for(int i=0; i<n; i++)
    {
        while(orientation(p0,ara1[i],ara1[i+1])==0  && i+2<n)
            i++;

        vec.push_back(ara1[i]);
        // printf("__%d %d\n",vec.back().x,vec.back().y);

    }

    stack<Points>stk;

    stk.push(vec[0]);
    stk.push(vec[1]);
    stk.push(vec[2]);

    for(int i=3; i<vec.size(); i++)
    {

        while(orientation(nextToTop(stk), stk.top(), vec[i])==+1)
            stk.pop();

        stk.push(vec[i]);

    }

    Points last=stk.top();



    while(stk.size()>1)
    {
        Points top1= stk.top(), top2=nextToTop(stk);
     //   printf("-> %d %d with %d %d\n",stk.top().x, stk.top().y, top2.x, top2.y);
        if(isSeparatingAxis(top1,top2,ara1,ara2)==true)
        {
            // printf("got= %d %d , %d %d\n",top1.x, top1.y, top2.x,top2.y);
            return true;
        }
        stk.pop();
    }

  //  printf("-> %d %d, %d %d\n",p0.x, p0.y, last.x, last.y);
    if(isSeparatingAxis(p0,last,ara1,ara2)==true)
        {
           // printf("->got  %d %d, %d %d\n",p0.x, p0.y, last.x, last.y);
            return true;
        }

    while(!stk.empty())
    stk.pop();
    vec.clear();

    return false;

}


int main()
{
    int test=0;

    while(scanf("%d %d",&d,&p)==2)
    {
        if(d==0 && p==0) return 0;

        if(test)
            puts("");
        int x1,y1,x2,y2;
        loop(i,d)
        {
            scanf("%d %d %d %d",&x1, &y1, &x2,&y2);
            pnts1.pb(mp(x1,y1)),pnts1.pb(mp(x2,y2)), pnts1.pb(mp(x1,y2)), pnts1.pb(mp(x2,y1));
        }
//
        loop(i,p)
        {
            scanf("%d %d %d %d",&x1,  &y1, &x2,&y2);
            pnts2.pb(mp(x1,y1)),pnts2.pb(mp(x2,y2)), pnts2.pb(mp(x1,y2)), pnts2.pb(mp(x2,y1));

        }

        int res1=0, res2=0;

        res1=Convexhull(pnts1, pnts2,pnts1.size());
        res2=Convexhull(pnts2,pnts1, pnts2.size());

        //printf("res1= %d  res2=%d\n",res1,res2);

        if(res1==1 || res2==1)
            printf("Case %d: It is possible to separate the two groups of vendors.\n",++test);
        else printf("Case %d: It is not possible to separate the two groups of vendors.\n",++test);

        pnts1.clear(),pnts2.clear();

    }

    return 0;
}

