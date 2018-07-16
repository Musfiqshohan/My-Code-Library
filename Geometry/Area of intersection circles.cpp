#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;

struct circle
{
    double x,y,r;
};

double distance(int x1, int y1, int x2, int y2 )
{
    double d=(x1-x2)*(x1-x2) +(y1-y2)*(y1-y2);
    d= sqrt(d);
    return d;
}

double CosineRule(double b, double c, double a)
{	
    return (b*b + c*c - a*a)/ (2*b*c);
}

double section(double r, double theta)
{
    return r*r*0.5 * (theta- sin(theta));
}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        circle c1,c2;
        cin>>c1.x>>c1.y>>c1.r>>c2.x>>c2.y>>c2.r;

        double area=0,area1=0,area2=0;

        double d=distance(c1.x,c1.y,c2.x,c2.y);

        if(c1.r+c2.r<=d)
        {
            area=0;
        }
        else if(d+ min(c1.r,c2.r) <= max(c1.r,c2.r))
        {
            area= min( pi*c1.r*c1.r, pi*c2.r*c2.r );
        }
        else
        {

            double theta= CosineRule(c1.r,d,c2.r);
            theta= acos(theta);
            theta*=2;
            area1= section(c1.r,theta);

            theta= CosineRule(c2.r,d,c1.r);
            theta= acos(theta);
            theta*=2;
            area2= section(c2.r, theta);

            area= area1+area2;

        }
       // cout<<area<<endl;

        printf("Case %d: %.10f\n",++tt,area);
    }

    return 0;
}

