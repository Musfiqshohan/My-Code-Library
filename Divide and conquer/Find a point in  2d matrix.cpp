#include<bits/stdc++.h>
using namespace std;
int ara[20][20];

///T(n) = 3T(n/2) + O(1)    O(n^1.58)


void f(int r1, int c1, int r2, int c2, int key)
{

    int midr=(r2-r1)/2;
    midr+=r1;
    int midc=(c2-c1)/2;
    midc+=c1;

    if(ara[midr][midc]==key)
    {
        printf("found at %d %d\n",midr, midc);
        return;
    }

    if(r1==r2 && c1==c2) return;

    if(ara[midr][midc]<key)
    {
        if(midr+1<=r2)
            f(midr+1, c1, r2, c2,key);

        if(midc+1<=c2)
            f(r1, midc+1, midr, c2,key);
    }
    else
    {
        if(midc-1>=c1)
            f(r1,c1,r2,midc-1,key);

        if(midr-1>=r1)
            f(r1,midc, midr-1, c2,key);
    }

}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&ara[i][j]);
    }

    int key;

    while(1) {
    scanf("%d",&key);

    f(0,0,n-1,n-1, key);
    }

    return 0;
}
