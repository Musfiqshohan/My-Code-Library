#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;
int ara[25][25];
vector<string>name;
int main()
{
    int t=0;

    int n,m,u,v,w   ;
    while(1){
    scanf("%d %d",&n,&m);

    if(m==0 && n==0 ) break;

    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        name.push_back(str);
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ara[i][j]= (i==j)? 0:100009;


    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        ara[u][v]=w;
        ara[v][u]=w;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(ara[i][k]+ara[k][j]<ara[i][j])
                    ara[i][j]=ara[i][k]+ara[k][j];

    int mn=100000,mni=0;

    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++)
            {
                sum+=ara[i][j];
                //printf("%d ",ara[i][j]);

            }
        if(sum<mn) { mn=sum; mni=i; }
       //    puts("");
    }

    printf("Case #%d : ",++t);
    cout<<name[mni-1]<<endl;

    ms(ara,0);
    name.clear();


    }

    return 0;
}
