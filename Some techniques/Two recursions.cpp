///http://codeforces.com/problemset/problem/51/B
//html files, stack wise things
#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

map<string,int>mp;
vector<int>tot;

void init()
{
    mp["<table>"]=3;
    mp["</table>"]=-3;
    mp["<tr>"]=2;
    mp["</tr>"]=-2;
    mp["<td>"]=1;
    mp["</td>"]=-1;

}


vector<int>vec,vec2;
void process(string str)
{
    string ret;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='<')
        {
            ret="";
            while(str[i]!='>'  && i<str.size())
                ret+=str[i], i++;

            ret+=str[i];


            if(mp[ret]!=2 && mp[ret]!=-2)
                vec.push_back(mp[ret]);

        }

    }

//    for(int i=0; i<vec.size(); i++)
//        printf("%d ",vec[i]);
//
//    puts("");

}

int pos;

int Table1();
int Table2();

int Table2()
{
   // printf("in 2: %d -> %d\n",pos,vec[pos]);


    if(vec[pos+1]==-1)
    {
        pos++;
        //printf("returning from 2\n");
        return 1;
    }

    int res=0;
    while(vec[pos+1]==3)
    {
        pos++;
        res+=Table1();
    }



//    printf("2=>%d\n",res);
//    tot.push_back(res);

    if(vec[pos+1]==-1)
    {
        pos++;
       // printf("returning from 2\n");
        return res;
    }
}

int Table1()
{
   // printf("in 1: %d -> %d\n",pos,vec[pos]);

    int res=0;
    while(vec[pos+1]==1)
    {
        pos++;
        res+=Table2();
    }

   // printf("1=>%d\n",res);
    tot.push_back(res);

    if(vec[pos+1]==-3)
    {
       // printf("returning from 1\n");
        pos++;
        return 1;
    }


}


int main()
{
    init();
    //freopen("input.txt","r",stdin);

    string str;
    char ara[6009];
    while((scanf("%s",&ara))!=EOF)
        str+=ara;

    process(str);


    stack<int>stk;

    int res=Table1();
//    cout<<"--->"<<res<<endl;
//    tot.push_back(res);



   // puts("");


    sort(tot.begin(),tot.end());

    for(int i=0; i<tot.size(); i++)
    {

        if(i) printf(" ");

        printf("%d",tot[i]);

    }

    puts("");


}

