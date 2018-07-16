#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;
}p0;


Point nextToTop(stack<Point>&S)
{
    Point p=S.top();
    S.pop();
    Point res= S.top();
    S.push(p);

    return res;
}

int calc_dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int res= (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);

   if(res==0) return 0;
   return (res>0)? 1:2;  /// clock or counterclock wise

}
bool compare(Point a, Point b)
{
    int o=orientation(p0,a,b);

    if(o==0)
        return  calc_dist(p0,a)< calc_dist(p0,b);

    if(o==2)
        return true;  /// in ccw 2nd case so  ok no  swap needed
    else return false;  /// not ok swap is

}

void convexHull(Point points[], int n)
{
    int miny=1e9,mini=0;

    for(int i=0; i<n; i++)
    {
        int y=points[i].y;
        if((y<miny) || (y==miny && points[i].x<points[mini].x))
        {
            miny=y;
            mini=i;
        }
    }

    swap(points[0],points[mini]);

    p0=points[0];

    sort(points+1, points+n, compare);

    int m=1;

    for(int i=1;i<n;i++)
    {
       // printf("%d %d\n",points[i].x,points[i].y);
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0)
            i++;

        points[m]=points[i];
        m++;
    }


    if(m<3) return;

    stack<Point>S;

    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);


    for(int i=3;i<m;i++)
    {

        while(orientation(nextToTop(S),S.top(),points[i])!=2)
            S.pop();

        S.push(points[i]);
    }


    while(!S.empty())
    {
        Point p= S.top();
        printf(" (%d,%d)\n",p.x,p.y);
        S.pop();
    }

}


int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
