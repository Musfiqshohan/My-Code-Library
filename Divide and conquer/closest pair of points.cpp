#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;
} ;


bool cmp1(Point a, Point b)
{
    return a.x<b.x;
}

bool cmp2(Point a, Point b)
{
    return a.y<b.y;
}

double dist(Point p1, Point p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) +
                 (p1.y-p2.y)*(p1.y-p2.y)
               );
}

double bruteForce(Point P[], int n)
{
    double mini=FLT_MAX;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            mini= min(mini, dist(P[i],P[j]));

    return mini;

}

double stripClosest(Point strip[], int n, double d)
{
    double mini=d;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n && (strip[j].y-strip[i].y)<mini; j++)
        {
            if(dist(strip[j],strip[i])<mini)
                mini= dist(strip[j],strip[i]);

        }
    }

    return mini;
}

double closestUtil(Point Px[], Point Py[], int n)
{
    if(n<=3)
        return bruteForce(Px,n);


    int mid= n/2;
    Point midPoint= Px[mid];

    Point Pyl[mid+1];
    Point Pyr[n-mid+1];

    int li=0,ri=0;
    for(int i=0; i<n; i++)
    {
        if(Py[i].x<=midPoint.x)
            Pyl[li++]=Py[i];
        else Pyr[ri++]=Py[i];
    }

    double dl=closestUtil(Px,Pyl,mid);
    double dr=closestUtil(Px+mid,Pyr, n-mid);

    double d=min(dl,dr);

    Point strip[n];

    int j=0;
    for(int i=0; i<n; i++)
    {
        if(abs(Py[i].x-midPoint.x)<d)
            strip[j++]=Py[i];
    }


    double ret= min(d, stripClosest(strip,j,d));
   // cout<<ret<<" "<<d<<endl;
    return ret;


}
double closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];

    for(int i=0; i<n; i++)
    {
        Px[i]=P[i];
        Py[i]=P[i];
    }

    sort(Px, Px+n,cmp1);
    sort(Py, Py+n, cmp2);

    return closestUtil(Px,Py,n);
}

int main()
{
    Point P[]= {{2,3}, {12,30}, {40,50},{5, 1}, {12, 10}, {3, 4} };
    int n= sizeof(P)/ sizeof(P[0]);


    cout<<"The smallest distance :"<<closest(P,n)<<endl;
    return 0;

}
