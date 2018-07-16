#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define i64 long long
using namespace std;

#define AS 2
struct node
{

    i64 endmarks, value;
    node* next[AS+2];
    i64 cnt[AS+2];

    node()
    {
        endmarks=0;
        for(i64 i=0;i<=AS;i++){
            next[i]=NULL;
            cnt[i]=0;
        }
    }
};

node* root;


i64 pri64(i64 id,i64 no)
{
    if(id==1)
    {
        printf("at no=%lld\n",no*2);
        no=no*2;
    }
    else
    {
        printf("at no=%lld\n",no*2+1);
        no=no*2+1;
    }

    return no;
}


void Insert(string str)
{

    node* cur=root;
    i64 no=1, l= str.size();
    for(i64 i=0; i<l; i++)
    {
        i64 id=str[i]-'0';

        if(cur->next[id]==NULL)
            cur->next[id]= new node();

        cur->cnt[id]++;
        cur=cur->next[id];
    }

    cur->endmarks++;

}


void Remove(string str)
{
    node* cur=root;
    i64 no=1, l= str.size();

    for(i64 i=0; i<l; i++)
    {
        i64 id=str[i]-'0';
        cur->cnt[id]--;
        cur=cur->next[id];
    }

    cur->endmarks--;

}

i64 Search(string str)
{
    node* cur=root;
    i64 l=str.size();
    i64 res=0;


    for(i64 i=0;i<l;i++)
    {
        i64 id=str[i]-'0';
        i64 idr=id^1;

        if(cur->next[idr]!=NULL && cur->cnt[idr])
        {
            cur=cur->next[idr];
            res= (res<<1)+idr;
        }
        else if(cur->next[id]!=NULL) {cur=cur->next[id]; res=(res<<1) + id; }
        else return 0;

    }

    return res;
}


int main()
{

    root=new node();
    i64 q;
    cin>>q;

    while(q--)
    {
        char ch;
         i64 x;
        cin>>ch>>x;
        getchar();

        string str=bitset<32>(x).to_string();

        if(ch=='+')
            Insert(str);
        else if(ch=='-')
            Remove(str);
        else
        {
            node* cur=root;
            i64 res=Search(str);
            printf("%lld\n",max(x,res^x));

        }


    }
}

