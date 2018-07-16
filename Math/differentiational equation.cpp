/**http://codeforces.com/contest/932/problem/E
see its tutorial

differentiate this equation and multiply by x:
x^b * (1+x)^c
= b*x^b * (1+x)^c  + c*x^(b+1)  * (1+x)^(c-1)

same as diff,  nCr x^r;  = nCr* r*x^r;

this can be written as the following dp function


*/
#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
#define mod 1000000007
using namespace std;

i64 pow1(int x, int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
    {
        i64 res= pow1(x,n/2);
        return (res*res)%mod;
    }

    return (x*pow1(x,n-1))%mod;
}

int dp[5001][5001];

int f(int k, int a, int n)
{

    if(k==0)
    {
        i64 res= pow1(2,n-a);


        return (int)res;
    }

    if(dp[k][a]!=-1)
        return dp[k][a];

    int rem=n-a;
    int res= ( (a? 1LL*a* f(k-1,a,n) :0LL)  +  (rem? 1LL*rem*f(k-1,a+1,n):0LL) )%mod;


    return dp[k][a]= res;

}

int main()
{
    memset(dp,-1,sizeof dp);
    int n,k;
    cin>>n>>k;

    cout<<f(k,0,n)<<endl;

}

