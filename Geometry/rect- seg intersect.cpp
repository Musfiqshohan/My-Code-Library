#include<stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define i64 long long

using namespace std;


struct Point
{
    int x,y;
};

/// q in segment pr?
bool onSegment(Point p, Point q, Point r)
{
    if(q.x<=max(p.x,r.x)&&q.y<=max(p.y,r.y) &&
            q.x>=min(p.x,r.x)&&q.y>=min(p.y,r.y))
        return true;

    return false;

}


int orin(Point p,Point q, Point r)
{
    int val= (q.y-p.y)*(r.x-q.x)
             -(q.x-p.x)*(r.y-q.y);

    //printf("val=%d  p=(%d,%d)  q=(%d,%d)  r=(%d,%d)\n",val,p.x,p.y, q.x,q.y,r.x,r.y);
    if(val==0) return 0;
    return (val>0)? 1:2;
}

bool doIntersect(Point p1,Point q1, Point p2, Point q2)
{
    int o1=orin(p1,q1,p2);
    int o2=orin(p1,q1,q2);

    int o3=orin(p2,q2,p1);
    int o4=orin(p2,q2,q1);

    ///general case
    //cout<<o1<<" "<<o2<<" "<<o3<<" "<<o4<<endl;
    if(o1!=o2 && o3!=o4) return true;

    if(o1==0 && onSegment(p1,p2,q1)) return true;
    if(o2==0 && onSegment(p1,q2,q1)) return true;
    if(o3==0 && onSegment(p2,p1,q2)) return true;
    if(o4==0 && onSegment(p2,q1,q2)) return true;

    return false;
}
int main()
{

    int tt=0;
    cin>>tt;

    while(tt--)
    {

        Point a,b,c,d,x,y;
        cin>>x.x>>x.y>>y.x>>y.y>>d.x>>d.y>>b.x>>b.y;

        a= {d.x,b.y};
        c= {b.x,d.y};


      //  printf("(%d,%d)  (%d,%d)  (%d,%d)  (%d,%d)\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
        int t=doIntersect(a,b,x,y);
        //cout<<t<<endl;


        //return 0;
        t+=doIntersect(b,c,x,y);
        //cout<<t<<endl;
        t+=doIntersect(c,d,x,y);
        //cout<<t<<endl;
        t+=doIntersect(d,a,x,y);
        //cout<<t<<endl;


        ///the inside check

        if(x.x<max(a.x,c.x)&& x.y<max(a.y,c.y) && x.x>min(a.x,c.x) && x.y>min(a.y,c.y) &&
           y.x<max(a.x,c.x)&& y.y<max(a.y,c.y) && y.x>min(a.x,c.x) && y.y>min(a.y,c.y))
            t++;


        if(t>0)
            printf("T\n");
        else printf("F\n");


    }

    return 0;

}


