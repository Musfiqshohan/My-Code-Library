 ///By MusfiqxShohan, contest: Codeforces Beta Round #91 (Div. 1 Only), problem: (E) Lucky Array, Accepted, #

#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


int ara[100002], store[320][10002], added[320];
bool lucky_ara[10002];

int lucky[]= {4,7,44,47,74,77, 444,447,474,477,744,747,774,777,
              4444,4447,4474,4477,4744,4747,4774,4777,
              7444,7447,7474,7477,7744,7747,7774,7777
             };
int b_size;




void update(int l, int r, int val)
{

    int cur_buck;
    while(l<r and l%b_size!=0 and l!=0)
    {
        cur_buck= l/b_size;

        store[cur_buck][ara[l]]--;
        store[cur_buck][ara[l]+val]++;
        ara[l]+=val;

        l++;
    }

    while(l+b_size<=r)
    {
        cur_buck= (l/b_size);
        added[cur_buck]+=val;

        l+= b_size;
    }

    while(l<=r)
    {
        //printf("hello %d\n",l);
        cur_buck= l/b_size;
        store[cur_buck][ara[l]]--;
        store[cur_buck][ara[l]+val]++;
        ara[l]+=val;

        l++;
    }

}


int lucky_in_buck(int id, int sum)
{
    int tot=0;
    for(int i=0; lucky[i]; i++)
    {
        if(lucky[i]-sum>=0)
        {
            tot+=store[id][lucky[i]-sum];
        }

    }

    return tot;
}

int query(int l, int r)
{
    int cnt=0;
    while(l<r and l%b_size!=0 && l!=0)
    {
        if(lucky_ara[ara[l]+added[l/b_size]]==true)
            cnt++;
        l++;
    }



    while(l+b_size<=r)
    {

        cnt+=lucky_in_buck(l/b_size, added[l/b_size]);
        l+=b_size;
    }

    while(l<=r)
    {


        if(lucky_ara[ara[l]+added[l/b_size]]==true)
            cnt++;
        l++;
    }

    return cnt;
}

void make_bucket(int n)
{
    int b_indx=-1;

    b_size=sqrt(n);

    loop(i,n)
    {

        if(i%b_size==0)
            b_indx++;

        store[b_indx][ara[i]]++;
    }

}
int main()
{


    for(int i=0; lucky[i]; i++) lucky_ara[lucky[i]]=true;

    int n,m;
    scanf("%d %d",&n,&m);

    loop(i,n)
    {
        scanf("%d",&ara[i]);
    }


    make_bucket(n);

    int l,r,val;



    char str[5];
    loop(i,m)
    {
        scanf("%s",&str);
        if(strlen(str)==5)
        {
            scanf("%d %d",&l,&r);

            printf("%d\n",query(l-1,r-1));
        }
        else
        {
            scanf("%d %d %d",&l,&r,&val);
            update(l-1,r-1,val);
        }
    }


    return 0;
}

